#include <iostream>
#include <time.h>

using namespace std;

const int SIZE = 2;

int f(int matrix[SIZE][SIZE]);

int main() {
    srand(time(NULL));
    int matrix[SIZE][SIZE];
    int min;
    int i, j;

    int start = rand() % 3 + 1;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            matrix[i][j] = start++;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    min = f(matrix);
    cout <<"Min element " << min << endl;
}

int f(int matrix[SIZE][SIZE])
{
    int i = 0, j = 1, min;
    min = matrix[0][0];
    for (i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if (min > matrix[i][j]) {
                min = matrix[i][j];
            }
        }
    }
    return min;
}