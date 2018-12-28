//
//  MergeSort.hpp
//  Demo
//
//  Created by Quang Huy on 12/3/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef MergeSortTopDown_hpp
#define MergeSortTopDown_hpp

#include <stdio.h>
#include "BaseSort.hpp"

template <typename Item>
class MergeSortTopDown: public BaseSort<Item> {
public:
    MergeSortTopDown(Item* array, int N);
    void sort();
private:
    void merge(Item* array, int l, int m, int r);
    void sort(Item* array, int l, int r);
};

template <typename Item>
MergeSortTopDown<Item>:: MergeSortTopDown(Item* array, int N): BaseSort<Item>(array, N) {}

template <typename Item>
void MergeSortTopDown<Item>:: sort() {
    sort(this -> array, 0, this -> N - 1);
}

template <typename Item>
void MergeSortTopDown<Item>:: sort(Item *array, int l, int r) {
    if (l == r) {
        return;
    }
    int m = (l + r) / 2;
    sort(array, l, m);
    sort(array, m + 1, r);
    merge(array, l, m, r);
}

template <typename Item>
void MergeSortTopDown<Item>:: merge(Item *array, int l, int m, int r) {
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

#endif /* MergeSortTopDown_hpp */
