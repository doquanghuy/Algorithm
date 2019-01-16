//
//  MinPriorityQueue.hpp
//  Demo
//
//  Created by Quang Huy on 12/6/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef MinPriorityQueue_hpp
#define MinPriorityQueue_hpp

#include <stdio.h>
#include <vector>

template <typename Item>
class MinPQ {
public:
    MinPQ(int maxN);
    MinPQ(Item* array, int N);
    void insert(Item item);
    Item min();
    Item delMin();
    bool isEmpty();
    int size();
private:
    Item* arr;
    int N;
    bool less(int i, int j);
    void exch(int i, int j);
    void swim(int k);
    void sink(int k);
};

template <typename Item>
inline MinPQ<Item>:: MinPQ(int maxN) {
    this -> N = 0;
    this -> arr = new Item[maxN + 1];
}

template <typename Item>
inline MinPQ<Item>:: MinPQ(Item* array, int N) {
    this -> N = N;
    this -> arr = new Item[N + 1];
    for (int i = 1; i < N + 1; i++) {
        this -> arr[i] = array[i - 1];
    }
    for (int i = N / 2; i >= 1; i--) {
        sink(i);
    }
}

template <typename Item>
inline void MinPQ<Item>:: insert(Item item) {
    N++;
    arr[N] = item;
    swim(N);
}

template <typename Item>
inline Item MinPQ<Item>:: min() {
    return arr[1];
}

template <typename Item>
inline Item MinPQ<Item>:: delMin() {
    Item first = arr[1];
    exch(1, N--);
    sink(1);
    return first;
}

template <typename Item>
inline bool MinPQ<Item>:: isEmpty() {
    return N == 0;
}

template <typename Item>
inline int MinPQ<Item>:: size() {
    return N;
}

template <typename Item>
inline bool MinPQ<Item>:: less(int i, int j) {
    return arr[i] < arr[j];
}

template <typename Item>
void MinPQ<Item>:: exch(int i, int j) {
    Item temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

template <typename Item>
inline void MinPQ<Item>:: swim(int k) {
    if (k > 1 && !less(k/2, k)) {
        exch(k/2, k);
        swim(k/2);
    }
}

template <typename Item>
inline void MinPQ<Item>:: sink(int k) {
    int leftChild = 2 * k;
    int rightChild = leftChild < N ? 2 * k + 1 : leftChild;
    int minChild = !less(leftChild, rightChild) ? rightChild : leftChild;
    
    if (minChild <= N && !less(k, minChild)) {
        exch(k, minChild);
        sink(minChild);
    }
}

#endif /* MinPriorityQueue_hpp */
