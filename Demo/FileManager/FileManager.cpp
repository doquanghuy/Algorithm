//
//  FileManager.cpp
//  Demo
//
//  Created by Quang Huy on 11/22/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#include "FileManager.hpp"

//StdOut implementation
void StdOut::print(string s) {
    cout << s;
}

void StdOut:: println(string s) {
    cout << s << endl;
}

void StdOut::println() {
    cout << endl;
}

//StdIn implementation
StdIn:: StdIn() {
    //TODO
}

StdIn:: StdIn(string fileName) {
    ifile.open(fileName);
}

StdIn:: ~StdIn() {
    this -> ifile.close();
}

int StdIn:: readInt() {
    int nextValue = 0;
    ifile >> nextValue;
    return nextValue;
}

double StdIn::readDouble() {
    double nextValue;
    ifile >> nextValue;
    return nextValue;
}

float StdIn::readFloat() {
    float nextValue;
    ifile >> nextValue;
    return nextValue;
}

char StdIn:: readChar() {
    char nextValue;
    ifile.get(nextValue);
    return nextValue;
}

string StdIn:: readWord() {
    string nextValue;
    ifile >> nextValue;
    return nextValue;
}

bool StdIn::readBoolean() {
    bool nextValue;
    ifile >> nextValue;
    return nextValue;
}

string StdIn::readAll() {
    char c;
    char *result = new char;
    int count = 0;
    while(ifile.get(c)) {
        *(result + count) = c;
        count ++;
    }
    *(result + count) = '\0';
    return result;
}

string StdIn::readLine() {
    string result;
    getline(ifile, result);
    return result;
}

string StdIn::readString() {
    string result;
    getline(ifile, result);
    return result;
}

bool StdIn::hasNextLine() {
    string nextLine;
    long currentPosition = ifile.tellg();
    getline(ifile, nextLine);
    ifile.seekg(currentPosition, ios:: beg);
    return !nextLine.empty();
}

bool StdIn::isEmpty() {
    return ifile.peek() == std::ifstream::traits_type::eof();
}
