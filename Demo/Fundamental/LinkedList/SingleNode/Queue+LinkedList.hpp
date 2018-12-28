//
//  Queue+LinkedList.hpp
//  Demo
//
//  Created by Quang Huy on 11/30/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef Queue_LinkedList_hpp
#define Queue_LinkedList_hpp

#include <stdio.h>
#include "Iterator.hpp"
#include "Link.hpp"

template<typename Item>
class LinkQueue: public Iterable<Item> {
    Link<Item> link;
public:
    LinkQueue<Item>();
    LinkQueue<Item>(const LinkQueue<Item>& queue);
    ~LinkQueue<Item>();
    SingleNode<Item>* first();
    int size();
    bool isEmpty();
    void enqueue(Item item);
    Item dequeue();
    Iterator<Item>* iterator() const;
    LinkQueue<Item>& operator=(const LinkQueue<Item>& queue);
};

template <typename Item>
class LinkQueueIterator: public Iterator<Item> {
private:
    Iterator<SingleNode<Item>*>* iterator;
public:
    LinkQueueIterator(Iterator<SingleNode<Item>*>* items);
    bool hasNext();
    Item next();
};

template <typename Item>
LinkQueue<Item>:: LinkQueue() {
    link = Link<Item>();
}

template <typename Item>
LinkQueue<Item>:: LinkQueue(const LinkQueue<Item>& queue) {
    this -> link = queue -> link;
}

template <typename Item>
LinkQueue<Item>:: ~LinkQueue() {
//    std:: cout << "Deallocate LinkQueue" << std:: endl;
}

template <typename Item>
LinkQueue<Item>& LinkQueue<Item>:: operator=(const LinkQueue<Item> &queue) {
    if (this == &queue) {
        return *this;
    }
    this -> link = queue.link;
    return *this;
}

template <typename Item>
SingleNode<Item>* LinkQueue<Item>:: first() {
    return link.getHead();
}

template <typename Item>
bool LinkQueue<Item>:: isEmpty() {
    return link.isEmpty();
}

template <typename Item>
int LinkQueue<Item>:: size() {
    return link.size();
}

template <typename Item>
void LinkQueue<Item>:: enqueue(Item item) {
    link.insertLast(item);
}

template <typename Item>
Item LinkQueue<Item>:: dequeue() {
    return link.removeFirst() -> item;
}

template <typename Item>
Iterator<Item>* LinkQueue<Item>:: iterator() const {
    return new LinkQueueIterator<Item>(link.iterator());
}

//MARK: QueueIterator
template <typename Item>
LinkQueueIterator<Item>:: LinkQueueIterator(Iterator<SingleNode<Item>*>* iterator) {
    this -> iterator = iterator;
}

template <typename Item>
bool LinkQueueIterator<Item>:: hasNext() {
    return iterator -> hasNext();
}

template <typename Item>
Item LinkQueueIterator<Item>:: next() {
    return iterator -> next() -> item;
}

#endif /* Queue_LinkedList_hpp */
