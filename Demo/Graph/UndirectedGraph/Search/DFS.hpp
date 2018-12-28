//
//  DFS.hpp
//  Demo
//
//  Created by Quang Huy on 12/18/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef DFS_hpp
#define DFS_hpp

#include <stdio.h>
class Graph;

class DFS {
public:
    DFS(Graph g, int s);
    bool marked(int v);
    int count(); // how many vertices connected to s;
private:
    void dfs(Graph g, int s);
    bool* markedVertices;
    int c;
};

#endif /* DFS_hpp */
