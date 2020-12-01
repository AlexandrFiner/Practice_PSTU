#include <iostream>

using namespace std;

// Размер массива
#define ARRAY_SIZE 100

const int MAX_INT = 500; // Максимальный элемент
const int MIN_INT = 1; // Минимальный элемент

// Количество элементов
int n;

// Массив
int a[ARRAY_SIZE];

// Сортировка простым выбором
void simpleSort(int *num, int size) {
    int min = 0, temp = 0;
    for (int i = 0; i < size-1; i++) {
        min = i;
        for (int j = i+1; j < size; j++)
        {
            if (num[j] < num[min])
                min = j;
        }
        temp = num[i];
        num[i] = num[min];
        num[min] = temp;
    }
}

int main() {
    int min = MAX_INT+1; // Минимальное число
    int minI = -1; // i минимального числа
    int max = MIN_INT-1; // Максимальное число
    int maxI = -1; // i максимального числа
    int k = 0; // Временная переменная

    cout << "Enter: N" << endl;
    do {
        cin >> n;
    } while (n >= ARRAY_SIZE || !n);
    cout << endl;

    // Заполнили и вывели (1, 2)
    for(int i = 0; i < n; i++) {
        a[i] = rand()%MAX_INT+MIN_INT;
        cout << i << ") " << a[i] << endl;
    }
    cout << endl;

    // Удалить (3, 4)
    for(int i = 0; i < n; i++) {
        if (min > a[i]) {
            min = a[i];
            minI = i;
        }
    }
    a[minI] = 0;
    for(int i = minI; i < n; i++) {
        a[i] = a[i+1];
    }

    for(int i = 0; i < n; i++) {
        cout << i << ") " << a[i] << endl;
    }
    cout << endl;

    // Добавление (5, 6)
    cout << "Enter: K" << endl;
    do {
        cin >> k;
    } while (k < 0 || k >= n);

    for(int i = n-1; i >= k; i--) {
        a[i] = a[i-1];
    }
    a[k] = rand()%MAX_INT+MIN_INT;
    for(int i = 0; i < n; i++) {
        cout << i << ") " << a[i] << endl;
    }
    cout << endl;
    // Перестановка (7, 8)

    // Обнуляем
    min = MAX_INT+1; // Минимальное число
    minI = -1; // i минимального числа

    for(int i = 0; i < n; i++) {
        if(a[i] > max) {
            max = a[i];
            maxI = i;
        } else if(a[i] < min) {
            min = a[i];
            minI = i;
        }
    }
    k = a[maxI]; // Запомнили сколько было
    a[maxI] = a[minI]; // Поменяли максимум на минимум
    a[minI] = k; // Поменяли минимум на максимум
    for(int i = 0; i < n; i++) {
        cout << i << ") " << a[i] << endl;
    }
    cout << endl;

    // Поиск указанных в массиве элементов
    // Среднее арифметическое (9, 10)
    int average = 0;
    int counter = 0;
    for(int i = 0; i < n; i++) {
        average += a[i];
    }
    k = -1;
    average /= n;
    for(int i = 0; i < n; i++) {
        if (average == a[i]) {
            k = i;
            break;
        }
        else
            counter++;
    }
    if(k >= 0)
        cout << "Success: Checks(" << counter << "), element " << k << endl;
    else
        cout << "Fail: Checks(" << counter << ")" << endl;
    cout << endl;

    // Сортировка массива (11, 12)
    simpleSort(a, n);
    for(int i = 0; i < n; i++) {
        cout << i << ") " << a[i] << endl;
    }
    cout << endl;

    // Поиск (13, 14)
    counter = 0, k = -1;
    for(int i = 0; i < n; i++) {
        if (average == a[i]) {
            k = i;
            break;
        }
        else
            counter++;
    }
    if(k >= 0)
        cout << "Success: Checks(" << counter << "), element " << k << endl;
    else
        cout << "Fail: Checks(" << counter << ")" << endl;

    return 0;
}
