//
// Created by alexandr on 19.03.2021.
//

#include "object.h"

#ifndef PRACTICE_PSTU_TRIAD_OBJECT_H
#define PRACTICE_PSTU_TRIAD_OBJECT_H

class Triad:public Obj {
protected:
    int first;
    int second;
    int third;
public:
    Triad(void);
    virtual ~Triad(void); // деструктор, (VIRTUAL - https://vk.cc/bZQnqZ)
    Triad(int, int, int);
    Triad(const Triad&);

    void Show();

    int get_first(){return first;}
    int get_second(){return second;}
    int get_third(){return third;}

    void set_first(int);
    void set_second(int);
    void set_third(int);

    Triad& operator=(const Triad&); // Перегрузим =

    friend istream& operator>>(istream&in, Triad&c); // Ввод
    friend ostream& operator<<(ostream&out, const Triad&c); // Вывод
};

Triad::Triad() {
    first = 0;
    second = 0;
    third = 0;
}

Triad::~Triad() {

}

Triad::Triad(int First, int Second, int Third) {
    first = First;
    second = Second;
    third = Third;
}

Triad::Triad(const Triad& Triad) {
    first = Triad.first;
    second = Triad.second;
    third = Triad.third;
}

void Triad::Show() {
    cout << endl << "First: " << first;
    cout << endl << "Second: " << second;
    cout << endl << "Third: " << third;
    cout << endl;
}

void Triad::set_first(int Num) {
    first = Num;
}

void Triad::set_second(int Num) {
    second = Num;
}

void Triad::set_third(int Num) {
    third = Num;
}

Triad& Triad::operator=(const Triad&T) {
    // Для умных, кто делает param = param
    if(&T==this) return *this;
    first = T.first;
    second = T.second;
    third = T.third;
    return *this;
}

istream& operator>>(istream&in, Triad&T) {
    cout << "First: "; in >> T.first;
    cout << "Second: "; in >> T.second;
    cout << "Third: "; in >> T.third;
    return in;
}
ostream& operator<<(ostream&out, const Triad&T) {
    out << endl << "First: " << T.first;
    out << endl << "Second: " << T.second;
    out << endl << "Third: " << T.third;
    out << endl;
    return out;
}

#endif //PRACTICE_PSTU_TRIAD_OBJECT_H
