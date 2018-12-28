//
//  EdgeWeightedGraph.hpp
//  Demo
//
//  Created by Quang Huy on 12/25/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef EdgeWeightedGraph_hpp
#define EdgeWeightedGraph_hpp

#include <stdio.h>
#include "Bag+LinkedList.hpp"
#include "FileManager.hpp"
class Edge;

class EdgeWeightedGraph {
public:
    EdgeWeightedGraph(int v);
    EdgeWeightedGraph(StdIn& in);
    int V();
    int E();
    void addEdge(Edge e);
    const Iterable<Edge>* adj(int v);
    const Iterable<Edge>* edges();
private:
    LinkBag<Edge>* _adj;
    int _v;
    int _e;
};

#endif /* EdgeWeightedGraph_hpp */
