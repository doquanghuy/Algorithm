//
//  NFA.hpp
//  Demo
//
//  Created by Quang Huy on 1/14/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#ifndef NFA_hpp
#define NFA_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "Digraph.hpp"

class Expression;
class Range;

class NFA {
public:
    NFA(std:: string regex);
    bool recognizes(std:: string txt);
private:
    std:: string regex;
    Digraph G;
    std:: string processRegex(std:: string regex);
    void buildGraph(std:: string normalizedString);
    std:: string squareBracketChars(std:: string regex, int from, int to);
    Range angleBracketChars(std:: string regex, int from, int to);
    Expression squareBracket(std:: string sub, std:: string regex, int from, int to);
    Expression angleBracket(Range range, std:: string sub, std:: string regex, int from, int to);
    Expression plusMark(std:: string a, std:: string regex, int from, int to);
    std:: string replace(Expression exp);
};

enum Operation {
    SquareBrackets, AngleBrackets, Parentheses
};

enum SquareBracketTypes {
    Set, SquareRange, Complement, RangeAndComplement
};

#endif /* NFA_hpp */
