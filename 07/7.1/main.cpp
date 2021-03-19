#include <iostream>
#include <utility>

using namespace std;

int counter(int *arr)
{
    cout << "Counter:: ";
    int count = 0;
    for(int i = 0; i < sizeof(arr); i++) {
        if(arr[i] % 2 == 0) {
            count++; cout << arr[i];
        }
    } cout << endl;
    return count;
}

int counter(char *string)
{
    int count = 0, i = 0;
    if(string[i]=='a' || string[i]=='а')
        count++;

    do {
        if(string[i]==' ' && (string[i+1]=='a' || string[i+1]=='а'))
            count++;

        i++;
    }
    while(string[i]!='\0');
    return count;
}

int main() {
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    int arr[10];
    cout << "Array:: ";
    for(int i = 0; i < 10; i++) {
        arr[i] = rand() % 9+1;
        cout << arr[i];
    } cout << endl;
    cout <<  "Result:: " << counter(arr) << endl  << endl;

    char string[255];
    cout << "String:: ";
    gets(string);
    cout <<  "Result:: " << counter(string) << endl  << endl;
}