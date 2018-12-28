//
//  DataType.cpp
//  Demo
//
//  Created by Quang Huy on 12/9/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#include "DataType.hpp"

using namespace std;

Key Key:: defaultValue = {""};

int Key:: hash() {
    return 0;
}

int operator<(const Key& a, const Key& b) {
    return a.data < b.data;
}

int operator>(const Key& a, const Key& b) {
    return a.data > b.data;
}

int operator<=(const Key& a, const Key& b) {
    return a.data <= b.data;
}

int operator>=(const Key& a, const Key& b) {
    return a.data >= b.data;
}

int operator==(const Key& a, const Key& b) {
    return a.data == b.data;
}

int operator!=(const Key& a, const Key& b) {
    return a.data != b.data;
}

Key Key:: min(const Key& a, const Key& b) {
    return a.data < b.data ? a : b;
}

Key Key:: max(const Key& a, const Key& b) {
    return a.data < b.data ? b : a;
}

std:: ostream& operator<<(std:: ostream& os, const Key& item) {
    os << item.data;
    return os;
}

Value Value:: defaultValue = {-1};

int operator<(const Value& a, const Value& b) {
    return a.data < b.data;
}

int operator>(const Value& a, const Value& b) {
    return a.data > b.data;
}

int operator<=(const Value& a, const Value& b) {
    return a.data <= b.data;
}

int operator>=(const Value& a, const Value& b) {
    return a.data >= b.data;
}

int operator==(const Value& a, const Value& b) {
    return a.data == b.data;
}

int operator!=(const Value& a, const Value& b) {
    return a.data != b.data;
}

Value Value:: min(const Value& a, const Value& b) {
    return a.data < b.data ? a : b;
}

Value Value:: max(const Value& a, const Value& b) {
    return a.data < b.data ? b : a;
}

std:: ostream& operator<<(std:: ostream& os, const Value& item) {
    os << to_string(item.data);
    return os;
}
