//
//  LSP.cpp
//  Demo
//
//  Created by Quang Huy on 1/5/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#include "LSD.hpp"
#include "Alphabet.hpp"

void LSD:: sort(std:: string* a, int N, int size) {
    int R = Alphabet:: BASE64.R();
    std:: string aux[N];
    
    for (int d = size - 1; d >= 0; d--) {
        int count[64] = {0};
        
        for (int i = 0; i < N; i++) {
            count[Alphabet:: BASE64.toIndex(a[i][d]) + 1]++;
        }
        
        for (int i = 0; i < R; i++) {
            count[i + 1] += count[i];
        }
        
        for (int i = 0; i < N; i++) {
            aux[count[Alphabet:: BASE64.toIndex(a[i][d])]++] = a[i];
        }
        
        for (int i = 0; i < N; i++) {
            a[i] = aux[i];
        }
    }
}
