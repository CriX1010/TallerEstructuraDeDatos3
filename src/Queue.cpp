#include "../include/Queue.h"
#include <iostream>

Queue::Queue() {
    this->front_queue = nullptr;
    this->back_queue = nullptr;
}
bool Queue::empty() const {
    return this-> front_queue == nullptr;
}

void Queue::push(int x) {
    Nodo* nuevo = new Nodo(x);

    if (empty()) {
        this -> front_queue = this -> back_queue = nuevo;
    } else {
        this -> back_queue -> sig = nuevo;
        this -> back_queue = nuevo;
    }
}

int Queue::pop() {
    if (empty()) {
        throw std::runtime_error("La Cola esta vacía.");
    }

    Nodo* temp = this -> front_queue;
    int valor = temp -> dato;

    this -> front_queue = this-> front_queue -> sig;

    if (this -> front_queue == nullptr) {
        this -> back_queue = nullptr;
    }
    delete temp;

    return valor;
}

int Queue::front() const {

    if (empty()) {
        throw std::runtime_error("La Cola esta vacía.");
    }

    return this -> front_queue->dato;
}

int Queue::back() const {
    if (empty()) {
        throw std::runtime_error("La Cola está vacía.");
    }
    return this->back_queue->dato;
}

Queue::~Queue() {
    while (!empty()) {pop();}
}
