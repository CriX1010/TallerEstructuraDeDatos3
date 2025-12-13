#include <chrono>
#include <iostream>
#include "../include/Sistema.h"
using namespace std;

int main() {
    Sistema* sistema = new Sistema(3);

    cout<<"Bienvenidos al sistema :D\n"<<endl;
    cout<<"¿Que desea hacer?\n"<<endl;
    int opcion;
    do {
        cout<<"1. Insertar Nodo Grafo"<<endl;
        cout<<"2. Buscar Nodo Grafo"<<endl;
        cout<<"3. Crear Nodo"<<endl;
        cout<<"4. Eliminar Archivo"<<endl;
        cout<<"5. Listar Contenido"<<endl;
        cout<<"6. Obtener Rutas Completas"<<endl;
        cout<<"7. Obtener Espacio ocupado"<<endl;
        cout<<"0. Salir"<<endl;

        cout<<">  ";
        cin>>opcion;

        if (opcion==0) {
            cout<<"Gracias por utilizar nuestro sistema. Nos vemos... :D"<<endl;
        }else if (opcion==1) {
            int op2;

            cout<<"Insertar un ....\n"<<endl;
            cout<<"1. Directorio"<<endl;
            cout<<"2. Archivo"<<endl;
            cout<<"0. Salir"<<endl;
            cin>>op2;

            if (op2 == 0) {
                break;
            }else if (op2==1) {
                int op2_1;
                cout<<"¿Dentro de otro directorio?\n"<<endl;
                cout<<"1. Si"<<endl;
                cout<<"2. No"<<endl;
                cout<<"0. Salir"<<endl;
                cin>>op2_1;
                if (op2_1 == 0) {
                    break;
                }else if (op2_1==1) {
                    int id_directorio_padre;
                    cout<<"¿Cuál es la ID del directorio padre?\n"<<endl;
                    cout<<"> ";
                    cin>>id_directorio_padre;
                    cout<<endl;
                }else if (op2_1==2) {
                    sistema -> crear_Directorio(-1);
                }
            }else if (op2==2) {
                int id_directorio_padre;
                cout<<"ID del directorio padre: \n>";
                cin>>id_directorio_padre;
                cout<<endl;

                int tamaño;
                cout<<"Tamaño del archivo (KB): \n>";
                cin>>tamaño;
                cout<<endl;

                int tipo;
                cout<<"Tipo de archivo (0: Imagen; 1: Documento; 2: ejecutable; 3: Video; 4: Comprimido) :\n>";
                cin>>tipo;
                cout<<endl;
            }

        }else if (opcion==2) {

        }else if (opcion==3) {

        }else if (opcion==4) {

        }else if (opcion==5) {

        }else if (opcion==6) {

        }else if (opcion==7) {

        }


    }while (opcion != 0);


    return 0;
}