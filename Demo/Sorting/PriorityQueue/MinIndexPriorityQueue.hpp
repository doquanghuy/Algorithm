//
//  MinIndexPriorityQueue.hpp
//  Demo
//
//  Created by Quang Huy on 12/6/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef MinIndexPriorityQueue_hpp
#define MinIndexPriorityQueue_hpp

#include <stdio.h>
#include <vector>

template <typename Item>
class MinIndexPQ {
public:
    MinIndexPQ(int maxN);
    void insert(int k, Item item);
    void change(int k, Item item);
    bool contains(int k);
    void deleteItem(int k);
    Item min();
    int minIndex();
    int deleteMin();
    bool isEmpty();
    int size();
private:
    int* pq;
    int* qp;
    Item* keys;
    int N;
    bool less(int i, int j);
    void exch(int i, int j);
    void swim(int k);
    void sink(int k);
};

template <typename Item>
inline MinIndexPQ<Item>:: MinIndexPQ(int maxN) {
    pq = new int[maxN + 1];
    qp = new int[maxN + 1];
    keys = new Item[maxN + 1];
    N = 0;
    for (int i = 0; i <= maxN; i++) {
        qp[i] = -1;
        pq[i] = 0;
    }
}

template <typename Item>
inline void MinIndexPQ<Item>:: insert(int k, Item item) {
    N++;
    keys[k] = item;
    pq[N] = k;
    qp[k] = N;
    swim(N);
}

template <typename Item>
inline void MinIndexPQ<Item>:: change(int k, Item item) {
    keys[k] = item;
    swim(qp[k]);
    sink(qp[k]);
}

template <typename Item>
inline bool MinIndexPQ<Item>:: contains(int k) {
    return qp[k] != -1;
}

template <typename Item>
inline void MinIndexPQ<Item>:: deleteItem(int k) {
    exch(qp[k], N--);
    pq[N + 1] = 0;
    qp[k] = -1;
    swim(qp[k]);
    sink(qp[k]);
}

template <typename Item>
inline Item MinIndexPQ<Item>:: min() {
    return keys[pq[1]];
}

template <typename Item>
inline int MinIndexPQ<Item>:: minIndex() {
    return pq[1];
}

template <typename Item>
inline int MinIndexPQ<Item>:: deleteMin() {
    int indexMax = pq[1];
    exch(1, N--);
    sink(1);
    pq[N + 1] = 0;
    qp[indexMax] = -1;
    return indexMax;
}

template <typename Item>
inline bool MinIndexPQ<Item>:: isEmpty() {
    return N == 0;
}

template <typename Item>
inline int MinIndexPQ<Item>:: size() {
    return N;
}

template <typename Item>
inline bool MinIndexPQ<Item>:: less(int i, int j) {
    return keys[pq[i]] < keys[pq[j]];
}

template <typename Item>
inline void MinIndexPQ<Item>:: exch(int i, int j) {
    int pqTemp = pq[i];
    pq[i] = pq[j];
    pq[j] = pqTemp;
    
    qp[pq[i]] = i;
    qp[pq[j]] = j;
}

template <typename Item>
inline void MinIndexPQ<Item>:: swim(int k) {
    if (k > 1 && !less(k/2, k)) {
        exch(k/2, k);
        swim(k/2);
    }
}

template <typename Item>
inline void MinIndexPQ<Item>:: sink(int k) {
    int leftChild = 2 * k;
    int rightChild = leftChild < N ? 2 * k + 1 : leftChild;
    int minChild = !less(leftChild, rightChild) ? rightChild : leftChild;
    
    if (minChild <= N && !less(k, minChild)) {
        exch(k, minChild);
        sink(minChild);
    }
}

#endif /* MinIndexPriorityQueue_hpp */
