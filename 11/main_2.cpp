#include <iostream>
#include <queue>

using namespace std;

queue<int> quInt; // пустая очередь int

queue<int> makeQueueInt();
void print(queue<int> qu);
void del(queue<int> &qu);

int main() {
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));

    cout << "-- Работа с очередью -- " << endl;
    quInt = makeQueueInt();
    print(quInt);
    del(quInt);
    print(quInt);
}

queue<int> makeQueueInt() {
    queue<int> qu;

    for(int i = 1; i <= 10; i++) {
        qu.push(rand() % 100);
    }
    return qu;
}

void print(queue<int> qu) {
    int p = qu.size();  // размер
    char arr[32];

    for(int i = 0; i < p; i++) {
        arr[i] = qu.front();
        cout << qu.front() << " ";
        qu.pop();
    }
    for(int i = 0; i < p; i++)
        qu.push(arr[i]);

    cout << endl;
}

void del(queue<int> &qu) {
    cout << "Удаляем последнее четное" << endl;

    int p = qu.size();  // размер
    char arr[32];

    for(int i = 0; i < p; i++) {
        if(qu.top() % 2 == 0) {
            qu.pop();
            break;
        } else {
            arr[i] = qu.top();
            qu.pop();
        }
    }
    for(int i = 0; i < p; i++)
        qu.push(arr[i]);
}