//
//  Edge.hpp
//  Demo
//
//  Created by Quang Huy on 12/25/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef Edge_hpp
#define Edge_hpp

#include <stdio.h>
#include <string>

class Edge {
public:
    Edge();
    Edge(int v, int w, double weight);
    double weight() const;
    int either() const;
    int other(int v) const;
    std:: string toString() const;
private:
    int v;
    int w;
    double _weight;
};

int operator<(const Edge&, const Edge&);
int operator>(const Edge&, const Edge&);
int operator<=(const Edge&, const Edge&);
int operator>=(const Edge&, const Edge&);
int operator==(const Edge&, const Edge&);
int operator!=(const Edge&, const Edge&);

#endif /* Edge_hpp */
