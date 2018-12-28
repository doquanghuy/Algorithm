//
//  UFConnected.cpp
//  Demo
//
//  Created by Quang Huy on 12/19/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#include "UFConnected.hpp"
#include "FileManager.hpp"

UFConnected:: UFConnected(StdIn& in) {
    this -> v = in.readInt();
    this -> e = in.readInt();
    this -> uf = WeightedUnion(v);
    this -> ids = new int[v]();
    
    for (int i = 0; i < e; i++) {
        int p = in.readInt();
        int q = in.readInt();
        uf.unionBetween(p, q);
    }
}

bool UFConnected:: connected(int v, int w) {
    return uf.connected(v, w);
}

int UFConnected:: count() {
    return uf.numberOfGroups();
}

int UFConnected:: id(int v) {
    return uf.find(v);
}
