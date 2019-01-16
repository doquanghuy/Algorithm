//
//  Trie.hpp
//  Demo
//
//  Created by Quang Huy on 1/6/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#ifndef Trie_hpp
#define Trie_hpp

#include <stdio.h>
#include "StringST.hpp"
#include "Alphabet.hpp"
#include "Bag+LinkedList.hpp"

template <typename Value>
class Trie: public StringST<Value> {
public:
    Trie();
    void put(std:: string key, Value val);
    Value get(std:: string key);
    void remove(std:: string key);
    bool contains(std:: string key);
    bool isEmpty();
    std:: string longestPrefixOf(std:: string s);
    Iterable<std:: string>* keysWithPrefix(std:: string s);
    Iterable<std:: string>* keysThatMatch(std:: string s);
    int size();
    Iterable<std:: string>* keys();
private:
    struct Node {
        Value val = Value{-1};
        Node* next[64];
    };
    Node* root;
    Node* put(Node* x, std:: string key, Value val, int d);
    Node* get(Node* x, std:: string key, int d);
    Node* remove(Node* x, std:: string key, int d);
    Node* contains(Node* x, std:: string key, int d);
    int longestPrefixOf(Node* x, std:: string s, int l);
    void keysWithPrefix(Node* x, std:: string s, LinkBag<std:: string>* bag, int d, char arr[], int& l);
    int size(Node* x);
    void keysThatMatch(Node* x, std:: string s, LinkBag<std:: string>* bag, int d, char arr[], int& l);
    void keys(Node* x, LinkBag<std:: string>* bag, char arr[], int& l);
};

template <typename Value>
Trie<Value>:: Trie() {
    
}

template <typename Value>
void Trie<Value>:: put(std:: string key, Value val) {
    root = put(root, key, val, 0);
}

template <typename Value>
typename Trie<Value>:: Node* Trie<Value>:: put(Node* x, std:: string key, Value val, int d) {
    if (!x) {
        x = new Node();
    }
    if (d == key.length()) {
        x -> val = val;
        return x;
    }
    int nextIndex = Alphabet:: BASE64.toIndex(key[d]);
    x -> next[nextIndex] = put(x -> next[nextIndex], key, val, d + 1);
    return x;
}

template <typename Value>
Value Trie<Value>:: get(std:: string key) {
    return get(root, key, 0) -> val;
}

template <typename Value>
typename Trie<Value>:: Node* Trie<Value>:: get(Node* x, std:: string key, int d) {
    if (!x) {
        return 0;
    }
    if (d == key.length()) {
        return x;
    }
    return get(x -> next[Alphabet:: BASE64.toIndex(key[d])], key, d + 1);
}

template <typename Value>
void Trie<Value>:: remove(std:: string key) {
    root = remove(root, key, 0);
}

template <typename Value>
typename Trie<Value>:: Node* Trie<Value>:: remove(Node* x, std:: string key, int d) {
    if (!x) {
        return 0;
    }
    if (d == key.length()) {
        x -> val = Value{};
    } else {
        int nextIndex = Alphabet:: BASE64.toIndex(key[d]);
        x -> next[nextIndex] = remove(x -> next[nextIndex], key, d + 1);
    }
    if (x -> val) {
        return x;
    }
    for (int i = 0; i < Alphabet:: BASE64.R(); i++) {
        if (x -> next[i]) {
            return x;
        }
    }
    return 0;
}

template <typename Value>
bool Trie<Value>:: contains(std:: string key) {
    return contains(root, key, 0);
}

template <typename Value>
typename Trie<Value>:: Node* Trie<Value>:: contains(Node* x, std:: string key, int d) {
    if (!x) {
        return 0;
    }
    if (d == key.length()) {
        return x;
    }
    int nextIndex = Alphabet:: BASE64.toIndex(key[d]);
    x -> next[nextIndex] = contains(x -> next[nextIndex], key, d + 1);
    return x;
}

template <typename Value>
bool Trie<Value>:: isEmpty() {
    return root;
}

template <typename Value>
std:: string Trie<Value>:: longestPrefixOf(std:: string s) {
    if (!root) {
        return "";
    }
    return s.substr(0, longestPrefixOf(root, s, 0));
}

