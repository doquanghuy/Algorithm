//
//  Cycle.cpp
//  Demo
//
//  Created by Quang Huy on 12/20/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#include "Cycle.hpp"
#include "Graph.hpp"

Cycle:: Cycle(Graph g, int s) {
    this -> markedVertices = new bool[g.vertices()]();
    this -> dfs(g, s, s);
}

bool Cycle:: isCycle() {
    return _isCycle;
}

void Cycle:: dfs(Graph g, int s, int d) {
    markedVertices[s] = true;
    
    Iterator<int>* adj = g.adjacent(s) -> iterator();
    while (adj -> hasNext()) {
        int w = adj -> next();
        if (!markedVertices[w]) {
            dfs(g, w, s);
        } else if (w != d) {
            _isCycle = true;
        }
    }
}
