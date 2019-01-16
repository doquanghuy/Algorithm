//
//  BFSubString.hpp
//  Demo
//
//  Created by Quang Huy on 1/11/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#ifndef BFSubString_hpp
#define BFSubString_hpp

#include <stdio.h>
#include <string>

class BFSubString {
public:
    BFSubString(std:: string pat);
    unsigned long search(std:: string txt);
private:
    std:: string pat;
};

#endif /* BFSubString_hpp */
