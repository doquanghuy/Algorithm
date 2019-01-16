//
//  KMPSubString.cpp
//  Demo
//
//  Created by Quang Huy on 1/11/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#include "KMPSubString.hpp"
#include "Alphabet.hpp"

KMPSubString:: KMPSubString(std:: string pat) {
    this -> pat = pat;
    this -> dfa = new int[Alphabet:: BASE64.R()][100](); // max pat has 100 elements, each element is 0;

    int X = 0;
    for (int j = 0 ; j < pat.length(); j++) {
        for (int i = 0; i < Alphabet::BASE64.R(); i++) {
            dfa[i][j] = dfa[i][X];
            dfa[Alphabet:: BASE64.toIndex(pat[j])][j] = j + 1;
        }
        X = dfa[Alphabet:: BASE64.toIndex(pat[j])][X];
    }
}

unsigned long KMPSubString:: search(std:: string txt) {
    int i, j = 0;
    for (i = 0, j = 0; i < txt.length() && j < pat.length(); i++) {
        j = dfa[Alphabet:: BASE64.toIndex(txt[i])][j];
    }
    if (j == pat.length())
        return i - pat.length();
    return txt.length();
}

KMPSubString:: ~KMPSubString() {
    delete[] dfa;
}
