
//
//  DFOrder.cpp
//  Demo
//
//  Created by Quang Huy on 12/24/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#include "DFOrder.hpp"
#include "Digraph.hpp"

DFOrder:: DFOrder(Digraph g) {
    this -> markedVertices = new bool[g.V()];
    for (int i = 0; i < g.V(); i++) {
        if (!markedVertices[i]) {
            dfs(g, i);
        }
    }
}

const Iterable<int>* DFOrder:: pre() {
    return &preQueue;
}

const Iterable<int>* DFOrder:: post() {
    return &postQueue;
}

const Iterable<int>* DFOrder:: reversePost() {
    return &reversePostStack;
}

void DFOrder:: dfs(Digraph g, int s) {
    preQueue.enqueue(s);
    markedVertices[s] = true;
    Iterator<int>* adj = g.adjacent(s) -> iterator();
    while (adj -> hasNext()) {
        int w = adj -> next();
        if (!markedVertices[w]) {
            dfs(g, w);
        }
    }
    postQueue.enqueue(s);
    reversePostStack.push(s);
}
