#include <iostream>

using namespace std;

#include "includes/money.h"

int main() {
    Money a;
    Money b;
    Money c;
    cin >> a;
    cin >> b;
    // a++;
    // cout << "a+1 копейка = " << a << endl;
    // c = (a++)+b;
    c = a+b;
    cout << "A = " << a << endl;
    cout << "B = " << b << endl;
    if(a == b) cout << "a == b" << endl;
    if(a != b) cout << "a != b" << endl;
    cout << "A = " << --a << endl;
    // cout << "C = (a+1 копейка + b) = " << c << endl;
}