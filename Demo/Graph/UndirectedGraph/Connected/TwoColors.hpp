//
//  TwoColors.hpp
//  Demo
//
//  Created by Quang Huy on 12/20/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef TwoColors_hpp
#define TwoColors_hpp

#include <stdio.h>
class Graph;

class TwoColors {
public:
    TwoColors(Graph g, int s);
    bool isTwoColors();
private:
    void dfs(Graph g, int s);
    bool* markedVertices;
    bool* colors;
    bool _isTwoColors;
};
#endif /* TwoColors_hpp */
