//
//  EdgeWeightedDigraph.hpp
//  Demo
//
//  Created by Quang Huy on 1/2/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#ifndef EdgeWeightedDigraph_hpp
#define EdgeWeightedDigraph_hpp

#include <stdio.h>
#include "Iterator.hpp"
#include "Bag+LinkedList.hpp"

class StdIn;
class DirectedEdge;

class EdgeWeightedDigraph {
public:
    EdgeWeightedDigraph(int V);
    EdgeWeightedDigraph(StdIn& in);
    int V();
    int E();
    void addEdge(DirectedEdge edge);
    const Iterable<DirectedEdge>* adj(int v) const;
    const Iterable<DirectedEdge>* edges() const;
    std::string toString();
private:
    int _V;
    int _E;
    LinkBag<DirectedEdge>* _adj;
};

#endif /* EdgeWeightedDigraph_hpp */
