//
//  MSD.hpp
//  Demo
//
//  Created by Quang Huy on 1/5/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#ifndef MSD_hpp
#define MSD_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "Alphabet.hpp"

class MSD {
public:
    static void sort(std::string* a, int N);
private:
    const static int M = 15;
    static void sort(std:: string* a, std:: string* aux, int lo, int hi, int d);
    static int charAt(std:: string s, int index);
};

#endif /* MSD_hpp */
