//
//  Queue+DoubleLinkedList.hpp
//  Demo
//
//  Created by Quang Huy on 12/1/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef Queue_DoubleLinkedList_hpp
#define Queue_DoubleLinkedList_hpp

#include <stdio.h>
#include "Iterator.hpp"
#include "Link.hpp"

template<typename Item>
class DoubleLinkQueue: public Iterable<Item> {
    Link<Item> link;
public:
    DoubleLinkQueue<Item>();
    DoubleLinkQueue<Item>(const DoubleLinkQueue<Item>& stack);
    ~DoubleLinkQueue<Item>();
    DoubleNode<Item>* first();
    int size();
    bool isEmpty();
    void enqueue(Item item);
    Item dequeue();
    Iterator<Item>* iterator() const;
    DoubleLinkQueue<Item>& operator=(const DoubleLinkQueue<Item>& stack);
};

template <typename Item>
class DoubleLinkQueueIterator: public Iterator<Item> {
private:
    Iterator<DoubleNode<Item>*>* iterator;
public:
    DoubleLinkQueueIterator(Iterator<DoubleNode<Item>*>* items);
    bool hasNext();
    Itemnext();
};

template <typename Item>
DoubleLinkQueue<Item>:: DoubleLinkQueue() {
    link = Link<Item>();
}

template <typename Item>
DoubleLinkQueue<Item>:: DoubleLinkQueue(const DoubleLinkQueue<Item>& stack) {
    this -> link = stack -> link;
}

template <typename Item>
DoubleLinkQueue<Item>:: ~DoubleLinkQueue() {
    std:: cout << "Deallocate DoubleLinkQueue" << std:: endl;
}

template <typename Item>
DoubleLinkQueue<Item>& DoubleLinkQueue<Item>:: operator=(const DoubleLinkQueue<Item> &stack) {
    if (this == &stack) {
        return *this;
    }
    this -> link = stack.link;
    return *this;
}

template <typename Item>
DoubleNode<Item>* DoubleLinkQueue<Item>:: first() {
    return link.getHead();
}

template <typename Item>
bool DoubleLinkQueue<Item>:: isEmpty() {
    return link.isEmpty();
}

template <typename Item>
int DoubleLinkQueue<Item>:: size() {
    return link.size();
}

template <typename Item>
void DoubleLinkQueue<Item>:: enqueue(Item item) {
    link.insertLast(item);
}

template <typename Item>
Item DoubleLinkQueue<Item>:: dequeue() {
    return link.removeFirst() -> item;
}

template <typename Item>
Iterator<Item>* DoubleLinkQueue<Item>:: iterator() const {
    return new DoubleLinkQueueIterator<Item>(link.iterator());
}

//MARK: StackIterator
template <typename Item>
DoubleLinkQueueIterator<Item>:: DoubleLinkQueueIterator(Iterator<DoubleNode<Item>*>* iterator) {
    this -> iterator = iterator;
}

template <typename Item>
bool DoubleLinkQueueIterator<Item>:: hasNext() {
    return iterator -> hasNext();
}

template <typename Item>
Item DoubleLinkQueueIterator<Item>:: next() {
    return iterator -> next();
}
#endif /* Queue_DoubleLinkedList_hpp */
