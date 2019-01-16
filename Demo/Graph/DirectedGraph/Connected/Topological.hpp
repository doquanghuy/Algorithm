//
//  Topological.hpp
//  Demo
//
//  Created by Quang Huy on 12/24/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef Topological_hpp
#define Topological_hpp

#include <stdio.h>
#include "Iterator.hpp"
class Digraph;

class Topological {
public:
    Topological(Digraph g);
    const Iterable<int>* order();
    bool isDAG();
private:
    const Iterable<int>* _order;
};

#endif /* Topological_hpp */
