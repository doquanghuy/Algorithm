//
//  KosarajuSCC.hpp
//  Demo
//
//  Created by Quang Huy on 12/24/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef KosarajuSCC_hpp
#define KosarajuSCC_hpp

#include <stdio.h>
class Digraph;

class KosarajuSCC {
public:
    KosarajuSCC(Digraph g);
    bool stronglyConnected(int v, int w);
    int id(int v);
    int count();
private:
    bool* markedVertices;
    int* _id;
    int _count;
    void dfs(Digraph g, int s);
};

#endif /* KosarajuSCC_hpp */
