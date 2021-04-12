#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    Stack<int> s;
    while(true)
    {
        system("clear");
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Print" << endl;
        cout << endl << "0. Выход" << endl;
        int choice;
        cin >> choice;
        system("clear");
        switch (choice) {
            case 1: {
                cout << "Push to stack: ";
                int n;
                cin >> n;
                s.push(n);

                cout << "Для продолжения нажмите любую клавишу.." << endl;
                cin >> choice;

                break;
            }
            case 2: {
                s.pop();

                cout << "Для продолжения нажмите любую клавишу.." << endl;
                cin >> choice;
                break;
            }
            case 3: {
                s.print();

                cout << "Для продолжения нажмите любую клавишу.." << endl;
                cin >> choice;
                break;
            }
            case 0: {
                return 1;
            }
            default: {
                cout << "Команда не найдена" << endl;
                break;
            }
        }
    }
}