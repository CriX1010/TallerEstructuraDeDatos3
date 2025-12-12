#pragma once
#include "Nodo.h"


class Queue {
private:
    Nodo* front_queue;
    Nodo* back_queue;

public:
    Queue();
    bool empty() const;
    void push(int x);
    int pop();
    int front() const;
    int back() const;
    ~Queue();

};
