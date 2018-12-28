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
                this -> st.put({vertices[i]}, {st.size()});
            }
        }
    }
    
    this -> keys = new Key[st.size()];
    Iterator<Key>* iterator = st.keys() -> iterator();
    while (iterator -> hasNext()) {
        Key key = iterator -> next();
        keys[st.get(key).data] = key;
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
            g -> addEdge(st.get({firtVertice}).data, st.get({nextVertice}).data);
        }
    }
}

bool SymbolGraph:: contain(string key) {
    return st.contains({key});
}

int SymbolGraph:: index(string key) {
    return st.get({key}).data;
}

string SymbolGraph:: name(int v) {
    return keys[v].data;
}

Graph SymbolGraph:: getGraph() {
    return *g;
}
