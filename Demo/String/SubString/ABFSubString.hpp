//
//  ABFSubString.hpp
//  Demo
//
//  Created by Quang Huy on 1/11/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#ifndef ABFSubString_hpp
#define ABFSubString_hpp

#include <stdio.h>
#include <string>

class ABFSubString {
public:
    ABFSubString(std:: string pat);
    unsigned long search(std:: string txt);
private:
    std:: string pat;
};

#endif /* ABFSubString_hpp */
