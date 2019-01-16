//
//  Regrex.hpp
//  Demo
//
//  Created by Quang Huy on 1/14/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#ifndef Operator_hpp
#define Operator_hpp

#include <stdio.h>

class Operator {
public:
    Operator();
    Operator(int index, char c);
    int index();
    char value();
private:
    int i;
    char c;
};

#endif /* Operator_hpp */
