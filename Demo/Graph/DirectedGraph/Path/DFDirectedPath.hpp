//
//  DFDirectedPath.hpp
//  Demo
//
//  Created by Quang Huy on 12/22/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef DFDirectedPath_hpp
#define DFDirectedPath_hpp

#include <stdio.h>
#include "Iterator.hpp"

class Digraph;

class DFDirectedPath {
public:
    DFDirectedPath(Digraph g, int s);
    bool hasPathTo(int v);
    Iterable<int>* pathTo(int v);
private:
    void dfs(Digraph g, int s);
    int s;
    int* edges;
    bool* markedVertices;
};
#endif /* DFDirectedPath_hpp */
