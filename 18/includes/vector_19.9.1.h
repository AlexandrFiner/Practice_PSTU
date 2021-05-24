//
// Created by alexandr on 24.05.2021.
//

#ifndef PRACTICE_PSTU_VECTOR_19_9_1_H
#define PRACTICE_PSTU_VECTOR_19_9_1_H

#include <iostream>

using namespace std;

class Plenty
{
    int size;
    int* beg;
public:
    Plenty() { size = 0; beg = 0; }
    Plenty(int s);
    Plenty(int s,int* mas);
    Plenty(const  Plenty&v);
    ~Plenty();
    const  Plenty& operator=(const  Plenty& v);
    int operator[](int i);
    Plenty operator+(int a);
    Plenty operator--();
    friend ostream& operator<<(ostream& out, const  Plenty& v);
    friend istream& operator>>(istream& in, Plenty& v);
};

Plenty::Plenty(int s)
{
    size = s;
    beg = new int[s];
    for (int i = 0; i < size; i++)
        beg[i] = 0;
}
Plenty::Plenty(const Plenty& v)
{
    size = v.size;
    beg = new int[size];
    for (int i = 0; i < size; i++)
        beg[i] = v.beg[i];
}
Plenty::~Plenty()
{
    if (beg != 0)
        delete[] beg;
}
Plenty::Plenty(int s, int* mas)
{
    size = s;
    beg = new int[size];
    for (int i = 0; i < size; i++)
        beg[i] = mas[i];
}
const Plenty& Plenty::operator =(const Plenty& v)
{
    if (this == &v)
        return *this;

    if (beg != 0)
        delete[] beg;
    size = v.size;
    beg = new int[size];
    for (int i = 0; i < size; i++)
        beg[i] = v.beg[i];

    return *this;
}

ostream& operator<<(ostream& out, const Plenty& v)
{
    if (v.size == 0) out << "Empty\n"; else
    {
        for (int i = 0; i < v.size; i++) out << v.beg[i] << " ";
        out << endl;
    }
    return out;
}

istream& operator >>(istream& in, Plenty& v)
{
    for (int i = 0; i < v.size; i++)
    {
        cout << ">"; in >> v.beg[i];
    }
    return in;
}

int Plenty::operator [](int i)
{
    if (i < 0)throw 2;
    if (i >= size)
    {
        cout << "error";
        return 0;
    }
    return beg[i];
}

Plenty Plenty::operator +(int a)
{
    Plenty temp(size+1,beg);
    temp.beg[size]=a;
    return temp;
}

Plenty Plenty::operator --()
{
    if (size == 0) throw 5;
    if (size == 1)
    {
        size = 0;
        delete[]beg;
        beg = 0;
        return *this;
    };
    Plenty temp(size, beg);
    delete[]beg;
    size--;
    beg = new int[size];
    for (int i = 0; i < size; i++)
        beg[i] = temp.beg[i]; return*this;
}

#endif //PRACTICE_PSTU_VECTOR_19_9_1_H
