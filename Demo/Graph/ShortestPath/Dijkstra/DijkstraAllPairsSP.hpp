//
//  DijkstraAllPairsSP.hpp
//  Demo
//
//  Created by Quang Huy on 1/2/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#ifndef DijkstraAllPairsSP_hpp
#define DijkstraAllPairsSP_hpp

#include <stdio.h>
#include "Iterator.hpp"
class EdgeWeightedDigraph;
class DirectedEdge;
class DijkstraSP;

class DijkstraAllPairsSP {
public:
    DijkstraAllPairsSP(EdgeWeightedDigraph G);
    Iterable<DirectedEdge>* path(int s, int t);
    double dist(int s, int t);
private:
    DijkstraSP** sps;
};

#endif /* DijkstraAllPairsSP_hpp */
