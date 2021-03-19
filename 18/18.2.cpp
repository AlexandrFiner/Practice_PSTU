#include <iostream>

using namespace std;

#include "includes/exam.h"

Exam make() {
    string name;
    string subject;
    int rating;

    cout << "Введите ФИО: "; cin >> name;
    cout << "Введите предмет: "; cin >> subject;
    cout << "Введите оценку: "; cin >> rating;
    Exam t(name, subject, rating);
    return t;
}

void print(Exam t) {
    t.show();
}

int main() {
    cout << "Конструктор без параметров" << endl;
    Exam t1;
    t1.show();
    cout << endl;

    cout << "Конструктор с параметрами" << endl;
    Exam t2("Маликов В.А", "История", 4);
    t2.show();
    cout << endl;

    cout << "Конструктор копирования" << endl;
    Exam t3 = t2;
    t3.set_name("Петров З.А");
    t3.set_subject("Математика");
    t3.set_rating(3);
    print(t3);
    cout << endl;

    cout << "Конструктор ввода" << endl;
    Exam t4 = make();
    t4.show();
    cout << endl;
}