//
//  KMPSubString.hpp
//  Demo
//
//  Created by Quang Huy on 1/11/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#ifndef KMPSubString_hpp
#define KMPSubString_hpp

#include <stdio.h>
#include <string>

class KMPSubString {
public:
    KMPSubString(std:: string pat);
    unsigned long search(std:: string txt);
    ~KMPSubString();
private:
    std:: string pat;
    int (*dfa)[100]; // must have ();
};

#endif /* KMPSubString_hpp */
