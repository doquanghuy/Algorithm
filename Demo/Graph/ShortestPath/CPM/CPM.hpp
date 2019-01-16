//
//  CPM.hpp
//  Demo
//
//  Created by Quang Huy on 1/2/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#ifndef CPM_hpp
#define CPM_hpp

#include <stdio.h>
#include "SequentialSearchST.hpp"
class StdIn;

class CPM {
public:
    static SymbolTable<int, double>* process(StdIn& in);
};

#endif /* CPM_hpp */
