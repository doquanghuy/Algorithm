//
//  BinarySearchST.hpp
//  Demo
//
//  Created by Quang Huy on 12/9/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef BinarySearchST_hpp
#define BinarySearchST_hpp

#include <stdio.h>
#include <vector>
#include "OrderedSymbolTable.hpp"
#include "Queue+LinkedList.hpp"

class BinarySearchST: public OrderedSymbolTable {
public:
     BinarySearchST();
     void put(Key key, Value value);
     Value get(Key key);
     void remove(Key key);
     bool contains(Key key);
     bool isEmpty();
     int size();
     Key min();
     Key max();
     Key ceiling(Key key);
     Key floor(Key key);
     Key select(int k);
     int rank(Key key);
     void deleteMin();
     void deleteMax();
     int size(Key lo, Key hi);
     Iterable<Key>* keys(Key lo, Key hi);
     Iterable<Key>* keys();
private:
    vector<Key> allKeys;
    vector<Value> values;
    int N;
};

BinarySearchST:: BinarySearchST() {
    allKeys = vector<Key>(1);
    values = vector<Value>(1);
}

int BinarySearchST:: rank(Key key){
    int lo = 0;
    int hi = N - 1;
    
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (allKeys[mid] == key) {
            return mid;
        } else if (allKeys[mid] > key) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    
    return lo;
}

void BinarySearchST:: put(Key key, Value value) {
    if (key == Key:: defaultValue) {
        return;
    }
    
    if (value == Value:: defaultValue) {
       return remove(key);
    }
    
    int k = rank(key);
    if (allKeys[k] == key) {
        values[k] = value;
        return;
    }
    
    N++;
    allKeys.insert(allKeys.begin() + k, key);
    values.insert(values.begin() + k, value);
}

Value BinarySearchST:: get(Key key) {
    int k = rank(key);
    if (k < N && allKeys[k] == key) {
        return values[k];
    }
    return Value:: defaultValue;
}

void BinarySearchST:: remove(Key key) {
    int k = rank(key);
    if (k < N && allKeys[k] != key) {
        return;
    }
    
    allKeys.erase(allKeys.begin() + k);
    values.erase(values.begin() + k);
    N--;
}

bool BinarySearchST:: contains(Key key) {
    int k = rank(key);
    return k < N && allKeys[k] == key;
}

bool BinarySearchST:: isEmpty() {
    return N == 0;
}

int BinarySearchST:: size() {
    return N;
}

Key BinarySearchST:: min() {
    return allKeys[0];
}

Key BinarySearchST:: max(){
    return allKeys[N - 1];
}

Key BinarySearchST:: ceiling(Key key) {
    int k = rank(key);
    if (k == N) {
        return Key:: defaultValue;
    }
    return allKeys[rank(key)];
}

Key BinarySearchST:: floor(Key key) {
    int k = rank(key);// allKeys[k] is always bigger than or equal to key;
    if (allKeys[k] == key) {
        return key;
    }
    if (k > 0 && k <= N) {
        return allKeys[k - 1];
    }
    return Key:: defaultValue;
}

Key BinarySearchST:: select(int k) {
    if (k <= 0 || k >= N) {
        return Key:: defaultValue;
    }
    return allKeys[k];
}

void BinarySearchST:: deleteMin() {
    if (N == 0) {
        return;
    }
    allKeys.erase(allKeys.begin());
    values.erase(values.begin());
    N--;
}

void BinarySearchST:: deleteMax() {
    if (N == 0) {
        return;
    }
    allKeys.erase(allKeys.begin() + N - 1);
    values.erase(values.begin() + N - 1);
    N--;
}

int BinarySearchST:: size(Key lo, Key hi) {
    if (hi < lo) {
        return 0;
    }
    int kLo = rank(lo);
    int kHi = rank(hi);
    int size = kHi - kLo;
    
    if (allKeys[kHi] == hi) {
        return size + 1;
    }
    return size;
}

Iterable<Key>* BinarySearchST:: keys(Key lo, Key hi) {
    if (hi < lo) {
        return 0;
    }
    int kLo = rank(lo);
    int kHi = rank(hi);
    
    LinkQueue<Key>* queue = new LinkQueue<Key>;
    for (int i = kLo; i < kHi; i++) {
        queue -> enqueue(allKeys[i]);
    }
    if (contains(hi)) {
        queue -> enqueue(hi);
    }
    return queue;
}

Iterable<Key>* BinarySearchST:: keys() {
    LinkQueue<Key>* queue = new LinkQueue<Key>;
    for (int i = 0; i < N; i++) {
        queue -> enqueue(allKeys[i]);
    }
    return queue;
}

#endif /* BinarySearchST_hpp */
