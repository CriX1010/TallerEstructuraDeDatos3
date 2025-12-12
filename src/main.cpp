#include <iostream>

#include "Sistema.cpp"

using namespace std;

int main () {
    cout<<"Hola mundo"<<endl;

    auto* S = new Sistema(3);

    S -> crear_Directorio(-1);


    return 0;
}