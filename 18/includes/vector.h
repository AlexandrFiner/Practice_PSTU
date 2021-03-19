//
// Created by alexandr on 19.03.2021.
//

#ifndef PRACTICE_PSTU_VECTOR_H
#define PRACTICE_PSTU_VECTOR_H

#include "object.h"

class Vector {
public:
    Vector(void);
    Vector(int);
    ~Vector(void);
    void Add(Obj *);
    friend ostream& operator<<(ostream&out, const Vector&);
private:
    Obj **begin; // первый элемент
    int size; // рахмерность
    int current; // Текущая позиция
};

Vector::Vector(void) {
    begin = 0;
    size = 0;
    current = 0;
}

Vector::Vector(int n) {
    begin = new Obj*[n];
    current = 0;
    size = n;
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

#endif //PRACTICE_PSTU_VECTOR_H
