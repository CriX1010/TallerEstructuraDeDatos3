#include <iostream>
#include "../include/Sistema.h"
using namespace std;

int main() {
    Sistema* sistema = new Sistema();

    cout<<"Bienvenidos al sistema :D\n"<<endl;
    cout<<"¿Que desea hacer?\n"<<endl;
    int opcion;
    do {
        cout<<"1. Listar Contenido"<<endl;
        cout<<"2. Obtener Rutas Completas"<<endl;
        cout<<"3. Obtener Espacio ocupado"<<endl;
        cout<<"0. Salir"<<endl;

        cout<<">  ";
        cin>>opcion;

        if (opcion==0) {
            cout<<"Gracias por utilizar nuestro sistema. Nos vemos... :D"<<endl;
        }


    }while (opcion != 0);


    return 0;
}