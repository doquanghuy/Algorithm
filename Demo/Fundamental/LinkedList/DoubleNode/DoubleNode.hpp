//
//  DoubleNode.hpp
//  Demo
//
//  Created by Quang Huy on 11/30/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef DoubleNode_hpp
#define DoubleNode_hpp

#include <stdio.h>

template <typename Item>
struct DoubleNode {
    DoubleNode(Item item): item(item), previous(nullptr), next(nullptr) {};    
    Item item;
    DoubleNode<Item>* previous;
    DoubleNode<Item>* next;
};
#endif /* DoubleNode_hpp */
