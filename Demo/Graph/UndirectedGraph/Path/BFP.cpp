//
//  BFP.cpp
//  Demo
//
//  Created by Quang Huy on 12/19/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#include "BFP.hpp"
#include "Graph.hpp"
#include "Queue+LinkedList.hpp"
#include "Stack+LinkedList.hpp"

BFP:: BFP(Graph g, int s) {
    int v = g.vertices();
    this -> edges = new int[v];
    this -> markedVertices = new bool[v]();
    this -> s = s;
    bfs(g, s);
}

bool BFP:: hasPathTo(int v) {
    return markedVertices[v];
}

Iterable<int>* BFP:: pathTo(int v) {
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

void BFP:: bfs(Graph g, int s) {
    LinkQueue<int> queue;
    
    queue.enqueue(s);
    markedVertices[s] = true;
    
    while (!queue.isEmpty()) {
        int v = queue.dequeue();
        
        Iterator<int>* adj = g.adjacent(v) -> iterator();
        while (adj -> hasNext()) {
            int w = adj -> next();
            if (markedVertices[w]) continue;
            markedVertices[w] = true;
            queue.enqueue(w);
            edges[w] = v;
        }
    }
}
