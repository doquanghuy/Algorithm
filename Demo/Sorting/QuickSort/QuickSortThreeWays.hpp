//
//  QuickSortThreeWays.hpp
//  Demo
//
//  Created by Quang Huy on 12/3/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef QuickSortThreeWays_hpp
#define QuickSortThreeWays_hpp

#include <stdio.h>
#include "BaseSort.hpp"

template <typename Item>
class QuickSortThreeWays: public BaseSort<Item> {
public:
    QuickSortThreeWays(Item* array, int N);
    void sort();
private:
    void sort(Item* array, int l, int r);
    int partion(Item* array, int l, int r);
};

template <typename Item>
inline QuickSortThreeWays<Item>:: QuickSortThreeWays(Item* array, int N): BaseSort<Item>(array, N) {}

template <typename Item>
inline void QuickSortThreeWays<Item>:: sort() {
    sort(this -> array, 0, this -> N - 1);
}

template <typename Item>
inline void QuickSortThreeWays<Item>:: sort(Item *array, int l, int r) {
    if (l >= r) return; // Only examine if have more than 2 elements;
    
    int lt = l; // Partion index;
    int i = l + 1; // Next index to examine;
    int gt = r; // element that bigger than lt is count down from the right hand;
    Item s = array[l];
    
    while (i <= gt) {
        if (array[i] < s) this -> exch(lt++, i++);
        else if (array[i] > s) this -> exch(i, gt--);
        else i++;
    }
    
    //After running while loop, need to make sure that lt is the partion, i and gt can be over range [l...r], however, it's not important because we only take care of lt
    
    sort(array, l, lt - 1);
    sort(array, lt + 1, r);
}

#endif /* QuickSortThreeWays_hpp */
