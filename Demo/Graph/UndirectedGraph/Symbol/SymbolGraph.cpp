//
//  SymbolGraph.cpp
//  Demo
//
//  Created by Quang Huy on 12/20/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#include "SymbolGraph.hpp"
#include "FileManager.hpp"
#include "Constant.hpp"
#include "Graph.hpp"

using namespace std;
SymbolGraph:: SymbolGraph(string fileName, string delim) {
    StdIn in(fileName);
    
    while (in.hasNextLine()) {
        string line = in.readLine();
        vector<string> vertices = Constant::split(line, delim);
        for (int i = 0; i < vertices.size(); i++) {
            if (!st.contains({vertices[i]})) {
                this -> st.put(vertices[i], st.size());
            }
        }
    }
    
    this -> keys = new string[st.size()];
    Iterator<string>* iterator = st.keys() -> iterator();
    while (iterator -> hasNext()) {
        string key = iterator -> next();
        keys[st.get(key)] = key;
    }
    
    StdIn in1(fileName);
    g = new Graph(st.size());
    while (in1.hasNextLine()) {
        string line = in1.readLine();
        vector<string> vertices = Constant::split(line, delim);
        string firtVertice = vertices[0];
        vertices.erase(vertices.begin());
        
        while (!vertices.empty()) {
            string nextVertice = vertices[0];
            vertices.erase(vertices.begin());
            g -> addEdge(st.get(firtVertice), st.get(nextVertice));
        }
    }
}

bool SymbolGraph:: contain(string key) {
    return st.contains({key});
}

int SymbolGraph:: index(string key) {
    return st.get(key);
}

string SymbolGraph:: name(int v) {
    return keys[v];
}

Graph SymbolGraph:: getGraph() {
    return *g;
}
