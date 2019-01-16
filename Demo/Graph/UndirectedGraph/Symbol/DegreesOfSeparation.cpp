//
//  DegreesOfSeparation.cpp
//  Demo
//
//  Created by Quang Huy on 12/20/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#include "DegreesOfSeparation.hpp"
#include "SymbolGraph.hpp"
#include "Graph.hpp"
#include "BFP.hpp"

using namespace std;
string DegreesOfSeparation:: paths(string fileName, string delim, string source, string des) {
    SymbolGraph sg(fileName, delim);
    Graph g = sg.getGraph();
    if (!sg.contain({source})) {
        return "Source is not existent";
    }
    int s = sg.index(source);
    int d = sg.index(des);
    BFP bfp(g, s);
    
    if (!bfp.hasPathTo(d)) {
        return "Not connected";
    }
    Iterator<int>* paths = bfp.pathTo(d) -> iterator();
    string res;
    while (paths ->hasNext()) {
        res += " " + sg.name(paths -> next());
    }
    return res;
}
