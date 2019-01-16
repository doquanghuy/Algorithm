//
//  DirectedCycle.hpp
//  Demo
//
//  Created by Quang Huy on 12/22/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef DirectedCycle_hpp
#define DirectedCycle_hpp

#include <stdio.h>
#include "Stack+LinkedList.hpp"
class Digraph;

class DirectedCycle {
public:
    DirectedCycle(Digraph g);
    bool hasCycle();
    Iterable<int>** cycles();
    int numberCycles();
private:
    int _numberCycles;
    bool* markedVertices;
    Iterable<int>** _cycles;
    int* edges;
    bool* onStack;
    void dfs(Digraph g, int s);
};

#endif /* DirectedCycle_hpp */
