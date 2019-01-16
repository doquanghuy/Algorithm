//
//  BFS.hpp
//  Demo
//
//  Created by Quang Huy on 12/18/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef BFS_hpp
#define BFS_hpp

#include <stdio.h>
class Graph;

class BFS {
public:
    BFS(Graph g, int s);
    bool marked(int v);
    int count();
    void bfs(Graph g, int s);
private:
    bool* markedVertices;
    int c;
};

#endif /* BFS_hpp */
