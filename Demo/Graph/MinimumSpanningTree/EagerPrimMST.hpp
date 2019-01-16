//
//  EagerPrimMST.hpp
//  Demo
//
//  Created by Quang Huy on 12/25/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef EagerPrimMST_hpp
#define EagerPrimMST_hpp

#include <stdio.h>
#include "EdgeWeightedGraph.hpp"
#include "MinIndexPriorityQueue.hpp"

class EagerPrimMST {
public:
    EagerPrimMST(EdgeWeightedGraph graph);
    Iterable<Edge>* edges();
    double weight();
private:
    int V;
    Edge* _edges;
    double* distTo;
    bool* marked;
    MinIndexPQ<double> pq;
    void visit(EdgeWeightedGraph graph, int v);
};

#endif /* EagerPrimMST_hpp */
