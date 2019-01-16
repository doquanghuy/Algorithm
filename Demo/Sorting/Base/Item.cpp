//
//  Item.cpp
//  Demo
//
//  Created by Quang Huy on 12/3/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#include <iostream>
#include "Item.hpp"

using namespace std;

Item Item:: defaultValue = {-1};

int operator<(const Item& a, const Item& b) {
    return a.i < b.i;
}

int operator>(const Item& a, const Item& b) {
    return a.i > b.i;
}

int operator==(const Item& a, const Item& b) {
    return a.i == b.i;
}

std:: ostream& operator<<(std:: ostream& os, const Item& item) {
    os << item.i;
    return os;
}

