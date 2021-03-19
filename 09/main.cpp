#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

string str;
int n;
int g;

void loadFile(string filename);
void printFile(string filename);
void getLastLine(string filename, string &str);
int countVowels(string str);
void moveString(string filename_in, string filename_out);

int main()
{
    setlocale(LC_ALL, "rus");

    cout << "Введите кол-во строк: ";
    cin >> n;

    // Делаем записи в файл
    loadFile("F1.txt");

    // Открываем файл
    printFile("F1.txt");

    // Перемещение строк из одного файла в другой
    moveString("F1.txt", "F2.txt");

    n -= g; // Подсчитываем, сколько мы должны вывести строчек
    printFile("F2.txt");

    getLastLine("F2.txt", str); // Получаем последнюю строку
    cout << "Кол-во гласных в последней строке: " << countVowels(str) << endl;
    return 0;
}

void loadFile(string filename) {
    cin.ignore();
    // F1
    ofstream f1(filename);
    if (!f1.is_open())
    {
        // Если не открывается
        cout << "Файл не открыт" << endl;
        exit (EXIT_FAILURE);
    }

    // Записываем строки
    for (int i = 0; i < n; i++)
    {
        // Получаем строчку
        getline(cin, str);
        f1 << str << "\n";
    }

    // Закрываем файл
    f1.close();
}

void printFile(string filename) {
    ifstream file(filename);
    if (!file.is_open())
    {
        // Если не открывается
        cout << "Файл не открыт" << endl;
        exit (EXIT_FAILURE);
    }

    // Выводим содержаения
    cout << "Содержание файла " << filename << endl;
    for (int i = 0; i < n; i++)
    {
        // Из файла в строчку
        getline(file, str);
        cout << str << endl;
    }
    // Выходим из файла
    file.close();
}

// Получаем последнюю строчку
void getLastLine(string filename, string &str) {
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Файлы не открыт" << endl;
        exit (EXIT_FAILURE);
    }

    for(int i = 0; i < n; i++) {
        getline(file, str);
    }
    file.close();
}

// Количество гласных
int countVowels(string str) {
    int count = 0;
    for (auto c : str)
    {
        switch (c)
        {
            case 'a': case 'e': case 'i': case 'o': case 'u': case 'y': case 'A': case 'E': case 'I': case 'O': case 'U': case 'Y': count++;
        }
    }
    return count;
}

void moveString(string filename_in, string filename_out) {
// Открываем файлы F1 и F2
    ifstream f(filename_in);
    ofstream f2(filename_out);
    if (!f.is_open() && !f2.is_open())
    {
        // Проверяем, вдруг файлы не открываются
        cout << "Файлы не открыт" << endl;
        exit (EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++)
    {
        // Ужасный код? Возможно
        getline(f, str); // Получили строчку из файла

        string s;
        string arr[50];
        stringstream str_word(str);
        int j = 0;
        while (str_word >> s)
        {
            arr[j] = s;
            j++;
        }
        for (int q = 0; q < j; q++)
            for(int k = q + 1; k < j;k++)
                if (arr[q] == arr[k])
                {
                    f2 << str << "\n";
                    g++;
                }
    }

    // Закрываем файлы
    f.close();
    f2.close();
}