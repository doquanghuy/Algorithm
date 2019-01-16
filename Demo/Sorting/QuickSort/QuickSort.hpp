//
//  QuickSort.hpp
//  Demo
//
//  Created by Quang Huy on 12/3/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef QuickSort_hpp
#define QuickSort_hpp

#include <stdio.h>
#include "BaseSort.hpp"

template <typename Item>
class QuickSort: public BaseSort<Item> {
public:
    QuickSort(Item* array, int N);
    void sort();
private:
    void sort(Item* array, int l, int r);
    int partion(Item* array, int l, int r);
};

template <typename Item>
QuickSort<Item>:: QuickSort(Item* array, int N): BaseSort<Item>(array, N) {}

template <typename Item>
void QuickSort<Item>:: sort() {
    sort(this -> array, 0, this -> N - 1);
}

template <typename Item>
int QuickSort<Item>:: partion(Item *array, int l, int r) {
    int i = l + 1;
    int j = r;
    Item s = array[l];
    
    while (true) {
        while (array[i] < s && i < r) i++;
        while (s < array[j] && j > l) j--;
        if (i >= j) break;
        this -> exch(i, j);
    }
    this -> exch(l, j); // because l is the first element, so we need to make sure that j is always smaller than or euqal to l;
    return j;
}

template <typename Item>
void QuickSort<Item>:: sort(Item *array, int l, int r) {
    if (l >= r) {
        return;
    }
    int p = partion(array, l, r);
    sort(array, l, p - 1);
    sort(array, p + 1, r);
}

#endif /* QuickSort_hpp */
