//
//  DFSConnected.hpp
//  Demo
//
//  Created by Quang Huy on 12/19/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef DFSConnected_hpp
#define DFSConnected_hpp

#include <stdio.h>
#include "Graph.hpp"

class DFSConnected {
public:
    DFSConnected(Graph g);
    bool connected(int v, int w);
    int count();
    int id(int v);
private:
    Graph g;
    bool* markedVertices;
    int* ids;
    int c;
    void dfs(Graph g, int s);
};
#endif /* DFSConnected_hpp */
