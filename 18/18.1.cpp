#include <iostream>
#include <cmath>
#include "hipo.h"

using namespace std;

int main() {
    float a, b;
    cout << "Введите катет a: "; cin >> a;
    cout << "Введите катет b: "; cin >> b;
    Hipo A(a, b);
    cout << "Ответ: " << A.getResult() << endl;
}