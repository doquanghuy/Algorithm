
//
//  DirectedCycle.cpp
//  Demo
//
//  Created by Quang Huy on 12/22/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#include "DirectedCycle.hpp"
#include "Digraph.hpp"

DirectedCycle:: DirectedCycle(Digraph g) {
    this -> _numberCycles = 0;
    this -> markedVertices = new bool[g.V()]();
    this -> edges = new int[g.V()];
    this -> onStack = new bool[g.V()];
    this -> _cycles = new Iterable<int>*[100];
    
    for (int i = 0; i < g.V(); i++) {
        dfs(g, i);
    }
}

bool DirectedCycle:: hasCycle() {
    return _numberCycles > 0;
}

Iterable<int>** DirectedCycle:: cycles() {
    return _cycles;
}

void DirectedCycle:: dfs(Digraph g, int s) {
    markedVertices[s] = true;
    onStack[s] = true;
    
    Iterator<int>* adj = g.adj(s) -> iterator();
    while (adj -> hasNext()) {
        int w = adj -> next();
        if (!markedVertices[w]) {
            edges[w] = s;
            dfs(g, w);
        } else if (onStack[w]) {
            int v = s;
            LinkStack<int>* _cycle = new LinkStack<int>;
            while (v != w) {
                _cycle -> push(v);
                v = edges[v];
            }
            _cycle -> push(w);
            _cycle -> push(s);
            _cycles[_numberCycles++] = _cycle;
        }
    }
    onStack[s] = false;
}

int DirectedCycle:: numberCycles() {
    return _numberCycles;
}

