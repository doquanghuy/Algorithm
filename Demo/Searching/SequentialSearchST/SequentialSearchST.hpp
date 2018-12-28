//
//  SequentialSearchST.hpp
//  Demo
//
//  Created by Quang Huy on 12/9/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef SequentialSearchST_hpp
#define SequentialSearchST_hpp

#include <stdio.h>
#include "SymbolTable.hpp"
#include "DataType.hpp"
#include "Queue+LinkedList.hpp"

class SequentialSearchST: public SymbolTable {
public:
    SequentialSearchST();
    Value get(Key key);
    void put(Key key, Value value);
    void remove(Key key);
    bool contains(Key key);
    bool isEmpty();
    int size();
    Iterable<Key>* keys();
    
    struct Node {
        Node(Key key = Key:: defaultValue, Value value = Value:: defaultValue, Node* next = 0): key(key), value(value), next(next) {}
        Key key;
        Value value;
        Node* next;
    };
private:
    int N;
    Node* first;
};

inline SequentialSearchST:: SequentialSearchST() {
    this -> first = 0;
}

inline Value SequentialSearchST:: get(Key key) {
    for (Node* x = first; x != 0; x = x -> next) {
        if (x -> key == key) {
            return x -> value;
        }
    }
    return Value:: defaultValue;
}


inline void SequentialSearchST:: put(Key key, Value value) {
    if (value == Value:: defaultValue) {
        return remove(key);
    }
    
    Node* node;
    for (node = first; node != 0; node = node -> next) {
        if (!(node -> key == key)) {
            continue;
        }
        node -> value = value;
        return;
    }
    
    first = new Node(key, value, first);
    N++;
}


inline void SequentialSearchST:: remove(Key key) {
    Node* previous = 0;
    Node* current = 0;
    Node* next = 0;
    
    if (first -> key == key) {
        current = first;
    } else {
        for (Node* x = first; x -> next != 0; x = x -> next) {
            if (x -> next -> key == key) {
                previous = x;
                current = x -> next;
                next = current -> next;
            }
        }
    }
    
    current -> next = 0;
    previous -> next = next;
    N--;
}


inline bool SequentialSearchST:: contains(Key key) {
    for (Node* x = first; x != 0; x = x -> next) {
        if (x -> key == key) {
            return true;
        }
    }
    return false;
}


inline bool SequentialSearchST:: isEmpty() {
    return N == 0;
}


inline int SequentialSearchST:: size() {
    return N;
}


inline Iterable<Key>* SequentialSearchST:: keys() {
    LinkQueue<Key>* queue = new LinkQueue<Key>;
    for (Node* x = first; x != 0; x = x -> next) {
        queue -> enqueue(x -> key);
    }
    return queue;
}

#endif /* SequentialSearchST_hpp */
