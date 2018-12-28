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
    this -> v = V;
    this -> e = 0;
    this -> adj = new LinkBag<int>[V];

    for (int i = 0; i < v; i++) {
        adj[i] = LinkBag<int>();
    }
}

Digraph:: Digraph(StdIn& in): Digraph(in.readInt()) {
    int e = in.readInt();
    for (int i = 0; i < e; i++) {
        this -> addEdge(in.readInt(), in.readInt());
    }
}

int Digraph:: V() {
    return v;
}

int Digraph:: E() {
    return e;
}

void Digraph:: addEdge(int v, int w) {
    adj[v].add(w);
    e++;
}

const Iterable<int>* Digraph:: adjacent(int v) {
    return &adj[v];
}

Digraph Digraph:: reverse() {
    Digraph dg(v);
    for (int i = 0; i < v; i++) {
        Iterator<int>* iterator = adj[i].iterator() ;
        while (iterator -> hasNext()) {
            dg.addEdge(iterator -> next(), i);
        }
    }
    return dg;
}

std:: string Digraph:: toString() {
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
