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
#include "Stack+LinkedList.hpp"

template<typename Key, typename Value>
class SequentialSearchST: public SymbolTable<Key, Value> {
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

template<typename Key, typename Value>
inline SequentialSearchST<Key, Value>:: SequentialSearchST() {
    this -> first = 0;
}

template<typename Key, typename Value>
inline Value SequentialSearchST<Key, Value>:: get(Key key) {
    for (Node* x = first; x != 0; x = x -> next) {
        if (x -> key == key) {
            return x -> value;
        }
    }
    return Value{};
}

template<typename Key, typename Value>
inline void SequentialSearchST<Key, Value>:: put(Key key, Value value) {
    if (value == Value{-1.0}) {
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

template<typename Key, typename Value>
inline void SequentialSearchST<Key, Value>:: remove(Key key) {
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

template<typename Key, typename Value>
inline bool SequentialSearchST<Key, Value>:: contains(Key key) {
    for (Node* x = first; x != 0; x = x -> next) {
        if (x -> key == key) {
            return true;
        }
    }
    return false;
}

template<typename Key, typename Value>
inline bool SequentialSearchST<Key, Value>:: isEmpty() {
    return N == 0;
}

template<typename Key, typename Value>
inline int SequentialSearchST<Key, Value>:: size() {
    return N;
}

template<typename Key, typename Value>
inline Iterable<Key>* SequentialSearchST<Key, Value>:: keys() {
    LinkStack<Key>* stack = new LinkStack<Key>;
    for (Node* x = first; x != 0; x = x -> next) {
        stack -> push(x -> key);
    }
    return stack;
}

#endif /* SequentialSearchST_hpp */
