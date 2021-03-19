#include <iostream>

using namespace std;

#include "../includes/vector.h"

Vector::Vector(void) {
    begin = 0;
    size = 0;
    current = 0;
}

Vector::~Vector() {
    if(begin != 0) delete [] begin;
    begin = 0;
}

void Vector::Add(Obj *p) {
    if(current < size) {
        begin[current] = p;
        current++;
    }
}

ostream& operator<<(ostream&out, const Vector&v) {
    if(v.size == 0) out << "Empty" << endl;
    else {
        Obj **p=v.begin;
        for(int i = 0; i < v.current; i++) {
            (*p)->Show();
            p++;
        }
    }
    return out;
}