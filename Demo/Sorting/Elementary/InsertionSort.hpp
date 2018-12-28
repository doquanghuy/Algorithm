//
//  InsertionSort.hpp
//  Demo
//
//  Created by Quang Huy on 12/3/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef InsertionSort_hpp
#define InsertionSort_hpp

#include <stdio.h>
#include "BaseSort.hpp"

template <typename Item>
class InsertionSort: public BaseSort<Item> {
public:
    InsertionSort(Item* array, int N);
    void sort();
};

template <typename Item>
InsertionSort<Item>:: InsertionSort(Item* array, int N): BaseSort<Item>(array, N) {}

template <typename Item>
void InsertionSort<Item>:: sort() {
    for (int i = 1; i < this -> N; i++) {
        for (int j = i; j > 0 && this -> array[j] < this -> array[j - 1]; j--) {
            this -> exch(j, j - 1);
        }
    }
}

#endif /* InsertionSort_hpp */
