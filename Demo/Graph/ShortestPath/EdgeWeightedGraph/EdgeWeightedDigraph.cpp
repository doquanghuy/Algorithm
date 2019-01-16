
//
//  EdgeWeightedDigraph.cpp
//  Demo
//
//  Created by Quang Huy on 1/2/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#include "EdgeWeightedDigraph.hpp"
#include "FileManager.hpp"
#include "DirectedEdge.hpp"

EdgeWeightedDigraph:: EdgeWeightedDigraph(int V) {
    this -> _V = V;
    this -> _E = 0;
    this -> _adj = new LinkBag<DirectedEdge>[V];
}

EdgeWeightedDigraph:: EdgeWeightedDigraph(StdIn& in) {
    this -> _V = in.readInt();
    this -> _adj = new LinkBag<DirectedEdge>[_V];
    
    int E = in.readInt();
    for (int i = 0 ; i < E; i++) {
        int v = in.readInt();
        int w = in.readInt();
        double weight = in.readDouble();
        this -> addEdge(DirectedEdge(v, w, weight));
    }
}

int EdgeWeightedDigraph:: V() {
    return _V;
}

int EdgeWeightedDigraph:: EdgeWeightedDigraph:: E() {
    return _E;
}

void EdgeWeightedDigraph:: addEdge(DirectedEdge edge) {
    _adj[edge.from()].add(edge);
    _E++;
}

const Iterable<DirectedEdge>* EdgeWeightedDigraph:: adj(int v) const {
    return &_adj[v];
}

const Iterable<DirectedEdge>* EdgeWeightedDigraph:: edges() const {
    LinkBag<DirectedEdge>* edges = new LinkBag<DirectedEdge>;
    for (int i = 0; i < _V; i++) {
        Iterator<DirectedEdge>* adj = this -> adj(i) -> iterator();
        while (adj -> hasNext()) {
            edges -> add(adj -> next());
        }
    }
    return edges;
}

std::string EdgeWeightedDigraph:: toString() {
    string s = to_string(_V) + " vertices and " + to_string(_E) + " edges:\n";
    for (int i = 0; i < _V; i++) {
        s += to_string(i) + ": ";
        Iterator<DirectedEdge>* adj = this -> adj(i) -> iterator();
        while (adj -> hasNext()) {
            s += adj -> next().toString() + " ";
        }
        s += "\n";
    }
    return s;
}
