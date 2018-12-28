//
//  LinearProbingHashST.hpp
//  Demo
//
//  Created by Quang Huy on 12/15/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef LinearProbingHashST_hpp
#define LinearProbingHashST_hpp

#include <stdio.h>
#include <algorithm>
#include <vector>
#include "Iterator.hpp"
#include "Queue+LinkedList.hpp"
#include "DataType.hpp"

class LinearProbingHashST {
public:
    LinearProbingHashST();
    LinearProbingHashST(int M);
    Value get(Key key);
    void put(Key key, Value value);
    void remove(Key key);
    bool contains(Key key);
    int size();
    Iterable<Key>* keys();
private:
    int N;
    int M;
    std:: vector<Key> allKeys;
    std:: vector<Value> values;
    int hash(Key key);
    void resize(int M);
    const static int initM = 4;
};

inline LinearProbingHashST:: LinearProbingHashST() {
    this -> N = 0;
    this -> M =  LinearProbingHashST:: initM;
    allKeys = std:: vector<Key>(M, Key:: defaultValue);
    values = std:: vector<Value>(M, Value:: defaultValue);
}

inline LinearProbingHashST:: LinearProbingHashST(int M) {
    this -> N = 0;
    this -> M = M;
    allKeys = std:: vector<Key>(M, Key:: defaultValue);
    values = std:: vector<Value>(M, Value:: defaultValue);
}

inline int LinearProbingHashST:: hash(Key key) {
    return (key.hash() & 0x7fffffff) % M;
}

inline bool LinearProbingHashST:: contains(Key key) {
    if (key == Key:: defaultValue) {
        return false;
    }
    
    for (int i = hash(key); allKeys[i] != Key:: defaultValue; i = (i + 1) % M) {
        if (allKeys[i] == key) {
            return true;
        }
    }
    return false;
}

inline int LinearProbingHashST:: size() {
    return N;
}

inline void LinearProbingHashST:: resize(int M) {
    LinearProbingHashST temp(M);
    for (int i = 0; i < this -> M; i++) {
        temp.put(allKeys[i], values[i]);
    }
    
    this -> M = M;
    this -> values = temp.values;
    this -> allKeys = temp.allKeys;
}

inline Value LinearProbingHashST:: get(Key key) {
    if (key == Key:: defaultValue) {
        return Value:: defaultValue;
    }
    
    for (int i = hash(key); allKeys[i] != Key:: defaultValue; i = (i + 1) % M) {
        if (allKeys[i] == key) {
            return values[i];
        }
    }
    return Value:: defaultValue;
}

inline void LinearProbingHashST:: put(Key key, Value value) {
    if (key == Key:: defaultValue) {
        return;
    }
    
    if (value == Value:: defaultValue) {
        remove(key);
    }
    
    int hashKey = hash(key);
    int i;
    for (i = hashKey; allKeys[i] != Key:: defaultValue; i = (i + 1) % M) {
        if (allKeys[i] == key) {
            values[i] = value;
            return;
        }
    }
    allKeys[i] = key;
    values[i] = value;

    N++;
    if (N == M / 2) {
        resize(M * 2);
    }
}

inline void LinearProbingHashST:: remove(Key key) {
    if (key == Key:: defaultValue) {
        return;
    }
    
    int hashKey = hash(key);
    if (allKeys[hashKey] == Key:: defaultValue) {
        return;
    }
    
    for (int i = hashKey; allKeys[i] != Key:: defaultValue; i = (i + 1) % M) {
        if (allKeys[i] == key) {
            allKeys[i] = Key:: defaultValue;
            values[i] = Value:: defaultValue;
        }
    }
    
    for (int i = hashKey + 1; allKeys[i] != Key:: defaultValue; i = (i + 1) % M) {
        Key k = allKeys[i];
        Value v = values[i];
        allKeys[i] = Key:: defaultValue;
        values[i] = Value:: defaultValue;
        N--;
        
        put(k, v);
    }
    
    N--;
    if (N >= LinearProbingHashST:: initM && N == M / 8) {
        resize(M / 2);
    }
}

inline Iterable<Key>* LinearProbingHashST:: keys() {
    LinkQueue<Key>* queue = new LinkQueue<Key>;
    for (int i = 0; i < M; i++) {
        if (allKeys[i] != Key:: defaultValue) {
            queue -> enqueue(allKeys[i]);
        }
    }
    return queue;
}

#endif /* LinearProbingHashST_hpp */
