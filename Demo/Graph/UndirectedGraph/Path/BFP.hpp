//
//  BFP.hpp
//  Demo
//
//  Created by Quang Huy on 12/19/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef BFP_hpp
#define BFP_hpp

#include <stdio.h>
#include <stdio.h>
#include "Iterator.hpp"
class Graph;

class BFP {
public:
    BFP(Graph g, int s);
    bool hasPathTo(int v);
    Iterable<int>* pathTo(int v);
private:
    void bfs(Graph g, int s);
    bool* markedVertices;
    int* edges;
    int s;
};

#endif /* BFP_hpp */
