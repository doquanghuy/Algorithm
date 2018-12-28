//
//  LazyPrimMST.hpp
//  Demo
//
//  Created by Quang Huy on 12/25/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef LazyPrimMST_hpp
#define LazyPrimMST_hpp

#include <stdio.h>
#include "Iterator.hpp"
#include "Queue+LinkedList.hpp"
#include "MinPriorityQueue.hpp"
class EdgeWeightedGraph;
class Edge;

class LazyPrimMST {
public:
    LazyPrimMST(EdgeWeightedGraph graph);
    Iterable<Edge>* edges();
    double weight();
private:
    bool* markedVertices;
    LinkQueue<Edge> mst;
    MinPQ<Edge> pq;
    void visit(EdgeWeightedGraph graph, int s);
};

#endif /* LazyPrimMST_hpp */
