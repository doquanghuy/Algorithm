//
//  DirectedCycleEDW.hpp
//  Demo
//
//  Created by Quang Huy on 1/2/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#ifndef DirectedCycleEDW_hpp
#define DirectedCycleEDW_hpp

#include <stdio.h>
#include "Stack+LinkedList.hpp"
class EdgeWeightedDigraph;
class DirectedEdge;

class DirectedCycleEDW {
public:
    DirectedCycleEDW(EdgeWeightedDigraph g);
    bool hasCycle();
    Iterable<DirectedEdge>** cycles();
    int numberCycles();
private:
    int _numberCycles;
    bool* markedVertices;
    Iterable<DirectedEdge>** _cycles;
    DirectedEdge* edges;
    bool* onStack;
    void dfs(EdgeWeightedDigraph g, int s);
};

#endif /* DirectedCycleEDW_hpp */
