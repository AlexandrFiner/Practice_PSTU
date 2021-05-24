#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

#include "includes/money.h"

// Функция для создания вектора
typedef vector<Money> Vec;    // Определяем тип для работы с вектором
Vec make_vector(int n) {
    Vec v; // Пустой вектор
    Money temp;
    for(int i = 0; i < n; i++) {
        Money temp(rand() % 100, rand() % 100);
        v.push_back(temp); // Добавляем a в конец вектора
    }
    return v;
}

// Функция для печати вектора
void print_vector(Vec v) {
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " || ";
    cout << endl;
}

void add_vector(Vec &v, Money el, int pos) {
    v.insert(v.begin()+pos, el);
}

void del_vector(Vec &v, int pos) {
    v.erase(v.begin()+pos);
}

int min(Vec v) {
    Money min = v[0]; int n = 0;
    for(int i = 1; i < v.size(); i++)
        if(min > v[i]) {
            min = v[i];
            n = i;
        }

    return n;
}

int main() {
    srand(time(NULL));
    try {
        vector<Money> v; // Вектор
        vector<Money>::iterator vi = v.begin(); // Итератор
        int n;
        cout << "N?\n>"; cin >> n;
        v = make_vector(n); // Формирование вектора
        print_vector(v);

        // Нахождение минимального
        Money el = v[min(v)];
        // Позиция для вставки
        int pos;
        cout << "Pos?\n>"; cin >> pos;
        // Генерация ошибки
        if(pos > v.size()) throw 1;
        add_vector(v, el, pos);
        print_vector(v);
    } catch (int) {
        cout << "error!" << endl;
    }
}