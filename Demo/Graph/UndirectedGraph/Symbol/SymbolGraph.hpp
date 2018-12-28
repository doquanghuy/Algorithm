//
//  SymbolGraph.hpp
//  Demo
//
//  Created by Quang Huy on 12/20/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef SymbolGraph_hpp
#define SymbolGraph_hpp

#include <stdio.h>
#include <string>
#include "LinearProbingHashST.hpp"
class Graph;

class SymbolGraph {
public:
    SymbolGraph(std:: string fileName, std:: string delim);
    bool contain(std:: string key);
    int index(std:: string key);
    std:: string name(int v);
    Graph getGraph();
private:
    LinearProbingHashST st;
    Key* keys;
    Graph* g;
};

#endif /* SymbolGraph_hpp */
