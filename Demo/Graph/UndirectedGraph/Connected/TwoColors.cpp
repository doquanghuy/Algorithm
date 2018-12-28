//
//  TwoColors.cpp
//  Demo
//
//  Created by Quang Huy on 12/20/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#include "TwoColors.hpp"
#include "Graph.hpp"

TwoColors:: TwoColors(Graph g, int s) {
    this -> markedVertices = new bool[g.vertices()]();
    this -> colors = new bool[g.vertices()]();
    this -> _isTwoColors = true;
    this -> dfs(g, s);
}

bool TwoColors:: isTwoColors() {
    return _isTwoColors;
}

void TwoColors:: dfs(Graph g, int s) {
    markedVertices[s] = true;
    
    Iterator<int>* adj = g.adjacent(s) -> iterator();
    while (adj -> hasNext()) {
        int w = adj -> next();
        if (!markedVertices[w]) {
            colors[w] = !colors[s];
            dfs(g, w);
        } else if (colors[w] == colors[s]) {
            _isTwoColors = false;
        }
    }
}
