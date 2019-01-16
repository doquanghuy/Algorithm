//
//  Alphabet.hpp
//  Demo
//
//  Created by Quang Huy on 1/5/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#ifndef Alphabet_hpp
#define Alphabet_hpp

#include <stdio.h>
#include <string>

class Alphabet {
public:
    Alphabet(std::string s);
    char toChar(int index) const;
    int toIndex(char c) const;
    bool contains(char c) const;
    const int R() const;
    const int lgR() const;
    int* toIndices(std:: string s) const;
    std:: string toChars(int* indices, int N) const;
    static const Alphabet BASE64;
private:
    std:: string s;
    const static int _R;
    const static std:: string chars;
};

#endif /* Alphabet_hpp */
