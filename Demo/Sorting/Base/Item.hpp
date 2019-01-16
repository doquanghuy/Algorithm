//
//  Item.hpp
//  Demo
//
//  Created by Quang Huy on 12/3/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef Item_hpp
#define Item_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "Edge.hpp"

struct Item {
    int i;
    static Item defaultValue;
};
int operator<(const Item&, const Item&);
int operator>(const Item&, const Item&);
int operator==(const Item&, const Item&);
std:: ostream& operator<<(std:: ostream& os, const Item& item);

#endif /* Item_hpp */
