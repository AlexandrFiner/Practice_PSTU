#include <iostream>
#include <queue>

using namespace std;

struct List {
    int data;
    List* next;
};

struct List_2 {
    char data;
    List_2* prev;
    List_2* next;
};

// Формируем
List* makeInt();
List_2* makeChar();

// Выводим
void print(List* first);
void print(List_2* first);

// Удаляем и добавляем
void del(List* first);
void add(List_2* &first);

int main() {
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));

    cout << "-- Работа со списками -- " << endl;

    List* list = makeInt();
    print(list);
    del(list);
    print(list);

    cout << endl;

    List_2* list2 = makeChar();
    print(list2);
    add(list2);
    print(list2);
}

List* makeInt() {
    List* first, *p;
    first = NULL; // Пока нет элементов, указываем на нул

    p = new List;   // Память под элемент

    // Инициализация первого элемента
    p->data = rand() % 100;
    p->next = NULL; // Это последний элемент

    first = p;

    for(int i = 1; i <= 10; i++) {
        List* h = new List; // Память под новый элемент
        p->next = h;
        p = p->next;
        p->data = rand() % 100;
        p->next = NULL; // Это последний элемент
    }
    return first;
}

List_2* makeChar() {
    List_2* first, *p;
    first = NULL; // Пока нет элементов, указываем на нул

    p = new List_2;   // Память под элемент

    // Инициализация первого элемента
    p->data = 'a' + rand() % 20;
    p->prev = NULL; // Это первый элемент
    p->next = NULL; // Это последний элемент

    first = p;

    for(int i = 1; i <= 10; i++) {
        List_2* h = new List_2; // Память под новый элемент
        List_2* q = p;
        p->next = h;
        p = p->next;
        p->data = 'a' + rand() % 20;
        p->next = NULL; // Это последний элемент
        p->prev = q;
    }
    return first;
}

void print(List* first) {
    if(first == NULL) {
        cout << "Список пуст" << endl;
    } else {
        List* p = first;
        while (p != NULL) {
            cout << p->data << " | ";
            p = p->next;
        }
        cout << endl;
    }
}

void print(List_2* first) {
    if(first == NULL) {
        cout << "Список пуст" << endl;
    } else {
        List_2* p = first;
        while (p != NULL) {
            cout << p->data << " | ";
            p = p->next;
        }
        cout << endl;
    }
}

void del(List* first) {
    cout << "Удаляем последнее четное" << endl;

    if(first == NULL) {
        cout << "Список пуст" << endl;
    } else {
        List* p = first;
        List* q = NULL;

        if(p->data % 2 == 0) {
            q = p;
        }
        p = p->next;

        while(p->next != NULL) {
            if (p->next->data % 2 == 0) {
                // Запоминаем четные
                q = p;
            }
            p = p->next;
        }
        if(q != NULL) {
            p = q;
            p->next = p->next->next;
            delete q;
        }
    }
}

void add(List_2* &first) {
    if(first == NULL) {
        cout << "Список пуст" << endl;
    } else {
        cout << "Введите символ, после которого будет добавляться: ";
        char s[2];
        cin >> s[0];

        cout << "Введите символ, который будет добавляться: ";
        cin >> s[1];

        List_2* p = first;
        while(p != NULL) {
            if(p->data == s[0]) {
                List_2* h = new List_2;
                h->data = s[1];
                h->next = p->next;
                h->prev = p;
                p->next = h;
                p = p->next->next;
            } else {
                p = p->next;
            }
        }
    }
}