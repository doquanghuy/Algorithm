//
//  BellmanFordSP.cpp
//  Demo
//
//  Created by Quang Huy on 1/2/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#include "BellmanFordSP.hpp"
#include "EdgeWeightedDigraph.hpp"
#include "DirectedEdge.hpp"
#include "Stack+LinkedList.hpp"
#include "DirectedCycleEDW.hpp"

BellmanFordSP:: BellmanFordSP(EdgeWeightedDigraph G, int s) {
    this -> V = G.V();
    this -> _distTo = new double[G.V()];
    this -> edgeTo = new DirectedEdge[G.V()]();
    this -> onQueue = new bool[G.V()];
    this -> s = s;
    this -> cost = 0;
    
    for (int i = 0; i < G.V(); i++) {
        _distTo[i] = std::numeric_limits<double>::infinity();
    }
    _distTo[s] = 0.0;
    
    queue.enqueue(s);
    onQueue[s] = true;
    
    while (!queue.isEmpty() && !hasNegativeCycle()) {
        int w = queue.dequeue();
        onQueue[w] = false;
        relax(G, w);
    }
}

void BellmanFordSP:: relax(EdgeWeightedDigraph G, int v) {
    Iterator<DirectedEdge>* adj = G.adj(v) -> iterator();
    while (adj -> hasNext()) {
        DirectedEdge edge = adj -> next();
        int w = edge.to();
        if (_distTo[w] > _distTo[v] + edge.weight()) {
            _distTo[w] = _distTo[v] + edge.weight();
            edgeTo[w] = edge;
            if (!onQueue[w]) {
                queue.enqueue(w);
                onQueue[w] = true;
            }
        }
        
        if (cost++ % G.V() == 0) {
            findNegativeCycle();
        }
    }
}

double BellmanFordSP:: distTo(int v) {
    return _distTo[v];
}

bool BellmanFordSP:: hasPathTo(int v) {
    return _distTo[v] != std::numeric_limits<double>::infinity();
}

Iterable<DirectedEdge>* BellmanFordSP:: pathTo(int v) {
    LinkStack<DirectedEdge>* path = new LinkStack<DirectedEdge>;
    int c = v;
    while (c != s) {
        path -> push(edgeTo[c]);
        c = edgeTo[c].from();
    }
    return path;
}

bool BellmanFordSP:: hasNegativeCycle() {
    return numberCycles > 0;
}

void BellmanFordSP:: findNegativeCycle() {
    EdgeWeightedDigraph G(V);
    for (int i = 0; i < V; i++) {
        if (edgeTo[i] != DirectedEdge:: defaultEdge) {
            G.addEdge(edgeTo[i]);
        }
    }
    DirectedCycleEDW dc(G);
    cycles = dc.cycles();
    numberCycles = dc.numberCycles();
}

Iterable<DirectedEdge>** BellmanFordSP:: negativeCycle() {
    return cycles;
}
