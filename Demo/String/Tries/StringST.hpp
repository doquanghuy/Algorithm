//
//  StringST.hpp
//  Demo
//
//  Created by Quang Huy on 1/6/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#ifndef StringST_hpp
#define StringST_hpp

#include <stdio.h>
#include <string>
#include "Iterator.hpp"

template <typename Value>
class StringST {
public:
    StringST();
    virtual void put(std:: string key, Value val) = 0;
    virtual Value get(std:: string key) = 0;
    virtual void remove(std:: string key) = 0;
    virtual bool contains(std:: string key) = 0;
    virtual bool isEmpty() = 0;
    virtual std:: string longestPrefixOf(std:: string s) = 0;
    virtual Iterable<std:: string>* keysWithPrefix(std:: string s) = 0;
    virtual Iterable<std:: string>* keysThatMatch(std:: string s) = 0;
    virtual int size() = 0;
    virtual Iterable<std:: string>* keys() = 0;
};

template <typename Value>
StringST<Value>:: StringST() {}

#endif /* StringST_hpp */
