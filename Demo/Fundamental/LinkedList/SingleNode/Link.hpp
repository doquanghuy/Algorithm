//
//  Link.hpp
//  Demo
//
//  Created by Quang Huy on 11/30/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef Link_hpp
#define Link_hpp

#include <stdio.h>
#include <iostream>
#include "Node.hpp"
#include "Iterator.hpp"

template <typename Item>
class Link: public Iterable<SingleNode<Item>*> {
    SingleNode<Item>* head;
    SingleNode<Item>* tail;
    int N;
public:
    Link(SingleNode<Item>* head = 0);
    Link(const Link<Item>& link);
    ~Link();
    int size() const;
    void insertFirstNode(SingleNode<Item>* node);
    void insertFirst(Item);
    void insertLast(Item);
    void insertAfter(SingleNode<Item>* previousNode, Item);
    void insertBefore(SingleNode<Item>* nextNode, Item);
    bool isEmpty();
    bool isOneNode();
    SingleNode<Item>* reverse(SingleNode<Item>*);
    void remove(SingleNode<Item>*); //Return new head
    SingleNode<Item>* getHead();
    SingleNode<Item>* getTail();
    SingleNode<Item>* removeFirst(); //Return new head
    SingleNode<Item>* removeLast(); //Return new head
    Iterator<SingleNode<Item>*>* iterator() const;
};

template <typename Item>
class LinkIterator: public Iterator<SingleNode<Item>*> {
    SingleNode<Item>* node;
public:
    LinkIterator<Item>(SingleNode<Item>* node);
    bool hasNext();
    SingleNode<Item>* next();
};

template <typename Item>
Link<Item>:: Link(SingleNode<Item>* head) {
    this -> head = head;
    this -> tail = head;
    this -> N = 0;
}

template <typename Item>
Link<Item>:: Link(const Link<Item>& link) {
    for (SingleNode<Item>* node = head; node != 0; node = node -> next) {
        insertLast(node -> item);
    }
    this -> N = link.size();
}

template <typename Item>
Link<Item>:: ~Link() {
//    std:: cout << "Deallocate Link" << std:: endl;
}

template <typename Item>
int Link<Item>:: size() const {
    return N;
}

template <typename Item>
bool Link<Item>:: isEmpty() {
    return !head;
}

template <typename Item>
bool Link<Item>:: isOneNode() {
    return head == tail;
}

template <typename Item>
SingleNode<Item>* Link<Item>:: getHead() {
    return head;
}

template <typename Item>
SingleNode<Item>* Link<Item>:: getTail() {
    return tail;
}

template <typename Item>
void Link<Item>:: insertAfter(SingleNode<Item>* previousNode, Item item) {
    if (!previousNode) {
        throw "Can not insert after null";
    }
    
    SingleNode<Item>* newNode = new SingleNode<Item>(item);
    SingleNode<Item>* oldNewNode = previousNode -> next;
    previousNode -> next = newNode;
    newNode -> next = oldNewNode;
    if (previousNode == tail) {
        tail = newNode;
    }
    N++;
}

template <typename Item>
void Link<Item>:: insertBefore(SingleNode<Item>* nextNode, Item item) {
    if (!nextNode) {
        throw "Can not insert before null";
    }

    SingleNode<Item>* previousNode;
    for (SingleNode<Item>* node = head; node != 0; node = node -> next) {
        if (node -> next == nextNode) {
            previousNode = node;
        }
    }
    SingleNode<Item>* newNode = new SingleNode<Item>(item);
    previousNode -> next = newNode;
    newNode -> next = nextNode;
    if (nextNode == head) {
        head = newNode;
    }
    N++;
}

template <typename Item>
void Link<Item>:: insertFirst(Item item) {
    SingleNode<Item>* newNode = new SingleNode<Item>(item);
    newNode -> next = head;
    head = newNode;
    if (!tail) {
        tail = newNode;
    }
    N++;
}

template <typename Item>
void Link<Item>:: insertFirstNode(SingleNode<Item>* node) {
    node -> next = head;
    head = node;
    if (!tail) {
        tail = node;
    }
    N++;
}

template <typename Item>
void Link<Item>:: insertLast(Item item) {
    SingleNode<Item>* newNode = new SingleNode<Item>(item);
    if (!head) {
        head = newNode;
    }
    if (tail) {
        tail -> next = newNode;
    }
    tail = newNode;
    N++;
}

template <typename Item>
SingleNode<Item>* Link<Item>:: removeFirst() {
    if (!head) {
        throw "Can not remove empty list";
    }
    
    SingleNode<Item>* newHead = head -> next;
    SingleNode<Item>* oldHead = head;
    head = newHead;
    if (!newHead) {
        tail = newHead;
    }
    N--;
    return oldHead;
}

template <typename Item>
SingleNode<Item>* Link<Item>:: removeLast() {
    if (!head) {
        throw "Can not remove empty list";
    }
    
    SingleNode<Item>* oldTail = tail;
    SingleNode<Item>* previousNode;
    for (SingleNode<Item>* node = head; node != 0; node = node -> next) {
        if (node -> next == tail) {
            previousNode = node;
        }
    }
    if (previousNode) {
        previousNode -> next = 0;
    }
    tail = previousNode;
    N--;
    return oldTail;
}

template <typename Item>
void Link<Item>:: remove(SingleNode<Item>* removedNode) {
    SingleNode<Item>* previousNode = nullptr;
    for (SingleNode<Item>* node = head; node != 0; node = node -> next) {
        if (node -> next == removedNode) {
            previousNode = node;
        }
    }
    
    if (removedNode == head) {
        head = removedNode -> next;
    }
    if (removedNode == tail) {
        tail = previousNode;
    }
    
    if (previousNode) {
        previousNode -> next = removedNode -> next;
    }
    N--;
}

template <typename Item>
SingleNode<Item>* Link<Item>:: reverse(SingleNode<Item>* x) {
    if (!x) {
        return nullptr;
    }
    if (!x -> next) {
        return x;
    }
    SingleNode<Item>* first = x;
    SingleNode<Item>* second = first -> next;
    SingleNode<Item>* newHead = reverse(second);
    if (second) {
        second -> next = first;
    }
    first -> next = 0;
    tail = first;
    head = newHead;
    return newHead;
}

template <typename Item>
Iterator<SingleNode<Item>*>* Link<Item>:: iterator() const {
    return new LinkIterator<Item>(head);
}

template <typename Item>
LinkIterator<Item>:: LinkIterator(SingleNode<Item>* node) {
    this -> node = new SingleNode<Item>();
    this -> node -> next = node;
}

template <typename Item>
bool LinkIterator<Item>:: hasNext() {
    return node -> next;
}

template <typename Item>
SingleNode<Item>* LinkIterator<Item>:: next() {
    node = node -> next;
    return node;
}

#endif /* Link_hpp */
