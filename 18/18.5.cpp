#include <iostream>

using namespace std;

#include "includes/object.h"
#include "includes/triad_object.h"
#include "includes/vector.h"
#include "includes/date.h"

int main() {
    /*
    Triad a;
    cin >> a;
    cout << a << endl;
    Obj *p = &a;
    p->Show();
    */

    Vector v(5); // Вектор из 5 элемент

    Triad a;
    cin >> a;

    Date b;
    cin >> b;

    Obj*p=&a;
    v.Add(p);
    p=&b;
    v.Add(p);
    cout << "Содержание вектора" << endl;
    cout << v;
}