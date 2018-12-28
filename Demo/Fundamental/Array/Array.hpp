//
//  Array.hpp
//  Demo
//
//  Created by Quang Huy on 11/25/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef Array_hpp
#define Array_hpp

#include <stdio.h>
#include <algorithm>
#include "Iterator.hpp"

//MARK: Array
template <typename Item>
class Array: public Iterable<Item> {
public:
    Array(const Item* items, int size);
    Array();
    Array(const Array& arr);
    ~Array();
    Array<Item>& operator=(const Array<Item> &array);
    
    int size() const;
    void append(const Item item);
    void insert(const Item item, int index);
    void makeEmpty();
    void reverseArray();
    bool isEmpty() const;
    bool contains(const Item item) const;
    
    Item remove(int index);
    Item removeFirst();
    Item removeLast();
    Item itemAtIdex(int index) const;
    
    Array<Item> reverse() const;
    Iterator<Item>* iterator() const;
private:
    int N;
    int actualSize;
    Item* items;
    void resize(int max);
};

//MARK: ArrayIterator
template <typename Item>
class ArrayIterator: public Iterator<Item> {
public:
    ArrayIterator(Item* items, int size);
    ~ArrayIterator();
    bool hasNext();
    Item next();
    void remove();
private:
    Item* items;
    int i;
    int N;
};

//MARK: Array Constructors
template <typename Item>
Array<Item>:: Array(): Iterable<Item>() {
    this -> N = 0;
    this -> actualSize = 1;
    this -> items = new Item[actualSize];
}

template <typename Item>
Array<Item>:: Array(const Array& arr) {
    this -> N = arr.N;
    this -> actualSize = arr.actualSize;
    this -> items = new Item[actualSize];
    for (int i = 0; i < N; i++) {
        this -> items[i] = arr.items[i];
    }
}

template <typename Item>
Array<Item>:: Array(const Item* items, int size): Iterable<Item>() {
    this -> N = size;
    this -> actualSize = size;
    this -> items = new Item[actualSize];
    for (int i = 0; i < N; i++) {
        this -> items[i] = items[i];
    }
}

template <typename Item>
Array<Item>:: ~Array() {
    delete [] items;
}

//MARK: Array Operator =
template <typename Item>
Array<Item>& Array<Item>:: operator=(const Array<Item> &array) {
    if (this == &array) {
        return *this;
    }

    this -> actualSize = array.actualSize;
    this -> N = array.N;
    this -> items = new Item[actualSize];

    for (int i = 0; i < this -> N; i++) {
        this -> items[i] = array.items[i];
    }
    return *this;
}

//MARK: Array functions
template <typename Item>
bool Array<Item>:: isEmpty() const {
    return N == 0;
}

template <typename Item>
bool Array<Item>:: contains(const Item item) const {
    for (int i = 0; i < this -> size(); i++) {
        if (itemAtIdex(i) == item) {
            return true;
        }
    }
    return false;
}

template <typename Item>
void Array<Item>:: resize(int max) {
    Item *newItems = new Item[max];
    for (int i = 0; i < std:: min(max, actualSize); i++) {
        newItems[i] = items[i];
    }
    delete [] items;
    items = newItems;
    actualSize = max;
}

template <typename Item>
int Array<Item>:: size() const {
    return N;
}

template <typename Item>
void Array<Item>:: append(const Item item) {
    if (N == actualSize) {
        resize(2 * actualSize);
    }
    items[N++] = item;
}

template <typename Item>
void Array<Item>:: insert(const Item item, int index) {
    if (index <= N) {
        if (N == actualSize) {
            resize(actualSize * 2);
        }
        N++;
        for (int i = N - 1; i >= 0; i--) {
            if (i == index) {
                items[i] = item;
            } else if (i > index) {
                items[i] = items[i - 1];
            }
        }
    } else {
        throw "Index is over the length of array";
    }
}

template <typename Item>
Item Array<Item>:: remove(int index) {
    if (index < N) {
        Item removedItem = items[index];
        N--;
        if (N > 0 && N == actualSize / 4) {
            resize(actualSize / 2);
        }
        for (int i = 0; i < N; i++) {
            if (i >= index) {
                items[i] = items[i + 1];
            }
        }
        return removedItem;
    } else {
        throw "Index is over the length of array";
    }
}

template <typename Item>
Item Array<Item>:: removeFirst() {
    return remove(0);
}

template <typename Item>
Item Array<Item>:: itemAtIdex(int index) const {
    if (index >= 0 && index < this -> size()) {
        return this -> items[index];
    }
    throw "Index is over the length of array";
}

template <typename Item>
Item Array<Item>:: removeLast() {
    return remove(N - 1);
}

template <typename Item>
void Array<Item>:: makeEmpty() {
    N = 0;
    actualSize = 1;
    delete [] items;
    items = new Item[actualSize];
}

template <typename Item>
void Array<Item>:: reverseArray() {
    Item reverseValues[actualSize];
    for (int i = N - 1; i >= 0; i --) {
        reverseValues[i] = items[N - i - 1];
    }
    items = reverseValues;
}

template <typename Item>
Array<Item> Array<Item>:: reverse() const {
    Item reverseValues[actualSize];
    for (int i = N - 1; i >= 0; i --) {
        reverseValues[i] = items[N - i - 1];
    }
    return reverseValues;
}

template <typename Item>
Iterator<Item>* Array<Item>:: iterator() const {
    ArrayIterator<Item>* iterator =  new ArrayIterator<Item>(items, N);
    return iterator;
}

//MARK: ArrayIterator
template <typename Item>
ArrayIterator<Item>:: ArrayIterator(Item* items, int size) {
    this -> items = items;
    this -> i = -1;
    this -> N = size;
}

//MARK: ArrayIterator
template <typename Item>
bool ArrayIterator<Item>:: hasNext() {
    return i < N - 1;
}

template <typename Item>
Item ArrayIterator<Item>:: next() {
    if (hasNext()) {
        return items[++i];
    } else {
        throw "Index is over the length of array";
    }
}

#endif /* Array_hpp */