template <typename Value>
int Trie<Value>:: longestPrefixOf(Node* x, std:: string s, int l) {
    if (!x) {
        return l - 1;
    }
    if (s.empty()) {
        return 0;
    }
    if (l == s.length()) {
        return l;
    }
    int nextIndex = Alphabet:: BASE64.toIndex(s[l]);
    return longestPrefixOf(x -> next[nextIndex], s, l + 1);
}

template <typename Value>
Iterable<std:: string>* Trie<Value>:: keysWithPrefix(std:: string s) {
    LinkBag<std:: string>* bag = new LinkBag<std:: string>;
    char arr[1000] = {0};
    int length = 0;
    keysWithPrefix(root, s, bag, 0, arr, length);
    return bag;
}

template <typename Value>
void Trie<Value>:: keysWithPrefix(Node* x, std:: string s, LinkBag<std:: string>* bag, int d, char arr[], int& l) {
    if (!x) {
        return;
    }
    if (s.empty()) {
        return;
    }
    if (d < s.length()) {
        int nextIndex = Alphabet:: BASE64.toIndex(s[d]);
        arr[l++] = s[d];
        keysWithPrefix(x -> next[nextIndex], s, bag, d + 1, arr, l);
        arr[--l] = 0;
        return;
    }
    
    if (x -> val != Value{-1}) {
        bag -> add(std:: string(arr));
    }

    for (int i = 0; i < Alphabet:: BASE64.R(); i++) {
        char nextChar = Alphabet:: BASE64.toChar(i);
        arr[l++] = nextChar;
        keysWithPrefix(x -> next[i], s, bag, d + 1, arr, l);
        arr[--l] = 0;
    }
}

template <typename Value>
Iterable<std:: string>* Trie<Value>:: keysThatMatch(std:: string s) {
    LinkBag<std:: string>* bag = new LinkBag<std:: string>;
    char arr[1000] = {0};
    int length = 0;
    keysThatMatch(root, s, bag, 0, arr, length);
    return bag;
}

template <typename Value>
void Trie<Value>:: keysThatMatch(Node* x, std:: string s, LinkBag<std:: string>* bag, int d, char arr[], int& l) {
    if (!x) {
        return;
    }
    
    if (s.empty()) {
        return;
    }
    
    if (d == s.length()) {
        if (x -> val != Value{-1}) {
            bag -> add(arr);
        }
        return;
    }
    
    if (s[d] == '.') {
        for (int i = 0; i < Alphabet:: BASE64.R(); i++) {
            char nextChar = Alphabet:: BASE64.toChar(i);
            arr[l++] = nextChar;
            keysThatMatch(x -> next[i], s, bag, d + 1, arr, l);
            arr[--l] = 0;
        }
        return;
    }
    int nextIndex = Alphabet:: BASE64.toIndex(s[d]);
    arr[l++] = s[d];
    keysThatMatch(x -> next[nextIndex], s, bag, d + 1, arr, l);
    arr[--l] = 0;
}

template <typename Value>
int Trie<Value>:: size() {
    return size(root);
}

template <typename Value>
int Trie<Value>:: size(Node* x) {
    if (!x) {
        return 0;
    }
    
    int s = 0;
    for (int i = 0; i < Alphabet:: BASE64.R(); i++) {
        s += size(x -> next[i]);
    }
    if (x -> val != Value{-1}) {
        s++;
    }
    return s;
}

template <typename Value>
Iterable<std:: string>* Trie<Value>:: keys() {
    LinkBag<std:: string>* bag = new LinkBag<std:: string>;
    char arr[1000] = {0};
    int length = 0;
    keys(root, bag, arr, length);
    return bag;
}

template <typename Value>
void Trie<Value>:: keys(Node* x, LinkBag<std:: string>* bag, char arr[], int& l) {
    if (!x) {
        return;
    }
    
    if (x -> val != Value{-1}) {
        bag -> add(arr);
    }
    
    for (int i = 0; i < Alphabet:: BASE64.R(); i++) {
        arr[l++] = Alphabet::BASE64.toChar(i);
        keys(x -> next[i], bag, arr, l);
        arr[--l] = 0;
    }
}

#endif /* Trie_hpp */
