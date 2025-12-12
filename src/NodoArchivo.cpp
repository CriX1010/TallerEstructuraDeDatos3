#include "../include/NodoArchivo.h"

NodoArchivo::NodoArchivo(int id, int tamaño, int tipo):NodoGrafo(id){
    this->tamaño = tamaño;
    this->tipo = tipo;
    this->cant_padres = 0;
    this->lista_padres = nullptr;
}


NodoArchivo::~NodoArchivo() {delete this->lista_padres;}

int* NodoArchivo::devolver_lista_padres() {
    return this->lista_padres;
}

int NodoArchivo::devolver_tipo() {
    return this->tipo;
}

int NodoArchivo::devolver_tamaño() {
    return this->tamaño;
}



