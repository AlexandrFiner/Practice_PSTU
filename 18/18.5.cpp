#include <iostream>

using namespace std;

#include "includes/triad.h"
#include "includes/date.h"

int main() {
    Date a(2020, 10, 25);
    cout << a;

    // Переопределение полей
    a.set_first(2021);
    a.set_second(1);
    a.set_third(10);
    cout << a;

    a++;
    cout << a;

    a + 33;
    cout << a;
}