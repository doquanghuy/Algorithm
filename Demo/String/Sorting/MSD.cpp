//
//  MSD.cpp
//  Demo
//
//  Created by Quang Huy on 1/5/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#include "MSD.hpp"
#include "Alphabet.hpp"

void MSD:: sort(std::string* a, int N) {
    std:: string aux[N];
    sort(a, aux, 0, N - 1, 0);
}

void MSD:: sort(std:: string* a, std:: string* aux, int lo, int hi, int d) {
    if (lo >= hi) {
        return;
    }
    
    int count[64 + 2] = {0};
    
    for (int i = lo; i <= hi; i++) {
        count[Alphabet:: BASE64.toIndex(a[i][d]) + 2]++;
    }
    
    for (int i = 0; i < Alphabet:: BASE64.R() + 1; i++) {
        count[i + 1] += count[i];
    }
    
    for (int i = lo; i <= hi; i++) {
        aux[count[Alphabet:: BASE64.toIndex(a[i][d]) + 1]++] = a[i]; // always runs from 0 -> hi - lo, so we must use aux[i - lo] in the following for loop;
    }
    
    for (int i = lo; i <= hi; i++) {
        a[i] = aux[i - lo];
    }
    
    for (int i = 0; i < Alphabet:: BASE64.R(); i++) {
        sort(a, aux, lo + count[i], lo + count[i + 1] - 1, d + 1);
    }
}

int MSD:: charAt(std:: string s, int index) {
    if (index < s.length()) {
        return Alphabet:: BASE64.toIndex(s[index]);
    }
    return -1;
}
