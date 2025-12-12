//
// Created by CriX on 11-12-2025.
//

#include "../include/ArbolB.h"

#include <cstdlib>

ArbolBPlus::ArbolBPlus(int orden)
{
    this->orden = orden;
    this->raiz = new NodoBHoja(orden);
    NodoGrafo* dato = new NodoGrafo(orden);
    NodoBHoja* Aux = (NodoBHoja*)raiz;
    Aux -> setDato(0, dato);
}

NodoGrafo* ArbolBPlus::buscar(int clave)
{
    NodoBPlusBase* actual = raiz;

    while (!actual->esHoja()) {
        NodoBInterno* interno = (NodoBInterno*)actual;
        int idx = interno->buscar_siguiente(clave);
        actual = interno->getHijo(idx);
    }

    NodoBHoja* hoja = (NodoBHoja*)actual;

    for (int i = 0; i < hoja->cant_claves; i++) {
        if (hoja->claves[i] == clave)
            return hoja->getDato(i);
    }

    return nullptr;
}
void ArbolBPlus::insertar(const int clave, NodoGrafo* dato)
{
    NodoBHoja* hoja = buscarHoja(clave);

    insertarEnHoja(hoja, clave, dato);

    if (hoja->cant_claves == orden) {
        splitHoja(hoja);
    }
}


NodoBHoja* ArbolBPlus::buscarHoja(int clave){

    NodoBPlusBase* actual = raiz;

    while (!actual->esHoja())
    {
        NodoBInterno* interno = (NodoBInterno*)actual;
        int idx = interno->buscar_siguiente(clave);
        actual = interno->getHijo(idx);
    }

    return (NodoBHoja*)actual;
}

void ArbolBPlus::insertarEnHoja(NodoBHoja* hoja, int clave, NodoGrafo* dato)
{
    int i = hoja->cant_claves - 1;

    while (i >= 0 && hoja->claves[i] > clave) {
        hoja->claves[i + 1] = hoja->claves[i];
        hoja->setDato(i + 1, hoja->getDato(i));
        i--;
    }

    hoja->claves[i + 1] = clave;
    hoja->setDato(i + 1, dato);

    hoja->cant_claves++;
}

void ArbolBPlus::splitHoja(NodoBHoja* hoja)
{
    int mitad = orden / 2;

    NodoBHoja* nuevaHoja = new NodoBHoja(orden);

    nuevaHoja->cant_claves = hoja->cant_claves - mitad;

    for (int i = 0; i < nuevaHoja->cant_claves; i++) {
        nuevaHoja->claves[i] = hoja->claves[mitad + i];
        nuevaHoja->setDato(i, hoja->getDato(mitad + i));
    }

    hoja->cant_claves = mitad;

    nuevaHoja->setSiguiente(hoja->getSiguiente());
    hoja->setSiguiente(nuevaHoja);

    int claveQueSube = nuevaHoja->claves[0];

    if (hoja == raiz) {

        NodoBInterno* nuevaRaiz = new NodoBInterno(orden);

        nuevaRaiz->claves[0] = claveQueSube;
        nuevaRaiz->cant_claves = 1;

        nuevaRaiz->setHijo(0, hoja);
        nuevaRaiz->setHijo(1, nuevaHoja);

        raiz = nuevaRaiz;
    }
    else {
        splitInterno((NodoBInterno*)hoja->padre, claveQueSube, hoja, nuevaHoja);
    }
}

void ArbolBPlus::splitInterno(NodoBInterno* interno)
{
    int mitad = orden / 2;

    NodoBInterno* nuevoInterno = new NodoBInterno(orden);

    int claveQueSube = interno->claves[mitad];

    nuevoInterno->cant_claves = interno->cant_claves - mitad - 1;

    for (int i = 0; i < nuevoInterno->cant_claves; i++)
        nuevoInterno->claves[i] = interno->claves[mitad + 1 + i];

    for (int i = 0; i <= nuevoInterno->cant_claves; i++)
        nuevoInterno->setHijo(i, interno->getHijo(mitad + 1 + i));

    interno->cant_claves = mitad;

    if (interno == raiz) {

        NodoBInterno* nuevaRaiz = new NodoBInterno(orden);

        nuevaRaiz->claves[0] = claveQueSube;
        nuevaRaiz->cant_claves = 1;

        nuevaRaiz->setHijo(0, interno);
        nuevaRaiz->setHijo(1, nuevoInterno);

        raiz = nuevaRaiz;
    }
    else {
        // Falta propagar hacia arriba: te la puedo completar si usas padre
    }
}

