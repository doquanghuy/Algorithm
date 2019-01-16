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

template<typename Key, typename Value>
class BinarySearchTree: public OrderedSymbolTable<Key, Value> {
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

template<typename Key, typename Value>
BinarySearchTree<Key, Value>:: BinarySearchTree() {
    allKeys = vector<Key>(1);
    values = vector<Value>(1);
}

template<typename Key, typename Value>
typename BinarySearchTree<Key, Value>::Node* BinarySearchTree<Key, Value>:: put(Node* node, Key key, Value value) {
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

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>:: put(Key key, Value value) {
    root = put(root, key, value);
}

template<typename Key, typename Value>
Value BinarySearchTree<Key, Value>:: get(Key key) {
    return get(root, key) -> value;
}

template<typename Key, typename Value>
typename BinarySearchTree<Key, Value>::Node*  BinarySearchTree<Key, Value>:: get(Node* node, Key key) {
    if (node -> key == key) {
        return node;
    }else if (node -> key > key) {
        return get(node -> left, key);
    } else {
        return get(node -> right, key);
    }
}

template<typename Key, typename Value>
int BinarySearchTree<Key, Value>:: size(){
    return size(root);
}

template<typename Key, typename Value>
int BinarySearchTree<Key, Value>:: size(Node* node){
    if (!node) {
        return 0;
    }
    return size(node -> left) + size(node -> right) + 1;
}

template<typename Key, typename Value>
bool BinarySearchTree<Key, Value>:: contains(Key key) {
    return contains(root, key);
}

template<typename Key, typename Value>
bool BinarySearchTree<Key, Value>:: contains(Node* node, Key key) {
    if (node -> key == key) {
        return true;
    } else if (node -> key > key) {
        return contains(node -> left, key);
    } else {
        return contains(node -> right, key);
    }
}

template<typename Key, typename Value>
bool BinarySearchTree<Key, Value>:: isEmpty(){
    return root -> N == 0;
}

template<typename Key, typename Value>
Key BinarySearchTree<Key, Value>:: min() {
    return min(root) -> key;
}

template<typename Key, typename Value>
typename BinarySearchTree<Key, Value>::Node* BinarySearchTree<Key, Value>:: min(Node* node) {
    if (!node -> left) {
        return node;
    }
    return min(node -> left);
}

template<typename Key, typename Value>
Key BinarySearchTree<Key, Value>:: max(){
    return max(root) -> key;
}

template<typename Key, typename Value>
typename BinarySearchTree<Key, Value>::Node* BinarySearchTree<Key, Value>:: max(Node* node) {
    if (!node -> right) {
        return node;
    }
    return max(node -> right);
}

template<typename Key, typename Value>
int BinarySearchTree<Key, Value>:: rank(Key key){
    return rank(root, key);
}

template<typename Key, typename Value>
int BinarySearchTree<Key, Value>:: rank(Node* node, Key key){
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

template<typename Key, typename Value>
Key BinarySearchTree<Key, Value>:: ceiling(Key key){
    Node* c = ceiling(root, key);
    if (!c) {
        return Key:: defaultValue;
    }
    return c -> key;
}

template<typename Key, typename Value>
typename BinarySearchTree<Key, Value>::Node* BinarySearchTree<Key, Value>:: ceiling(Node* node, Key key) {
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

template<typename Key, typename Value>
Key BinarySearchTree<Key, Value>:: floor(Key key){
    Node* f = floor(root, key);
    if (!f) {
        return Key:: defaultValue;
    }
    return f -> key;
}

template<typename Key, typename Value>
typename BinarySearchTree<Key, Value>::Node* BinarySearchTree<Key, Value>:: floor(Node* node, Key key){
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

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>:: deleteMin(){
    root = deleteMin(root);
}

template<typename Key, typename Value>
typename BinarySearchTree<Key, Value>::Node* BinarySearchTree<Key, Value>:: deleteMin(Node* node) {
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

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>:: deleteMax(){
    root = deleteMax(root);
}

template<typename Key, typename Value>
typename BinarySearchTree<Key, Value>::Node* BinarySearchTree<Key, Value>:: deleteMax(Node* node) {
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

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>:: remove(Key key) {
    root = remove(root, key);
}

template<typename Key, typename Value>
typename BinarySearchTree<Key, Value>::Node* BinarySearchTree<Key, Value>:: remove(Node* node, Key key) {
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

template<typename Key, typename Value>
Key BinarySearchTree<Key, Value>:: select(int k) {
    Node* node = select(root, k);
    if (!node) {
        return Key:: defaultValue;
    }
    return node -> key;
}

template<typename Key, typename Value>
typename BinarySearchTree<Key, Value>::Node* BinarySearchTree<Key, Value>:: select(Node* node, int k) {
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

template<typename Key, typename Value>
int BinarySearchTree<Key, Value>:: size(Key lo, Key hi) {
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

template<typename Key, typename Value>
Iterable<Key>* BinarySearchTree<Key, Value>:: keys(Key lo, Key hi) {
    if (lo > hi) {
        return 0;
    }
    LinkQueue<Key>* queue = new LinkQueue<Key>;
    keys(root, queue, lo, hi);
    return queue;
}

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>:: keys(Node* node, LinkQueue<Key>* queue, Key lo, Key hi) {
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

template<typename Key, typename Value>
Iterable<Key>* BinarySearchTree<Key, Value>:: keys() {
    LinkQueue<Key>* queue = new LinkQueue<Key>;
    keys(root, queue);
    return queue;
}

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>:: keys(Node* node, LinkQueue<Key>* queue) {
    if (!node) {
        return;
    }
    keys(node -> left, queue);
    queue -> enqueue(node -> key);
    keys(node -> right, queue);
}

#endif /* BinarySearchTree_hpp */
