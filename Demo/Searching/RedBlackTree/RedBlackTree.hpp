//
//  RedBlackTree.hpp
//  Demo
//
//  Created by Quang Huy on 12/9/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef RedBlackTree_hpp
#define RedBlackTree_hpp

#include <stdio.h>
#include <vector>
#include "OrderedSymbolTable.hpp"
#include "Queue+LinkedList.hpp"

class RedBlackTree: public OrderedSymbolTable {
public:
    struct Node {
        Node(Key key, Value value, int N = 1, bool color = false, Node* left = 0, Node* right = 0, int h = 0): key(key), value(value), N(N), color(color), left(left), right(right), h(h) {}
        bool color; // Red is true
        Node* left;
        Node* right;
        Key key;
        Value value;
        int N;
        int h;
        bool isLeaf() {
            return !this -> left && !this -> right;
        }
    };
    RedBlackTree();
    void put(Key key, Value value);
    Value get(Key key);
    void remove(Key key);
    void deleteMin();
    void deleteMax();
    bool contains(Key key);
    bool isBalanced();
    void setHeights();
    bool isEmpty();
    int size();
    Key min();
    Key max();
    Key ceiling(Key key);
    Key floor(Key key);
    Key select(int k);
    int rank(Key key);
    int size(Key lo, Key hi);
    Iterable<Key>* keys(Key lo, Key hi);
    Iterable<Key>* keys();
private:
    std:: vector<Key> allKeys;
    std:: vector<Value> values;
    Node* root;
    
    Node* rotateLeft(Node* node);
    Node* rotateRight(Node* node);
    void flipColor(Node* node);
    bool isRed(Node* node);
    Node* maintainLeftChild(Node* node);
    Node* balance(Node* node);
    Node* maintainRightChild(Node* node);
    
