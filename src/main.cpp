#include <iostream>

#include "NodoBInterno.cpp"
#include "NodoBHoja.cpp"
#include "NodoBPlusBase.cpp"

using namespace std;

int main () {
    cout<<"Hola mundo"<<endl;

    NodoBPlusBase* Arbol = new NodoBInterno(2);

    cout<<"Hola mundo"<<endl;

    return 0;
}