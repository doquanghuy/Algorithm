//
//  HeapSort.hpp
//  Demo
//
//  Created by Quang Huy on 12/6/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef HeapSort_hpp
#define HeapSort_hpp

#include <stdio.h>
#include <vector>
#include "BaseSort.hpp"

template <typename Item>
class HeapSort: public BaseSort<Item> {
public:
    HeapSort(Item* array, int N);
    void sort();
private:
    Item* temp;
    bool less(int i, int j);
    void exch(int i, int j);
    void swim(int k);
    void sink(int k);
};

template <typename Item>
HeapSort<Item>:: HeapSort(Item* array, int N): BaseSort<Item>(array, N) {
    temp = array - 1;
}

template <typename Item>
void HeapSort<Item>:: sort() {
    for (int i = this -> N/2; i >= 1; i--) {
        sink(i);
    }
    
    int c = this -> N;
    while (this -> N > 1) {
        exch(1, this -> N--);
        sink(1);
    }
    
    this -> N = c;
    this -> array = temp + 1;
}

template <typename Item>
bool HeapSort<Item>:: less(int i, int j) {
    return temp[i] < temp[j];
}

template <typename Item>
void HeapSort<Item>:: exch(int i, int j) {
    Item t = temp[i];
    temp[i] = temp[j];
    temp[j] = t;
}

template <typename Item>
void HeapSort<Item>:: swim(int k) {
    if (k > 1 && less(k/2, k)) {
        exch(k/2, k);
        swim(k/2);
    }
}

template <typename Item>
void HeapSort<Item>:: sink(int k) {
    int leftChild = 2 * k;
    int rightChild = leftChild < this -> N ? 2 * k + 1 : leftChild;
    int maxChild = less(leftChild, rightChild) ? rightChild : leftChild;
    
    if (maxChild <= this -> N && less(k, maxChild)) {
        exch(k, maxChild);
        sink(maxChild);
    }
}

#endif /* HeapSort_hpp */
