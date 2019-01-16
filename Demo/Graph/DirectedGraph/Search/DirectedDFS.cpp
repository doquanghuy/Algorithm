//
//  DirectedDFS.cpp
//  Demo
//
//  Created by Quang Huy on 12/22/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#include "DirectedDFS.hpp"
#include "Digraph.hpp"

DirectedDFS:: DirectedDFS(Digraph g, int s) {
    this -> markedVertices = new bool[g.V()]();
    dfs(g, s);
}

DirectedDFS:: DirectedDFS(Digraph g, Iterable<int>* sources) {
    this -> markedVertices = new bool[g.V()]();
    Iterator<int>* iterator = sources -> iterator();
    while (iterator -> hasNext()) {
        dfs(g, iterator -> next());
    }
}

bool DirectedDFS:: marked(int v) {
    return markedVertices[v];
}

void DirectedDFS:: dfs(Digraph g, int s) {
    markedVertices[s] = true;
    Iterator<int>* adj = g.adj(s) -> iterator();
    while (adj -> hasNext()) {
        int w = adj -> next();
        if (!markedVertices[w]) {
            dfs(g, w);
        }
    }
}
