#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main() {
    cout << "Введите количество элементов в бинарном дереве:" << endl;
    do {
        cout << ">";
        cin >> array_numbers_size;
        if (array_numbers_size < 1)
            cout << "Введите положительное число" << endl;
    } while (array_numbers_size < 1);
    array_numbers = new double[array_numbers_size];
    BinaryTree tree;
    cout << "Введите вещественные числа:\n";
    tree.create_balanced_binary_tree(array_numbers_size);
    system("clear");
    cout << "\t\tВЫВОД БИНАРНОГО ДЕРЕВА";
    cout << "\n\t\tГлубина дерева: " << tree.depth_tree();
    tree.print_tree();
    cout << "\n\n\n\n";
    cin.get();
    system("clear");
    BinaryTree search_tree;
    for (int i = 0; i < array_numbers_size; i++)
        search_tree.insert_in_search_tree(array_numbers[i]);

    isBalancedSortPrinting = false;
    cout << "\t\tВЫВОД БИНАРНОГО ДЕРЕВА ПОИСКА";
    cout << "\n\t\tГлубина дерева: " << search_tree.depth_tree();
    search_tree.print_tree();
    cout << "\n\n\n\n";
    cin.get();
    cout << endl;
    cout << "Максимальное значение элемента в дереве: " << search_tree.find_max() << endl;
    cin.get();
    system("clear");
    search_tree.print_tree();
    cin.get();
    return 0;
}