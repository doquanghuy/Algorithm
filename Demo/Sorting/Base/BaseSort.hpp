//
//  SortTemplate.hpp
//  Demo
//
//  Created by Quang Huy on 12/3/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef BaseSort_hpp
#define BaseSort_hpp

#include <stdio.h>
#include <iostream>

template <typename Item>
class BaseSort {
protected:
    Item* array;
    int N;
public:
    BaseSort(Item* array, int N);
    virtual void sort() = 0;
    virtual void exch(int i, int j);
    virtual bool isSorted();
    virtual Item itemAtIndex(int index) const;
    virtual int size() const;
};
template <typename Item>
std:: ostream& operator<<(std:: ostream& os, const BaseSort<Item>& sort);

template <typename Item>
BaseSort<Item>:: BaseSort(Item* array, int N) {
    this -> array = array;
    this -> N = N;
}

template <typename Item>
void BaseSort<Item>:: exch(int i, int j) {
    Item temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

template <typename Item>
bool BaseSort<Item>:: isSorted() {
    for (int i = 0; i < N - 1; i++) {
        if (!(array[i] < array[i + 1])) {
            return false;
        }
    }
    return true;
}

template <typename Item>
std:: ostream& operator<<(std:: ostream& os, const BaseSort<Item>& sort) {
    for (int i = 0; i < sort.size(); i++) {
        os << sort.itemAtIndex(i) << " ";
    }
    return os;
}

template <typename Item>
Item BaseSort<Item>:: itemAtIndex(int index) const {
    return array[index];
}

template <typename Item>
int BaseSort<Item>:: size() const {
    return N;
}
#endif /* BaseSort_hpp */
