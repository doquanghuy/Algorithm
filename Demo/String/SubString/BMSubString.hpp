//
//  BMSubString.hpp
//  Demo
//
//  Created by Quang Huy on 1/11/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#ifndef BMSubString_hpp
#define BMSubString_hpp

#include <stdio.h>
#include <string>

class BMSubString {
public:
    BMSubString(std:: string pat);
    unsigned long search(std:: string txt);
    ~BMSubString();
private:
    int* right;
    std:: string pat;
};
#endif /* BMSubString_hpp */
