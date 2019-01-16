//
//  TST.hpp
//  Demo
//
//  Created by Quang Huy on 1/6/19.
//  Copyright © 2019 Techmaster. All rights reserved.
//

#ifndef TST_hpp
#define TST_hpp

#include <stdio.h>
#include "StringST.hpp"
#include "Alphabet.hpp"
#include "Bag+LinkedList.hpp"

template <typename Value>
class TST: public StringST<Value> {
public:
    TST();
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
        char c;
        Value val = Value{-1};
        Node* left;
        Node* mid;
        Node* right;
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
TST<Value>:: TST() {
    
}

template <typename Value>
void TST<Value>:: put(std:: string key, Value val) {
    root = put(root, key, val, 0);
}

template <typename Value>
typename TST<Value>:: Node* TST<Value>:: put(Node* x, std:: string key, Value val, int d) {
    if (!x) {
        x = new Node();
        x -> c = key[d];
    }
    
    if (d == key.length() - 1) {
        x -> val = val;
        return x;
    }
    
    int nextIndex = Alphabet:: BASE64.toIndex(key[d]);
    int currentIndex = Alphabet:: BASE64.toIndex(x -> c);
    if (currentIndex < nextIndex) {
        x -> right = put(x -> right, key, val, d);
    } else if (currentIndex == nextIndex) {
        x -> mid = put(x -> mid, key, val, d + 1);
    } else {
        x -> left = put(x -> left, key, val, d);
    }
    return x;
}

template <typename Value>
Value TST<Value>:: get(std:: string key) {
    return get(root, key, 0) -> val;
}

template <typename Value>
typename TST<Value>:: Node* TST<Value>:: get(Node* x, std:: string key, int d) {
    if (!x) {
        return 0;
    }
    if (d == key.length() - 1) {
        return x;
    }
    
    int nextIndex = Alphabet:: BASE64.toIndex(key[d]);
    int currentIndex = Alphabet:: BASE64.toIndex(x -> c);
    if (currentIndex < nextIndex) {
        return get(x -> right, key, d);
    } else if (currentIndex == nextIndex) {
        return get(x -> mid, key, d + 1);
    } else {
        return get(x -> left, key, d);
    }
}

template <typename Value>
void TST<Value>:: remove(std:: string key) {
    root = remove(root, key, 0);
}

template <typename Value>
typename TST<Value>:: Node* TST<Value>:: remove(Node* x, std:: string key, int d) {
    if (!x) {
        return 0;
    }
    if (d == key.length() - 1) {
        x -> val = Value{-1};
    } else {
        int nextIndex = Alphabet:: BASE64.toIndex(key[d]);
        int currentIndex = Alphabet:: BASE64.toIndex(x -> c);
        if (currentIndex < nextIndex) {
            x -> right = remove(x -> right, key, d);
        } else if (currentIndex == nextIndex) {
            x -> mid = remove(x -> mid, key, d + 1);
        } else {
            x -> left = remove(x -> left, key, d);
        }
    }
    
    if (x -> val != Value{-1}) {
        return x;
    }
    
    if (x -> mid) {
        return x;
    }
    
    if (!x -> left) {
        return x -> right;
    }
    
    if (!x -> right) {
        return x -> left;
    }
    return 0;
}

template <typename Value>
bool TST<Value>:: contains(std:: string key) {
    return contains(root, key, 0);
}

template <typename Value>
typename TST<Value>:: Node* TST<Value>:: contains(Node* x, std:: string key, int d) {
    if (!x) {
        return 0;
    }
    if (d == key.length() - 1) {
        return x;
    }
    int nextIndex = Alphabet:: BASE64.toIndex(key[d]);
    int currentIndex = Alphabet:: BASE64.toIndex(x -> c);
    if (currentIndex < nextIndex) {
        return contains(x -> right, key, d);
    } else if (currentIndex == nextIndex) {
        return contains(x -> mid, key, d + 1);
    } else {
        return contains(x -> left, key, d);
    }
}

template <typename Value>
bool TST<Value>:: isEmpty() {
    return root;
}

template <typename Value>
std:: string TST<Value>:: longestPrefixOf(std:: string s) {
    return s.substr(0, longestPrefixOf(root, s, 0));
}

template <typename Value>
int TST<Value>:: longestPrefixOf(Node* x, std:: string s, int l) {
    if (!x) {
        return l;
    }
    if (l == s.length() - 1) {
        return l;
    }
    
    int nextIndex = Alphabet:: BASE64.toIndex(s[l]);
    int currentIndex = Alphabet:: BASE64.toIndex(x -> c);
    if (currentIndex < nextIndex) {
        return longestPrefixOf(x -> right, s, l);
    } else if (currentIndex == nextIndex) {
        return longestPrefixOf(x -> mid, s, l + 1);
    } else {
        return longestPrefixOf(x -> left, s, l);
    }
}

template <typename Value>
Iterable<std:: string>* TST<Value>:: keysWithPrefix(std:: string s) {
    LinkBag<std:: string>* bag = new LinkBag<std:: string>;
    char arr[1000] = {0};
    int length = 0;
    keysWithPrefix(root, s, bag, 0, arr, length);
    return bag;
}

template <typename Value>
void TST<Value>:: keysWithPrefix(Node* x, std:: string s, LinkBag<std:: string>* bag, int d, char arr[], int& l) {
    if (!x) {
        return;
    }
    
    int nextIndex = Alphabet:: BASE64.toIndex(s[d]);
    int currentIndex = Alphabet:: BASE64.toIndex(x -> c);

    if (currentIndex == nextIndex || d > s.length() - 1) {
        arr[l++] = d > s.length() - 1 ? x -> c : s[d];
        if (x -> val != Value{-1})
            bag -> add(std:: string(arr));
        keysWithPrefix(x -> mid, s, bag, d + 1, arr, l);
        arr[--l] = 0;
    }
    
    if (currentIndex < nextIndex || d > s.length() - 1) {
        keysWithPrefix(x -> right, s, bag, d, arr, l);
    }
    
    if (currentIndex > nextIndex || d > s.length() - 1) {
        keysWithPrefix(x -> left, s, bag, d, arr, l);
    }
}

template <typename Value>
Iterable<std:: string>* TST<Value>:: keysThatMatch(std:: string s) {
    LinkBag<std:: string>* bag = new LinkBag<std:: string>;
    char arr[1000] = {0};
    int length = 0;
    keysThatMatch(root, s, bag, 0, arr, length);
    return bag;
}

template <typename Value>
void TST<Value>:: keysThatMatch(Node* x, std:: string s, LinkBag<std:: string>* bag, int d, char arr[], int& l) {
    if (!x) {
        return;
    }
    
    int nextIndex = Alphabet:: BASE64.toIndex(s[d]);
    int currentIndex = Alphabet:: BASE64.toIndex(x -> c);
    
    if (currentIndex == nextIndex || s[d] == '.') {
        arr[l++] = s[d] == '.' ? x -> c : s[d];
        if (d == s.length() - 1 && x -> val != Value{-1})
            bag -> add(arr);
        keysThatMatch(x -> mid, s, bag, d + 1, arr, l);
        arr[--l] = 0;
    }
    
    if (currentIndex < nextIndex || s[d] == '.') {
        keysThatMatch(x -> right, s, bag, d, arr, l);
    }
    
    if (currentIndex > nextIndex || s[d] == '.') {
        keysThatMatch(x -> left, s, bag, d, arr, l);
    }
}

template <typename Value>
int TST<Value>:: size() {
    return size(root);
}

template <typename Value>
int TST<Value>:: size(Node* x) {
    if (!x) {
        return 0;
    }
    
    int s = 0;
    if (x -> val != Value{-1}) {
        s++;
    }
    s += size(x -> mid);
    s += size(x -> left);
    s += size(x -> right);
    
    return s;
}

template <typename Value>
Iterable<std:: string>* TST<Value>:: keys() {
    LinkBag<std:: string>* bag = new LinkBag<std:: string>;
    char arr[1000] = {0};
    int length = 0;
    keys(root, bag, arr, length);
    return bag;
}

template <typename Value>
void TST<Value>:: keys(Node* x, LinkBag<std:: string>* bag, char arr[], int& l) {
    if (!x) {
        return;
    }
    arr[l++] = x -> c;
    if (x -> val != Value{-1}) {
        bag -> add(arr);
    }
    keys(x -> mid, bag, arr, l);
    arr[--l] = 0;
    keys(x -> left, bag, arr, l);
    keys(x -> right, bag, arr, l);
}

#endif /* TST_hpp */
