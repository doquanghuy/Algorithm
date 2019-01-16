//
//  TopologicalEDW.hpp
//  Demo
//
//  Created by Quang Huy on 1/2/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#ifndef TopologicalEDW_hpp
#define TopologicalEDW_hpp

#include <stdio.h>
#include "Iterator.hpp"
class EdgeWeightedDigraph;

class TopologicalEDW {
public:
    TopologicalEDW(EdgeWeightedDigraph g);
    const Iterable<int>* order();
    bool isDAG();
private:
    const Iterable<int>* _order;
};

#endif /* TopologicalEDW_hpp */
