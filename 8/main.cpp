#include <iostream>

using namespace std;

struct State {
    string title;   // название страны
    string lang;    // язык
    string money;   // Как называется валюта
    float course;   // Курс
};

struct List {
    State data;  // Элемент списка
    List* next; // Указатель на следующий элемент
};

List* readFile() {
    List* first, *p;
    first = NULL; // Пока нет элементов, указываем на нул

    FILE *fp;
    if((fp = fopen("data.dat", "rb")) == NULL) {
        perror("\nОшибка при открытии файла data.dat");
        exit(0);
    }
    fclose(fp);

    p = new List;
    if(!feof(fp)) {
        fread(&p, sizeof(p), 1, fp);
    }
    cout << p->data.title << endl;
    cout << "Чтение окончено" << endl;
    return first;
}

void saveFile(List* first) {
    if(first == NULL) {
        cout << "Список пуст" << endl;
    } else {
        List* p = first;

        FILE *fp;
        if((fp = fopen("data.dat", "wb")) == NULL) {
            perror("\nОшибка при открытии файла data.dat");
            exit(0);
        }
        rewind(fp);

        while (!feof(fp) && p != NULL) {
            /*
            fwrite(&p->data.title, sizeof(string), 1, fp);
            fwrite(&p->data.lang, sizeof(string), 1, fp);
            fwrite(&p->data.money, sizeof(string), 1, fp);
            fwrite(&p->data.course, sizeof(float), 1, fp);
            */
            fwrite(&p, sizeof(*p), 1, fp);
            p = p->next;
        }
        fclose(fp);
    }
}

List* make() {
    List* first, *p;
    first = NULL; // Пока нет элементов, указываем на нул

    p = new List;   // Память под элемент

    // Инициализация первого элемента
    p->data.title = "Россия";
    p->data.lang = "Русский";
    p->data.money = "Рубль";
    p->data.course = 72.4;
    p->next = NULL; // Это последний элемент

    first = p;

    List* h = new List; // Память под новый элемент
    p->next = h;
    p = p->next;        // Перешли к управлению над след элементом, так сказать :)
    p->data.title = "Украина";
    p->data.lang = "Украинский";
    p->data.money = "Гривна";
    p->data.course = 18.4;
    p->next = NULL; // Это последний элемент
    return first;
}

void del(List* &first) {
    if(first == NULL) {
        cout << "Список пуст" << endl;
    } else {
        List* p = first;
        string title;
        cout << "Введите государство, которое будет удалено:" << endl;
        cin >> title;
        while(p->data.title == title) {
            List* q = p->next;
            first = p->next;
            delete q;
            p = first;
            cout << "Найден элемент" << endl;
        }
        while(p->next != NULL) {
            if(p->next->data.title == title) {
                List* q = p->next;
                p->next = p->next->next; // Делаем "прыжок" через одного
                delete q;
            } else
                p = p->next;
        }
    }
}

void add(List* &first, int count) {
    if (first == NULL) {
        cout << "Список пуст" << endl;
    } else {
        cout << "Добавление элементов" << endl;
        List* p = first;
        int size = 0;
        while (p->next != NULL) {
            p = p->next;
            size++;
        }
        p = first;
        for(int i = 1; i < size; i++) {
            p = p->next;
        }

        for (int i = 1; i <= count; i++) {
            List* h = new List;
            List* q = p;
            p->next = h;
            p = p->next;

            cout << "Введите название страны: ";
            cin >> p->data.title;

            cout << "Введите язык: ";
            cin >> p->data.lang;

            cout << "Введите денежную еденицу: ";
            cin >> p->data.money;

            cout << "Введите курс USD: ";
            cin >> p->data.course;

            p->next = NULL;
        }
    }
}

void print(List* first) {
    if(first == NULL) {
        cout << "Список пуст" << endl;
    } else {
        List* p = first;
        while (p != NULL) {
            cout << "Страна: " << p->data.title << " | ";
            cout << "Язык: " << p->data.lang << " | ";
            cout << "Валюта: " << p->data.money << " | ";
            cout << "Курс USD: " << p->data.course << endl;
            p = p->next;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    // List* list = readFile();
    // return 0;
    List* list = make();
    saveFile(list);
    readFile();
    return 0;

    cout << "Актуальный список" << endl;
    print(list);
    cout << endl;

    del(list);

    cout << "Актуальный список" << endl;
    print(list);
    cout << endl;

    add(list, 2);

    cout << "Актуальный список" << endl;
    print(list);
    cout << endl;

    return 0;
}