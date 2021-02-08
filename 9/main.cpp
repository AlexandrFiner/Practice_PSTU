#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    FILE *in;   // Исходный
    FILE *out;  // Выходной
    if((in=fopen("f1.txt", "r")) == NULL) {
        perror("ошибка при открытии файла");
        exit(0);
    }

    char str[128];
    char *estr; // Указатель на конец строки
    while(true) {
        estr = fgets(str, sizeof(str), in);
        if(estr == NULL) {
            if(feof(in) != 0) {
                printf("Чтение файла закончено");
                break;
            } else {
                printf("Произошла ошибка при чтении файла");
                break;
            }
        }
        printf("%s", str);
    }

    if((out=fopen("f2.txt", "w+")) == NULL) {
        perror("ошибка при открытии файла");
        exit(0);
    }

    fclose(in);
    fclose(out);
}