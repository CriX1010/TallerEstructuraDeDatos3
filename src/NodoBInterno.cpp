#include "../include/NodoBInterno.h"

NodoBInterno::NodoBInterno(int orden):NodoBPlusBase(orden, false){
    punteros = new NodoBPlusBase*[orden + 1];
    for (int i = 0; i < orden + 1; i++) punteros[i] = nullptr;
}

NodoBInterno::~NodoBInterno() {
    delete[] punteros;
}

void NodoBInterno::setHijo(int index, NodoBPlusBase* ptr) {
    punteros[index] = ptr;
}

NodoBPlusBase* NodoBInterno::getHijo(int index) const {
    return punteros[index];
}

int NodoBInterno::buscar_siguiente(int clave) {
    int i = 0;
    while (i < cant_claves && clave >= claves[i]) {
        i++;
    }
    return i;
}