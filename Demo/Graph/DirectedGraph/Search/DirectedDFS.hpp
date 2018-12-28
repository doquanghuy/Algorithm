//
//  DirectedDFS.hpp
//  Demo
//
//  Created by Quang Huy on 12/22/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef DirectedDFS_hpp
#define DirectedDFS_hpp

#include <stdio.h>
#include "Iterator.hpp"
class Digraph;

class DirectedDFS {
public:
    DirectedDFS(Digraph g, int s);
    DirectedDFS(Digraph g, Iterable<int> sources);
    bool marked(int v);
    void dfs(Digraph g, int s);
private:
    bool* markedVertices;
};
#endif /* DirectedDFS_hpp */
