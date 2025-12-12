#pragma once
#include "Nodo.h"

class Stack {

private:
    Nodo* top_stack;

public:
    Stack();
    bool empty() const;
    void push(int x);
    int pop();
    int top() const;
    ~Stack();
};
