//
//  Digraph.cpp
//  Demo
//
//  Created by Quang Huy on 12/22/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#include "Digraph.hpp"
#include "FileManager.hpp"

using namespace std;
Digraph:: Digraph(int V) {
    this -> _V = V;
    this -> _E = 0;
    this -> _adj = new LinkBag<int>[V];

    for (int i = 0; i < _V; i++) {
        _adj[i] = LinkBag<int>();
    }
}

Digraph:: Digraph(StdIn& in): Digraph(in.readInt()) {
    int e = in.readInt();
    for (int i = 0; i < e; i++) {
        this -> addEdge(in.readInt(), in.readInt());
    }
}

int Digraph:: V() {
    return _V;
}

int Digraph:: E() {
    return _E;
}

void Digraph:: addEdge(int v, int w) {
    _adj[v].add(w);
    _E++;
}

const Iterable<int>* Digraph:: adj(int v) {
    return &_adj[v];
}

Digraph Digraph:: reverse() {
    Digraph dg(_V);
    for (int i = 0; i < _V; i++) {
        Iterator<int>* iterator = _adj[i].iterator() ;
        while (iterator -> hasNext()) {
            dg.addEdge(iterator -> next(), i);
        }
    }
    return dg;
}

std:: string Digraph:: toString() {
    string s = to_string(_V) + " vertices and " + to_string(_E) + " edges:\n";
    for (int i = 0; i < _V; i++) {
        s += to_string(i) + ": ";
        Iterator<int>* iterator = _adj[i].iterator();
        while (iterator -> hasNext()) {
            s += to_string(iterator -> next()) + " ";
        }
        s += "\n";
    }
    return s;
}
