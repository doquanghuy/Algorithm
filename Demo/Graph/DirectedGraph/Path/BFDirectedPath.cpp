
//
//  BFDirectedPath.cpp
//  Demo
//
//  Created by Quang Huy on 12/22/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#include "BFDirectedPath.hpp"
#include "Digraph.hpp"
#include "Queue+LinkedList.hpp"
#include "Stack+LinkedList.hpp"

BFDirectedPath:: BFDirectedPath(Digraph g, int s) {
    int v = g.V();
    this -> edges = new int[v];
    this -> markedVertices = new bool[v]();
    this -> s = s;
    bfs(g, s);
}

bool BFDirectedPath:: hasPathTo(int v) {
    return markedVertices[v];
}

Iterable<int>* BFDirectedPath:: pathTo(int v) {
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

void BFDirectedPath:: bfs(Digraph g, int s) {
    LinkQueue<int> queue;
    
    queue.enqueue(s);
    markedVertices[s] = true;
    
    while (!queue.isEmpty()) {
        int v = queue.dequeue();
        
        Iterator<int>* adj = g.adj(v) -> iterator();
        while (adj -> hasNext()) {
            int w = adj -> next();
            if (markedVertices[w]) continue;
            markedVertices[w] = true;
            queue.enqueue(w);
            edges[w] = v;
        }
    }
}
