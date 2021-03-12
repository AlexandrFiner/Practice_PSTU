#include <iostream>
#include <string>

using namespace std;

struct info
{
    string fio;
    string date;
    string number;
};

string correction(string str)
{
    int d = str.size();
    if (str[0] == '+' && str[1] == '7')
    {
        str[0] = '8';
        for (int j = 1; j < d; j++)
        {
            str[j] = str[j + 1];
        }
        d--;
    }
    for (int i = 0; i < d; i++)
    {
        while (str[i] == '+' || str[i] == '-' || str[i] == '(' || str[i] == ')' || str[i] == ' ')
        {
            for (int j = i; j < d; j++)
            {
                str[j] = str[j + 1];
            }
            d--;
        }
    }
    str.resize(d);
    return str;
}
bool knut_morris_pratt(string str, string obr)
{
    int ds, dk,i,j,k;
    bool res = 0;
    ds = str.size();
    dk = obr.size();
    if (ds == 0)
        cout << "Неверно задана строка\n";
    else if (dk == 0)
        cout << "Неверно задана подстрока\n";
    else
    {
        j = 0;
        k = -1;
    }
    int* pf = new int[1000];
    pf[0] = -1;
    while (j < dk - 1) {
        while (k >= 0 && obr[j] != obr[k])
            k = pf[k];
        j++;
        k++;
        if (obr[j] == obr[k])
            pf[j] = pf[k];
        else
            pf[j] = k;
    }
    i = 0;
    j = 0;
    while (j < dk && i < ds) {
        while (j >= 0 && str[i] != obr[j])
            j = pf[j];
        i++;
        j++;
    }
    delete[] pf;
    if (j == dk)
        res = 1;
    return res;
}
bool boyer_moor(string str, string obr) {
    int ds = str.size();
    int dk = obr.size();
    if (ds == 0)
        cout << "Неверно задана строка\n";
    else if (dk == 0)
        cout << "Неверно задана подстрока\n";
    else
        int  i, Pos;
    int  bmt[256];
    for (int i = 0; i < 256; i++)
        bmt[i] = dk;
    for (int i = dk - 1; i >= 0; i--)
        if (bmt[(short)(obr[i])] == dk)
            bmt[(short)(obr[i])] = dk - i - 1;
    int pos = dk - 1;
    while (pos < ds)
        if (obr[dk - 1] != str[pos])
            pos += bmt[(short)(str[pos])];
        else
            for (int i = dk - 2; i >= 0; i--) {
                if (obr[i] != str[pos - dk + i + 1]) {
                    pos += bmt[(short)(str[pos - dk + i + 1])] - 1;
                    break;
                }
                else
                if (i == 0)
                {
                    return true;
                }
            }
    return false;
}
void boyer(info* st, string key,int n)
{
    bool l;
    bool p = 0;
    for (int i = 0; i < n; i++)
    {
        l = boyer_moor(st[i].number, key);
        if (l != 0)
        {
            cout << "Элемент найден под номером: " << i << endl;
            cout << "ФИО: "<< st[i].fio << endl;
            cout << "Дата рождения: "<< st[i].date << endl;
            cout << "Номер телефона: " << st[i].number << endl;
            p = 1;
        }
    }
    if (p == 0)
    {
        cout << "Такого элемента не найдено" << endl;
    }
}
void knut(info* st, string key, int n)
{
    bool l;
    bool p = 0;
    for (int i = 0; i < n; i++)
    {
        l = knut_morris_pratt(st[i].number, key);
        if (l != 0)
        {
            cout << "Элемент найден под номером: " << i << endl;
            cout << "ФИО: " << st[i].fio << endl;
            cout << "Дата рождения: " << st[i].date << endl;
            cout << "Номер телефона: " << st[i].number << endl;
            p = 1;
        }
    }
    if (p == 0)
    {
        cout << "Такого элемента не найдено" << endl;
    }
}
int main()
{
    int n;
    string key;
    cout << "Кол-во элементов: ";
    cin >> n;
    cin.ignore();
    cout << "Ключ для поиска: ";
    getline(cin, key);
    key = correction(key);
    info* st = new info[n];
    for (int i = 0; i < n; i++)
    {
        cout << "ФИО: ";
        getline(cin, st[i].fio);
        cout << "Дата рождения: ";
        getline(cin, st[i].date);
        cout << "Номер телефона: ";
        getline(cin, st[i].number);
        st[i].number = correction(st[i].number);
    }
    bool a;
    cout << "Введите 0, если хотите произвести поиск алгоритмом Бойера-Мура. Введите 1, если хотите произвести поиск алгоритмом Кнута-Морриса-Пратта." << endl;
    cin >> a;
    switch (a)
    {
        case 0: boyer(st,key, n); break;
        case 1: knut(st, key, n); break;
        default: cout << "Неизвестная операция. Поиск не выполнен." << endl;
    }
    return 0;
}