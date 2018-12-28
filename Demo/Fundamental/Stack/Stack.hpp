//
//  Stack.hpp
//  Demo
//
//  Created by Quang Huy on 11/25/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
#include "Iterator.hpp"
#include "Array.hpp"

template <typename Item>
class Stack: public Iterable<Item> {
public:
    Stack<Item>();
    Stack<Item>(const Stack<Item>& stack);
    ~Stack<Item>();
    bool isEmpty();
    int size();
    void push(Item item);
    Item pop();
    Iterator<Item>* iterator() const;
    Stack<Item>& operator=(const Stack<Item>& stack);
private:
    Array<Item> items;
};

template <typename Item>
class StackIterator: public Iterator<Item> {
private:
    Iterator<Item>* iterator;
public:
    StackIterator(Iterator<Item>* iterator);
    bool hasNext();
    Item next();
};

template <typename Item>
Stack<Item>:: Stack() {
    //TODO
}

template <typename Item>
Stack<Item>:: Stack(const Stack<Item>& stack) {
    this -> items = stack.items;
}

template <typename Item>
Stack<Item>:: ~Stack() {
    std:: cout << "Deallocate Stack" << std:: endl;
}

template <typename Item>
Stack<Item>& Stack<Item>:: operator=(const Stack<Item> &stack) {
    if (this == &stack) {
        return *this;
    }
    this -> items = stack.items;
    return *this;
}

template <typename Item>
bool Stack<Item>:: isEmpty() {
    return items.size() == 0;
}

template <typename Item>
int Stack<Item>:: size() {
    return items.size();
}

template <typename Item>
void Stack<Item>:: push(Item item) {
    items.insert(item, 0);
}

template <typename Item>
Item Stack<Item>:: pop() {
    return items.removeFirst();
}

template <typename Item>
Iterator<Item>* Stack<Item>:: iterator() const {
    return new StackIterator<Item>(items.iterator());
}

//MARK: StackIterator
template <typename Item>
StackIterator<Item>:: StackIterator(Iterator<Item>* iterator) {
    this -> iterator = iterator;
}

template <typename Item>
bool StackIterator<Item>:: hasNext() {
    return iterator -> hasNext();
}

template <typename Item>
Item StackIterator<Item>:: next() {
    return iterator -> next();
}
#endif /* Stack_hpp */
