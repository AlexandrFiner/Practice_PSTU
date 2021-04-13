//
// Created by alexandr on 30.03.2021.
//

#ifndef PRACTICE_PSTU_VECTOR_18_7_H
#define PRACTICE_PSTU_VECTOR_18_7_H

#include <iostream>
#include <string>

using namespace std;

template<class T>
class Vector;

template<class T>
ostream& operator<< (ostream& out, const Vector<T>& a);

template<class T>
istream& operator>> (istream& in, Vector<T>& a);

template<class T>
class Vector {
    int size;
    T *data;
    int len() { return size; }
public:
    // s элементов, заполняем k
    Vector(int s, T k);
    // Конструктор с параметрами
    Vector(const Vector<T>&a);
    // деструктор
    ~Vector();
    // Присваивание
    Vector &operator=(const Vector<T>&a);
    // Доступ по индексу
    T&operator[](int index);
    // Операция добавления константы
    Vector operator+(const T k);
    // Вернуть длину вектора
    int operator()();
    friend ostream& operator<< <T>(ostream& out, const Vector<T>& a);
    friend istream& operator>> <T>(istream& in, Vector<T>& a);
};

template<class T>
Vector<T>::Vector(int s, T k) {
    size = s;
    data = new T[size];
    for(int i = 0; i < size; i++)
        data[i] = k;
}

template<class T>
Vector<T>::Vector(const Vector &a) {
    size = a.size;
    data = new T[size];
    for(int i = 0; i < size; i++)
        data[i] = a.data[i];
}

template<class T>
Vector<T>::~Vector() {
    delete [] data;
    data = 0;
}

template<class T>
Vector<T> &Vector<T>::operator=(const Vector<T>&a) {
    if(this == &a) return *this;
    size = a.size;
    if(data != 0) delete[]data; // Если не пуст, то очистим
    data = new int[size];
    for(int i = 0; i < size; i++)
        data[i] = a.data[i];
    return *this;
}

template<class T>
T&Vector<T>::operator[](int index) {
    if(index<size) return data[index];
    cerr << "\nError! Index > size";
    // return 0;
}

template<class T>
Vector<T> Vector<T>::operator+(const T k) {
    Vector<T> temp(size, k);
    for(int i = 0; i < size; i++) {
        temp.data[i] += data[i] + k;
    }
    return temp;
}

template<class T>
int Vector<T>::operator()() {
    return len();
}


template<class T>
ostream& operator<< (ostream& out, const Vector<T>& a)
{
    for (int i = 0; i < a.size; ++i)
        out << a.data[i] << " ";
    return out;
}
template<class T>
istream& operator>> (istream& in, Vector<T>& a)
{
    for (int i = 0; i < a.size; ++i)
        in >> a.data[i];
    return in;
}

#endif //PRACTICE_PSTU_VECTOR_18_7_H
