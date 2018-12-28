//
//  Topological.cpp
//  Demo
//
//  Created by Quang Huy on 12/24/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#include "Topological.hpp"
#include "Digraph.hpp"
#include "DirectedCycle.hpp"
#include "DFOrder.hpp"

Topological:: Topological(Digraph g) {
    _order = 0;
    DirectedCycle dc(g);
    if (dc.hasCycle()) {
        return;
    }
    DFOrder dfo(g);
    _order = dfo.reversePost();
}

const Iterable<int>* Topological:: order() {
    return _order;
}

bool Topological:: isDAG() {
    return _order != 0;
}

