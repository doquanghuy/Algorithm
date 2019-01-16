//
//  DFSConnected.cpp
//  Demo
//
//  Created by Quang Huy on 12/19/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#include "DFSConnected.hpp"
#include "Graph.hpp"

DFSConnected:: DFSConnected(Graph g): g(g) {
    int v = g.V();
    this -> ids = new int[v]();
    this -> markedVertices = new bool[v]();
    this -> c = 0;
    
    for (int i = 0; i < g.V(); i++) {
        if (!markedVertices[i]) {
            dfs(g, i);
            c++;
        }
    }
}

using namespace std;
bool DFSConnected:: connected(int v, int w) {
    return ids[v] = ids[w];
}
int DFSConnected:: count() {
    return c;
}

void DFSConnected:: dfs(Graph g, int s) {
    markedVertices[s] = true;
    ids[s] = c;
    
    Iterator<int>* adj = g.adj(s) -> iterator();
    while (adj -> hasNext()) {
        int w = adj -> next();
        if (markedVertices[w]) {
            continue;
        }
        dfs(g, w);
    }
}

int DFSConnected:: id(int v) {
    return 0;
}
