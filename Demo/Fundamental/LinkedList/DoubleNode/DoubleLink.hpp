//
//  DoubleLink.hpp
//  Demo
//
//  Created by Quang Huy on 11/30/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef DoubleLink_hpp
#define DoubleLink_hpp

#include <stdio.h>
#include "DoubleNode.hpp"
#include "Iterator.hpp"

template <typename Item>
class DoubleLink: public Iterable<DoubleNode<Item>*> {
    DoubleNode<Item>* head;
    DoubleNode<Item>* tail;
public:
    DoubleLink(DoubleNode<Item>* head);
    DoubleLink(const DoubleLink<Item>& link);
    ~DoubleLink();
    void insertFirstNode(DoubleNode<Item>* node);
    void insertFirst(Item);
    void insertLast(Item);
    void insertAfter(DoubleNode<Item>* previousNode, Item);
    void insertBefore(DoubleNode<Item>* nextNode, Item);
    void remove(DoubleNode<Item>*); //Return new head
    bool isEmpty();
    bool isOneNode();
    DoubleNode<Item>* reverse(DoubleNode<Item>*);
    DoubleNode<Item>* getHead();
    DoubleNode<Item>* getTail();
    DoubleNode<Item>* removeFirst(); //Return new head
    DoubleNode<Item>* removeLast(); //Return new head
    Iterator<DoubleNode<Item>*>* iterator() const;
};

template <typename Item>
class DoubleLinkIterator: public Iterator<DoubleNode<Item>*> {
    DoubleNode<Item>* node;
public:
    DoubleLinkIterator<Item>(DoubleNode<Item>* node);
    bool hasNext();
    DoubleNode<Item>* next();
};

template <typename Item>
DoubleLink<Item>:: DoubleLink(DoubleNode<Item>* head) {
    this -> head = head;
    this -> tail = head;
}

template <typename Item>
DoubleLink<Item>:: DoubleLink(const DoubleLink<Item>& link) {
    for (DoubleNode<Item>* node = head; node != 0; node = node -> next) {
        insertLast(node -> item);
    }
}

template <typename Item>
DoubleLink<Item>:: ~DoubleLink() {
    //TODO
}

template <typename Item>
bool DoubleLink<Item>:: isEmpty() {
    return !head;
}

template <typename Item>
bool DoubleLink<Item>:: isOneNode() {
    return head == tail;
}

template <typename Item>
DoubleNode<Item>* DoubleLink<Item>:: getHead() {
    return head;
}

template <typename Item>
DoubleNode<Item>* DoubleLink<Item>:: getTail() {
    return tail;
}

template <typename Item>
void DoubleLink<Item>:: insertAfter(DoubleNode<Item>* previousNode, Item item) {
    if (!previousNode) {
        throw "Can not insert after null";
    }
    
    DoubleNode<Item>* newNode = new DoubleNode<Item>(item);
    DoubleNode<Item>* oldNewNode = previousNode -> next;
    previousNode -> next = newNode;
    newNode -> next = oldNewNode;
    newNode -> previous = previousNode;
    if (previousNode == tail) {
        tail = newNode;
    }
}

template <typename Item>
void DoubleLink<Item>:: insertBefore(DoubleNode<Item>* nextNode, Item item) {
    if (!nextNode) {
        throw "Can not insert before null";
    }
    
    DoubleNode<Item>* previousNode = nextNode -> previous;
    DoubleNode<Item>* newNode = new DoubleNode<Item>(item);
    previousNode -> next = newNode;
    newNode -> next = nextNode;
    newNode -> previous = previousNode;
    if (nextNode == head) {
        head = newNode;
    }
}

template <typename Item>
void DoubleLink<Item>:: insertFirst(Item item) {
    DoubleNode<Item>* newNode = new DoubleNode<Item>(item);
    newNode -> next = head;
    head = newNode;
    if (!tail) {
        tail = newNode;
    }
}

template <typename Item>
void DoubleLink<Item>:: insertFirstNode(DoubleNode<Item>* node) {
    node -> next = head;
    head = node;
    if (!tail) {
        tail = node;
    }
}

template <typename Item>
void DoubleLink<Item>:: insertLast(Item item) {
    DoubleNode<Item>* newNode = new DoubleNode<Item>(item);
    if (!head) {
        head = newNode;
    }
    if (tail) {
        tail -> next = newNode;
    }
    newNode -> previous = tail;
    tail = newNode;
}

template <typename Item>
DoubleNode<Item>* DoubleLink<Item>:: removeFirst() {
    if (!head) {
        throw "Can not remove empty list";
    }
    DoubleNode<Item>* newHead = head -> next;
    DoubleNode<Item>* oldHead = head;
    if (!newHead) {
        tail = newHead;
    }
    head = newHead;
    return oldHead;
}

template <typename Item>
DoubleNode<Item>* DoubleLink<Item>:: removeLast() {
    if (!head) {
        throw "Can not remove empty list";
    }
    DoubleNode<Item>* oldTail = tail;
    DoubleNode<Item>* previousNode = tail -> previous;
    if (previousNode) {
        previousNode -> next = 0;
    }
    tail = previousNode;
    if (head == tail) {
        head = previousNode;
    }
    return oldTail;
}

template <typename Item>
void DoubleLink<Item>:: remove(DoubleNode<Item>* removedNode) {
    DoubleNode<Item>* previousNode = removedNode -> previous;
    if (removedNode == head) {
        head = removedNode -> next;
    }
    if (removedNode == tail) {
        tail = previousNode;
    }
    
    if (previousNode) {
        previousNode -> next = removedNode -> next;
        removedNode -> previous = previousNode;
    }
}

template <typename Item>
DoubleNode<Item>* DoubleLink<Item>:: reverse(DoubleNode<Item>* x) {
    if (!x) {
        return nullptr;
    }
    if (!x -> next) {
        return x;
    }
    DoubleNode<Item>* first = x;
    DoubleNode<Item>* second = first -> next;
    DoubleNode<Item>* newHead = reverse(second);
    if (second) {
        second -> next = first;
    }
    first -> next = 0;
    tail = first;
    head = newHead;
    return newHead;
}

template <typename Item>
Iterator<DoubleNode<Item>*>* DoubleLink<Item>:: iterator() const {
    return new DoubleLinkIterator<Item>(head);
}

template <typename Item>
DoubleLinkIterator<Item>:: DoubleLinkIterator(DoubleNode<Item>* node) {
    this -> node = new DoubleNode<Item>(0);
    this -> node -> next = node;
}

template <typename Item>
bool DoubleLinkIterator<Item>:: hasNext() {
    return node -> next;
}

template <typename Item>
DoubleNode<Item>* DoubleLinkIterator<Item>:: next() {
    node = node -> next;
    return node;
}
#endif /* Link_hpp */
