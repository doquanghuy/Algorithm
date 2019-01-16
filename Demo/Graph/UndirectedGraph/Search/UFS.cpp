
//
//  UFS.cpp
//  Demo
//
//  Created by Quang Huy on 12/19/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#include "UFS.hpp"
#include "Graph.hpp"
#include "FileManager.hpp"

UFS:: UFS(StdIn& in, int s) {
    this -> source = s;
    this -> numberOfVertices = in.readInt();
    this -> numberOfEdges = in.readInt();
    this -> uf = WeightedUnion(numberOfVertices);
    this -> setup(in, s);
}

bool UFS:: marked(int v) {
    return uf.connected(v, source);
}

int UFS:: count() {
    return uf.size(source);
}

void UFS:: setup(StdIn& in, int s) {
    for (int i = 0; i < numberOfEdges; i++) {
        int p = in.readInt();
        int q = in.readInt();
        uf.unionBetween(p, q);
    }
}

