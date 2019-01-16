//
//  Expression.cpp
//  Demo
//
//  Created by Quang Huy on 1/14/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#include "Expression.hpp"

Expression:: Expression() {
    
}

Expression:: Expression(std:: string p, std:: string s, int from, int to) {
    this -> _exp = s;
    this -> _from = from;
    this -> _to = to;
    this -> _par = p;
}

int Expression:: from() {
    return _from;
}

int Expression:: to() {
    return _to;
}

std:: string Expression:: exp() {
    return _exp;
}

std:: string Expression:: par() {
    return _par;
}


Range:: Range() {
    
}

Range:: Range(int from, int end) {
    this -> _from = from;
    this -> _end = end;
}

int Range:: from() {
    return _from;
}

int Range:: end() {
    return _end;
}

int Range:: isSingle() {
    return _from == _end;
}
