//
//  DijkstraAllPairsSP.cpp
//  Demo
//
//  Created by Quang Huy on 1/2/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#include "DijkstraAllPairsSP.hpp"
#include "EdgeWeightedDigraph.hpp"
#include "DijkstraSP.hpp"

DijkstraAllPairsSP:: DijkstraAllPairsSP(EdgeWeightedDigraph G) {
    this -> sps = new DijkstraSP*[G.V()];
    for (int i = 0; i < G.V(); i++) {
        sps[i] = new DijkstraSP(G, i);
    }
}

Iterable<DirectedEdge>* DijkstraAllPairsSP:: path(int s, int t) {
    return sps[s] -> pathTo(t);
}

double DijkstraAllPairsSP:: dist(int s, int t) {
    return sps[s] -> distTo(t);
}
