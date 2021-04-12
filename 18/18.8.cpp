#include "includes/18.8/print.h"
#include "includes/18.8/magazin.h"
#include "includes/18.8/object.h"
#include "includes/18.8/list.h"
#include "includes/18.8/dialog.h"

#include <iostream>

using namespace std;

int main() {
    cout << "Печатное издание: " << endl;
    Print* a = new Print;
    a->Input();
    system("clear");
    cout << "Журнал: " << endl;
    Magazin* b = new Magazin;
    b->Input();

    List v(2);
    Object* p = a;
    v.Add();
    p = b;
    v.Add();
    v.Show();
    v.Del();

    cout << "\nVector size = " << v();

    Dialog D;
    D.Execute();
}