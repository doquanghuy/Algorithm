
//
//  NFA.cpp
//  Demo
//
//  Created by Quang Huy on 1/14/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#include "NFA.hpp"
#include "Stack+LinkedList.hpp"
#include "Queue+LinkedList.hpp"
#include "Bag+LinkedList.hpp"
#include "Operator.hpp"
#include "Expression.hpp"
#include "Alphabet.hpp"
#include "Constant.hpp"
#include "DirectedDFS.hpp"

NFA:: NFA(std:: string regex): G(Digraph(int(regex.length()) + 1)) {
    this -> regex = processRegex(regex);
    this -> buildGraph(this -> regex);
}

bool NFA:: recognizes(std:: string txt) {
    std:: cout << txt << std:: endl;
    std:: cout << G.toString() << std:: endl;
    LinkBag<int> et;
    DirectedDFS dfs(G, 0);
    for (int i = 0; i < G.V(); i++) {
        if (dfs.marked(i)) {
            et.add(i);
        }
    }
    
    for (int i = 0; i < txt.length(); i++) {
        LinkBag<int> match;
        Iterator<int>* iterator = et.iterator();
        while (iterator -> hasNext()) {
            int v = iterator -> next();
            if (v < regex.length() && ((regex[v] == txt[i] || (regex[v] == '.' && regex[v - 1] != '\\')))) {
                match.add(v + 1);
            }
        }
        
        et = LinkBag<int>();
        dfs = DirectedDFS(G, &match);
        for (int i = 0; i < G.V(); i++) {
            if (dfs.marked(i)) {
                et.add(i);
            }
        }
    }
    
    Iterator<int>* iterator = et.iterator();
    while (iterator -> hasNext()) {
        if (iterator -> next() == regex.length()) {
            return true;
        }
    }
    return false;
}

void NFA:: buildGraph(std:: string normalizedString) {
    std:: cout << normalizedString << std:: endl;

    LinkStack<Operator> parenthese;
    LinkQueue<Operator> verticalBar;
    G = Digraph(int(normalizedString.length()) + 1);
    int lp;
    
    for (int i = 0; i < normalizedString.length(); i++) {
        lp = i;
        char c = normalizedString[i];
        if (c == '(' && normalizedString[i - 1] != '\\') {
            parenthese.push(Operator(i, c));
        } else if (c == ')' && normalizedString[i - 1] != '\\') {
            Operator par = parenthese.pop();
            lp = par.index();
            while (!verticalBar.isEmpty()) {
                Operator sqb = verticalBar.dequeue();
                G.addEdge(lp, sqb.index() + 1);
                G.addEdge(sqb.index(), i);
            }
        } else if (c == '|') {
            verticalBar.enqueue(Operator(i, c));
        }
        if (i < normalizedString.length() - 1 && normalizedString[i + 1] == '*') {
            G.addEdge(lp, i + 1);
            G.addEdge(i + 1, lp);
        }
        if (c == '(' || c == ')' || c == '*') {
            G.addEdge(i, i + 1);
        }
    }
}

std:: string NFA:: processRegex(std:: string regex) {
    std:: string temp = regex;
    LinkStack<Operator> stack;
    Expression lastParenthesesExp;
    
    for (int i = 0; i < temp.length(); i++) {
        char c = temp[i];
        if ((c == '(' && temp[i - 1] != '\\') || c == '[' || c == '{') {
            stack.push(Operator(i, c));
        } else if (c == ')' && temp[i - 1] != '\\') {
            Operator op = stack.pop();
            int index = op.index();
            char arr[i - index + 2];
            for (int k = index; k <= i; k++) {
                arr[k - index] = temp[k];
            }
            arr[i - index + 1] = 0;
            lastParenthesesExp = Expression(temp, arr, index, i);
        } else if (c == ']') {
            Operator op = stack.pop();
            int index = op.index();
            std:: string s = squareBracketChars(temp, index, i);
            lastParenthesesExp = squareBracket(s, temp, index, i);
            temp = replace(lastParenthesesExp);
            return processRegex(temp);
        } else if (c == '}') {
            Operator op = stack.pop();
            int index = op.index();
            Range range = angleBracketChars(temp, index, i);
            lastParenthesesExp = angleBracket(range, lastParenthesesExp.exp(), temp, lastParenthesesExp.from(), i);
            temp = replace(lastParenthesesExp);
            return processRegex(temp);
        } else if (c == '+') {
            Expression exp;
            if (temp[i - 1] == ')') {
                exp = plusMark(lastParenthesesExp.exp(), temp, lastParenthesesExp.from(), i);
            } else {
                exp = plusMark(std:: string({temp[i - 1]}), temp, i - 1, i);
            }
            temp = replace(exp);
            return processRegex(temp);
        }
    }
    return temp;
}

