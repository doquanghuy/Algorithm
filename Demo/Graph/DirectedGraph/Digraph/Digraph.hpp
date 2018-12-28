//
//  Digraph.hpp
//  Demo
//
//  Created by Quang Huy on 12/22/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef Digraph_hpp
#define Digraph_hpp

#include <stdio.h>
#include "Bag+LinkedList.hpp"
#include "Iterator.hpp"
class StdIn;
class StdIn;

class Digraph {
public:
    Digraph(int V);
    Digraph(StdIn& in);
    int V();
    int E();
    void addEdge(int v, int w);
    const Iterable<int>* adjacent(int v);
    Digraph reverse();
    std:: string toString();
private:
    int v;
    int e;
    LinkBag<int>* adj;
};

#endif /* Digraph_hpp */
