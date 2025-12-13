#include <iostream>
#include "../include/Sistema.h"
using namespace std;

static void limpiarEntrada() {
    cin.clear();
    cin.ignore(1000000, '\n');
}

int leerEntero(const string& mensaje) {
    int x;
    while (true) {
        cout << mensaje;
        if (cin >> x) {
            cin.ignore(1000000, '\n');
            return x;
        }
        limpiarEntrada();
        cout << "Entrada invalida. Debes ingresar un número entero.\n\n";
    }
}

int leerEnteroRango(const string& mensaje, int valorMin, int valorMax) {
    while (true) {
        int x = leerEntero(mensaje);
        if (x >= valorMin && x <= valorMax) return x;
        cout << "Fuera de rango. La opcion debe estar entre " << valorMin << " y " << valorMax << ".\n\n";
    }
}

int leerEnteroMin_paraID(const string& mensaje, int valorMin) {
    while (true) {
        int x = leerEntero(mensaje);
        if (x >= valorMin) return x;
        cout << "Valor invalido. Debe ser >= " << valorMin << ".\n\n";
    }
}

int main() {
    Sistema* sistema = new Sistema(3);

    cout << "Bienvenidos al sistema :D\n\n";

    while (true) {
        cout << "¿Que desea hacer?\n\n";
        cout << "1. Insertar Nodo Grafo\n";
        cout << "2. Buscar Nodo Grafo\n";
        cout << "3. Eliminar Archivo\n";
        cout << "4. Listar Contenido\n";
        cout << "5. Obtener Rutas Completas\n";
        cout << "6. Obtener Espacio ocupado\n";
        cout << "0. Salir\n";

        int opcion = leerEnteroRango("> ", 0, 6);
        cout << "\n";

        if (opcion == 0) {
            cout << "Gracias por utilizar nuestro sistema. Nos vemos... :D\n";
            break;
        }

        if (opcion == 1) {
            cout << "Insertar un ...\n\n";
            cout << "1. Directorio\n";
            cout << "2. Archivo\n";
            cout << "0. Volver\n";

            int op1 = leerEnteroRango("> ", 0, 2);
            cout << "\n";
            if (op1 == 0) continue;

            if (op1 == 1) {
                cout << "¿Dentro de otro directorio?\n\n";
                cout << "1. Si\n";
                cout << "2. No\n";
                cout << "0. Volver\n";

                int op1_1 = leerEnteroRango("> ", 0, 2);
                cout << "\n";
                if (op1_1 == 0) continue;

                if (op1_1 == 1) {
                    int id_padre = leerEnteroMin_paraID("ID del directorio padre: ", 0);
                    cout << "\n";
                    sistema->crear_Directorio(id_padre);
                } else {
                    sistema->crear_Directorio(-1);
                }
            } else {
                int id_padre = leerEnteroMin_paraID("ID del directorio padre: ", 0);
                int tamKB = leerEnteroMin_paraID("Tamaño del archivo (KB): ", 0);
                int tipo = leerEnteroRango(
                    "Tipo (0: Imagen, 1: Documento, 2: Ejecutable, 3: Video, 4: Comprimido): ",
                    0, 4
                );
                cout << "\n";
                sistema->crear_Archivo(tamKB, tipo, id_padre);
            }

            continue;
        }

        if (opcion == 2) {
            int id = leerEnteroMin_paraID("ID del elemento a buscar: ", 0);
            cout << "\n";

            auto* elemento = sistema->Arbol->buscar(id);
            if (elemento) cout << "Se encontro el elemento con ID " << id << ".\n\n";
            else cout << "No existe ningún elemento con ID " << id << ".\n\n";
            continue;
        }

        if (opcion == 3) {
            int id_archivo = leerEnteroMin_paraID("ID del archivo a eliminar: ", 0);
            int id_directorio_padre   = leerEnteroMin_paraID("ID del directorio padre del archivo a eliminar: ", 0);
            cout << "\n";
            sistema->eliminar_Archivo(id_directorio_padre, id_archivo);
            cout << "\n";
            continue;
        }

        if (opcion == 4) {
            int id_directorio = leerEnteroMin_paraID("ID del directorio para listar su contenido: ", 0);
            cout << "\n";
            sistema->listar_contenido(id_directorio);
            cout << "\n";
            continue;
        }

        if (opcion == 5) {
            int id_archivo = leerEnteroMin_paraID("ID del archivo para conocer sus rutas: ", 0);
            cout << "\n";
            sistema->obtener_rutas_completas(id_archivo);
            cout << "\n";
            continue;
        }

        if (opcion == 6) {
            int id_directorio = leerEnteroMin_paraID("ID del directorio para conocer el espacio ocupado: ", 0);
            cout << "\n";
            sistema->calcular_espacio_ocupado(id_directorio);
            cout << "\n";
            continue;
        }
    }

    delete sistema;
    return 0;
}