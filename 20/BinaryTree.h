//
// Created by alexandr on 02.05.2021.
//

#ifndef PRACTICE_PSTU_BINARYTREE_H
#define PRACTICE_PSTU_BINARYTREE_H

#include <iostream>
#include <stdio.h>

using namespace std;

void SetCursorPos(int XPos, int YPos)
{
    printf("\033[%d;%dH", YPos+1, XPos+1);
}

double* array_numbers;
int array_numbers_size;
int indx = 1;
bool isBalancedSortPrinting = true;
const int start_x_position = 100;

struct Node {
    double data;
    Node *left, *right;
};

class BinaryTree {
private:
    Node* root;
    void delete_tree(Node* leaf) {
        if (leaf != NULL) {
            delete_tree(leaf->left);
            delete_tree(leaf->right);
            delete leaf;
        }
    }
    bool isElementInTree(Node* leaf, const double& element) {
        if (leaf == NULL)
            return false;
        if (leaf->data == element)
            return true;
        if (element < leaf->data)
            isElementInTree(leaf->left, element);
        return isElementInTree(leaf->right, element);
    }
    void get_subtrees_sizes(const int size, int& left_size, int& right_size) {
        if ((size - 1) % 2 == 0) {
            left_size = (size - 1) / 2;
            right_size = left_size;
        }
        else {
            left_size = size / 2;
            right_size = (size - 1) / 2;
        }
    }
    void create_balanced_binary_tree(Node*& leaf, int size) {
        if (size == 0) {
            leaf = NULL;
            return;
        }
        cout << indx + 1 << ") ";
        double number;
        cin >> number;
        array_numbers[indx] = number;
        indx++;
        leaf = new Node;
        leaf->data = number;
        int left_subtree_size, right_subtree_size;
        get_subtrees_sizes(size, left_subtree_size, right_subtree_size);
        create_balanced_binary_tree(leaf->left, left_subtree_size);
        create_balanced_binary_tree(leaf->right, right_subtree_size);
    }
    int depth_tree(Node* leaf) {
        if (leaf == NULL)
            return 0;
        return max(depth_tree(leaf->right), depth_tree(leaf->left)) + 1;
    }
    void print_branch(Node* leaf, int x, int y) {
        if (leaf == NULL)
            return;

        SetCursorPos(x, y);
        cout << leaf->data;
        int formula_new_x_left_leaf, formula_new_x_right_leaf;
        if (isBalancedSortPrinting) {
            formula_new_x_left_leaf = x - 2 * (y + 2);
            formula_new_x_right_leaf = x + 2 * (y + 2);
        }
        else {
            formula_new_x_left_leaf = x - 2 * (y + 1);
            formula_new_x_right_leaf = x + 2 * y;
        }
        print_branch(leaf->left, formula_new_x_left_leaf, y + 2);
        print_branch(leaf->right, formula_new_x_right_leaf, y + 2);
    }
    void print_tree(Node*& leaf) {
        if (leaf == NULL)
            return;
        Node* branch_left = NULL;
        Node* branch_right = NULL;
        branch_left = leaf->left;
        branch_right = leaf->right;
        SetCursorPos(start_x_position, 3);
        cout << leaf->data;
        int depthOfTheTree = depth_tree(leaf);
        int offset_coefficient;
        if (isBalancedSortPrinting)
            offset_coefficient = 6;
        else
            offset_coefficient = 4;
        print_branch(branch_left, start_x_position - offset_coefficient * depthOfTheTree, 5);
        print_branch(branch_right, start_x_position + offset_coefficient * depthOfTheTree, 5);
    }
    Node* insert_in_search_tree(Node*& leaf, const double element) {
        if (isElementInTree(leaf, element))
            return leaf;

        if (leaf == NULL) {
            Node* new_leaf = new Node;
            new_leaf->data = element;
            new_leaf->left = NULL;
            new_leaf->right = NULL;
            return new_leaf;
        }
        if (element < leaf->data)
            leaf->left = insert_in_search_tree(leaf->left, element);
        if (element > leaf->data)
            leaf->right = insert_in_search_tree(leaf->right, element);
        return leaf;
    }
    double find_max(Node* leaf) {
        system("clear");
        cout << "\t\tПРОЦЕСС ПОИСКА СЕРДНЕГО АРИФМЕТИЧЕСКОГО\n";
        print_tree(leaf);
        cout << endl;
        getchar();
        system("clear");
        if (leaf->right == NULL)
            return leaf->data;
        return find_max(leaf->right);
    }

public:
    BinaryTree() {
        root = NULL;
    }
    ~BinaryTree() {
        delete_tree(root);
    }
    void create_balanced_binary_tree(int size) {
        double number;
        cout << "1) ";
        cin >> number;
        root = new Node;
        root->data = number;
        array_numbers[0] = number;
        if ((size - 1) > 0) {
            int left_subtree_size, right_subtree_size;
            get_subtrees_sizes(size, left_subtree_size, right_subtree_size);
            create_balanced_binary_tree(root->left, left_subtree_size);
            create_balanced_binary_tree(root->right, right_subtree_size);
        }
    }

    int depth_tree() {
        return depth_tree(root);
    }
    void print_tree() {
        print_tree(root);
    }
    void insert_in_search_tree(const double element) {
        root = insert_in_search_tree(root, element);
    }

    double find_max() {
        return find_max(root);
    }

};

#endif //PRACTICE_PSTU_BINARYTREE_H
