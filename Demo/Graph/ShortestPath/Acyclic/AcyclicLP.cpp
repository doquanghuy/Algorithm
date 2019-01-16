//
//  AcyclicLP.cpp
//  Demo
//
//  Created by Quang Huy on 1/2/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#include "AcyclicLP.hpp"
#include "EdgeWeightedDigraph.hpp"
#include "DirectedEdge.hpp"
#include "Stack+LinkedList.hpp"
#include "TopologicalEDW.hpp"

AcyclicLP:: AcyclicLP(EdgeWeightedDigraph G, int s) {
    this -> edgeTo = new DirectedEdge[G.V()];
    this -> _distTo = new double[G.V()];
    this -> s = s;
    
    for (int i = 0; i < G.V(); i++) {
        _distTo[i] = -std::numeric_limits<double>::infinity();
    }
    _distTo[s] = 0.0;

    TopologicalEDW top(G);
    Iterator<int>* order = top.order() -> iterator();
    while (order -> hasNext()) {
        relax(G, order -> next());
    }
}

void AcyclicLP:: relax(EdgeWeightedDigraph G, int v) {
    Iterator<DirectedEdge>* adj = G.adj(v) -> iterator();
    while (adj -> hasNext()) {
        DirectedEdge edge = adj -> next();
        int w = edge.to();
        if (_distTo[w] < _distTo[v] + edge.weight()) {
            _distTo[w] = _distTo[v] + edge.weight();
            edgeTo[w] = edge;
        }
    }
}

double AcyclicLP:: distTo(int v) {
    return _distTo[v];
}

bool AcyclicLP:: hasPathTo(int v) {
    return _distTo[v] != -std::numeric_limits<double>::infinity();
}

Iterable<DirectedEdge>* AcyclicLP:: pathTo(int v) {
    LinkStack<DirectedEdge>* path = new LinkStack<DirectedEdge>;
    int c = v;
    while (c != s) {
        path -> push(edgeTo[c]);
        c = edgeTo[c].from();
    }
    return path;
}
