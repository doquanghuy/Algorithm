//
//  Alphabet.cpp
//  Demo
//
//  Created by Quang Huy on 1/5/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#include "Alphabet.hpp"

const int Alphabet:: _R = 64;

const std::string Alphabet:: chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

const Alphabet Alphabet:: BASE64 = Alphabet(Alphabet:: chars);

Alphabet:: Alphabet(std:: string s) {
    this -> s = s;
}

char Alphabet:: toChar(int index) const {
    for (int i = 0; i < _R; i++) {
        if (i == index) {
            return s[i];
        }
    }
    return '0';
}

int Alphabet:: toIndex(char c) const {
    for (int i = 0; i < _R; i++) {
        if (s[i] == c) {
            return i;
        }
    }
    return -1;
}

bool Alphabet:: contains(char c) const {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == c) {
            return true;
        }
    }
    return false;
}

const int Alphabet:: R() const {
    return _R;
}

const int Alphabet:: lgR() const {
    return 6;
}

int* Alphabet:: toIndices(std:: string s) const {
    int* indices = new int[s.length()];
    for (int i = 0; i < s.length(); i++) {
        indices[i] = toIndex(s[i]);
    }
    return indices;
}

std:: string Alphabet:: toChars(int* indices, int N) const {
    char c[N + 1];
    for (int i = 0; i < N; i++) {
        c[i] = toChar(indices[i]);
    }
    c[N] = '\0';
    return std:: string(c);
}
