//
//  BellmanFordSP.hpp
//  Demo
//
//  Created by Quang Huy on 1/2/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#ifndef BellmanFordSP_hpp
#define BellmanFordSP_hpp

#include <stdio.h>
#include "Iterator.hpp"
#include "Queue+LinkedList.hpp"
class DirectedEdge;
class EdgeWeightedDigraph;

class BellmanFordSP {
public:
    BellmanFordSP(EdgeWeightedDigraph G, int s);
    double distTo(int v);
    bool hasPathTo(int v);
    Iterable<DirectedEdge>* pathTo(int v);
    bool hasNegativeCycle();
    Iterable<DirectedEdge>** negativeCycle();
private:
    int s;
    int cost;
    int V;
    int numberCycles;
    DirectedEdge* edgeTo;
    double* _distTo;
    bool* onQueue;
    LinkQueue<int> queue;
    Iterable<DirectedEdge>** cycles;
    void relax(EdgeWeightedDigraph G, int v);
    void findNegativeCycle();
};

#endif /* BellmanFordSP_hpp */
