
#include "../include/NodoBHoja.h"

NodoBHoja::NodoBHoja(int orden):NodoBPlusBase(orden, true)
{
    datos = new NodoGrafo*[orden];
    for (int i = 0; i < orden; i++) datos[i] = nullptr;
    siguiente_hoja = nullptr;
}
NodoBHoja::~NodoBHoja() {
    delete[] datos;
}

void NodoBHoja::setDato(int index, NodoGrafo* ptr) const {
    datos[index] = ptr;
}
NodoGrafo* NodoBHoja::getDato(int index) const {
    return datos[index];
}

void NodoBHoja::setSiguiente(NodoBHoja* next) {
    siguiente_hoja = next;
}
NodoBHoja* NodoBHoja::getSiguiente() const {
    return siguiente_hoja;
}