#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


char** makeArr(int cnt, int len);
void initialize(char** A, int cnt, int len);
void print(char** A, int cnt);
char** compare(char** A, int& cnt);

template<size_t N>
int getSize(char (&arr)[N]) {
    return N;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    /*
     * 1 Ввести размер массива;
     */
    int cnt = 0, len = 0;
    cout << "Введите кол-во слов в массиве" << endl;
    cin >> cnt;
    cout << "Введите длину слова" << endl;
    cin >> len;
    cout << endl;

    /*
     * 2.Сформировать массив с помощью операции new или библиотечных функций malloc (calloc);
     */
    char **A;
    A = makeArr(cnt, len);

    /*
     * 3.Заполнить массив (можно с помощью датчика случайных чисел);
     */
    initialize(A, cnt, len);
    print(A, cnt);

    /*
     * 4.Выполнить задание варианта, сформировать новый массив(ы)-результат(ы);
     */
    char **A_New;
    A_New = compare(A, len);

    /*
     * 5.Напечатать массив(ы)-результат(ы);
     */
    cnt = 1;
    print(A_New, cnt);

    // for(int i = 0; i < cnt; i++) delete A_New[i];
    // delete [] A_New;

    /*
     * 6.Удалить динамические массивы с помощью операции delete или библиотечной функции free.
     */
    delete [] A;
    delete [] A_New;

    return 0;
}

char** makeArr(int n, int len) {
    char **A;// Создаем матрицу введенной размерности
    A = new char *[n]; // через массив указателей
    for (int i = 0; i < n; i++)
        A[i] = new char [len];

    return A;
}

void initialize(char** A, int cnt, int len)// Функция заполнения
{
    srand(time(0));
    for(int i = 0; i < cnt; i++)
        for(int j = 0;  j < len;  j++)
            A[i][j] = 'A' + rand() % 2;
}

void print(char** A, int cnt) {
    for(int i = 0; i < cnt; i++)
        cout << A[i] << endl;
}

char** compare(char** A, int& cnt) // Функция сравнения
{
    int count = 0;
    char *tmp;
    for (int i = 0; i < cnt; i++) {
        if (A[i][0] == A[i][strlen(A[i]) - 1]) {
            cout << "Найдено: " << A[i] << " (" << i << ") " << endl;

            if(i > 0) {
                tmp = A[i];
                A[count] = A[i]; //удаляемые элементы переместим в начало массива
                A[i] = tmp;
            }
            count++;
        }
    }

    print(A, cnt);

    cnt = cnt - count;
    char **result = makeArr(cnt, strlen(A[0]));
    for (unsigned i = 0; i < cnt; i++) {
        result[i] = A[i + count];
        cout << i << " " << result[i] << endl;
    }
    return result;
}