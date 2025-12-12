#include "../include/Stack.h"
#include <iostream>


Stack::Stack() {
    this-> top_stack = nullptr;
}

bool Stack::empty() const {
    return this->top_stack == nullptr;
}

void Stack::push(int x) {
    Nodo* nuevo = new Nodo(x);
    nuevo -> sig = this -> top_stack;
    this -> top_stack = nuevo;
}

int Stack::pop() {
    if (empty()) { throw std::runtime_error("La pila esta vacía.");}
    Nodo* temp = this -> top_stack;
    int valor = temp -> dato;
    this->top_stack = this->top_stack -> sig;
    delete temp;
    return valor;
}

int Stack::top() const {
    if (empty()) { throw std::runtime_error("La pila esta vacía.");}
    return this -> top_stack -> dato;
}

Stack::~Stack() {
    while (!empty()) {pop();}
}



