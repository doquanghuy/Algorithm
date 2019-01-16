//
//  EagerPrimMST.cpp
//  Demo
//
//  Created by Quang Huy on 12/25/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#include "EagerPrimMST.hpp"
#include "Edge.hpp"
#include "Queue+LinkedList.hpp"

EagerPrimMST:: EagerPrimMST(EdgeWeightedGraph graph): pq(MinIndexPQ<double>(graph.V())) {
    this -> V = graph.V();
    this -> _edges = new Edge[V];
    this -> distTo = new double[V];
    this -> marked = new bool[V]();
    
    for (int i = 0; i < V; i++) {
        distTo[i] = std::numeric_limits<double>::infinity();
    }
    
    distTo[0] = 0.0;
    pq.insert(0, 0.0);
    while (!pq.isEmpty()) {
        visit(graph, pq.deleteMin());
    }
}

Iterable<Edge>* EagerPrimMST:: edges() {
    LinkQueue<Edge>* queue = new LinkQueue<Edge>;
    for (int i = 1; i < V; i++) {
        queue -> enqueue(_edges[i]);
    }
    return queue;
}

double EagerPrimMST:: weight() {
    double weight = 0.0;
    for (int i = 1; i < V; i++) {
        weight += _edges[i].weight();
    }
    return weight;
}

void EagerPrimMST:: visit(EdgeWeightedGraph graph, int v) {
    marked[v] = true;
    Iterator<Edge>* adj = graph.adj(v) -> iterator();
    while (adj -> hasNext()) {
        Edge edge = adj -> next();
        int w = edge.other(v);
        if (marked[w]) {
            continue;
        }
        if (edge.weight() < distTo[w]) {
            distTo[w] = edge.weight();
            _edges[w] = edge;
            if (!pq.contains(w)) {
                pq.insert(w, distTo[w]);
            } else {
                pq.change(w, distTo[w]);
            }
        }
    }
}

