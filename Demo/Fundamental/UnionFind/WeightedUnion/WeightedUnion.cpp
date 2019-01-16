//
//  WeightedUnion.cpp
//  Demo
//
//  Created by Quang Huy on 12/2/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#include "WeightedUnion.hpp"

WeightedUnion:: WeightedUnion() {}

WeightedUnion:: WeightedUnion(int N) {
    count = N;
    id = std:: vector<int>(N);
    sizes = std:: vector<int>(N);
    
    for (int i = 0; i < N; i++) {
        id[i] = i;
        sizes[i] = 1; // 1 node to itself
    }
}

int WeightedUnion:: numberOfGroups() {
    return count;
}

int WeightedUnion:: find(int p) {
    while (id[p] != p) {
        p = id[p];
    }
    return p;
}

int WeightedUnion:: size(int p) {
    return sizes[find(p)];
}

bool WeightedUnion:: connected(int p, int q) {
    return find(p) == find(q);
}

void WeightedUnion:: unionBetween(int p, int q) {
    int rootP = find(p);
    int rootQ = find(q);
    
    if (rootP == rootQ) {
        return;
    }
    
    if (sizes[rootP] < sizes[rootQ]) { // q is the larger tree => assign tree of q is child of tree of q
        id[rootP] = rootQ;
        sizes[rootQ] += sizes[rootP];
    } else {
        id[rootQ] = rootP;
        sizes[rootP] += sizes[rootQ];
    }
    count --;
}
