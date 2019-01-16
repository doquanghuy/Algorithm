
//
//  ABFSubString.cpp
//  Demo
//
//  Created by Quang Huy on 1/11/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#include "ABFSubString.hpp"

ABFSubString:: ABFSubString(std:: string pat) {
    this -> pat = pat;
}

unsigned long ABFSubString:: search(std:: string txt) {
    unsigned long M = pat.length();
    unsigned long N = txt.length();
    
    for (int i = 0, j = 0; i < N && j < M; i++) {
        if (pat[j] == txt[i]) {
            j++;
            if (j == M) {
                return i - j + 1;
            }
        } else {
            i -= j;
            j = 0;
        }
    }
    return N;
}
