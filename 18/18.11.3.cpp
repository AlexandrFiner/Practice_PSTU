#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

#include "includes/vector_18.7.h"
#include "includes/money.h"

int main() {
    srand(time(NULL));
    try {
        Vector<Money>vec(5);
        vec.Print();
    } catch (int) {
        cout << "error!" << endl;
    }
}