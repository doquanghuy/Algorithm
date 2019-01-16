//
//  UnionFind.cpp
//  Demo
//
//  Created by Quang Huy on 12/2/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#include "UnionFind.hpp"

UnionFind:: UnionFind(int N) {
    count = N;
    id = std:: vector<int>(N);
    for (int i = 0; i < N; i++) {
        id[i] = i;
    }
}

int UnionFind:: numberOfGroups() {
    return count;
}

int UnionFind:: find(int p) {
    return id[p];
}

bool UnionFind:: connected(int p, int q) {
    return find(p) == find(q);
}

void UnionFind:: unionBetween(int p, int q) {
    int pValue = id[p];
    int qValue = id[q];
    
    if (pValue == qValue) {
        return;
    }
    
    for (int i = 0; i < id.size(); i++) {
        if (id[i] == pValue) {
            id[i] = qValue;
        }
    }
    
    count --;
}
