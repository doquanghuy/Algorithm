//
//  QuickSortString.hpp
//  Demo
//
//  Created by Quang Huy on 1/5/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#ifndef QuickSortString_hpp
#define QuickSortString_hpp

#include <stdio.h>
#include <string>

class QuickSortString {
public:
    static void sort(std:: string* a, int N);
private:
    static void sort(std:: string* a, int lo, int hi, int d);
    static int chartAt(std:: string s, int index);
    static void exchange(std:: string* a, int i, int j);
};

#endif /* QuickSortString_hpp */
