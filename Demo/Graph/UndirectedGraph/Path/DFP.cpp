//
//  DFP.cpp
//  Demo
//
//  Created by Quang Huy on 12/19/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#include "DFP.hpp"
#include "Graph.hpp"
#include "Stack+LinkedList.hpp"

DFP:: DFP(Graph g, int s) {
    int v = g.vertices();
    this -> edges = new int[v];
    this -> s = s;
    this -> markedVertices = new bool[v]();
    
    dfs(g, s);
}

bool DFP:: hasPathTo(int v) {
    return markedVertices[v];
}

Iterable<int>* DFP:: pathTo(int v) {
    LinkStack<int>* stack = new LinkStack<int>;
    if (!markedVertices[v]) {
        return stack;
    }

    while (v != s) {
        stack -> push(v);
        v = edges[v];
    }
    stack -> push(s);
    return stack;
}

void DFP:: dfs(Graph g, int s) {
    markedVertices[s] = true;
    Iterator<int>* iterator = g.adjacent(s) -> iterator();

    while (iterator -> hasNext()) {
        int w = iterator -> next();
        if (!markedVertices[w]) {
            edges[w] = s;
            dfs(g, w);
        }
    }
}

