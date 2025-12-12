#include "../include/NodoGrafo.h"

NodoGrafo::NodoGrafo(int id) {
    this->id = id;
}
int NodoGrafo::obtener_id() {
    return this->id;
}

bool NodoGrafo::es_directorio() {
    return false;
}

int* NodoGrafo::lista_padres() {
    return nullptr;
}

NodoGrafo::~NodoGrafo(){}
