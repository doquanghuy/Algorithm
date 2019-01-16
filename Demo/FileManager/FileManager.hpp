//
//  FileManager.hpp
//  Demo
//
//  Created by Quang Huy on 11/22/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#ifndef FileManager_hpp
#define FileManager_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class StdOut {
public:
    static void print(string s);
    static void println(string s);
    static void println();
};

class StdIn {
private:
    ifstream ifile;
public:
    StdIn();
    StdIn(string fileName);
    ~StdIn();
    int readInt();
    double readDouble();
    float readFloat();
    long readLong();
    bool readBoolean();
    char readChar();
    string readWord();
    string readLine();
    string readAll();
    string readString();
    bool isEmpty();
    bool hasNextLine();
};
#endif /* FileManager_hpp */
