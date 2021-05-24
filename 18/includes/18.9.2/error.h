//
// Created by alexandr on 24.05.2021.
//

#ifndef PRACTICE_PSTU_ERROR_H
#define PRACTICE_PSTU_ERROR_H

#include <string>
#include <iostream>

using namespace std;

class error
{
    string str;
public:
    error(string s) {
        str = s;
    }
    void what() {
        cout << str << endl;
    }
};

#endif //PRACTICE_PSTU_ERROR_H