    bool isBalanced(Node* node, int &h);
    void setHeights(Node* node, int h);
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

inline RedBlackTree:: RedBlackTree(){
    allKeys = std:: vector<Key>(1);
    values = std:: vector<Value>(1);
}

inline RedBlackTree:: Node* RedBlackTree:: rotateLeft(Node* node) {
    Node* x = node -> right;
    node -> right = x -> left;
    x -> left = node;
    
    x -> color = node -> color;
    node -> color = true;
    
    x -> N = node -> N;
    node -> N = size(node -> left) + size(node -> right) + 1;
    
    return x;
}
 
inline RedBlackTree:: Node* RedBlackTree:: rotateRight(Node* node){
    Node* x = node -> left;
    node -> left = x -> right;
    x -> right = node;
    
    x -> color = node -> color;
    node -> color = true;
    
    x -> N = node -> N;
    node -> N = size(node -> left) + size(node -> right) + 1;
    return x;
}

inline void RedBlackTree:: flipColor(Node* node){
    node -> color = !node -> color;
    if (node -> left) {
        node -> left -> color = !node -> left -> color;
    }
    if (node -> right) {
        node -> right -> color = !node -> right -> color;
    }
}

inline bool RedBlackTree:: isRed(Node* node){
    if (!node) {
        return false;
    }
    return node -> color;
}

inline void RedBlackTree:: put(Key key, Value value){
    root = put(root, key, value);
    root -> color = false;
}

inline RedBlackTree:: Node* RedBlackTree:: put(Node* node, Key key, Value value){
    if (!node) {
        return new Node(key, value, 1, true);
    }
    
    if (node -> key == key) {
        node -> value = value;
    } else if (node -> key > key) {
        node -> left = put(node -> left, key, value);
    } else {
        node -> right = put(node -> right, key, value);
    }
    
    if (isRed(node -> right) && !isRed(node -> left)) {
        node = rotateLeft(node);
    }
    if (node -> left -> left && isRed(node -> left) && isRed(node -> left -> left)) {
        node = rotateRight(node);
    }
    if (isRed(node -> left) && isRed(node -> right)) {
        flipColor(node);
    }
    
    node -> N = size(node -> left) + size(node -> right) + 1;
    return node;
}


inline Value RedBlackTree:: get(Key key){
    return get(root, key) -> value;
}

inline RedBlackTree:: Node* RedBlackTree:: get(Node* node, Key key){
    if (!node) {
        return 0;
    }
    
    if (node -> key == key) {
        return node;
    } else if (node -> key > key) {
        return get(node -> left, key);
    } else {
        return get(node -> right, key);
    }
}


inline void RedBlackTree:: deleteMin(){
    if (!isRed(root -> left) && !isRed(root -> right)) {
        root -> color = true;
    }
    root = deleteMin(root);
    if (!isEmpty()) {
        root -> color = false;
    }
}

inline RedBlackTree:: Node* RedBlackTree:: deleteMin(Node* node){
    if (!node -> left) {
        return node -> right;
    }
    node = maintainLeftChild(node);
    node -> left = deleteMin(node -> left);
    node = balance(node);
    return node;
}

inline RedBlackTree:: Node* RedBlackTree:: maintainLeftChild(Node* node) {
    if (!node) {
        return 0;
    }
    
    Node* left = node -> left;
    Node* right = node -> right;
    
    if (!left) {
        return node;
    }
    
    if (isRed(left) || isRed(left -> left)) {
        return node;
    }
    
    flipColor(node);
    if (right && isRed(right -> left)) {
        node -> right = rotateRight(node -> right);
        node = rotateLeft(node);
        flipColor(node);
        return node;
    }
    return node;
}

inline RedBlackTree:: Node* RedBlackTree:: balance(Node* node) {
    if (!node) {
        return 0;
    }
    if (isRed(node -> right) && !isRed(node -> left)) {
        node = rotateLeft(node);
    }
    if (node -> left && node -> left -> left && isRed(node -> left) && isRed(node -> left -> left)) {
        node = rotateRight(node);
    }
    if (isRed(node -> left) && isRed(node -> right)) {
        flipColor(node);
    }
    
    node -> N = size(node -> left) + size(node -> right) + 1;
    return node;
}

inline void RedBlackTree:: deleteMax(){
    root = deleteMax(root);
}

inline RedBlackTree:: Node* RedBlackTree:: maintainRightChild(Node* node) {
    if (!node) {
        return 0;
    }
    
    Node* left = node -> left;
    Node* right = node -> right;
    
    if (!right) {
        return node;
    }
    
    if (isRed(right) || isRed(right -> right)) {
        return node;
    }
    
    flipColor(node);
    
    if (left && isRed(left -> left)) {
        node = rotateRight(node);
        return node;
    }
    return node;
}

inline RedBlackTree:: Node* RedBlackTree:: deleteMax(Node* node){
    if (!node) {
        return 0;
    }
    
    if (!node -> right) {
        return node -> left;
    }
    
    node = maintainRightChild(node);
    node -> right = deleteMax(node -> right);
    node = balance(node);
    return node;
}

inline void RedBlackTree:: remove(Key key){
    if (!isRed(root -> left) && !isRed(root -> right)) {
        root -> color = true;
    }
    root = remove(root, key);
    if (!isEmpty()) {
        root -> color = false;
    }
}

inline RedBlackTree:: Node* RedBlackTree:: remove(Node* node, Key key){
    if (!node) {
        return 0;
    }
    
    if (node -> key == key) {
        flipColor(node);
        if (!node -> right) {
            return node -> left;
        }
        Node* minRight = min(node -> right);
        node -> right = deleteMin(node -> right);
        
        minRight -> color = node -> color;
        minRight -> left = node -> left;
        minRight -> right = node -> right;
        
        minRight = balance(minRight);
        return minRight;
    } else if (node -> key > key) {
        if (!node -> left) {
            return node;
        }
        
        if (!isRed(node -> left) && !isRed(node -> left -> left)) {
            node = maintainLeftChild(node);
        }
        node -> left = remove(node -> left, key);
    } else {
        if (!node -> right) {
            return node;
        }
        
        if (!isRed(node -> right) && !isRed(node -> right -> right)) {
            node = maintainRightChild(node);
        }
        
        node -> right = remove(node -> right, key);
    }
    node = balance(node);
    return node;
}


inline bool RedBlackTree:: contains(Key key){
    return contains(root, key);
}

inline bool RedBlackTree:: contains(Node* node, Key key){
    if (!node) {
        return false;
    }
    
    if (node -> key == key) {
        return true;
    } else if (node -> key > key) {
        return get(node -> left, key);
    } else {
        return get(node -> right, key);
    }
}

inline bool RedBlackTree:: isBalanced() {
    setHeights();
    int h = 0;
    int& refHeight = h;
    return isBalanced(root, refHeight);
}

inline bool RedBlackTree:: isBalanced(Node* node, int& h) {
    if (!node) {
        return true;
    }
    if (node -> isLeaf()) {
        if (!h) {
            h = node -> h;
        } else if (h != 0 && h != node -> h) {
            return false;
        }
        return true;
    }
    return isBalanced(node -> left, h) && isBalanced(node -> right, h);
}

inline void RedBlackTree:: setHeights() {
    setHeights(root, 0);
}

inline void RedBlackTree:: setHeights(Node* node, int h) {
    if (!node) {
        return;
    }
    int newHeight = node -> color ? h : h + 1;
    node -> h = newHeight;
    setHeights(node -> left, newHeight);
    setHeights(node -> right, newHeight);
}

inline bool RedBlackTree:: isEmpty() {
    return root == 0;
}

inline int RedBlackTree:: size() {
    return size(root);
}

inline int RedBlackTree:: size(Node* node) {
    if (!node) {
        return 0;
    }
    
    return size(node -> left) + size(node -> right) + 1;
}


inline Key RedBlackTree:: min() {
    return min(root) -> key;
}

inline RedBlackTree:: Node* RedBlackTree:: min(Node* node){
    if (!node) {
        return 0;
    }
    
    if (!node -> left) {
        return node;
    }
    
    return min(node -> left);
}


inline Key RedBlackTree:: max(){
    return max(root) -> key;
}

inline RedBlackTree:: Node* RedBlackTree:: max(Node* node){
    if (!node) {
        return 0;
    }
    
    if (!node -> right) {
        return node;
    }
    
    return max(node -> right);
}


inline Key RedBlackTree:: ceiling(Key key){
    Node* c = ceiling(root, key);
    if (!c) {
        return Key:: defaultValue;
    }
    return c -> key;
}

inline RedBlackTree:: Node* RedBlackTree:: ceiling(Node* node, Key key){
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
        return ceilingLeft -> key > node -> key ? node : ceilingLeft;
    } else {
        return ceiling(node -> right, key);
    }
}


