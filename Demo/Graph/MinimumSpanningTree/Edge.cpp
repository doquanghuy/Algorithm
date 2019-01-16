
//
//  Edge.cpp
//  Demo
//
//  Created by Quang Huy on 12/25/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#include "Edge.hpp"

Edge:: Edge() {}

Edge:: Edge(int v, int w, double weight) {
    this -> v = v;
    this -> w = w;
    this -> _weight = weight;
}

double Edge:: weight() const {
    return _weight;
}

int Edge:: either() const {
    return v;
}

int Edge:: other(int v) const {
    return this -> v == v ? w : this -> v;
}

std:: string Edge:: toString() const {
    return std::to_string(v) + " --- " + std::to_string(w) + ": " + std::to_string(_weight);
}

int operator<(const Edge& a, const Edge& b) {
    return a.weight() < b.weight();
}
int operator>(const Edge& a, const Edge& b) {
    return a.weight() > b.weight();
}

int operator<=(const Edge& a, const Edge& b) {
    return a.weight() <= b.weight();
}

int operator>=(const Edge& a, const Edge& b) {
    return a.weight() >= b.weight();
}

int operator==(const Edge& a, const Edge& b) {
    return a.weight() == b.weight();
}

int operator!=(const Edge& a, const Edge& b) {
    return a.weight() != b.weight();
}
