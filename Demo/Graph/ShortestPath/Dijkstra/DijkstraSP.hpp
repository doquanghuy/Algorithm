//
//  DijkstraSP.hpp
//  Demo
//
//  Created by Quang Huy on 1/2/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#ifndef DijkstraSP_hpp
#define DijkstraSP_hpp

#include <stdio.h>
#include "Iterator.hpp"
#include "MinIndexPriorityQueue.hpp"
class DirectedEdge;
class EdgeWeightedDigraph;

class DijkstraSP { // Condition: no cycle, no negative weight;
public:
    DijkstraSP(EdgeWeightedDigraph G, int s);
    double distTo(int v);
    bool hasPathTo(int v);
    Iterable<DirectedEdge>* pathTo(int v);
private:
    void relax(EdgeWeightedDigraph G, int v);
    DirectedEdge* edgeTo;
    double* _distTo;
    MinIndexPQ<double> pq;
    int s;
};
#endif /* DijkstraSP_hpp */
