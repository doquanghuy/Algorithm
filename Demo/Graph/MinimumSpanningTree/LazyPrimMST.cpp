//
//  LazyPrimMST.cpp
//  Demo
//
//  Created by Quang Huy on 12/25/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#include "LazyPrimMST.hpp"
#include "EdgeWeightedGraph.hpp"
#include "Edge.hpp"

LazyPrimMST:: LazyPrimMST(EdgeWeightedGraph graph): pq(MinPQ<Edge>(graph.E())) {
    this -> markedVertices = new bool[graph.V()];
    visit(graph, 0);
    while (!pq.isEmpty()) {
        Edge edge = pq.delMin();
        int v = edge.either();
        int w = edge.other(v);
        if (markedVertices[v] && markedVertices[w]) {
            continue;
        }
        mst.enqueue(edge);
        if (!markedVertices[v]) {
            visit(graph, v);
        }
        if (!markedVertices[w]) {
            visit(graph, w);
        }
    }
}

Iterable<Edge>* LazyPrimMST:: edges() {
    return &mst;
}

double LazyPrimMST:: weight() {
    double weight = 0.0;
    Iterator<Edge>* iterator = mst.iterator();
    while (iterator -> hasNext()) {
        weight += iterator -> next().weight();
    }
    return weight;
}

void LazyPrimMST:: visit(EdgeWeightedGraph graph, int s) {
    markedVertices[s] = true;
    Iterator<Edge>* adj = graph.adj(s) -> iterator();
    while (adj -> hasNext()) {
        Edge edge = adj -> next();
        pq.insert(edge);
    }
}

