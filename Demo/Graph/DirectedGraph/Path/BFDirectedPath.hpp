//
//  BFDirectedPath.hpp
//  Demo
//
//  Created by Quang Huy on 12/22/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef BFDirectedPath_hpp
#define BFDirectedPath_hpp

#include <stdio.h>
#include "Iterator.hpp"
class Digraph;

class BFDirectedPath {
public:
    BFDirectedPath(Digraph g, int s);
    bool hasPathTo(int v);
    Iterable<int>* pathTo(int v);
private:
    void bfs(Digraph g, int s);
    bool* markedVertices;
    int* edges;
    int s;
};

#endif /* BFDirectedPath_hpp */
