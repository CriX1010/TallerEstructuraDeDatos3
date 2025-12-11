#include "../include/NodoBInterno.h"

NodoBInterno::NodoBInterno(int orden):NodoBPlusBase(orden, false)
{

    hijos = new NodoBPlusBase*[orden + 1];
    for (int i = 0; i < orden + 1; i++) hijos[i] = nullptr;
}

NodoBInterno::~NodoBInterno() {
    delete[] hijos;
}

void NodoBInterno::setHijo(int index, NodoBPlusBase* ptr) {
    hijos[index] = ptr;
}

NodoBPlusBase* NodoBInterno::getHijo(int index) const {
    return hijos[index];
}

int NodoBInterno::buscar_siguiente(int clave) {
    int i = 0;
    while (i < cant_claves && clave >= claves[i]) {
        i++;
    }
    return i;
}