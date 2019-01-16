//
//  DFDirectedPath.cpp
//  Demo
//
//  Created by Quang Huy on 12/22/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#include "DFDirectedPath.hpp"
#include "Digraph.hpp"
#include "Stack+LinkedList.hpp"

DFDirectedPath:: DFDirectedPath(Digraph g, int s) {
    int v = g.V();
    this -> s = s;
    this -> edges = new int[v]; // number elements of edges array is never bigger than v because dfs will automatically ignore circle if have
    this -> markedVertices = new bool[v]();
    dfs(g, s);
}

bool DFDirectedPath:: hasPathTo(int v) {
    return markedVertices[v];
}

Iterable<int>* DFDirectedPath:: pathTo(int v) {
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

void DFDirectedPath:: dfs(Digraph g, int s) {
    markedVertices[s] = true;
    Iterator<int>* iterator = g.adj(s) -> iterator();
    
    while (iterator -> hasNext()) {
        int w = iterator -> next();
        if (!markedVertices[w]) {
            edges[w] = s;
            dfs(g, w);
        }
    }
}

