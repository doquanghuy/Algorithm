//
//  SeparateChainingHashST.hpp
//  Demo
//
//  Created by Quang Huy on 12/15/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef SeparateChainingHashST_hpp
#define SeparateChainingHashST_hpp

#include <stdio.h>
#include "SequentialSearchST.hpp"
#include "Iterator.hpp"
#include "Queue+LinkedList.hpp"

template <typename Key, typename Value>
class SeparateChainingHashST {
public:
    SeparateChainingHashST();
    SeparateChainingHashST(int M);
    Value get(Key key);
    void put(Key key, Value value);
    void remove(Key key);
    int size();
    bool contains(Key key);
    Iterable<Key>* keys();
private:
    int N;
    int M;
    SequentialSearchST<Key, Value>* sts;
    int hash(Key key);
    void resize(int M);
    const static int initM = 4;
};

template <typename Key, typename Value>
inline SeparateChainingHashST<Key, Value>:: SeparateChainingHashST() {
    this -> N = 0;
    this -> M = SeparateChainingHashST<Key, Value>:: initM;
    this -> sts = new SequentialSearchST<Key, Value>[M];
}

template <typename Key, typename Value>
inline SeparateChainingHashST<Key, Value>:: SeparateChainingHashST(int M) {
    this -> N = 0;
    this -> M = M;
    this -> sts = new SequentialSearchST<Key, Value>[M];
}

template <typename Key, typename Value>
inline void SeparateChainingHashST<Key, Value>:: resize(int M) {
    SeparateChainingHashST temp(M);
    for (int i = 0; i < M; i++) {
        Iterator<Key>* iterator = sts[i].keys() -> iterator();
        while (iterator -> hasNext()) {
            Key key = iterator -> next();
            temp.put(key, get(key));
        }
    }
    
    this -> M = M;
    this -> sts = temp.sts;
}

template <typename Key, typename Value>
inline int SeparateChainingHashST<Key, Value>:: hash(Key key) {
    return (key.hash() & 0x7fffffff) % M;
}

template <typename Key, typename Value>
inline int SeparateChainingHashST<Key, Value>:: size() {
    return N;
}

template <typename Key, typename Value>
inline bool SeparateChainingHashST<Key, Value>:: contains(Key key) {
    return sts[hash(key)].contains(key);
}

template <typename Key, typename Value>
inline Value SeparateChainingHashST<Key, Value>:: get(Key key) {
    return sts[hash(key)].get(key);
}

template <typename Key, typename Value>
inline void SeparateChainingHashST<Key, Value>:: put(Key key, Value value) {
    if (key == Key:: defaultValue) {
        return;
    }
    if (value == Value:: defaultValue) {
        remove(key);
        return;
    }
    
    if (N > 8 * M) {
        resize(2 * M);
    }
    int h = hash(key);
    sts[h].put(key, value);
    N++;
}

template <typename Key, typename Value>
inline void SeparateChainingHashST<Key, Value>:: remove(Key key) {
    if (key == Key:: defaultValue) {
        return;
    }
    
    if (N > SeparateChainingHashST<Key, Value>:: initM && N < 2 * M) {
        resize(M / 2);
    }
    sts[hash(key)].remove(key);
    N--;
}

template <typename Key, typename Value>
inline Iterable<Key>* SeparateChainingHashST<Key, Value>:: keys() {
    LinkQueue<Key>* queue = new LinkQueue<Key>;
    for (int i = 0; i < M; i++) {
        Iterator<Key>* iterator = sts[i].keys() -> iterator();
        while (iterator -> hasNext()) {
            queue -> enqueue(iterator -> next());
        }
    }
    return queue;
}

#endif /* SeparateChainingHashST_hpp */
