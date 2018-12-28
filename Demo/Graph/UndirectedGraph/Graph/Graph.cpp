
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
    this -> e = 0;
    this -> v = v;
    this -> adj = new LinkBag<int>[v];
    for (int i = 0; i < v; i++) {
        adj[i] = LinkBag<int>();
    }
}

Graph:: Graph(StdIn& in): Graph(in.readInt()) {
    int e = in.readInt();
    for (int i = 0; i < e; i++) {
        this -> addEdge(in.readInt(), in.readInt());
    }
}

int Graph:: vertices() {
    return v;
}

int Graph:: edges() {
    return e;
}

void Graph:: addEdge(int v, int w) {
    adj[v].add(w);
    adj[w].add(v);
    e++;
}

Iterable<int>* Graph:: adjacent(int v) {
    return adj + v;
}

string Graph:: toString() {
    string s = to_string(v) + " vertices and " + to_string(e) + " edges:\n";
    for (int i = 0; i < v; i++) {
        s += to_string(i) + ": ";
        Iterator<int>* iterator = adj[i].iterator();
        while (iterator -> hasNext()) {
            s += to_string(iterator -> next()) + " ";
        }
        s += "\n";
    }
    return s;
}

