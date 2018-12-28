//
//  QuickUnion.hpp
//  Demo
//
//  Created by Quang Huy on 12/2/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef QuickUnion_hpp
#define QuickUnion_hpp

#include <stdio.h>
#include <vector>

class QuickUnion {
    std:: vector<int> id;
    int count;
public:
    QuickUnion(int N);
    void unionBetween(int p, int q);
    int find(int);
    bool connected(int p, int q);
    int numberOfGroups();
};

#endif /* QuickUnion_hpp */
