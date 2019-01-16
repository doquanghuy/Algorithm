//
//  Regrex.cpp
//  Demo
//
//  Created by Quang Huy on 1/14/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#include "Operator.hpp"

Operator:: Operator() {
    
}

Operator:: Operator(int index, char c) {
    this -> i = index;
    this -> c = c;
}

int Operator:: index() {
    return i;
}
char Operator:: value() {
    return c;
}

