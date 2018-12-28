//
//  BFS.cpp
//  Demo
//
//  Created by Quang Huy on 12/18/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#include "BFS.hpp"
#include "Graph.hpp"
#include "Queue+LinkedList.hpp"

BFS:: BFS(Graph g, int s) {
    this -> markedVertices = new bool[g.vertices()]();
    bfs(g, s);
}

bool BFS:: marked(int v) {
    return markedVertices[v];
}

int BFS:: count() {
    return c;
}

void BFS:: bfs(Graph g, int s) {
    LinkQueue<int> queue;
    markedVertices[s] = true;
    queue.enqueue(s);
    c++;
    
    while (!queue.isEmpty()) {
        int v = queue.dequeue();
        Iterator<int>* adj = g.adjacent(v) -> iterator();
        
        while (adj -> hasNext()) {
            int w = adj -> next();
            if (!markedVertices[w]) {
                queue.enqueue(w);
                markedVertices[w] = true;
                c++;
            }
        }
    }
}
