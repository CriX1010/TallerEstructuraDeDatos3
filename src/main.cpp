#include <iostream>

#include "../include/Sistema.h"

using namespace std;

int main () {
    cout<<"Hola mundo"<<endl;

    auto* S = new Sistema(3);
    S-> crear_Directorio(-1);//0
    S-> crear_Directorio(-1);//1
    S-> crear_Directorio(0);//2
    S-> crear_Directorio(0);//3

    S-> crear_Archivo(10,1,3);
    S-> crear_Archivo(10,2,3);
    S-> crear_Archivo(10,3,3);



    delete S;
    return 0;
}