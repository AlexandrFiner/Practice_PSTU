//
// Created by alexandr on 19.03.2021.
//

#ifndef PRACTICE_PSTU_OBJECT_H
#define PRACTICE_PSTU_OBJECT_H

class Obj {
public:
    Obj(void);
    ~Obj(void);
    virtual void Show()=0;
};

Obj::Obj() {}
Obj::~Obj() {}

#endif //PRACTICE_PSTU_OBJECT_H
