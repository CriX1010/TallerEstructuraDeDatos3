#include "../include/Sistema.h"

#include <iostream>
#include <ostream>

#include "../include/ArbolB.h"
#include "../include/NodoArchivo.h"
#include "../include/NodoDirectorio.h"


Sistema::Sistema(int n) {
    Arbol = new ArbolB(n);
    this->Id = 0;
}

Sistema::~Sistema() {}

void Sistema::crear_Directorio(int id_padre) {
    NodoDirectorio* Nuevo = new NodoDirectorio(Id);
    Arbol->insertar(Id, Nuevo);
    cout << "creaste el directorio con la id " << Id << endl;
    Id++;
}

void Sistema::crear_Archivo(int tamaño, int tipo, int id_padre) {
    NodoArchivo* Nuevo = new NodoArchivo(id_padre,tamaño,tipo);
    Arbol -> insertar(Id, Nuevo);
    Id++;
}

void Sistema::eliminar_Directorio(int id_padre, int id_propio) {

}

void Sistema::eliminar_Archivo(int id_padre, int id_propio) {

}

void Sistema::listar_contenido(int id_directorio) {

}

std::string *Sistema::obtener_rutas_completas(int id_archivo) {

}

int Sistema::calcular_espacio_ocupado(int id_directorio) {

}

ArbolB* Sistema::GetArbol() {
    return Arbol;
}





