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

struct State {
    string name;            // Фио
    string birthday;        // Дата рождения
    int birthday_weight;    // 'вес' даты
    string pasport;         // Паспорт
};

struct Node {
    State data;     // Элемент списка
    Node* next;     // Указатель на следующий элемент
    Node* prev;     // Указатель на прошлый элемент
};

Node* make();
void print(Node* first);
void searchLinear(Node* first);
int parseDate(string &input);

void searchInString(Node* first); // Основная

int searchInterpol(Node* first);
void insertionSort(struct Node **head_ref);

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "Rus");

    Node* list = make();

    int choice;
    do {
        cout << "Main Menu" << endl;
        cout << "1 - Генерация списка (not yet)" << endl;
        cout << "2 - Вывести текущий список" << endl << endl;
        cout << "3 - Линейный поиск" << endl;
        cout << "4 - Интерполяционный поиск" << endl;
        cout << "5 - Прямой поиск подстроки в строке" << endl;
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
            case 3:
                searchLinear(list);
                break;
            case 4:
                // Сортировка списка
                insertionSort(&list);
                searchInterpol(list);
                break;
            case 5:
                searchInString(list);
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

void searchLinear(Node* first) {
    if(first == NULL) {
        cout << "Список пуст" << endl;
    } else {
        system("clear");
        string search;
        cout << "Введите дату рождения для поиска" << endl;
        cin >> search;


        unsigned int start_time =  clock(); // начальное время
        int search_count = 0;
        Node* p = first;
        while (p != NULL) {
            search_count += 1;
            if(p->data.birthday == search) {
                cout << "ФИО: " << p->data.name << " | ";
                cout << "Дата рождения: " << p->data.birthday << " | ";
                cout << "Паспорт: " << p->data.pasport << endl;
            }
            p = p->next;
        }
        unsigned int end_time = clock(); // конечное время
        unsigned int search_time = end_time - start_time; // искомое время

        cout << endl << "Debug:";
        cout << endl << "Пройдено сравнений: " << search_count;
        cout << endl << "Время выполнения функции: " << search_time/1000.0 << " мс." << endl;

        int out = 1;
        while(out != 0) {
            cout << endl << "0 - назад" << endl;
            cin >> out;
        }
        system("clear");
    }
}

int searchInStringFunc(string st, string ct, int b[256]); // Вспомогательная
void searchInString(Node* first) {
    if(first == NULL) {
        cout << "Список пуст" << endl;
    } else {
        system("clear");
        string search;
        cout << "Введите дату рождения для поиска" << endl;
        cin >> search;


        unsigned int start_time =  clock(); // начальное время
        int search_count = 0;
        int i, b[256];

        int ctl = search.size();
        for(i = 0; i < 256; i++) {
            b[i] = ctl; // задаем смещение равное длине шаблона
        }
        for(i = ctl - 2; i >= 0; i--) { // корректировка массива
            if (b[(int) (unsigned) (char) search[i]] == ctl) { // для символов шаблона находим их ячейку в массиве
                b[(int) (unsigned) (char) search[i]] = ctl - i - 1; // присваиваем необходимое значение
            }
        }

        Node* p = first;
        while (p != NULL) {
            search_count += 1;
            if(searchInStringFunc(p->data.birthday, search, b)) {
                cout << "ФИО: " << p->data.name << " | ";
                cout << "Дата рождения: " << p->data.birthday << " | ";
                cout << "Паспорт: " << p->data.pasport << endl;
            }
            p = p->next;
        }
        unsigned int end_time = clock(); // конечное время
        unsigned int search_time = end_time - start_time; // искомое время

        cout << endl << "Debug:";
        cout << endl << "Пройдено сравнений: " << search_count;
        cout << endl << "Время выполнения функции: " << search_time/1000.0 << " мс." << endl;

        int out = 1;
        while(out != 0) {
            cout << endl << "0 - назад" << endl;
            cin >> out;
        }
        system("clear");
    }
}

int searchInStringFunc(string st, string ct, int b[256]) {
    /* Работаем со строкой поиска */
    int stl, ctl;
    stl = st.size();
    ctl = ct.size();
    int i, p;

    if(stl != 0 && ctl != 0 && stl >= ctl) { // проверка на сущ строки и шаблона
        p = ctl - 1; // позиция последнего элемента шаблона относительно строки

        while(p < stl) { // пока строка не все
            if(ct[ctl - 1] != st[p]) { // если символы не совпали
                p += b[(int)(unsigned)(char)st[p]];
            } else {
                for(i = ctl - 1; i >= 0; i--) { // Проверяем каждый элемент
                    if(ct[i] != st[p - ctl + i + 1]) {
                        p += b[(int)(unsigned)(char)st[p]];
                        break;
                    } else if(i == 0) {
                        return p - ctl + 1;
                    }
                }
            }
        }
    }

    return -1;
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

void addElements() {

}

/*
 * Credits:
 * https://www.geeksforgeeks.org/insertion-sort-for-singly-linked-list/
 */


void sortedInsert(struct Node**, struct Node*);
void insertionSort(struct Node **head_ref)
{
    struct Node *sorted = NULL;
    struct Node *current = *head_ref;
    while (current != NULL)
    {
        struct Node *next = current->next;
        sortedInsert(&sorted, current);
        current = next;
    }
    *head_ref = sorted;
}

void sortedInsert(struct Node** head_ref, struct Node* new_node)
{
    struct Node* current;
    if (*head_ref == NULL || (*head_ref)->data.birthday_weight >= new_node->data.birthday_weight)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else
    {
        current = *head_ref;
        while (current->next!=NULL &&
               current->next->data.birthday_weight < new_node->data.birthday_weight)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

int searchInterpol(Node* first) {
    system("clear");

    cout << "Введите дату рождения для поиска" << endl;
    cout << "Формат: дд.мм.гггг" << endl;
    string searchStr;
    cin >> searchStr;
    int searchInt;
    searchInt = parseDate(searchStr);



    // Я пытался посчитать через sizeof, но не очень получилось :(
    int counter = 0;
    Node* p = first;
    while(p != NULL) {
        counter++;
        p = p->next;
    }

    State* arrData = new State[counter];

    p = first;
    counter = 0;
    while(p != NULL) {
        arrData[counter].name = p->data.name;
        arrData[counter].birthday = p->data.birthday;
        arrData[counter].birthday_weight = p->data.birthday_weight;
        arrData[counter].pasport = p->data.pasport;

        counter++;
        p = p->next;
    }

    int lo = 0, hi = (counter - 1);

    while (lo <= hi && searchInt >= arrData[lo].birthday_weight && searchInt <= arrData[hi].birthday_weight) {
        if(lo == hi) {
            if(arrData[lo].birthday_weight == searchInt) {
                system("clear");
                cout << "Поиск успешно окончен. Найден результат: " << endl << endl;
                cout << "ФИО: " << arrData[lo].name << " | ";
                cout << "Дата рождения: " << arrData[lo].birthday << " | ";
                cout << "Паспорт: " << arrData[lo].pasport << endl;

                int out = 1;
                while(out != 0) {
                    cout << endl << "0 - назад" << endl;
                    cin >> out;
                }
                system("clear");
                return lo;
            }

            system("clear");
            cout << "Поиск окончен. По вашему запросу ничего не найдено. " << endl;
            cout << "DEBUG:: End point = 1 " << endl << endl;
            int out = 1;
            while(out != 0) {
                cout << endl << "0 - назад" << endl;
                cin >> out;
            }
            system("clear");
            return -1;
        }

        int pos = lo + (((double)(hi - lo) /
                         (arrData[hi].birthday_weight - arrData[lo].birthday_weight)) * (searchInt - arrData[lo].birthday_weight));

        if(arrData[pos].birthday_weight == searchInt) {
            system("clear");
            cout << "Поиск успешно окончен. Найден результат: " << endl << endl;
            cout << "ФИО: " << arrData[pos].name << " | ";
            cout << "Дата рождения: " << arrData[pos].birthday << " | ";
            cout << "Паспорт: " << arrData[pos].pasport << endl;

            int out = 1;
            while(out != 0) {
                cout << endl << "0 - назад" << endl;
                cin >> out;
            }
            system("clear");
            return pos;
        }

        if(arrData[pos].birthday_weight < searchInt)
            lo = pos + 1;
        else
            hi = pos - 1;
    }

    cout << "Поиск окончен. По вашему запросу ничего не найдено. " << endl;
    int out = 1;
    while(out != 0) {
        cout << endl << "0 - назад" << endl;
        cin >> out;
    }
    system("clear");
    return -1;
}