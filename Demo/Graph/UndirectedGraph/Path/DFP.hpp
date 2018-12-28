//
//  DFP.hpp
//  Demo
//
//  Created by Quang Huy on 12/19/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef DFP_hpp
#define DFP_hpp

#include <stdio.h>
#include "Iterator.hpp"
class Graph;

class DFP {
public:
    DFP(Graph g, int s);
    bool hasPathTo(int v);
    Iterable<int>* pathTo(int v);
private:
    void dfs(Graph g, int s);
    int s;
    int* edges;
    bool* markedVertices;
};

#endif /* DFP_hpp */
