#include <iostream>

using namespace std;

int searchFunc(string st, string ct);

int main() {
    string str    = "hello ascd abcde";
    string search = "abcde";
    cout << "Ищем: " << search << endl;
    cout << "В строке: " << str << endl;
    cout << "Позиция: " << searchFunc(str, search) << endl;
}

int searchFunc(string st, string ct) {
    /*
     * Сортировка методом Бойера-Мура
     */

    /* Работаем со строкой поиска */
    int stl, ctl;
    stl = st.size();
    ctl = ct.size();
    int i, p;
    int b[256];


    if(stl != 0 && ctl != 0 && stl >= ctl) { // проверка на сущ строки и шаблона
        for(i = 0; i < 256; i++) {
            b[i] = ctl; // задаем смещение равное длине шаблона
        }
        for(i = ctl - 2; i >= 0; i--) { // корректировка массива
            if (b[(int) (unsigned) (char) ct[i]] == ctl) { // для символов шаблона находим их ячейку в массиве
                b[(int) (unsigned) (char) ct[i]] = ctl - i - 1; // присваиваем необходимое значение
            }
        }
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