inline Key RedBlackTree:: floor(Key key){
    Node* f = floor(root, key);
    if (!f) {
        return Key:: defaultValue;
    }
    return f -> key;
}

inline RedBlackTree:: Node* RedBlackTree:: floor(Node* node, Key key){
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
        return floorRight -> key > node -> key ? floorRight : node;
    }
}


inline Key RedBlackTree:: select(int k){
    Node* s = select(root, k);
    if (!s) {
        return Key:: defaultValue;
    }
    return s -> key;
}

inline RedBlackTree:: Node* RedBlackTree:: select(Node* node, int k){
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


inline int RedBlackTree:: rank(Key key){
    return rank(root, key);
}

inline int RedBlackTree:: rank(Node* node, Key key){
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

inline int RedBlackTree:: size(Key lo, Key hi) {
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

inline Iterable<Key>* RedBlackTree:: keys(Key lo, Key hi){
    LinkQueue<Key>* queue = new LinkQueue<Key>;
    keys(root, queue, lo, hi);
    return queue;
}

inline void RedBlackTree:: keys(Node* node, LinkQueue<Key>* queue, Key lo, Key hi){
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


inline Iterable<Key>* RedBlackTree:: keys(){
    LinkQueue<Key>* queue = new LinkQueue<Key>;
    keys(root, queue);
    return queue;
}

inline void RedBlackTree:: keys(Node* node, LinkQueue<Key>* queue){
    if (!node) {
        return;
    }
    keys(node -> left, queue);
    queue -> enqueue(node -> key);
    keys(node -> right, queue);
}


#endif /* RedBlackTree_hpp */
