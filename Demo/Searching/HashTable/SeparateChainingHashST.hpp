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
    SequentialSearchST* sts;
    int hash(Key key);
    void resize(int M);
    const static int initM = 4;
};

inline SeparateChainingHashST:: SeparateChainingHashST() {
    this -> N = 0;
    this -> M = SeparateChainingHashST:: initM;
    this -> sts = new SequentialSearchST[M];
}

inline SeparateChainingHashST:: SeparateChainingHashST(int M) {
    this -> N = 0;
    this -> M = M;
    this -> sts = new SequentialSearchST[M];
}

inline void SeparateChainingHashST:: resize(int M) {
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

inline int SeparateChainingHashST:: hash(Key key) {
    return (key.hash() & 0x7fffffff) % M;
}

inline int SeparateChainingHashST:: size() {
    return N;
}

inline bool SeparateChainingHashST:: contains(Key key) {
    return sts[hash(key)].contains(key);
}

inline Value SeparateChainingHashST:: get(Key key) {
    return sts[hash(key)].get(key);
}

inline void SeparateChainingHashST:: put(Key key, Value value) {
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

inline void SeparateChainingHashST:: remove(Key key) {
    if (key == Key:: defaultValue) {
        return;
    }
    
    if (N > SeparateChainingHashST:: initM && N < 2 * M) {
        resize(M / 2);
    }
    sts[hash(key)].remove(key);
    N--;
}

inline Iterable<Key>* SeparateChainingHashST:: keys() {
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
