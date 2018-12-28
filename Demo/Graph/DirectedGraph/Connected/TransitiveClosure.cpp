
//
//  TransitiveClosure.cpp
//  Demo
//
//  Created by Quang Huy on 12/24/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#include "TransitiveClosure.hpp"
#include "Digraph.hpp"
#include "DirectedDFS.hpp"

TransitiveClosure:: TransitiveClosure(Digraph g) {
    this -> ddfs = new DirectedDFS*[g.V()];
    for (int i = 0; i < g.V(); i++) {
        this -> ddfs[i] = new DirectedDFS(g, i);
    }
}

bool TransitiveClosure:: reachable(int v, int w) {
    return ddfs[v] -> marked(w);
}
