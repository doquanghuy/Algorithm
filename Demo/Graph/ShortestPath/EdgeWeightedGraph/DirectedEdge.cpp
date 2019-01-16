
//
//  DirectedEdge.cpp
//  Demo
//
//  Created by Quang Huy on 1/2/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#include "DirectedEdge.hpp"

const DirectedEdge DirectedEdge:: defaultEdge = DirectedEdge(0, 0, 0.0);

int operator==(const DirectedEdge& a, const DirectedEdge& b) {
    return a.from() == b.from() && a.to() == b.to() && a.weight() == b.weight();
}

int operator!=(const DirectedEdge& a, const DirectedEdge& b) {
    return a.from() != b.from() || a.to() != b.to() || a.weight() != b.weight();
}

DirectedEdge:: DirectedEdge() {
    this -> v = 0;
    this -> w = 0;
    this -> _weight = 0.0;
}

DirectedEdge:: DirectedEdge(int v, int w, double weight) {
    this -> v = v;
    this -> w = w;
    this -> _weight = weight;
}

double DirectedEdge:: weight() const {
    return _weight;
}

int DirectedEdge:: from() const {
    return v;
}

int DirectedEdge:: to() const {
    return w;
}

std::string DirectedEdge:: toString() const {
    return std::to_string(v) + " --- " + std::to_string(w) + ": " + std::to_string(_weight);
}
