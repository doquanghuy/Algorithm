//
//  MergeSortBottomUp.hpp
//  Demo
//
//  Created by Quang Huy on 12/3/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef MergeSortBottomUp_hpp
#define MergeSortBottomUp_hpp

#include <stdio.h>
#include "BaseSort.hpp"

template <typename Item>
class MergeSortBottomUp: public BaseSort<Item> {
public:
    MergeSortBottomUp(Item* array, int N);
    void sort();
private:
    void merge(Item* array, int l, int m, int r);
};

template <typename Item>
MergeSortBottomUp<Item>:: MergeSortBottomUp(Item* array, int N): BaseSort<Item>(array, N) {}

template <typename Item>
void MergeSortBottomUp<Item>:: sort() {
    for (int size = 1; size < this -> N; size *= 2) {
        for (int lo = 0; lo < this -> N - size; lo += size * 2) {
            merge(this -> array, lo, lo + size - 1, min(lo + size * 2 - 1, this -> N - 1));
        }
    }
}

template <typename Item>
void MergeSortBottomUp<Item>:: merge(Item *array, int l, int m, int r) {
    int i = l;
    int j = m + 1;
    Item aux[this -> N];
    
    for (int k = 0; k < this -> N; k++) {
        aux[k] = array[k];
    }
    
    for (int k = l; k <= r; k++) {
        if (i > m) {
            array[k] = aux[j++];
        } else if (j > r) {
            array[k] = aux[i++];
        } else if (aux[i] < aux[j]) {
            array[k] = aux[i++];
        } else {
            array[k] = aux[j++];
        }
    }
}

#endif /* MergeSortBottomUp_hpp */
