//
// Created by alexandr on 19.03.2021.
//

#ifndef PRACTICE_PSTU_HIPO_H
#define PRACTICE_PSTU_HIPO_H

class Hipo {
    float first;  // Первый катет
    float second; // Второй катет
public:
    Hipo(float a, float b) {
        this->first = a;
        this->second = b;
    }
    float getResult() {
        return sqrtf(pow(this->first, 2) + pow(this->second, 2));
    }

};

#endif //PRACTICE_PSTU_HIPO_H
