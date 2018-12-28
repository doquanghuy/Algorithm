//
//  Queue.hpp
//  Demo
//
//  Created by Quang Huy on 11/26/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>
#include "Iterator.hpp"

//MARK: Queue
template <typename Item>
class Queue: public Iterable<Item> {
public:
    Queue<Item>();
    Queue<Item>(const Queue<Item>& queue);
    ~Queue<Item>();
    Queue<Item>& operator=(Queue<Item>& queue);
    void enqueue(Item item);
    Item dequeue();
    bool isEmpty();
    int size();
    Iterator<Item>* iterator() const;
private:
    Array<Item> items;
};

//MARK: QueueIterator
template <typename Item>
class QueueIterator: public Iterator<Item> {
public:
    QueueIterator(Iterator<Item>* iterator);
    bool hasNext();
    Item next();
private:
    Iterator<Item>* iterator;
};

//MARK: Queue
template <typename Item>
Queue<Item>:: Queue() {
    //TODO
}

template <typename Item>
Queue<Item>:: Queue(const Queue<Item>& queue) {
    this -> items = queue.items;
}

template <typename Item>
Queue<Item>:: ~Queue() {
    
}

template <typename Item>
Queue<Item>& Queue<Item>:: operator=(Queue<Item>& queue) {
    if (this == &queue) {
        return *this;
    }
    delete items;
    this -> items = queue.items;
    return *this;
}

template <typename Item>
void Queue<Item>:: enqueue(Item item) {
    items.append(item);
}

template <typename Item>
Item Queue<Item>:: dequeue() {
    return items.removeLast();
}

template <typename Item>
bool Queue<Item>:: isEmpty() {
    return items.isEmpty();
}

template <typename Item>
int Queue<Item>:: size() {
    return items.size();
}

template <typename Item>
Iterator<Item>* Queue<Item>:: iterator() const {
    return new QueueIterator<Item>(&items);
}

//MARK: QueueIterator
template <typename Item>
QueueIterator<Item>:: QueueIterator(Iterator<Item>* iterator) {
    this -> iterator = iterator;
}

template <typename Item>
bool QueueIterator<Item>:: hasNext() {
    return !iterator -> hasNext();
}

template <typename Item>
Item QueueIterator<Item>:: next() {
    return iterator -> next();
}
#endif /* Queue_hpp */
