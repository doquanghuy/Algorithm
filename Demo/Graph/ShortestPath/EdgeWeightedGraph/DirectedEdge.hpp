//
//  DirectedEdge.hpp
//  Demo
//
//  Created by Quang Huy on 1/2/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#ifndef DirectedEdge_hpp
#define DirectedEdge_hpp

#include <stdio.h>
#include <string>

class DirectedEdge {
public:
    DirectedEdge();
    DirectedEdge(int v, int w, double weight);
    double weight() const;
    int from() const;
    int to() const;
    std::string toString() const;
    const static DirectedEdge defaultEdge;
private:
    int v;
    int w;
    double _weight;
};

int operator==(const DirectedEdge& a, const DirectedEdge& b);
int operator!=(const DirectedEdge& a, const DirectedEdge& b);

#endif /* DirectedEdge_hpp */
