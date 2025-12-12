#include "../include/NodoDirectorio.h"
#include <iostream>

NodoDirectorio::NodoDirectorio(int id):NodoGrafo(id) {
    this->lista_hijos_propio = nullptr;
    this->cant_hijos = 0;
}

NodoDirectorio::~NodoDirectorio() {
    delete[] this->lista_hijos_propio;
}

int* NodoDirectorio::lista_hijos() {
    return this->lista_hijos_propio;
}

int NodoDirectorio::cantidad_hijos() {
    return this->cant_hijos;
}

void NodoDirectorio::agregarHijo(int id_hijo) {

    int* nuevo = new int[this->cant_hijos + 1];

    for (int i = 0; i < this->cant_hijos; i++)
        nuevo[i] = this->lista_hijos_propio[i];

    nuevo[this->cant_hijos] = id_hijo;

    delete[] this->lista_hijos_propio;
    this->lista_hijos_propio = nuevo;

    this->cant_hijos++;
}

void NodoDirectorio::eliminarHijo(int id_hijo) {
    if (this->cant_hijos == 0){return;}

    int* nuevo = new int[this->cant_hijos-1];
    int  j = 0;

    for (int i = 0; i < this->cant_hijos; i++) {
        if (this->lista_hijos_propio[i] != id_hijo) {
            nuevo[j] = this->lista_hijos_propio[i];
            j++;
        }
    }
    delete[] this->lista_hijos_propio;
    this->lista_hijos_propio = nuevo;
    this->cant_hijos--;
}