//
//  BinarySearchTree.hpp
//  Demo
//
//  Created by Quang Huy on 12/9/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include <stdio.h>
#include <vector>
#include "OrderedSymbolTable.hpp"
#include "Queue+LinkedList.hpp"

class BinarySearchTree: public OrderedSymbolTable {
public:
    struct Node {
        Node(Key key, Value value, int N, Node* left = 0, Node* right = 0): key(key), value(value), N(N), left(left), right(right) {}
        Node* left;
        Node* right;
        int N;
        Key key;
        Value value;
    };
    BinarySearchTree();
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
    Node* root;
    
    bool contains(Node* node, Key key);
    Node* put(Node* node, Key key, Value value);
    int size(Node* node);
    Node* get(Node* node, Key key);
    Node* min(Node* node);
    Node* max(Node* node);
    int rank(Node* node, Key key);
    Node* ceiling(Node* node, Key key);
    Node* floor(Node* node, Key key);
    Node* remove(Node* node, Key key);
    Node* deleteMin(Node* node);
    Node* deleteMax(Node* node);
    Node* select(Node* node, int k);
    void keys(Node* node, LinkQueue<Key>* queue, Key lo, Key hi);
    void keys(Node* node, LinkQueue<Key>* queue);
};

BinarySearchTree:: BinarySearchTree() {
    allKeys = vector<Key>(1);
    values = vector<Value>(1);
}

BinarySearchTree:: Node* BinarySearchTree:: put(Node* node, Key key, Value value) {
    if (!node) {
        node = new Node(key, value, 1);
        return node;
    }
    
    if (key == node -> key) {
        node -> value = value;
    } else if (key > node -> key) {
        node -> right = put(node -> right, key, value);
    } else {
        node -> left = put(node -> left, key, value);
    }
    node -> N = size(node -> left) + size(node -> right) + 1;
    return node;
}

void BinarySearchTree:: put(Key key, Value value) {
    root = put(root, key, value);
}

Value BinarySearchTree:: get(Key key) {
    return get(root, key) -> value;
}

BinarySearchTree::Node*  BinarySearchTree:: get(Node* node, Key key) {
    if (node -> key == key) {
        return node;
    }else if (node -> key > key) {
        return get(node -> left, key);
    } else {
        return get(node -> right, key);
    }
}

int BinarySearchTree:: size(){
    return size(root);
}

int BinarySearchTree:: size(Node* node){
    if (!node) {
        return 0;
    }
    return size(node -> left) + size(node -> right) + 1;
}

bool BinarySearchTree:: contains(Key key) {
    return contains(root, key);
}

bool BinarySearchTree:: contains(Node* node, Key key) {
    if (node -> key == key) {
        return true;
    } else if (node -> key > key) {
        return contains(node -> left, key);
    } else {
        return contains(node -> right, key);
    }
}

bool BinarySearchTree:: isEmpty(){
    return root -> N == 0;
}


Key BinarySearchTree:: min() {
    return min(root) -> key;
}

BinarySearchTree:: Node* BinarySearchTree:: min(Node* node) {
    if (!node -> left) {
        return node;
    }
    return min(node -> left);
}

Key BinarySearchTree:: max(){
    return max(root) -> key;
}

BinarySearchTree:: Node* BinarySearchTree:: max(Node* node) {
    if (!node -> right) {
        return node;
    }
    return max(node -> right);
}

int BinarySearchTree:: rank(Key key){
    return rank(root, key);
}

int BinarySearchTree:: rank(Node* node, Key key){
    if (!node) {
        return 0;
    }
    
    if (node -> key == key) {
        return size(node -> left);
    } else if (node -> key > key) {
        return rank(node -> left, key);
    } else {
        return 1 + size(node -> left) + rank(node -> right, key);
    }
}

Key BinarySearchTree:: ceiling(Key key){
    Node* c = ceiling(root, key);
    if (!c) {
        return Key:: defaultValue;
    }
    return c -> key;
}

BinarySearchTree:: Node* BinarySearchTree:: ceiling(Node* node, Key key) {
    if (!node) {
        return 0;
    }
    
    if (node -> key == key) {
        return node;
    } else if (node -> key > key) {
        Node* ceilingLeft = ceiling(node -> left, key);
        if (!ceilingLeft) {
            return node;
        }
        Node* min = ceilingLeft -> key > node -> key ? node : ceilingLeft;
        return min;
    } else {
        return ceiling(node -> right, key);
    }
}

