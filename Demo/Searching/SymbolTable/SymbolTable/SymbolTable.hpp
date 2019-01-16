//
//  SymbolTable.hpp
//  Demo
//
//  Created by Quang Huy on 12/9/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef SymbolTable_hpp
#define SymbolTable_hpp

#include <stdio.h>
#include "Iterator.hpp"

template<typename Key, typename Value>
class SymbolTable {
public:
    SymbolTable();
    virtual Value get(Key key) = 0;
    virtual void put(Key key, Value value) = 0;
    virtual void remove(Key key) = 0;
    virtual bool contains(Key key) = 0;
    virtual bool isEmpty() = 0;
    virtual int size() = 0;
    virtual Iterable<Key>* keys() = 0;
};

template<typename Key, typename Value>
inline SymbolTable<Key, Value>:: SymbolTable() {}
#endif /* SymbolTable_hpp */
