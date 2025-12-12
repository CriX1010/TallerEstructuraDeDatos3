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

NodoGrafo::~NodoGrafo(){}
