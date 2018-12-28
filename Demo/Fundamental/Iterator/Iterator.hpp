//
//  Array.hpp
//  Demo
//
//  Created by Quang Huy on 11/25/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef Iterator_hpp
#define Iterator_hpp

#include <stdio.h>

//MARK: Iterator
template <typename Item>
class Iterator {
public:
    virtual bool hasNext() = 0;
    virtual Item next() = 0;
};

//MARK: Iterable
template <typename Item>
class Iterable {
public:
    virtual Iterator<Item>* iterator() const = 0;
};
#endif /* Iterator_hpp */
