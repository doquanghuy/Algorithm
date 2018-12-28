//
//  EvaluateExpression.hpp
//  Demo
//
//  Created by Quang Huy on 11/26/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef EvaluateExpression_hpp
#define EvaluateExpression_hpp

#include <stdio.h>
#include "Stack.hpp"
#include <string>

struct EvaluateResult {
    Stack<double> vals;
    Stack<char> ops;
};

class EvaluateExpression {
public:
    EvaluateExpression(std:: string expression);
    double evaluate();
private:
    std:: string expression;
    double convertFrom(Array<char> chars);
};

#endif /* EvaluateExpression_hpp */
