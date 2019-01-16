//
//  KruskalPrimMST.cpp
//  Demo
//
//  Created by Quang Huy on 12/25/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#include "KruskalPrimMST.hpp"
#include "Edge.hpp"
#include "MinPriorityQueue.hpp"
#include "WeightedUnion.hpp"

KruskaPrimMST:: KruskaPrimMST(EdgeWeightedGraph graph) {
    Edge edges[graph.E()];
    Iterator<Edge>* iterator = graph.edges() -> iterator();
    int count = 0;
    while (iterator -> hasNext()) {
        Edge edge = iterator -> next();
        edges[count++] = edge;
    }
    MinPQ<Edge> pq(edges, graph.E());
    WeightedUnion uf(graph.V());
    
    while (!pq.isEmpty() && mst.size() < graph.V() - 1) {
        Edge minEdge = pq.delMin();
        int v = minEdge.either();
        int w = minEdge.other(v);
        if (uf.connected(v, w)) {
            continue;
        }
        uf.unionBetween(v, w);
        mst.enqueue(minEdge);
    }
}

Iterable<Edge>* KruskaPrimMST:: edges() {
    return &mst;
}

double KruskaPrimMST:: weight() {
    double weight = 0.0;
    Iterator<Edge>* iterator = mst.iterator();
    while (iterator -> hasNext()) {
        weight += iterator -> next().weight();
    }
    return weight;
}
