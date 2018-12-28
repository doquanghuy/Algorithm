//
//  Stack+DoubleLinkedList.hpp
//  Demo
//
//  Created by Quang Huy on 12/1/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef Stack_DoubleLinkedList_hpp
#define Stack_DoubleLinkedList_hpp

#include <stdio.h>
template<typename Item>
class DoubleLinkStack: public Iterable<Item> {
    Link<Item> link;
public:
    DoubleLinkStack<Item>();
    DoubleLinkStack<Item>(const DoubleLinkStack<Item>& stack);
    ~DoubleLinkStack<Item>();
    DoubleNode<Item>* first();
    int size();
    bool isEmpty();
    void push(Item item);
    Item pop();
    Iterator<Item>* iterator() const;
    DoubleLinkStack<Item>& operator=(const DoubleLinkStack<Item>& stack);
};

template <typename Item>
class DoubleLinkStackIterator: public Iterator<Item*> {
private:
    Iterator<DoubleNode<Item>*>* iterator;
public:
    DoubleLinkStackIterator(Iterator<DoubleNode<Item>*>* items);
    bool hasNext();
    Item next();
};

template <typename Item>
DoubleLinkStack<Item>:: DoubleLinkStack() {
    link = Link<Item>();
}

template <typename Item>
DoubleLinkStack<Item>:: DoubleLinkStack(const DoubleLinkStack<Item>& stack) {
    this -> link = stack -> link;
}

template <typename Item>
DoubleLinkStack<Item>:: ~DoubleLinkStack() {
    std:: cout << "Deallocate DoubleLinkStack" << std:: endl;
}

template <typename Item>
DoubleLinkStack<Item>& DoubleLinkStack<Item>:: operator=(const DoubleLinkStack<Item> &stack) {
    if (this == &stack) {
        return *this;
    }
    this -> link = stack.link;
    return *this;
}

template <typename Item>
DoubleNode<Item>* DoubleLinkStack<Item>:: first() {
    return link.getHead();
}

template <typename Item>
bool DoubleLinkStack<Item>:: isEmpty() {
    return link.isEmpty();
}

template <typename Item>
int DoubleLinkStack<Item>:: size() {
    return link.size();
}

template <typename Item>
void DoubleLinkStack<Item>:: push(Item item) {
    link.insertFirst(item);
}

template <typename Item>
Item DoubleLinkStack<Item>:: pop() {
    return link.removeFirst() -> item;
}

template <typename Item>
Iterator<Item>* DoubleLinkStack<Item>:: iterator() const {
    return new DoubleLinkStackIterator<Item>(link.iterator());
}

//MARK: StackIterator
template <typename Item>
DoubleLinkStackIterator<Item>:: DoubleLinkStackIterator(Iterator<DoubleNode<Item>*>* iterator) {
    this -> iterator = iterator;
}

template <typename Item>
bool DoubleLinkStackIterator<Item>:: hasNext() {
    return iterator -> hasNext();
}

template <typename Item>
Item DoubleLinkStackIterator<Item>:: next() {
    return iterator -> next() -> item;
}

#endif /* Stack_DoubleLinkedList_hpp */
