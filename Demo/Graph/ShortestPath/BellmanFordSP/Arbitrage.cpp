//
//  Arbitrage.cpp
//  Demo
//
//  Created by Quang Huy on 1/2/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#include <math.h>
#include "Arbitrage.hpp"
#include "FileManager.hpp"
#include "EdgeWeightedDigraph.hpp"
#include "BellmanFordSP.hpp"
#include "DirectedEdge.hpp"

void Arbitrage:: process(StdIn &in) {
    int V = stoi(in.readLine());
    string name[V];
    EdgeWeightedDigraph G(V);
    for (int v = 0; v < V; v++) {
        name[v] = in.readWord();
        for (int w = 0; w < V; w++) {
            double rate = in.readDouble();
            DirectedEdge edge(v, w, -log(rate));
            G.addEdge(edge);
        }
    }
    
    BellmanFordSP bfsp(G, 0);
    if (bfsp.hasNegativeCycle()) {
        double stake = 1000.0;
        Iterator<DirectedEdge>* adj = bfsp.negativeCycle()[0] -> iterator();
        while (adj -> hasNext()) {
            DirectedEdge edge = adj -> next();
            cout << stake << " " << name[edge.from()];
            stake *= exp(-edge.weight());
            cout << "= " << stake << " " << name[edge.to()] << endl;
        }
        cout << endl;
    } else {
        cout << "No arbitrage opportunity" << endl;
    }
}
