#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

// Функция для создания вектора
typedef vector<float> Vec;    // Определяем тип для работы с вектором
Vec make_vector(int n) {
    Vec v; // Пустой вектор
    for(int i = 0; i < n; i++) {
        float a = rand() % 100 - 50;
        v.push_back(a); // Добавляем a в конец вектора
    }
    return v;
}

// Функция для печати вектора
void print_vector(Vec v) {
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

void add_vector(Vec &v, int el, int pos) {
    v.insert(v.begin()+pos, el);
}

void del_vector(Vec &v, int pos) {
    v.erase(v.begin()+pos);
}

float srednee(Vec v) {
    float s = 0;
    for(int i = 0; i < v.size(); i++)
        s += v[i];

    int n = v.size();
    return s/n;
}

int max(Vec v) {
    float max = v[0], n = 0;
    for(int i = 1; i < v.size(); i++)
        if(max < v[i]) {
            max = v[i];
            n = i;
        }

    return n;
}

int min(Vec v) {
    float min = v[0], n = 0;
    for(int i = 1; i < v.size(); i++)
        if(min > v[i]) {
            min = v[i];
            n = i;
        }

    return n;
}

void delenie(Vec &v) {
    int n = min(v);
    for(int i = 0; i < v.size(); i++)
        v[i] = float(v[i] / v[n]);
}

int main() {
    srand(time(NULL));
    try {
        vector<float> v; // Вектор
        vector<float>::iterator vi = v.begin(); // Итератор
        int n;
        cout << "N?\n>"; cin >> n;
        v = make_vector(n); // Формирование вектора
        print_vector(v);

        // Нахождение минимального
        float el = srednee(v);
        // Позиция для вставки
        int pos;
        cout << "Pos?\n>"; cin >> pos;
        // Генерация ошибки
        if(pos > v.size()) throw 1;
        add_vector(v, el, pos);
        print_vector(v);

        int n_max = max(v);
        del_vector(v, n_max);
        print_vector(v);

        delenie(v);
        print_vector(v);
    } catch (int) {
        cout << "error!" << endl;
    }
}