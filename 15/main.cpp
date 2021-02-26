#include <iostream>

using namespace std;

void hoarasort(int* a, int first, int last);
void shellsort(int* a, int n);

int main() {
    /*
     * Сортировка методом шелла
     * Сортировка методом Хоара
     */
    int n;
    int a[56];
    int b[56];

    cout << "Введите количество озер для генерации списка: " << endl;
    cin >> n;
    for(int i = 0; i < n; i++) {
        a[i] = (int)(rand()) % 100 + 1;
        b[i] = a[i];
        cout << a[i] << " ";
    } cout << endl;

    hoarasort(a, n);
    shellsort(a, n);


    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    for(int i = 0; i < n; i++)
        cout << b[i] << " ";
}

void hoarasort(int* a, int first, int last) {
    int i = first, j = last;  // i - первый | j - последний
    double tmp, x = a[(first + last) / 2]; // x = середина

    do {
        while (a[i] < x)
            i++;

        while (a[j] > x)
            j--;

        if (i <= j)
        {
            if (i < j)
            {
                tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last)
        hoarasort(a, i, last);

    if (first < j)
        hoarasort(a, first,j);
}

void shellsort(int* a, int n) {
    int i, j, step;
    int tmp;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            tmp = a[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < a[j - step])
                    a[j] = a[j - step];
                else
                    break;
            }
            a[j] = tmp;
        }
}