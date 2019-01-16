//
//  WeightedUnion.hpp
//  Demo
//
//  Created by Quang Huy on 12/2/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef WeightedUnion_hpp
#define WeightedUnion_hpp

#include <stdio.h>
#include <vector>

class WeightedUnion {
    std:: vector<int> id;
    std:: vector<int> sizes;
    int count;
public:
    WeightedUnion();
    WeightedUnion(int N);
    int size(int p);
    void unionBetween(int p, int q);
    int find(int);
    bool connected(int p, int q);
    int numberOfGroups();
};

#endif /* WeightedUnion_hpp */
