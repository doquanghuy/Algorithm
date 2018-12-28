//
//  DataType.hpp
//  Demo
//
//  Created by Quang Huy on 12/9/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef DataType_hpp
#define DataType_hpp

#include <stdio.h>
#include <string>

struct Key {
    std:: string data;
    static Key defaultValue;
    static Key min(const Key& a, const Key& b);
    static Key max(const Key& a, const Key& b);
    int hash();
};
int operator<(const Key&, const Key&);
int operator>(const Key&, const Key&);
int operator<=(const Key&, const Key&);
int operator>=(const Key&, const Key&);
int operator==(const Key&, const Key&);
int operator!=(const Key&, const Key&);
std:: ostream& operator<<(std:: ostream& os, const Key& item);

struct Value {
    int data;
    static Value defaultValue;
    static Value min(const Value& a, const Value& b);
    static Value max(const Value& a, const Value& b);
};
int operator<(const Value&, const Value&);
int operator>(const Value&, const Value&);
int operator<=(const Value&, const Value&);
int operator>=(const Value&, const Value&);
int operator==(const Value&, const Value&);
int operator!=(const Value&, const Value&);
std:: ostream& operator<<(std:: ostream& os, const Value& item);
#endif /* DataType_hpp */
