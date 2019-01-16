//
//  DFOrder.hpp
//  Demo
//
//  Created by Quang Huy on 12/24/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef DFOrder_hpp
#define DFOrder_hpp

#include <stdio.h>
#include "Queue+LinkedList.hpp"
#include "Stack+LinkedList.hpp"
#include "Iterator.hpp"

class Digraph;

class DFOrder {
public:
    DFOrder(Digraph g);
    const Iterable<int>* pre();
    const Iterable<int>* post();
    const Iterable<int>* reversePost();
private:
    void dfs(Digraph g, int s);
    LinkQueue<int> preQueue;
    LinkQueue<int> postQueue;
    LinkStack<int> reversePostStack;
    bool* markedVertices;
};
#endif /* DFOrder_hpp */
