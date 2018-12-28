//
//  Stack+LinkedList.hpp
//  Demo
//
//  Created by Quang Huy on 11/30/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef Stack_LinkedList_hpp
#define Stack_LinkedList_hpp

#include <stdio.h>
#include <iostream>
#include "Iterator.hpp"
#include "Link.hpp"

template<typename Item>
class LinkStack: public Iterable<Item> {
    Link<Item> link;
public:
    LinkStack<Item>();
    LinkStack<Item>(const LinkStack<Item>& stack);
    ~LinkStack<Item>();
    SingleNode<Item>* first();
    int size();
    bool isEmpty();
    void push(Item item);
    Item pop();
    Iterator<Item>* iterator() const;
    LinkStack<Item>& operator=(const LinkStack<Item>& stack);
};

template <typename Item>
class LinkStackIterator: public Iterator<Item> {
private:
    Iterator<SingleNode<Item>*>* iterator;
public:
    LinkStackIterator(Iterator<SingleNode<Item>*>* items);
    bool hasNext();
    Item next();
};

template <typename Item>
LinkStack<Item>:: LinkStack() {
    link = Link<Item>();
}

template <typename Item>
LinkStack<Item>:: LinkStack(const LinkStack<Item>& stack) {
    this -> link = stack.link;
}

template <typename Item>
LinkStack<Item>:: ~LinkStack() {
//    std:: cout << "Deallocate LinkStack" << std:: endl;
}

template <typename Item>
LinkStack<Item>& LinkStack<Item>:: operator=(const LinkStack<Item> &stack) {
    if (this == &stack) {
        return *this;
    }
    this -> link = stack.link;
    return *this;
}

template <typename Item>
SingleNode<Item>* LinkStack<Item>:: first() {
    return link.getHead();
}

template <typename Item>
bool LinkStack<Item>:: isEmpty() {
    return link.isEmpty();
}

template <typename Item>
int LinkStack<Item>:: size() {
    return link.size();
}

template <typename Item>
void LinkStack<Item>:: push(Item item) {
    link.insertFirst(item);
}

template <typename Item>
Item LinkStack<Item>:: pop() {
    return link.removeFirst() -> item;
}

template <typename Item>
Iterator<Item>* LinkStack<Item>:: iterator() const {
    return new LinkStackIterator<Item>(link.iterator());
}

//MARK: StackIterator
template <typename Item>
LinkStackIterator<Item>:: LinkStackIterator(Iterator<SingleNode<Item>*>* iterator) {
    this -> iterator = iterator;
}

template <typename Item>
bool LinkStackIterator<Item>:: hasNext() {
    return iterator -> hasNext();
}

template <typename Item>
Item LinkStackIterator<Item>:: next() {
    return iterator -> next() -> item;
}

#endif /* Stack_LinkedList_hpp */
