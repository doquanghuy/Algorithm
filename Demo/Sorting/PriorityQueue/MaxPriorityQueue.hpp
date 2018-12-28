//
//  MaxPriorityQueue.hpp
//  Demo
//
//  Created by Quang Huy on 12/6/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef MaxPriorityQueue_hpp
#define MaxPriorityQueue_hpp

#include <stdio.h>
#include <vector>

template <typename Item>
class MaxPQ {
public:
    MaxPQ(int maxN);
    MaxPQ(Item* array, int N, int maxN);
    void insert(Item item);
    Item max();
    Item delMax();
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
inline MaxPQ<Item>:: MaxPQ(int maxN) {
    N = 0;
    arr = new Item[maxN + 1];
}

template <typename Item>
inline MaxPQ<Item>:: MaxPQ(Item* array, int N, int maxN) {
    this -> N = N;
    arr = new Item[maxN + 1];
    for (int i = 1; i <= N; i++) {
        arr[i] = array[i - 1];
    }
    for (int i = N / 2; i >= 1; i--) {
        sink(i);
    }
}

template <typename Item>
inline void MaxPQ<Item>:: insert(Item item) {
    N++;
    arr[N] = item;
    swim(N);
}

template <typename Item>
inline Item MaxPQ<Item>:: max() {
    return arr[1];
}

template <typename Item>
inline Item MaxPQ<Item>:: delMax() {
    Item first = arr[1];
    exch(1, N--);
    sink(1);
    return first;
}

template <typename Item>
inline bool MaxPQ<Item>:: isEmpty() {
    return N == 0;
}

template <typename Item>
inline int MaxPQ<Item>:: size() {
    return N;
}

template <typename Item>
inline bool MaxPQ<Item>:: less(int i, int j) {
    return arr[i] < arr[j];
}

template <typename Item>
inline void MaxPQ<Item>:: exch(int i, int j) {
    Item temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

template <typename Item>
inline void MaxPQ<Item>:: swim(int k) {
    if (k > 1 && less(k/2, k)) {
        exch(k/2, k);
        swim(k/2);
    }
}

template <typename Item>
inline void MaxPQ<Item>:: sink(int k) {
    int leftChild = 2 * k;
    int rightChild = leftChild < N ? 2 * k + 1 : leftChild;
    int maxChild = less(leftChild, rightChild) ? rightChild : leftChild;
    
    if (maxChild <= N && less(k, maxChild)) {
        exch(k, maxChild);
        sink(maxChild);
    }
}

#endif /* MaxPriorityQueue_hpp */
