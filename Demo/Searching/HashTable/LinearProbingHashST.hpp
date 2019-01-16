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

template<typename Key, typename Value>
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

template<typename Key, typename Value>
inline LinearProbingHashST<Key, Value>::LinearProbingHashST() {
    this -> N = 0;
    this -> M = LinearProbingHashST<Key, Value>:: initM;
    allKeys = std:: vector<Key>(M, Key{});
    values = std:: vector<Value>(M, Value{});
}

template<typename Key, typename Value>
inline LinearProbingHashST<Key, Value>::LinearProbingHashST(int M) {
    this -> N = 0;
    this -> M = M;
    allKeys = std:: vector<Key>(M, Key{});
    values = std:: vector<Value>(M, Value{});
}

template<typename Key, typename Value>
inline int LinearProbingHashST<Key, Value>:: hash(Key key) {
//    return (key.hash() & 0x7fffffff) % M;
    return 1;
}

template<typename Key, typename Value>
inline bool LinearProbingHashST<Key, Value>:: contains(Key key) {
    if (key == Key{}) {
        return false;
    }
    
    for (int i = hash(key); allKeys[i] != Key{}; i = (i + 1) % M) {
        if (allKeys[i] == key) {
            return true;
        }
    }
    return false;
}

template<typename Key, typename Value>
inline int LinearProbingHashST<Key, Value>:: size() {
    return N;
}

template<typename Key, typename Value>
inline void LinearProbingHashST<Key, Value>:: resize(int M) {
   LinearProbingHashST<Key, Value> temp(M);
    for (int i = 0; i < this -> M; i++) {
        temp.put(allKeys[i], values[i]);
    }
    
    this -> M = M;
    this -> values = temp.values;
    this -> allKeys = temp.allKeys;
}

template<typename Key, typename Value>
inline Value LinearProbingHashST<Key, Value>:: get(Key key) {
    if (key == Key{}) {
        return Value{};
    }
    
    for (int i = hash(key); allKeys[i] != Key{}; i = (i + 1) % M) {
        if (allKeys[i] == key) {
            return values[i];
        }
    }
    return Value{};
}

template<typename Key, typename Value>
inline void LinearProbingHashST<Key, Value>:: put(Key key, Value value) {
    if (key == Key{}) {
        return;
    }
    
    if (value == Value{}) {
        remove(key);
    }
    
    int hashKey = hash(key);
    int i;
    for (i = hashKey; allKeys[i] != Key{}; i = (i + 1) % M) {
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

template<typename Key, typename Value>
inline void LinearProbingHashST<Key, Value>:: remove(Key key) {
    if (key == Key{}) {
        return;
    }
    
    int hashKey = hash(key);
    if (allKeys[hashKey] == Key{}) {
        return;
    }
    
    for (int i = hashKey; allKeys[i] != Key{}; i = (i + 1) % M) {
        if (allKeys[i] == key) {
            allKeys[i] = Key{};
            values[i] = Value{};
        }
    }
    
    for (int i = hashKey + 1; allKeys[i] != Key{}; i = (i + 1) % M) {
        Key k = allKeys[i];
        Value v = values[i];
        allKeys[i] = Key{};
        values[i] = Value{};
        N--;
        
        put(k, v);
    }
    
    N--;
    if (N >=LinearProbingHashST<Key, Value>:: initM && N == M / 8) {
        resize(M / 2);
    }
}

template<typename Key, typename Value>
inline Iterable<Key>* LinearProbingHashST<Key, Value>:: keys() {
    LinkQueue<Key>* queue = new LinkQueue<Key>;
    for (int i = 0; i < M; i++) {
        if (allKeys[i] != Key{}) {
            queue -> enqueue(allKeys[i]);
        }
    }
    return queue;
}

#endif /* LinearProbingHashST_hpp */
