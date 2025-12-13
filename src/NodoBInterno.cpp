#include "../include/NodoBInterno.h"
#include <iostream>

NodoBInterno::NodoBInterno(int orden):NodoBPlusBase(orden, false){
    punteros = new NodoBPlusBase*[orden + 2];
    for (int i = 0; i < orden + 2; i++) punteros[i] = nullptr;
    padre = nullptr;
}

NodoBInterno::~NodoBInterno() {
    delete[] punteros;
}

int NodoBInterno::insertarClaveEnInterno(int clave, NodoBPlusBase* hijoIzq, NodoBPlusBase* hijoDer)
{
    int i = 0;

    while (i <= cant_claves && punteros[i] != hijoIzq)
        i++;

    if (i > cant_claves) {
        cout << "ERROR: hijoIzq no encontrado en insertarClaveEnInterno.\n";
        return -1;
    }

    for (int j = cant_claves; j > i; j--)
        claves[j] = claves[j - 1];

    for (int j = cant_claves + 1; j > i + 1; j--)
        punteros[j] = punteros[j - 1];

    claves[i] = clave;
    punteros[i + 1] = hijoDer;

    if (hijoDer) {
        hijoDer->setPadre(this);
    }

    cant_claves++;

    return i;
}
void NodoBInterno::setHijo(int index, NodoBPlusBase* ptr) const {
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