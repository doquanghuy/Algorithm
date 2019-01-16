
//
//  DirectedCycleEDW.cpp
//  Demo
//
//  Created by Quang Huy on 1/2/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#include "DirectedCycleEDW.hpp"
#include "EdgeWeightedDigraph.hpp"
#include "DirectedEdge.hpp"

DirectedCycleEDW:: DirectedCycleEDW(EdgeWeightedDigraph g) {
    this -> _numberCycles = 0;
    this -> markedVertices = new bool[g.V()]();
    this -> edges = new DirectedEdge[g.V()];
    this -> onStack = new bool[g.V()];
    this -> _cycles = new Iterable<DirectedEdge>*[100];
    
    for (int i = 0; i < g.V(); i++) {
        dfs(g, i);
    }
}

bool DirectedCycleEDW:: hasCycle() {
    return _numberCycles > 0;
}

Iterable<DirectedEdge>** DirectedCycleEDW:: cycles() {
    return _cycles;
}

void DirectedCycleEDW:: dfs(EdgeWeightedDigraph g, int s) {
    markedVertices[s] = true;
    onStack[s] = true;
    
    Iterator<DirectedEdge>* adj = g.adj(s) -> iterator();
    while (adj -> hasNext()) {
        DirectedEdge edge = adj -> next();
        int w = edge.to();
        if (!markedVertices[w]) {
            edges[w] = edge;
            dfs(g, w);
        } else if (onStack[w]) {
            int v = s;
            LinkStack<DirectedEdge>* _cycle = new LinkStack<DirectedEdge>;
            while (v != w) {
                _cycle -> push(edges[v]);
                v = edges[v].from();
            }
            _cycle -> push(edge);
            _cycles[_numberCycles++] = _cycle;
        }
    }
    onStack[s] = false;
}

int DirectedCycleEDW:: numberCycles() {
    return _numberCycles;
}
