#include "../include/Sistema.h"

#include <iostream>
#include <ostream>


Sistema::Sistema(int n) {
    Arbol = new ArbolB(n);
    this->Id = 0;
    Arbol -> insertar(-1,new NodoDirectorio(-1));
}

Sistema::~Sistema() = default;

void Sistema::crear_Directorio(int id_padre) {
    auto* Nuevo = new NodoDirectorio(Id);
    auto* Aux = (NodoDirectorio*)Arbol -> buscar(id_padre);
    if (Aux) {
        Aux -> agregarHijo(Id);
        Arbol->insertar(Id, Nuevo);
        cout << "creaste el directorio con la id " << Id << endl;
        Id++;
    } else {cout << "no se pudo crear el directorio"<< endl;}
}

void Sistema::crear_Archivo(int tamaño, int tipo, int id_padre) {
    auto* Nuevo = new NodoArchivo(id_padre,tamaño,tipo);
    Arbol -> insertar(Id, Nuevo);
    auto* Aux = (NodoDirectorio*)Arbol -> buscar(id_padre);
    if (Aux) {
        Aux -> agregarHijo(Id);
        Arbol->insertar(Id, Nuevo);
        cout << "creaste el Archivo con la id " << Id << endl;
        Id++;
    } else {cout << "no se pudo crear el Archivo"<< endl;}
}

void Sistema::eliminar_Directorio(int id_padre, int id_propio) {
    auto* Aux = (NodoDirectorio*)Arbol -> buscar(id_padre);
    auto* Aux2 = (NodoDirectorio*)Arbol -> buscar(id_propio);
    if (Aux && Aux2) {
        Aux -> eliminarHijo(id_propio);
        Arbol -> remove(id_propio);
        cout << "eliminaste el Directorio con la id: " << Id << endl;
    } else if (!Aux2) {
        cout << "el directorio con id " << id_propio<< " no existe" << endl;
    } else {cout << "No se pudo eliminar el directorio" << endl;}
}

void Sistema::eliminar_Archivo(int id_padre, int id_propio) const{
    auto* Aux = (NodoDirectorio*)Arbol -> buscar(id_padre);
    auto* Aux2 = (NodoArchivo*)Arbol -> buscar(id_propio);
    if (Aux && Aux2) {
        Aux -> eliminarHijo(id_propio);
        Arbol -> remove(id_propio);
        cout << "eliminaste el Archivo con la id: " << Id << endl;
    } else if (!Aux2) {
        cout << "el Archivo con id " << id_propio << " no existe" << endl;
    } else {cout << "No se pudo eliminar el Archivo" << endl;}
}

void Sistema::listar_contenido(int id_directorio) {
    NodoDirectorio* Aux = (NodoDirectorio*)Arbol -> buscar(id_directorio);
    if (Aux) {
        int* punteros = Aux->lista_hijos();
        cout << "El directorio con id " << Id <<" Contiene : " << endl;
        while (punteros) {
            auto* Aux = Arbol -> buscar(*punteros);
            if (Aux-> es_directorio()) {
                cout << "Directorio con id " << Aux->obtener_id() << endl;
            } else {
                cout << "Archivo con id " << Aux->obtener_id() << endl;
            }
            punteros+=1;
        }
    } else {cout << "No se encontro el directorio " << endl;}
}

std::string *Sistema::obtener_rutas_completas(int id_archivo) {


    return nullptr;
}

int Sistema::calcular_espacio_ocupado(int id_directorio) {


    return 0;
}

ArbolB* Sistema::GetArbol() const {
    return Arbol;
}





