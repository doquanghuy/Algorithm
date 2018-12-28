//
//  TransitiveClosure.hpp
//  Demo
//
//  Created by Quang Huy on 12/24/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef TransitiveClosure_hpp
#define TransitiveClosure_hpp

#include <stdio.h>
class Digraph;
class DirectedDFS;

class TransitiveClosure {
public:
    TransitiveClosure(Digraph g);
    bool reachable(int v, int w);
private:
    DirectedDFS** ddfs;
};

#endif /* TransitiveClosure_hpp */
