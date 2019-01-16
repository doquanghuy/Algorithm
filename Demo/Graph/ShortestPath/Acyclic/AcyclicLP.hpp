//
//  AcyclicLP.hpp
//  Demo
//
//  Created by Quang Huy on 1/2/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#ifndef AcyclicLP_hpp
#define AcyclicLP_hpp

#include <stdio.h>
#include "Iterator.hpp"
#include "MinIndexPriorityQueue.hpp"
class DirectedEdge;
class EdgeWeightedDigraph;

class AcyclicLP {
public:
    AcyclicLP(EdgeWeightedDigraph G, int s);
    double distTo(int v);
    bool hasPathTo(int v);
    Iterable<DirectedEdge>* pathTo(int v);
private:
    void relax(EdgeWeightedDigraph G, int v);
    DirectedEdge* edgeTo;
    double* _distTo;
    int s;
};

#endif /* AcyclicLP_hpp */
