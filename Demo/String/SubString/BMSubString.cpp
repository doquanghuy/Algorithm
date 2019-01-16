//
//  BMSubString.cpp
//  Demo
//
//  Created by Quang Huy on 1/11/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#include "BMSubString.hpp"
#include "Alphabet.hpp"
#include <iostream>

BMSubString:: BMSubString(std:: string pat) {
    this -> pat = pat;
    this -> right = new int[Alphabet:: BASE64.R()];
    for (int i = 0; i < Alphabet:: BASE64.R(); i++) {
        right[i] = -1;
    }
    for (int j = 0; j < pat.length(); j++) {
        right[Alphabet:: BASE64.toIndex(pat[j])] = j;
    }
}

unsigned long BMSubString:: search(std:: string txt) {
    int skip = 0;
    int i, j;
    int N = int(txt.length());
    int M = int(pat.length());
    
    for (i = 0; i <= N - M; i += skip) {
        for (j = M - 1; j >= 0; j--) {
            if (pat[j] != txt[i + j]) {
                skip = j - right[Alphabet:: BASE64.toIndex(txt[i + j])];
                if (skip < 0) {
                    skip = 1;
                }
                break;
            }
            if (j == 0) {
                return i;
            }
        }
    }
    return N;
}
                            
BMSubString:: ~BMSubString() {
    delete[] right;
}