Key BinarySearchTree:: floor(Key key){
    Node* f = floor(root, key);
    if (!f) {
        return Key:: defaultValue;
    }
    return f -> key;
}

BinarySearchTree:: Node* BinarySearchTree:: floor(Node* node, Key key){
    if (!node) {
        return 0;
    }
    
    if (node -> key == key) {
        return node;
    } else if (node -> key > key) {
        return floor(node -> left, key);
    } else {
        Node* floorRight = floor(node -> right, key);
        if (!floorRight) {
            return node;
        }
        Node* max = floorRight -> key > node -> key ? floorRight : node;
        return max;
    }
}

void BinarySearchTree:: deleteMin(){
    root = deleteMin(root);
}

BinarySearchTree:: Node* BinarySearchTree:: deleteMin(Node* node) {
    if (!node) {
        return 0;
    }
    if (!node -> left) {
        return node -> right;
    }
    node -> left = deleteMin(node -> left);
    node -> N = size(node -> left) + size(node -> right) + 1;
    return node;
}

void BinarySearchTree:: deleteMax(){
    root = deleteMax(root);
}

BinarySearchTree:: Node* BinarySearchTree:: deleteMax(Node* node) {
    if (!node) {
        return 0;
    }
    if (!node -> right) {
        return node -> left;
    }
    node -> right = deleteMax(node -> right);
    node -> N = size(node -> left) + size(node -> right) + 1;
    return node;
}

void BinarySearchTree:: remove(Key key) {
    root = remove(root, key);
}

BinarySearchTree:: Node* BinarySearchTree:: remove(Node* node, Key key) {
    if (!node) {
        return 0;
    }
    
    if (node -> key == key) {
        if (!node -> right) {
            return node -> left;
        }
        if (!node -> left) {
            return node -> right;
        }
        Node* minRight = min(node -> right);
        if (minRight) {
            minRight -> left = node -> left;
            minRight -> right = deleteMin(node -> right);
            node = minRight;
        }
    } else if (node -> key > key) {
        node -> left = remove(node -> left, key);
    } else {
        node -> right = remove(node -> right, key);
    }
    node -> N = size(node -> left) + size(node -> right) + 1;
    return node;
}

Key BinarySearchTree:: select(int k) {
    Node* node = select(root, k);
    if (!node) {
        return Key:: defaultValue;
    }
    return node -> key;
}

BinarySearchTree:: Node* BinarySearchTree:: select(Node* node, int k) {
    if (!node) {
        return 0;
    }
    int s = size(node -> left);
    if (s == k) {
        return node;
    } else if (s > k) {
        return select(node -> left, k);
    } else {
        return select(node -> right, k - s - 1);
    }
}

int BinarySearchTree:: size(Key lo, Key hi) {
    if (lo > hi) {
        return 0;
    }
    
    int kLo = rank(lo);
    int kHi = rank(hi);
    int size = kHi - kLo;
    
    if (contains(hi)) {
        size += 1;
    }
    return size;
}

Iterable<Key>* BinarySearchTree:: keys(Key lo, Key hi) {
    if (lo > hi) {
        return 0;
    }
    LinkQueue<Key>* queue = new LinkQueue<Key>;
    keys(root, queue, lo, hi);
    return queue;
}

void BinarySearchTree:: keys(Node* node, LinkQueue<Key>* queue, Key lo, Key hi) {
    if (!node) {
        return;
    }
    
    if (node -> key > lo) {
        keys(node -> left, queue, lo, hi);
    }
    if (node -> key >= lo && node -> key <= hi) {
        queue -> enqueue(node -> key);
    }
    if (node -> key < hi) {
        keys(node -> right, queue, lo, hi);
    }
}

Iterable<Key>* BinarySearchTree:: keys() {
    LinkQueue<Key>* queue = new LinkQueue<Key>;
    keys(root, queue);
    return queue;
}

void BinarySearchTree:: keys(Node* node, LinkQueue<Key>* queue) {
    if (!node) {
        return;
    }
    keys(node -> left, queue);
    queue -> enqueue(node -> key);
    keys(node -> right, queue);
}

#endif /* BinarySearchTree_hpp */
