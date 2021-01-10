#include <iostream>

using namespace std;

#define ARRAY_SIZE 10 // Размер массива

int a[ARRAY_SIZE];

int main() {
    do {
        cin >> n;
    } while (n >= ARRAY_SIZE || !n);

    if(n % 2 == 0) { // Четное
        for(int i = 0; i < (n / 2); i++) {
            a[i] = rand() % 9 + 1;
            a[n - i - 1] = a[i];
        }
    } else { // Нечетное
        for(int i = 0; i < (n / 2); i++) {
            a[i] = rand() % 9 + 1;
            a[n - i - 1] = a[i];
        }
    }

    for(int i =0; i < n; i++) {
        cout << a[i] << endl;
    }
}