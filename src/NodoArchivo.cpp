#include "../include/NodoArchivo.h"

NodoArchivo::NodoArchivo(int id, int tamaño, int tipo):NodoGrafo(id){
    this->tamaño = tamaño;
    this->tipo = tipo;
    this->cant_padres = 0;
    this->lista_padres_propio = nullptr;
}


NodoArchivo::~NodoArchivo() {delete[] this->lista_padres_propio;}

int* NodoArchivo::lista_padres() {
    return this->lista_padres_propio;
}

int NodoArchivo::devolver_tipo() const {
    return this->tipo;
}

int NodoArchivo::devolver_tamaño() const {
    return this->tamaño;
}

void NodoArchivo::agregar_padre(int id_padre) {
    int* nueva_lista = new int[this->cant_padres + 1];
    for (int i = 0; i < this->cant_padres; ++i) {
        nueva_lista[i] = this->lista_padres_propio[i];
    }
    nueva_lista[this->cant_padres] = id_padre;
    delete[] this->lista_padres_propio;
    this->lista_padres_propio = nueva_lista;
    this->cant_padres++;
}

void NodoArchivo::eliminar_padre(int id_padre) {
    if (this->cant_padres == 0) return;
    int* nueva_lista = new int[this->cant_padres - 1];
    int j = 0;
    for (int i = 0; i < this->cant_padres; ++i) {
        if (this->lista_padres_propio[i] != id_padre) {
            nueva_lista[j++] = this->lista_padres_propio[i];
        }
    }
    delete[] this->lista_padres_propio;
    this->lista_padres_propio = nueva_lista;
    this->cant_padres--;
}


