//
//  BFSubString.cpp
//  Demo
//
//  Created by Quang Huy on 1/11/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#include "BFSubString.hpp"

BFSubString:: BFSubString(std:: string pat) {
    this -> pat = pat;
}

unsigned long BFSubString:: search(std:: string txt) {
    unsigned long M = pat.length();
    unsigned long N = txt.length();
    
    for (int i = 0; i < N - M; i++) {
        for (int j = 0; j < M; j++) {
            if (pat[j] != txt[i + j]) {
                break;
            } else if (j == M - 1) {
                return i;
            }
        }
    }
    return N;
}
