//
//  EvaluateExpression.cpp
//  Demo
//
//  Created by Quang Huy on 11/26/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#include <iostream>
#include "EvaluateExpression.hpp"
#include "Stack.hpp"
#include "Constant.hpp"

EvaluateExpression:: EvaluateExpression(std:: string expression) {
    this -> expression = expression;
}

double EvaluateExpression:: evaluate() {
    Stack<char> ops;
    Stack<double> vals;
    
    Array<char> numberChars;
    
    char currentChar;
    char nextChar;
    char chars[11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};
    Array<char> arrNumberChars(chars, 11);
    
    for (int i = 0; i < expression.length(); i++) {
        currentChar = expression[i];
        nextChar = i < expression.length() - 1 ? expression[i + 1] : '\0';
        bool isCurrentCharANumber = arrNumberChars.contains(currentChar);
        bool isNextCharANumber = arrNumberChars.contains(nextChar);

        if (isCurrentCharANumber && isNextCharANumber) {
            numberChars.append(currentChar);
        } else if (isCurrentCharANumber && !isNextCharANumber) {
            numberChars.append(currentChar);
            vals.push(convertFrom(numberChars));
            numberChars.makeEmpty();
        } else if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/') {
            ops.push(currentChar);
        } else if (currentChar == ')') {
            char op = ops.pop();
            double secondNum = vals.pop();
            double firstNum = vals.pop();
            
            if (op == '+') {
                firstNum += secondNum;
            } else if (op == '-') {
                firstNum -= secondNum;
            } else if (op == '*') {
                firstNum *= secondNum;
            } else if (op == '/') {
                firstNum /= secondNum;
            }

            vals.push(firstNum);
        }
    }
    
    return vals.pop();
}

double EvaluateExpression:: convertFrom(Array<char> chars) {
    int size = chars.size();
    char numberChars[size + 1];
    for (int i = 0; i < size; i++) {
        numberChars[i] = chars.itemAtIdex(i);
    }
    numberChars[size] = '\0';
    try {
        return std:: stod(std:: string(numberChars));
    } catch(const char* error) {
        std:: cout << error << std:: endl;
        return 0.0;
    }
}
