//
//  Constants.hpp
//  Demo
//
//  Created by Quang Huy on 11/27/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef Constant_hpp
#define Constant_hpp

#include <stdio.h>
#include <vector>
#include <string>
//MARK:
struct Constant {
    static std:: vector<std:: string> split(std:: string input, std:: string delim) {
        const char* sp = delim.c_str();
        const char* c_str = input.c_str();
        int length_input = int(input.length());
        int length_delim = int(delim.length());
        int indexs[length_input + 1];
        
        for (int i = 0; i < length_input; i++) {
            for (int j = i; j < i + length_delim; j++) {
                if (c_str[j] != sp[j - i]) {
                    j = i + length_delim;
                    continue;
                }
                if (j == i + length_delim - 1) {
                    indexs[i] = -1;
                }
            }
        }
        
        indexs[length_input] = -1;
        
        std:: vector<std:: string> res;
        char word[length_input + 1];
        int index = 0;
        int i = 0;
        while (i <= length_input) {
            if (indexs[i] == -1) {
                word[index] = 0;
                res.push_back(std:: string(word));
                word[0] = 0;
                index = 0;
                i += length_delim;
            } else {
                word[index++] = c_str[i++];
            }
        }
        
        return res;
    }
};

#endif /* Constant_hpp */
