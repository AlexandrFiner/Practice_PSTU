/*
 *
 * Шаблон заготовка
 * - Ключ: дата рождения
 * - Используется: массива
 *
 */

#include <iostream>
#include <ctime>

using namespace std;

#define RND_CNT 100

#define FAKE_DATA 14

/*
 *
 */

// ФИО
string name_fake[FAKE_DATA] = {
    "Иванов Иван Иванович",
    "Петров Петр Петрович",
    "Александров Александр Александрович",
    "Иванов Петр Иванович",
    "Александров Петр Александрович",
    "Петров Иван Петрович",
    "Александров Иван Александрович",
    "Иванов Александр Иванович",
    "Петров Александр Петрович",
    "Иванов Петр Александрович",
    "Петров Александр Иванович",
    "Александров Петр Александрович",
    "Петров Иван Александрович",
    "Иванов Александр Петрович"
};

string birthday_fake[FAKE_DATA] = {
    "10.10.2001",
    "20.02.2002",
    "20.02.2003",
    "20.02.2004",
    "20.02.2005",
    "20.02.2006",
    "20.02.2007",
    "20.02.2008",
    "20.02.2009",
    "20.02.2010",
    "20.02.2011",
    "20.02.2012",
    "20.02.2013",
    "20.02.2014"
};

string pasport_fake[FAKE_DATA] = {
    "5715 403111",
    "5716 401022",
    "5717 401023",
    "5718 401024",
    "5719 401025",
    "5720 401026",
    "5721 401027",
    "5722 401028",
    "5723 401029",
    "5724 401010",
    "5725 401011",
    "5726 401012",
    "5727 401013",
    "5728 401014"
};

struct User {
    string name;            // Фио
    string birthday;        // Дата рождения
    int birthday_weight;    // 'вес' даты
    string pasport;         // Паспорт
};

struct Node {
    User data;     // Элемент списка
    Node* next;     // Указатель на следующий элемент
    Node* prev;     // Указатель на прошлый элемент
};

Node* make();
void print(Node* first);
int parseDate(string &input);

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "Rus");

    Node* list = make();

    int choice;
    do {
        cout << "Main Menu" << endl;
        cout << "1 - Генерация списка (not yet)" << endl;
        cout << "2 - Вывести текущий список" << endl << endl;
        cout << endl << endl << "0 - ВЫХОД" << endl;
        cin >> choice;
        system("clear");
        switch (choice) {
            case 0:
                break;
            case 1:
                break;
            case 2:
                print(list);
                break;
        }
    } while (choice != 0);
}

Node* make() {
    Node* first, *p;
    first = NULL;

    p = new Node;
    p->data.name = name_fake[rand() % FAKE_DATA];
    p->data.birthday = birthday_fake[rand() % FAKE_DATA];
    p->data.birthday_weight = parseDate(p->data.birthday);
    p->data.pasport = pasport_fake[rand() % FAKE_DATA];
    p->next = NULL;
    p->prev = NULL;

    first = p;

    for(int i = 2; i <= RND_CNT; i++) {
        Node* h = new Node; // Память под новый элемент
        Node* q = p;
        p->next = h;
        p = p->next;  // Перешли к управлению над след элементом, так сказать :)
        p->data.name = name_fake[rand() % FAKE_DATA];
        p->data.birthday = birthday_fake[rand() % FAKE_DATA];
        p->data.birthday_weight = parseDate(p->data.birthday);
        p->data.pasport = pasport_fake[rand() % FAKE_DATA];
        p->next = NULL; // Это последний элемент
        p->prev = q;
    }

    return first;
}

void print(Node* first) {
    if(first == NULL) {
        cout << "Список пуст" << endl;
    } else {
        Node* p = first;
        while (p != NULL) {
            cout << "ФИО: " << p->data.name << " | ";
            cout << "Дата рождения: " << p->data.birthday << " | ";
            cout << "Паспорт: " << p->data.pasport << endl;
            p = p->next;
        }
        int out = 1;
        while(out != 0) {
            cout << endl << "0 - назад" << endl;
            cin >> out;
        }
        system("clear");
    }
}

int parseDate(string &input) {
    int day;
    int month;
    int year;
    if (sscanf(input.c_str(), "%d.%d.%d", &day, &month, &year) != 3) {
        // обработка ошибок
        // но пока тут ничего нет :)
    } else {
        return 100 * year + 10 * month + day;
    }
    return 0;
}