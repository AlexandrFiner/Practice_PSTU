/*
 *
 * Шаблон заготовка
 * - Ключ: дата рождения
 * - Используется: списки
 *
 */

#include <iostream>
#include <ctime>

using namespace std;

#define RND_CNT 100

#define FAKE_DATA 14

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

void print(User* users, int counter);
User* make(int counter);

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "Rus");

    User* users = make(RND_CNT);
    print(users, RND_CNT);
}

int parseDate(string &input);

User* make(int counter) {
    User* arrData = new User[counter];

    for(int i = 0; i < counter; i++) {
        arrData[i].name = name_fake[rand() % FAKE_DATA];
        arrData[i].birthday = birthday_fake[rand() % FAKE_DATA];
        arrData[i].birthday_weight = parseDate(arrData[i].birthday);
        arrData[i].pasport = pasport_fake[rand() % FAKE_DATA];
    }
    return arrData;
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

void print(User* users, int counter) {
    for(int i = 0; i < counter; i++) {
        cout << "ФИО: " << users[i].name << " | ";
        cout << "Дата рождения: " << users[i].birthday << " | ";
        cout << "Паспорт: " << users[i].pasport << endl;
    }
}