//
//  Node.hpp
//  Demo
//
//  Created by Quang Huy on 11/30/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <iostream>
#include <string>

template <typename Item>
struct SingleNode {
    SingleNode(): item(Item{}) {};
    SingleNode(Item item): item(item), next(0) {};
    Item item;
    SingleNode<Item>* next;
};

#endif /* Node_hpp */
