#include <iostream>

using namespace std;

#include "includes/vector_18.6.h"

int main() {
    Vector a(5);
    cout << "Создан вектор a" << endl;
    cout << a << endl;
    cout << endl << "Ввод вектор a" << endl;
    cin >> a;
    cout << endl << "Данные в векторе a" << endl;
    cout << a << endl;
    cout << endl << "a[2] = 100" << endl;
    a[2] = 100;
    cout << endl << "Данные в векторе a" << endl;
    cout << a << endl;

    cout << "Создан вектор b" << endl;
    Vector b(10, 3);
    cout << endl << "Данные в векторе b" << endl;
    cout << b << endl;
    cout << "Создан вектор c" << endl;
    Vector c(10);
    cout << endl << "c = b+100" << endl;
    c=b+100;
    cout << endl << "Данные в векторе c" << endl;
    cout << c << endl;
    cout << endl << "a.length = " << a() << endl;

    cout << *(a.first()) << endl;
    Iterator i = a.first();
    i++;
    cout << endl << "*i = " << *i << endl;
    cout << endl << "Iterator a:" << endl;
    for(i = a.first(); i != a.last(); i++) {
        cout << *i << endl;
    }
}