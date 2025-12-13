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
            int op1;

            cout<<"Insertar un ....\n"<<endl;
            cout<<"1. Directorio"<<endl;
            cout<<"2. Archivo"<<endl;
            cout<<"0. Salir"<<endl;
            cin>>op1;

            if (op1 == 0) {
                break;
            }else if (op1==1) {
                int op1_1;
                cout<<"¿Dentro de otro directorio?\n"<<endl;
                cout<<"1. Si"<<endl;
                cout<<"2. No"<<endl;
                cout<<"0. Salir"<<endl;
                cin>>op1_1;
                if (op1_1 == 0) {
                    break;
                }else if (op1_1==1) {
                    int id_directorio_padre;
                    cout<<"¿Cuál es la ID del directorio padre?\n"<<endl;
                    cout<<"> ";
                    cin>>id_directorio_padre;

                }else if (op1_1==2) {
                    sistema -> crear_Directorio(-1);
                }
            }else if (op1==2) {
                int id_directorio_padre;
                cout<<"ID del directorio padre: \n>";
                cin>>id_directorio_padre;


                int tamaño;
                cout<<"Tamaño del archivo (KB): \n>";
                cin>>tamaño;


                int tipo;
                cout<<"Tipo de archivo (0: Imagen; 1: Documento; 2: ejecutable; 3: Video; 4: Comprimido) :\n>";
                cin>>tipo;

            }

        }else if (opcion==2) {
            int op2;

            cout<<"Buscar un ....\n"<<endl;
            cout<<"1. Directorio"<<endl;
            cout<<"2. Archivo"<<endl;
            cout<<"0. Salir"<<endl;
            cin>>op2;

            if (op2 == 0) {break;}
            else if (op2==1) {
                int id_directorio;
                cout<<"ID del directorio a buscar: \n>";
                cin>>id_directorio;

            }else if (op2==2) {
                int id_archivo;
                cout<<"ID de archivo a buscar: \n>";
                cin>>id_archivo;
            }

        }else if (opcion==3) {
            int op3;

            cout<<"Crear un ....\n"<<endl;
            cout<<"1. Directorio"<<endl;
            cout<<"2. Archivo"<<endl;
            cout<<"0. Salir"<<endl;
            cin>>op3;

            if (op3 == 0) {
                break;
            }else if (op3==1) {
                int id_directorio_padre;
                cout<<"¿Cuál es la ID del directorio padre?\n"<<endl;
                cout<<"> ";
                cin>>id_directorio_padre;

            }

        }else if (opcion==4) {
            int id_archivo;
            cout<<"ID de archivo a buscar: \n>";
            cin>>id_archivo;


        }else if (opcion==5) {
            int id_directorio;
            cout<<"ID del directorio a conocer su contenido: \n>";
            cin>>id_directorio;


        }else if (opcion==6) {
            int id_archivo;
            cout<<"ID de archivo a conocer sus rutas: \n>";
            cin>>id_archivo;

        }else if (opcion==7) {
            int id_directorio;
            cout<<"ID del directorio, para conocer el espacio que sus archivos ocupan: \n>";
            cin>>id_directorio;

        }

        if (opcion!= 0 && opcion != 1) {
            cout<<"Opcion no valida.\n";
        }


    }while (opcion != 0);


    return 0;
}