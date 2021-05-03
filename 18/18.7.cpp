#include <iostream>

using namespace std;

#include "includes/vector_18.7.h"
#include "includes/money.h"

int main() {
    Vector<int>A(5, 0);
    cout << "A: "; cin >> A;
    cout << "A: " << A << endl;
    Vector <int>B(10, 1);
    cout << "B: " << B << endl;
    B = A;
    cout << "B: " << B << endl;

    Money t;
    cin >> t;
    cout << "t: " << t;
    int k;
    cout << endl << "k: ";
    cin >> k;
    Money d(k, k);
    Money p;
    p = t - d;
    cout <<"p: " << p;
    Money q;
    cout <<endl<< "Enter q: ";
    cin >> q;
    cout << "q: " << q;
    Vector<Money> C(5, q);
    cout << endl << "Enter C: ";
    cin >> C;
    cout << "C: " << C << endl;
    Vector<Money> D(10, q);
    cout << "D: " << D << endl;
    D = C;
    cout << "D: " << D << endl;
    cout << "C[2]: " << C[2] << endl;
    cout << "size C()=" << C() << endl;
    D = C - q;
    cout << "D=C-q: " << D << endl;
}