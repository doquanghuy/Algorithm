//
//  DFOrderEDW.hpp
//  Demo
//
//  Created by Quang Huy on 1/2/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#ifndef DFOrderEDW_hpp
#define DFOrderEDW_hpp

#include <stdio.h>
#include "Queue+LinkedList.hpp"
#include "Stack+LinkedList.hpp"
#include "Iterator.hpp"

class EdgeWeightedDigraph;

class DFOrderEDW {
public:
    DFOrderEDW(EdgeWeightedDigraph g);
    const Iterable<int>* pre();
    const Iterable<int>* post();
    const Iterable<int>* reversePost();
private:
    void dfs(EdgeWeightedDigraph g, int s);
    LinkQueue<int> preQueue;
    LinkQueue<int> postQueue;
    LinkStack<int> reversePostStack;
    bool* markedVertices;
};

#endif /* DFOrderEDW_hpp */
