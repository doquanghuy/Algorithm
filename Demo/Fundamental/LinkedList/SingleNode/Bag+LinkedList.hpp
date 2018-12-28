//
//  Bag+LinkedList.hpp
//  Demo
//
//  Created by Quang Huy on 11/30/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef Bag_LinkedList_hpp
#define Bag_LinkedList_hpp

#include <stdio.h>
#include <iostream>
#include "Iterator.hpp"
#include "Link.hpp"

template <typename Item>
class LinkBag: public Iterable<Item> {
    Link<Item> link;
public:
    LinkBag<Item>();
    LinkBag<Item>(const LinkBag<Item>& bag);
    ~LinkBag<Item>();
    SingleNode<Item>* first();
    int size();
    bool isEmpty();
    void add(Item item);
    Iterator<Item>* iterator() const;
    LinkBag<Item>& operator=(const LinkBag<Item>& bag);
};

template <typename Item>
class LinkBagIterator: public Iterator<Item> {
private:
    Iterator<SingleNode<Item>*>* iterator;
public:
    LinkBagIterator(Iterator<SingleNode<Item>*>* items);
    bool hasNext();
    Item next();
};

template <typename Item>
LinkBag<Item>:: LinkBag() {
    link = Link<Item>();
}

template <typename Item>
LinkBag<Item>:: LinkBag(const LinkBag<Item>& bag) {
    this -> link = bag -> link;
}

template <typename Item>
LinkBag<Item>:: ~LinkBag() {
//    std:: cout << "Deallocate LinkBag" << std:: endl;
}

template <typename Item>
LinkBag<Item>& LinkBag<Item>:: operator=(const LinkBag<Item>& bag) {
    if (this == &bag) {
        return *this;
    }
    this -> link = bag.link;
    return *this;
}

template <typename Item>
SingleNode<Item>* LinkBag<Item>:: first() {
    return link.getHead();
}

template <typename Item>
bool LinkBag<Item>:: isEmpty() {
    return link.isEmpty();
}

template <typename Item>
int LinkBag<Item>:: size() {
    return link.size();
}

template <typename Item>
void LinkBag<Item>:: add(Item item) {
    link.insertFirst(item);
}

template <typename Item>
Iterator<Item>* LinkBag<Item>:: iterator() const {
    return new LinkBagIterator<Item>(link.iterator());
}

//MARK: BagIterator
template <typename Item>
LinkBagIterator<Item>:: LinkBagIterator(Iterator<SingleNode<Item>*>* iterator) {
    this -> iterator = iterator;
}

template <typename Item>
bool LinkBagIterator<Item>:: hasNext() {
    return iterator -> hasNext();
}

template <typename Item>
Item LinkBagIterator<Item>:: next() {
    return iterator -> next() -> item;
}
#endif /* Bag_LinkedList_hpp */
