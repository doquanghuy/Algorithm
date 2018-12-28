//
//  UFS.hpp
//  Demo
//
//  Created by Quang Huy on 12/19/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef UFS_hpp
#define UFS_hpp

#include <stdio.h>
#include "WeightedUnion.hpp"
class StdIn;

class UFS {
public:
    UFS(StdIn& in, int s);
    bool marked(int v);
    int count();
private:
    int numberOfVertices;
    int numberOfEdges;
    int source;
    WeightedUnion uf;
    void setup(StdIn& in, int s);
};

#endif /* UFS_hpp */
