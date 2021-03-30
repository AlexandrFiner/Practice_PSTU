//
// Created by alexandr on 30.03.2021.
//

#ifndef PRACTICE_PSTU_VECTOR_18_6_H
#define PRACTICE_PSTU_VECTOR_18_6_H

class Iterator {
    friend class Vector;
    int *elem;
public:
    Iterator() { elem = 0; } // Создаем
    Iterator(const Iterator&it) { elem=it.elem; }   // Копируем
    bool operator==(const Iterator&it) { return elem==it.elem; }
    bool operator!=(const Iterator&it) { return elem!=it.elem; }
    void operator++() { ++elem; }
    void operator++(int) { ++elem; }
    void operator--() { --elem; }
    int &operator*()const {return *elem;}
};

class Vector {
    int size;
    int *data;
    int len() { return size; }

    Iterator beg;
    Iterator end;
public:
    // s элементов, заполняем k
    Vector(int s, int k = 0);
    // Конструктор с параметрами
    Vector(const Vector&a);
    // деструктор
    ~Vector();
    // Присваивание
    Vector &operator=(const Vector&a);
    // Доступ по индексу
    int &operator[](int index);
    // Операция добавления константы
    Vector operator+(const int k);
    // Вернуть длину вектора
    int operator()();
    friend ostream &operator<<(ostream &out, const Vector&a);
    friend istream &operator>>(istream &in, Vector&a);


    Iterator first() { return beg; }
    Iterator last() { return end; }
};

Vector::Vector(int s, int k) {
    size = s;
    data = new int[size];
    for(int i = 0; i < size; i++)
        data[i] = k;

    beg.elem = &data[0];
    end.elem = &data[size];
}

Vector::Vector(const Vector &a) {
    size = a.size;
    data = new int[size];
    for(int i = 0; i < size; i++)
        data[i] = a.data[i];

    beg = a.beg;
    end = a.end;
}

Vector::~Vector() {
    delete [] data;
    data = 0;
}

Vector &Vector::operator=(const Vector &a) {
    if(this == &a) return *this;
    size = a.size;
    if(data != 0) delete[]data; // Если не пуст, то очистим
    data = new int[size];
    for(int i = 0; i < size; i++)
        data[i] = a.data[i];

    beg = a.beg;
    end = a.end;
    return *this;
}

int &Vector::operator[](int index) {
    if(index<size) return data[index];
    cerr << "\nError! Index > size";
    // return 0;
}

Vector Vector::operator+(const int k) {
    Vector temp(size);
    for(int i = 0; i < size; i++) {
        temp.data[i] += data[i] + k;
    }
    return temp;
}

int Vector::operator()() {
    return len();
}

ostream &operator<<(ostream &out, const Vector&a) {
    for(int i = 0; i < a.size; i++) {
        out << a.data[i] << endl;
    }
    return out;
}

istream &operator>>(istream &in, Vector&a) {
    for(int i = 0; i < a.len(); i++) {
        in >> a.data[i];
    }
    return in;
}

#endif //PRACTICE_PSTU_VECTOR_18_6_H
