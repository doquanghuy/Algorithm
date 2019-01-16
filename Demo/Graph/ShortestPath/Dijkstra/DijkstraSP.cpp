//
//  DijkstraSP.cpp
//  Demo
//
//  Created by Quang Huy on 1/2/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#include "DijkstraSP.hpp"
#include "EdgeWeightedDigraph.hpp"
#include "DirectedEdge.hpp"
#include "Stack+LinkedList.hpp"

DijkstraSP:: DijkstraSP(EdgeWeightedDigraph G, int s): pq(MinIndexPQ<double>(G.V())) {
    this -> s = s;
    this -> edgeTo = new DirectedEdge[G.V()];
    this -> _distTo = new double[G.V()];
    for (int i = 0; i < G.V(); i++) {
        _distTo[i] = std::numeric_limits<double>::infinity();
    }
    _distTo[s] = 0;
    pq.insert(s, 0.0);
    while (!pq.isEmpty()) {
        relax(G, pq.deleteMin());
    }
}

void DijkstraSP:: relax(EdgeWeightedDigraph G, int v) {
    Iterator<DirectedEdge>* adj = G.adj(v) -> iterator();
    while (adj -> hasNext()) {
        DirectedEdge edge = adj -> next();
        int w = edge.to();
        if (_distTo[w] > edge.weight() + _distTo[v]) {
            _distTo[w] = edge.weight() + _distTo[v];
            edgeTo[w] = edge;
            if (pq.contains(w)) {
                pq.change(w, _distTo[w]);
            } else {
                pq.insert(w, _distTo[w]);
            }
        }
    }
}

double DijkstraSP:: distTo(int v) {
    return _distTo[v];
}

bool DijkstraSP:: hasPathTo(int v) {
    return _distTo[v] != std::numeric_limits<double>::infinity();
}

Iterable<DirectedEdge>* DijkstraSP:: pathTo(int v) {
    if (!hasPathTo(v)) {
        return 0;
    }
    LinkStack<DirectedEdge>* path = new LinkStack<DirectedEdge>;
    int c = v;
    while (c != s) {
        path -> push(edgeTo[c]);
        c = edgeTo[c].from();
    }
    return path;
}
