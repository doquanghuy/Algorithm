//
//  SelectionSort.hpp
//  Demo
//
//  Created by Quang Huy on 12/3/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef SelectionSort_hpp
#define SelectionSort_hpp

#include <stdio.h>
#include "BaseSort.hpp"

template <typename Item>
class SelectionSort: public BaseSort<Item> {
public:
    SelectionSort(Item* array, int N);
    void sort();
};

template <typename Item>
SelectionSort<Item>:: SelectionSort(Item* array, int N): BaseSort<Item>(array, N) {}

template <typename Item>
void SelectionSort<Item>:: sort() {
    for (int i = 0; i < this -> N; i++) {
        int min = i;
        for (int j = i + 1; j < this -> N; j++) {
            if (this -> array[j] < this -> array[min]) {
                min = j;
            }
        }
        this -> exch(i, min);
    }
}

#endif /* SelectionSort_hpp */
