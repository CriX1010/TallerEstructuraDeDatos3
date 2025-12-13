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
        cout<<"3. Eliminar Archivo"<<endl;
        cout<<"4. Listar Contenido"<<endl;
        cout<<"5. Obtener Rutas Completas"<<endl;
        cout<<"6. Obtener Espacio ocupado"<<endl;
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
                    sistema -> crear_Directorio(id_directorio_padre);

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

                sistema -> crear_Archivo(tamaño,tipo,id_directorio_padre);

            }

        }else if (opcion==2) {

            int id_directorio;
            cout<<"ID del elemento a buscar: \n>";
            cin>>id_directorio;

            auto* elemento = sistema ->Arbol ->buscar(id_directorio);

            if (elemento) {cout << "se encontro el elemento buscado con id " << id_directorio << endl;}


        }else if (opcion==3) {
            int id_archivo;
            int id_padre;
            cout<<"ID de archivo a eliminar: \n>";
            cin>>id_archivo;
            cout<<"ID del padre del archivo a eliminar: \n>";
            cin>>id_padre;
            sistema -> eliminar_Archivo(id_padre,id_archivo);

        }else if (opcion==4) {
            int id_directorio;
            cout<<"ID del directorio a conocer su contenido: \n>";
            cin>>id_directorio;

            sistema ->listar_contenido(id_directorio);

        }else if (opcion==5) {
            int id_archivo;
            cout<<"ID de archivo a conocer sus rutas: \n>";
            cin>>id_archivo;

            sistema ->obtener_rutas_completas(id_archivo);

        }else if (opcion==6) {
            int id_directorio;
            cout<<"ID del directorio, para conocer el espacio que sus archivos ocupan: \n>";
            cin>>id_directorio;
            sistema -> obtener_rutas_completas(id_directorio);

        }

        if (opcion!= 0 && opcion != 1) {
            cout<<"Opcion no valida.\n";
        }


    }while (opcion != 0);


    return 0;
}