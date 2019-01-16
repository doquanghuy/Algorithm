//
//  DFS.cpp
//  Demo
//
//  Created by Quang Huy on 12/18/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#include "DFS.hpp"
#include "Graph.hpp"

DFS:: DFS(Graph g, int s) {
    this -> markedVertices = new bool[g.V()]();
    this -> dfs(g, s);
}

bool DFS:: marked(int v) {
    return markedVertices[v];
}

int DFS:: count() {
    return c;
}

void DFS:: dfs(Graph g, int s) {
    markedVertices[s] = true;
    c++;
    
    Iterator<int>* adj = g.adj(s) -> iterator();
    while (adj -> hasNext()) {
        int w = adj -> next();
        if (!markedVertices[w]) {
            dfs(g, w);
        }
    }
}
