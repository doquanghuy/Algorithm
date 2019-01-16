//
//  DFOrderEDW.cpp
//  Demo
//
//  Created by Quang Huy on 1/2/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#include "DFOrderEDW.hpp"
#include "EdgeWeightedDigraph.hpp"
#include "DirectedEdge.hpp"

DFOrderEDW:: DFOrderEDW(EdgeWeightedDigraph g) {
    this -> markedVertices = new bool[g.V()];
    for (int i = 0; i < g.V(); i++) {
        if (!markedVertices[i]) {
            dfs(g, i);
        }
    }
}

const Iterable<int>* DFOrderEDW:: pre() {
    return &preQueue;
}

const Iterable<int>* DFOrderEDW:: post() {
    return &postQueue;
}

const Iterable<int>* DFOrderEDW:: reversePost() {
    return &reversePostStack;
}

void DFOrderEDW:: dfs(EdgeWeightedDigraph g, int s) {
    preQueue.enqueue(s);
    markedVertices[s] = true;
    Iterator<DirectedEdge>* adj = g.adj(s) -> iterator();
    while (adj -> hasNext()) {
        DirectedEdge edge = adj -> next();
        int w = edge.to();
        if (!markedVertices[w]) {
            dfs(g, w);
        }
    }
    postQueue.enqueue(s);
    reversePostStack.push(s);
}
