//
//  Expression.hpp
//  Demo
//
//  Created by Quang Huy on 1/14/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#ifndef Expression_hpp
#define Expression_hpp

#include <stdio.h>
#include <string>

class Expression {
public:
    Expression();
    Expression(std:: string p, std:: string s, int from, int to);
    int from();
    int to();
    std:: string exp();
    std:: string par();
private:
    int _from;
    int _to;
    std:: string _exp;
    std:: string _par;
};

class Range {
public:
    Range();
    Range(int from, int end);
    int from();
    int end();
    int isSingle();
private:
    int _from;
    int _end;
};

#endif /* Expression_hpp */
