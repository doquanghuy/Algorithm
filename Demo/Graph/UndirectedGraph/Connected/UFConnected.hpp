//
//  UFConnected.hpp
//  Demo
//
//  Created by Quang Huy on 12/19/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef UFConnected_hpp
#define UFConnected_hpp

#include <stdio.h>
#include "WeightedUnion.hpp"
class StdIn;

class UFConnected {
public:
    UFConnected(StdIn& in);
    bool connected(int v, int w);
    int count();
    int id(int v);
private:
    WeightedUnion uf;
    int* ids;
    int v;
    int e;
};

#endif /* UFConnected_hpp */
