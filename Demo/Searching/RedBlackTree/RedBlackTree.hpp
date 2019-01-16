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

template<typename Key, typename Value>
class RedBlackTree: public OrderedSymbolTable<Key, Value> {
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

template<typename Key, typename Value>
inline RedBlackTree<Key, Value>:: RedBlackTree(){
    allKeys = std:: vector<Key>(1);
    values = std:: vector<Value>(1);
}

template<typename Key, typename Value>
inline  typename RedBlackTree<Key, Value>:: Node* RedBlackTree<Key, Value>:: rotateLeft(Node* node) {
    Node* x = node -> right;
    node -> right = x -> left;
    x -> left = node;
    
    x -> color = node -> color;
    node -> color = true;
    
    x -> N = node -> N;
    node -> N = size(node -> left) + size(node -> right) + 1;
    
    return x;
}

template<typename Key, typename Value>
inline typename RedBlackTree<Key, Value>:: Node* RedBlackTree<Key, Value>:: rotateRight(Node* node){
    Node* x = node -> left;
    node -> left = x -> right;
    x -> right = node;
    
    x -> color = node -> color;
    node -> color = true;
    
    x -> N = node -> N;
    node -> N = size(node -> left) + size(node -> right) + 1;
    return x;
}

template<typename Key, typename Value>
inline void RedBlackTree<Key, Value>:: flipColor(Node* node){
    node -> color = !node -> color;
    if (node -> left) {
        node -> left -> color = !node -> left -> color;
    }
    if (node -> right) {
        node -> right -> color = !node -> right -> color;
    }
}

template<typename Key, typename Value>
inline bool RedBlackTree<Key, Value>:: isRed(Node* node){
    if (!node) {
        return false;
    }
    return node -> color;
}

template<typename Key, typename Value>
inline void RedBlackTree<Key, Value>:: put(Key key, Value value){
    root = put(root, key, value);
    root -> color = false;
}

template<typename Key, typename Value>
inline typename RedBlackTree<Key, Value>:: Node* RedBlackTree<Key, Value>:: put(Node* node, Key key, Value value){
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

template<typename Key, typename Value>
inline Value RedBlackTree<Key, Value>:: get(Key key){
    return get(root, key) -> value;
}

template<typename Key, typename Value>
inline typename RedBlackTree<Key, Value>:: Node* RedBlackTree<Key, Value>:: get(Node* node, Key key){
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

template<typename Key, typename Value>
inline void RedBlackTree<Key, Value>:: deleteMin(){
    if (!isRed(root -> left) && !isRed(root -> right)) {
        root -> color = true;
    }
    root = deleteMin(root);
    if (!isEmpty()) {
        root -> color = false;
    }
}

template<typename Key, typename Value>
inline typename RedBlackTree<Key, Value>:: Node* RedBlackTree<Key, Value>:: deleteMin(Node* node){
    if (!node -> left) {
        return node -> right;
    }
    node = maintainLeftChild(node);
    node -> left = deleteMin(node -> left);
    node = balance(node);
    return node;
}

template<typename Key, typename Value>
inline typename RedBlackTree<Key, Value>:: Node* RedBlackTree<Key, Value>:: maintainLeftChild(Node* node) {
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

template<typename Key, typename Value>
inline typename RedBlackTree<Key, Value>:: Node* RedBlackTree<Key, Value>:: balance(Node* node) {
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

template<typename Key, typename Value>
inline void RedBlackTree<Key, Value>:: deleteMax(){
    root = deleteMax(root);
}

template<typename Key, typename Value>
inline typename RedBlackTree<Key, Value>:: Node* RedBlackTree<Key, Value>:: maintainRightChild(Node* node) {
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

template<typename Key, typename Value>
inline typename RedBlackTree<Key, Value>:: Node* RedBlackTree<Key, Value>:: deleteMax(Node* node){
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

template<typename Key, typename Value>
inline void RedBlackTree<Key, Value>:: remove(Key key){
    if (!isRed(root -> left) && !isRed(root -> right)) {
        root -> color = true;
    }
    root = remove(root, key);
    if (!isEmpty()) {
        root -> color = false;
    }
}

template<typename Key, typename Value>
inline typename RedBlackTree<Key, Value>:: Node* RedBlackTree<Key, Value>:: remove(Node* node, Key key){
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

template<typename Key, typename Value>
inline bool RedBlackTree<Key, Value>:: contains(Key key){
    return contains(root, key);
}

template<typename Key, typename Value>
inline bool RedBlackTree<Key, Value>:: contains(Node* node, Key key){
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

template<typename Key, typename Value>
inline bool RedBlackTree<Key, Value>:: isBalanced() {
    setHeights();
    int h = 0;
    int& refHeight = h;
    return isBalanced(root, refHeight);
}

template<typename Key, typename Value>
inline bool RedBlackTree<Key, Value>:: isBalanced(Node* node, int& h) {
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

template<typename Key, typename Value>
inline void RedBlackTree<Key, Value>:: setHeights() {
    setHeights(root, 0);
}

template<typename Key, typename Value>
inline void RedBlackTree<Key, Value>:: setHeights(Node* node, int h) {
    if (!node) {
        return;
    }
    int newHeight = node -> color ? h : h + 1;
    node -> h = newHeight;
    setHeights(node -> left, newHeight);
    setHeights(node -> right, newHeight);
}

template<typename Key, typename Value>
inline bool RedBlackTree<Key, Value>:: isEmpty() {
    return root == 0;
}

template<typename Key, typename Value>
inline int RedBlackTree<Key, Value>:: size() {
    return size(root);
}

template<typename Key, typename Value>
inline int RedBlackTree<Key, Value>:: size(Node* node) {
    if (!node) {
        return 0;
    }
    
    return size(node -> left) + size(node -> right) + 1;
}

template<typename Key, typename Value>
inline Key RedBlackTree<Key, Value>:: min() {
    return min(root) -> key;
}

template<typename Key, typename Value>
inline typename RedBlackTree<Key, Value>:: Node* RedBlackTree<Key, Value>:: min(Node* node){
    if (!node) {
        return 0;
    }
    
    if (!node -> left) {
        return node;
    }
    
    return min(node -> left);
}

template<typename Key, typename Value>
inline Key RedBlackTree<Key, Value>:: max(){
    return max(root) -> key;
}

template<typename Key, typename Value>
inline typename RedBlackTree<Key, Value>:: Node* RedBlackTree<Key, Value>:: max(Node* node){
    if (!node) {
        return 0;
    }
    
    if (!node -> right) {
        return node;
    }
    
    return max(node -> right);
}

template<typename Key, typename Value>
inline Key RedBlackTree<Key, Value>:: ceiling(Key key){
    Node* c = ceiling(root, key);
    if (!c) {
        return Key:: defaultValue;
    }
    return c -> key;
}

template<typename Key, typename Value>
inline typename RedBlackTree<Key, Value>:: Node* RedBlackTree<Key, Value>:: ceiling(Node* node, Key key){
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

template<typename Key, typename Value>
inline Key RedBlackTree<Key, Value>:: floor(Key key){
    Node* f = floor(root, key);
    if (!f) {
        return Key:: defaultValue;
    }
    return f -> key;
}

template<typename Key, typename Value>
inline typename RedBlackTree<Key, Value>:: Node* RedBlackTree<Key, Value>:: floor(Node* node, Key key){
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

template<typename Key, typename Value>
inline Key RedBlackTree<Key, Value>:: select(int k){
    Node* s = select(root, k);
    if (!s) {
        return Key:: defaultValue;
    }
    return s -> key;
}

template<typename Key, typename Value>
inline typename RedBlackTree<Key, Value>:: Node* RedBlackTree<Key, Value>:: select(Node* node, int k){
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
inline int RedBlackTree<Key, Value>:: rank(Key key){
    return rank(root, key);
}

template<typename Key, typename Value>
inline int RedBlackTree<Key, Value>:: rank(Node* node, Key key){
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
inline int RedBlackTree<Key, Value>:: size(Key lo, Key hi) {
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
inline Iterable<Key>* RedBlackTree<Key, Value>:: keys(Key lo, Key hi){
    LinkQueue<Key>* queue = new LinkQueue<Key>;
    keys(root, queue, lo, hi);
    return queue;
}

template<typename Key, typename Value>
inline void RedBlackTree<Key, Value>:: keys(Node* node, LinkQueue<Key>* queue, Key lo, Key hi){
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
inline Iterable<Key>* RedBlackTree<Key, Value>:: keys(){
    LinkQueue<Key>* queue = new LinkQueue<Key>;
    keys(root, queue);
    return queue;
}

template<typename Key, typename Value>
inline void RedBlackTree<Key, Value>:: keys(Node* node, LinkQueue<Key>* queue){
    if (!node) {
        return;
    }
    keys(node -> left, queue);
    queue -> enqueue(node -> key);
    keys(node -> right, queue);
}

#endif /* RedBlackTree_hpp */
