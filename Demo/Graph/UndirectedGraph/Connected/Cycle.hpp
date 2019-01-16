//
//  Cycle.hpp
//  Demo
//
//  Created by Quang Huy on 12/20/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef Cycle_hpp
#define Cycle_hpp

#include <stdio.h>
class Graph;

class Cycle {
public:
    Cycle(Graph g, int s);
    bool isCycle();
private:
    void dfs(Graph g, int s, int d);
    bool* markedVertices;
    bool _isCycle;
};

#endif /* Cycle_hpp */
