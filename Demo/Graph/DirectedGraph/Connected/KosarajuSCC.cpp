//
//  KosarajuSCC.cpp
//  Demo
//
//  Created by Quang Huy on 12/24/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#include "KosarajuSCC.hpp"
#include "Digraph.hpp"
#include "DFOrder.hpp"

KosarajuSCC:: KosarajuSCC(Digraph g) {
    this -> markedVertices = new bool[g.V()];
    this -> _id = new int[g.V()];
    Digraph reversedGraph = g.reverse();
    DFOrder dfo(reversedGraph);
    Iterator<int>* iterator = dfo.reversePost() -> iterator();
    while (iterator -> hasNext()) {
        int w = iterator -> next();
        if (markedVertices[w]) continue;
        dfs(g, w);
        _count++;
    }
}

bool KosarajuSCC:: stronglyConnected(int v, int w) {
    return id(v) == id(w);
}

int KosarajuSCC:: id(int v) {
    return _id[v];
}

int KosarajuSCC:: count() {
    return _count;
}

void KosarajuSCC:: dfs(Digraph g, int s) {
    markedVertices[s] = true;
    _id[s] = _count;
    Iterator<int>* adj = g.adjacent(s) -> iterator();
    while (adj -> hasNext()) {
        int w = adj -> next();
        if (!markedVertices[w]) {
            dfs(g, w);
        }
    }
}
