//
//  Graph.hpp
//  Demo
//
//  Created by Quang Huy on 12/18/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <string>
#include "Iterator.hpp"
#include "Bag+LinkedList.hpp"

class StdIn;

class Graph {
public:
    Graph(int v);
    Graph(StdIn& in);
    int vertices();
    int edges();
    void addEdge(int v, int w);
    Iterable<int>* adjacent(int v);
    std:: string toString();
private:
    int v;
    int e;
    LinkBag<int>* adj;
};

#endif /* Graph_hpp */
