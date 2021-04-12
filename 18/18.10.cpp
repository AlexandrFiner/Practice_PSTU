#include <iostream>
#include <fstream>
#include <string>
#include "includes/18.10/money.h"
#include "includes/18.10/file.h"

using namespace std;

int main() {
    Money p, p1, p2;
    int k, c, num;
    char file_name[30];
    do
    {
        system("clear");
        cout << "1. Создание файла" << endl;
        cout << "2. Печать файла" << endl;
        cout << "3. Удалить запись из файла" << endl;
        cout << "4. Добавить запись в файл" << endl;
        cout << "5. Заменить запись в файле" << endl << endl;
        cout << "0. Выход" << endl;
        cin >> c;
        system("clear");
        switch (c)
        {
            case 1:
                cout << "Имя файла: "; cin >> file_name;
                k = make_file(file_name);
                if (k < 0) cout << endl << "Невозможно создать файл";
                cout << endl << endl << "Введите любое число для продолжения: "; cin >> c;
                break;
            case 2:
                cout << "Имя файла: "; cin >> file_name;
                k = print_file(file_name);
                if (k == 0) cout << "- ПУСТО\n";
                if (k < 0)  cout << endl << "Невозможно открыть/создать файл";
                cout << endl << endl << "Введите любое число для продолжения: "; cin >> c;
                break;
            case 3:
                cout << "Имя файла: "; cin >> file_name;
                cout << "Номер: "; cin >> num;
                k = del_file(file_name, num);
                if (k < 0) cout << endl << "Невозможно открыть/создать файл";
                cout << endl << endl << "Введите любое число для продолжения: "; cin >> c;
                break;
            case 4:
                cout << "Имя файла: "; cin >> file_name;
                cout << "Номер: "; cin >> num;
                cout << "Сумма:"; cin>>p1;
                k = add_file(file_name, num, p1);
                if (k < 0) cout << endl << "Невозможно открыть/создать файл";
                if (k == 0) k = add_end(file_name, p1);
                cout << endl << endl << "Введите любое число для продолжения: "; cin >> c;
                break;
            case 5:
                cout << "Имя файла: "; cin >> file_name;
                cout << "Номер: "; cin >> num;
                cout << "Новая сумма: "; cin >> p2;
                k = change_file(file_name, num, p2);
                if (k < 0) cout << endl << "Невозможно открыть/создать файл";
                if (k == 0) cout << endl << "Запись не найдена";
                cout << endl << endl << "Введите любое число для продолжения: "; cin >> c;
                break;
        }
    }
    while (c != 0);
}