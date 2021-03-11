#include <iostream>
#include <stack>

using namespace std;

stack <int> quInt; // пустая очередь int

stack<int> makeStackInt();
void print(stack<int> qu);
void del(stack<int> &qu);

int main() {
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));

    cout << "-- Работа со стеком -- " << endl;
    quInt = makeStackInt();
    print(quInt);
    del(quInt);
    print(quInt);
}

stack <int> makeStackInt() {
    stack<int> qu;

    for(int i = 1; i <= 10; i++) {
        qu.push(rand() % 100);
    }
    return qu;
}

void print(stack<int> qu) {
    int p = qu.size();  // размер

    for(int i = 0; i < p; i++) {
        cout << qu.top() << " ";
        qu.pop();
    }

    cout << endl;
}

void del(stack<int> &qu) {
    cout << "Удаляем последнее четное" << endl;

    int p = qu.size();  // размер
    int arr[32], j = 0, val = 0;

    for(int i = 0; i < p; i++) {
        val = qu.top();
        if(val % 2 == 0)
            qu.pop();
        else {
            arr[j] = val;
            j++;
            qu.pop();
        }
    }
    for(int i = 0; i < j; i++)
        qu.push(arr[i]);
}