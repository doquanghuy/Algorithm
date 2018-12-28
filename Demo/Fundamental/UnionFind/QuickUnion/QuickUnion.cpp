//
//  QuickUnion.cpp
//  Demo
//
//  Created by Quang Huy on 12/2/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#include "QuickUnion.hpp"
#include <vector>

QuickUnion:: QuickUnion(int N) {
    count = N;
    id = std:: vector<int>(N);
    for (int i = 0; i < N; i++) {
        id[i] = i;
    }
}

int QuickUnion:: numberOfGroups() {
    return count;
}

int QuickUnion:: find(int p) {
    while (id[p] != p) {
        p = id[p];
    }
    return p;
}

bool QuickUnion:: connected(int p, int q) {
    return find(p) == find(q);
}

void QuickUnion:: unionBetween(int p, int q) {
    int rootP = find(p);
    int rootQ = find(q);
    
    if (rootP == rootQ) {
        return;
    }
    
    id[rootP] = rootQ;
    count--;
}

