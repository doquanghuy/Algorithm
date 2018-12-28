//
//  EdgeWeightedGraph.cpp
//  Demo
//
//  Created by Quang Huy on 12/25/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#include "EdgeWeightedGraph.hpp"
#include "Edge.hpp"

EdgeWeightedGraph:: EdgeWeightedGraph(int v) {
    this -> _adj = new LinkBag<Edge>[v]();
    this -> _v = v;
}

EdgeWeightedGraph:: EdgeWeightedGraph(StdIn& in) {
    this -> _v = in.readInt();
    this -> _adj = new LinkBag<Edge>[this -> _v]();
    while (!in.isEmpty()) {
        this -> addEdge(Edge(in.readInt(), in.readInt(), in.readDouble()));
    }
}

int EdgeWeightedGraph:: V() {
    return _v;
}

int EdgeWeightedGraph:: E() {
    return _e;
}

void EdgeWeightedGraph:: addEdge(Edge e) {
    _adj[e.either()].add(e);
    _adj[e.other(e.either())].add(e);
    _e++;
}

const Iterable<Edge>* EdgeWeightedGraph:: adj(int v) {
    return &_adj[v];
}

const Iterable<Edge>* EdgeWeightedGraph:: edges() {
    LinkBag<Edge>* bag = new LinkBag<Edge>;
    for (int i = 0; i < _v; i++) {
        Iterator<Edge>*  adj = _adj[i].iterator();
        while (adj -> hasNext()) {
            Edge e = adj -> next();
            if (i > e.other(i)) {
                bag -> add(e);
            }
        }
    }
    return bag;
}
