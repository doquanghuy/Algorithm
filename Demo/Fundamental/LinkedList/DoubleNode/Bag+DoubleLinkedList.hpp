//
//  Bag+DoubleLinkedList.hpp
//  Demo
//
//  Created by Quang Huy on 12/1/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef Bag_DoubleLinkedList_hpp
#define Bag_DoubleLinkedList_hpp

#include <stdio.h>
template <typename Item>
class DoubleLinkBag: public Iterable<Item> {
public:
    DoubleLinkBag<Item>();
    DoubleLinkBag<Item>(const DoubleLinkBag<Item>& bag);
    ~DoubleLinkBag<Item>();
    DoubleNode<Item>* first();
    int size();
    bool isEmpty();
    void add(Item item);
    Iterator<Item>* iterator() const;
    DoubleLinkBag<Item>& operator=(const DoubleLinkBag<Item>& bag);
}

template <typename Item>
class DoubleLinkBagIterator: public Iterator<Item> {
private:
    Iterator<DoubleNode<Item>*>* iterator;
public:
    DoubleLinkBagIterator(Iterator<DoubleNode<Item>*>* items);
    bool hasNext();
    Item next();
};

template <typename Item>
DoubleLinkBag<Item>:: DoubleLinkBag() {
    link = Link<Item>();
}

template <typename Item>
DoubleLinkBag<Item>:: DoubleLinkBag(const DoubleLinkBag<Item>& bag) {
    this -> link = bag -> link;
}

template <typename Item>
DoubleLinkBag<Item>:: ~DoubleLinkBag() {
    std:: cout << "Deallocate DoubleLinkBag" << std:: endl;
}

template <typename Item>
DoubleLinkBag<Item>& DoubleLinkBag<Item>:: operator=(const DoubleLinkBag<Item>& bag) {
    if (this == &bag) {
        return *this;
    }
    this -> link = bag.link;
    return *this;
}

template <typename Item>
DoubleNode<Item>* DoubleLinkBag<Item>:: first() {
    return link.getHead();
}

template <typename Item>
bool DoubleLinkBag<Item>:: isEmpty() {
    return link.isEmpty();
}

template <typename Item>
int DoubleLinkBag<Item>:: size() {
    return link.size();
}

template <typename Item>
void DoubleLinkBag<Item>:: add(Item item) {
    link.insertFirst(item);
}

template <typename Item>
Iterator<Item>* DoubleLinkBag<Item>:: iterator() const {
    return new DoubleLinkBagIterator<Item>(link.iterator());
}

//MARK: BagIterator
template <typename Item>
DoubleLinkBagIterator<Item>:: DoubleLinkBagIterator(Iterator<DoubleNode<Item>*>* iterator) {
    this -> iterator = iterator;
}

template <typename Item>
bool DoubleLinkBagIterator<Item>:: hasNext() {
    return iterator -> hasNext();
}

template <typename Item>
Item DoubleLinkBagIterator<Item>:: next() {
    return iterator -> next() -> item;
}
#endif /* Bag_DoubleLinkedList_hpp */
