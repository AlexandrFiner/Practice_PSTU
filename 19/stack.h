//
// Created by alexandr on 12.04.2021.
//

#ifndef PRACTICE_PSTU_STACK_H
#define PRACTICE_PSTU_STACK_H

#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node<T>* next;
};

template <class T>
class Stack {
private:
    Node<T>* top;
public:
    Stack() {
        top = nullptr;
    }
    bool isEmpty();
    T Top();
    void push(const T& val);
    void pop();
    void print();
};

template <class T>
bool Stack<T>::isEmpty() {
    if (top == nullptr)
        return false;
    else
        return true;
}

template <class T>
T Stack<T>::Top() {
    if(top)
        return top->data;

    cout << "Stack is empty" << endl;
}

template <class T>
void Stack<T>::push(const T &val) {
    if (top == NULL) {
        top = new Node<T>;
        top->next = NULL;
        top->data = val;
    }
    else {
        Node<T>* temp = new Node<T>;
        temp->data = val;
        temp->next = top;
        top = temp;
    }
}

template <class T>
void Stack<T>::pop() {
    if(top == nullptr) {
        cout << "Stack is empty" << endl;
        return;
    }

    cout << top->data << " is popped" << endl;
    Node<T>* temp = top;
    top = top->next;
    delete temp;
}

template <class T>
void Stack<T>::print() {
    Node<T>* temp = top;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

#endif //PRACTICE_PSTU_STACK_H
