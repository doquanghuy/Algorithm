
//
//  TopologicalEDW.cpp
//  Demo
//
//  Created by Quang Huy on 1/2/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#include "TopologicalEDW.hpp"
#include "EdgeWeightedDigraph.hpp"
#include "DirectedCycleEDW.hpp"
#include "DFOrderEDW.hpp"

TopologicalEDW:: TopologicalEDW(EdgeWeightedDigraph g) {
    this -> _order = 0;
    DirectedCycleEDW dc(g);
    if (dc.hasCycle()) {
        return;
    }
    DFOrderEDW* dfo = new DFOrderEDW(g);
    this -> _order = dfo -> reversePost();
}

const Iterable<int>* TopologicalEDW:: order() {
    return this -> _order;
}

bool TopologicalEDW:: isDAG() {
    return _order != 0;
}
