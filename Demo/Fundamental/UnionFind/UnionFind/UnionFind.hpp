//
//  UnionFind.hpp
//  Demo
//
//  Created by Quang Huy on 12/2/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef UnionFind_hpp
#define UnionFind_hpp

#include <stdio.h>
#include <vector>

class UnionFind {
    std:: vector<int> id;
    int count;
public:
    UnionFind(int);
    void unionBetween(int p, int q);
    int find(int);
    bool connected(int p, int q);
    int numberOfGroups();
};

#endif /* UnionFind_hpp */