std:: string NFA:: squareBracketChars(std:: string regex, int from, int to) {
    char chars[Alphabet::BASE64.R()];
    SquareBracketTypes type = Set;
    
    for (int i = from + 1; i <= to - 1; i++) {
        if (regex[i] == '-') {
            type = SquareRange;
        } else if (regex[i] == '^' && type != Set) {
            type = RangeAndComplement;
        } else if (regex[i] == '^' && type == Set) {
            type = Complement;
        }
    }
    
    int count = 0;
    
    if (type == SquareRange) {
        for (int i = Alphabet:: BASE64.toIndex(regex[from + 1]); i <= Alphabet:: BASE64.toIndex(regex[to - 1]); i++) {
            chars[i - Alphabet:: BASE64.toIndex(regex[from + 1])] = Alphabet:: BASE64.toChar(i);
            count++;
        }
    } else if (type == RangeAndComplement) {
        int k = 0;
        for (int i = 0; i < Alphabet:: BASE64.R(); i++) {
            if (Alphabet:: BASE64.toIndex(regex[i + 2] > i || i > Alphabet:: BASE64.toChar(regex[i + 4]))) {
                chars[k++] = Alphabet:: BASE64.toChar(i);
                count++;
            }
        }
    } else if (type == Complement) {
        int k = 0;
        for (int i = 0; i < Alphabet:: BASE64.R(); i++) {
            bool notMatch = true;
            for (int j = from + 1; j <= to - 1; j++) {
                if (Alphabet:: BASE64.toIndex(regex[j]) == i) {
                    notMatch = false;
                }
            }
            if (notMatch) {
                chars[k++] = Alphabet:: BASE64.toChar(i);
                count++;
            }
        }
    } else {
        for (int i = from + 1; i <= to - 1; i++) {
            chars[i - from - 1] = regex[i];
            count++;
        }
    }
    
    chars[count] = 0;
    return chars;
}

Range NFA:: angleBracketChars(std:: string regex, int from, int to) {
    char chars[to - from];
    for (int i = from + 1; i <= to - 1; i++) {
        chars[i - from - 1] = regex[i];
    }
    chars[to - from - 1] = 0;
    
    std:: vector<std:: string> v = Constant:: split(chars, "-");
    if (v.size() == 1) {
        int s = std:: stoi(v.front());
        return Range(s, s);
    } else {
        int s = std:: stoi(v.front());
        int e = std:: stoi(v.back());
        return Range(s, e);
    }
}

Expression NFA:: squareBracket(std:: string sub, std:: string regex, int from, int to) {
    std:: string s = "(";
    for (int i = 0; i < sub.length(); i++) {
        if (i == sub.length() - 1) {
            s += std:: string({sub[i]});
        } else {
            s += std:: string({sub[i], '|'});
        }
    }
    s += ")";
    return Expression(regex, s, from, to);
}

Expression NFA:: angleBracket(Range range, std:: string sub, std:: string regex, int from, int to) {
    std:: string s = "(";
    for (int i = range.from(); i <= range.end(); i++) {
        for (int j = 0; j < i; j++) {
            s += sub;
        }
        if (i < range.end()) {
            s += "|";
        }
    }
    s += ")";
    
    return Expression(regex, s, from, to);
}

Expression NFA:: plusMark(std:: string a, std:: string regex, int from, int to) {
    std:: string s = a;
    s = s + s + "*";
    return Expression(regex, s, from, to);
}

std:: string NFA:: replace(Expression exp) {
    char heads[exp.from() + 1];
    char tails[exp.par().length() - exp.to()];

    for (int i = 0; i < exp.par().length(); i++) {
        if (i < exp.from()) {
            heads[i] = exp.par()[i];
        } else if (i > exp.to()) {
            tails[i - exp.to() - 1] = exp.par()[i];
        }
    }
    
    heads[exp.from()] = 0;
    tails[exp.par().length() - exp.to() - 1] = 0;
    
    std:: string s = std:: string(heads);
    for (int i = 0; i < int(exp.exp().length()); i++) {
        s += exp.exp()[i];
    }
    
    s += tails;
    return s;
}
