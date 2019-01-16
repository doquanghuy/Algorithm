//
//  CPM.cpp
//  Demo
//
//  Created by Quang Huy on 1/2/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#include "CPM.hpp"
#include "SequentialSearchST.hpp"
#include "FileManager.hpp"
#include "EdgeWeightedDigraph.hpp"
#include "DirectedEdge.hpp"
#include "Constant.hpp"
#include "AcyclicLP.hpp"

using namespace std;
SymbolTable<int, double>* CPM:: process(StdIn &in) {
    int N = stoi(in.readLine());
    EdgeWeightedDigraph G(2 * N + 2);
    int s = 2 * N;
    int t = 2 * N + 1;
    for (int i = 0; i < N; i++) {
        string line = in.readLine();
        vector<string> parts = Constant:: split(line, " ");
        double duration;
        if (!parts.empty()) {
            duration = stod(parts[0]);
            parts.erase(parts.begin());
            G.addEdge(DirectedEdge(i, i + N, duration));
        }
        
        while (!parts.empty()) {
            int v = stoi(parts.front());
            parts.erase(parts.begin());
            G.addEdge(DirectedEdge(i + N, v, 0.0));
        }
        G.addEdge(DirectedEdge(s, i, 0.0));
        G.addEdge(DirectedEdge(i, t, 0.0));
    }
    
    AcyclicLP alp(G, s);
    SequentialSearchST<int, double>* sb = new SequentialSearchST<int, double>;
    for (int i = 0; i < N; i++) {
        sb -> put(i, alp.distTo(i));
    }
    return sb;
}
