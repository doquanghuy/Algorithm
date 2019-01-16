//
//  QuickSortString.cpp
//  Demo
//
//  Created by Quang Huy on 1/5/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#include "QuickSortString.hpp"
#include "Alphabet.hpp"

void QuickSortString:: sort(std:: string* a, int N) {
    sort(a, 0, N - 1, 0);
}

void QuickSortString:: sort(std:: string* a, int lo, int hi, int d) {
    if (lo >= hi) {
        return;
    }

    int i = lo;
    int j = hi;
    int v = lo + 1;
    while (v <= j) {
        int cI = chartAt(a[i], d); // though i always changes but cI is always equal to cLo;
        int cV = chartAt(a[v], d);
        if (cI > cV) {
            exchange(a, i++, v++);
        } else if (cV > cI) {
            exchange(a, v, j--);
        } else {
            v++;
        }
    }
    
    sort(a, lo, i - 1, d);
    if (chartAt(a[lo], d) >= 0) {
        sort(a, i, j, d + 1);
    }
    sort(a, v, hi, d);
}

int QuickSortString:: chartAt(std:: string s, int index) {
    if (index < s.length()) {
        return Alphabet:: BASE64.toIndex(s[index]);
    }
    return -1;
}

void QuickSortString:: exchange(std:: string* a, int i, int j) {
    std:: string temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
