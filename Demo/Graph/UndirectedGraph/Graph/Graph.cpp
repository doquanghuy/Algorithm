
//
//  Graph.cpp
//  Demo
//
//  Created by Quang Huy on 12/18/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#include "Graph.hpp"
#include "FileManager.hpp"

using namespace std;

Graph:: Graph(int v) {
    this -> _E = 0;
    this -> _V = v;
    this -> _adj = new LinkBag<int>[v];
    for (int i = 0; i < v; i++) {
        _adj[i] = LinkBag<int>();
    }
}

Graph:: Graph(StdIn& in): Graph(in.readInt()) {
    int e = in.readInt();
    for (int i = 0; i < e; i++) {
        this -> addEdge(in.readInt(), in.readInt());
    }
}

int Graph:: V() {
    return _V;
}

int Graph:: E() {
    return _E;
}

void Graph:: addEdge(int v, int w) {
    _adj[v].add(w);
    _adj[w].add(v);
    _E++;
}

Iterable<int>* Graph:: adj(int v) {
    return _adj + v;
}

string Graph:: toString() {
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

