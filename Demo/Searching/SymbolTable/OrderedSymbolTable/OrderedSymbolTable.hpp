//
//  OrderedSymbolTable.hpp
//  Demo
//
//  Created by Quang Huy on 12/9/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef OrderedSymbolTable_hpp
#define OrderedSymbolTable_hpp

#include <stdio.h>
#include "Iterator.hpp"

template<typename Key, typename Value>
class OrderedSymbolTable {
public:
    OrderedSymbolTable();
    virtual void put(Key key, Value value) = 0;
    virtual Value get(Key key) = 0;
    virtual void remove(Key key) = 0;
    virtual bool contains(Key key) = 0;
    virtual bool isEmpty() = 0;
    virtual int size() = 0;
    virtual Key min() = 0;
    virtual Key max() = 0;
    virtual Key ceiling(Key key) = 0;
    virtual Key floor(Key key) = 0;
    virtual Key select(int k) = 0;
    virtual int rank(Key key) = 0;
    virtual void deleteMin() = 0;
    virtual void deleteMax() = 0;
    virtual int size(Key lo, Key hi) = 0;
    virtual Iterable<Key>* keys(Key lo, Key hi) = 0;
    virtual Iterable<Key>* keys() = 0;
};

template<typename Key, typename Value>
inline OrderedSymbolTable<Key, Value>:: OrderedSymbolTable() {}

#endif /* OrderedSymbolTable_hpp */
