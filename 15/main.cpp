#include <iostream>
#include <string>
#include <ctime>

#define DEBUG_MODE // режим отладки

using namespace std;

struct Node {
    string name;    // Название озера
    float weight;   // Площадь озера
};

void echoMenuCreate(Node* st, int n);
void createList(Node* a, int n);
void createListRandom(Node* a, int n);
void echoMenu(Node* a, int n);
void ShellSort(Node* a, int n);
void HoaraSort(Node* arr, int left, int right);
void printList(Node* a, int n);

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Rus");

    int n;
    cout << "Введите количество озёр: ";
    cin >> n;
    Node* st = new Node[n];

    echoMenuCreate(st, n);
    echoMenu(st, n);
    printList(st, n);
}

void echoMenuCreate(Node* st, int n) {
    int type = 0;
    system("clear");
    cout << "Заполнение массива" << endl;
    cout << "1. Ручное" << endl;
    cout << "2. Автоматическое" << endl;
    cin >> type;
    switch (type) {
        case 1: { createList(st, n); break; }
        case 2: { createListRandom(st, n); break; }
        default: { createListRandom(st, n); break; }
    }
}

void createList(Node* st, int n) {
    for (int i = 0; i < n; i++)
    {
        system("clear");
        cout << "Заполнение массива  (" << i+1 << "/" << n << ")" << endl;

        cout << " Название озера: ";
        cin >> st[i].name;

        cout << " Площадь: ";
        cin >> st[i].weight;

        cout << endl;
    }
}

void createListRandom(Node* st, int n) {
    for (int i = 0; i < n; i++)
    {
        st[i].name = 'a' + rand() % 20;
        st[i].weight = rand() % 5000;
    }
}

void echoMenu(Node* st, int n) {
    int a = 0;
    while(a != 1 && a != 2) {
        system("clear");
        cout << "Выбор сортировки:" << endl;
        cout << "1. Сортировка Шелла " << endl;
        cout << "2. Сортировка Хоара" << endl;
        cout << "3. Вывод" << endl;
        cout << "Введите операцию: ";
        cin >> a;
        switch (a) {
            case 1: {
#if defined DEBUG_MODE
                unsigned int start_time =  clock(); // начальное время
#endif
                ShellSort(st, n);
#if defined DEBUG_MODE
                unsigned int end_time = clock(); // конечное время
                unsigned int search_time = end_time - start_time; // искомое время

                system("clear");

                cout << endl << "Debug:::";
                cout << endl << "   Время выполнения функции: " << search_time/1000.0 << " мс." << endl;

                int out;
                cout << endl << "Для продолжение введите любое положительное число" << endl;
                cout << endl << "0. Вернутся в меню" << endl;
                cin >> out;
                if(!out)
                    a = 0;
#endif
                break;
            }
            case 2: {
#if defined DEBUG_MODE
                unsigned int start_time =  clock(); // начальное время
#endif
                HoaraSort(st, 0, n - 1);
#if defined DEBUG_MODE
                unsigned int end_time = clock(); // конечное время
                unsigned int search_time = end_time - start_time; // искомое время

                system("clear");

                cout << endl << "Debug:";
                cout << endl << "Время выполнения функции: " << search_time/1000.0 << " мс." << endl;

                int out;
                cout << endl << "Для продолжение введите любое положительное число" << endl;
                cout << endl << "0. Вернутся в меню" << endl;
                cin >> out;
                if(!out)
                    a = 0;
#endif
                break;
            }
            case 3: {
                printList(st, n);
                break;
            }
        }
    }
}

void ShellSort(Node* a, int n)
{
    int b = n / 2; // нашли середину
    while (b > 0)
    {
        for (int i = 0; i < n - b; i++)
        {
            int j = i;
            while (j >= 0)
            {
                if (a[j].weight < a[j + b].weight)
                {
                    float d = a[j].weight;
                    a[j].weight = a[j + b].weight;
                    a[j + b].weight = d;
                    string f = a[j].name;
                    a[j].name = a[j + b].name;
                    a[j + b].name = f;
                    j -= b;
                }
                else
                    j = -1;
            }
        }
        b /= 2;
    }
}

void HoaraSort(Node* arr, int left, int right)
{
    float d;
    string f;
    int i = left;
    int j = right;

    while (i <= j)
    {
        while (arr[i].weight > arr[(left + right) / 2].weight && i < right)
            i++;

        while (arr[j].weight < arr[(left + right) / 2].weight && j > left)
            j--;

        if (i <= j)
        {
            d = arr[i].weight;
            arr[i].weight = arr[j].weight;
            arr[j].weight = d;
            f = arr[i].name;
            arr[i].name = arr[j].name;
            arr[j].name = f;
            i++;
            j--;
        }
        if (i < right)
        {
            HoaraSort(arr, i, right);
        }
        if (j > left)
        {
            HoaraSort(arr, left, j);
        }
    }
}

void printList(Node* st, int n) {
    system("clear");
    cout << "Результат работы: " << endl << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Озеро: "  << st[i].name << " (" << st[i].weight << ")" << endl;
    }

    int out = 1;
    cout << endl << "0. Вернутся в меню" << endl;
    while (out)
        cin >> out;
}