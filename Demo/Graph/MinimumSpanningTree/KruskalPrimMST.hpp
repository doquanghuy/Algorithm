//
//  KruskalPrimMST.hpp
//  Demo
//
//  Created by Quang Huy on 12/25/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef KruskalPrimMST_hpp
#define KruskalPrimMST_hpp

#include <stdio.h>
#include "EdgeWeightedGraph.hpp"
#include "Queue+LinkedList.hpp"

class KruskaPrimMST {
public:
    KruskaPrimMST(EdgeWeightedGraph graph);
    Iterable<Edge>* edges();
    double weight();
private:
    LinkQueue<Edge> mst;
};

#endif /* KruskalPrimMST_hpp */
