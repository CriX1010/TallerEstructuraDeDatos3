#include "../include/NodoDirectorio.h"

NodoDirectorio::NodoDirectorio(int id):NodoGrafo(id) {
    this->lista_hijos = nullptr;
    this->cant_hijos = 0;
}

NodoDirectorio::~NodoDirectorio() {
    delete[] this->lista_hijos;
}

int* NodoDirectorio::devolver_lista_hijos() {
    return lista_hijos;
}

int NodoDirectorio::cantidad_hijos() {
    return this->cant_hijos;
}

void agregar_hijo(int id_hijo) {

    int* nuevo = new int[this->cant_hijos + 1];

    for (int i = 0; i < this->cant_hijos; i++)
        nuevo[i] = this->lista_hijos[i];

    nuevo[this->cant_hijos] = id_hijo;

    delete[] this->lista_hijos;
    this->lista_hijos = nuevo;

    this->cant_hijos++;
}

void eliminarHijo(int id_hijo) {
    if (this->cant_hijos == 0){return;}

    int* nuevo = new int[this->cant_hijos-1];
    int  j = 0;

    for (int i = 0; i < this->cant_hijos; i++) {
        if (this->lista_hijos[i] != id_hijo) {
            nuevo[j] = this->lista_hijos[i];
            j++;
        }
    }
    delete[] this->lista_hijos;
    this->lista_hijos = nuevo;
    this->cant_hijos--;
}