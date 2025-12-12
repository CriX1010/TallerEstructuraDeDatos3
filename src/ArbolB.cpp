//
// Created by CriX on 11-12-2025.
//

#include "../include/ArbolB.h"

#include <cstdlib>

ArbolB::ArbolB(int orden)
{
    this->orden = orden;
    this->raiz = new NodoBHoja(orden);
    NodoGrafo* dato = new NodoGrafo(orden);
    NodoBHoja* Aux = (NodoBHoja*)raiz;
    Aux -> setDato(-1, dato);
}
NodoGrafo* ArbolB::buscar(int clave)
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
NodoBHoja* ArbolB::buscarHoja(int clave){

    NodoBPlusBase* actual = raiz;

    while (!actual->esHoja())
    {
        NodoBInterno* interno = (NodoBInterno*)actual;
        int idx = interno->buscar_siguiente(clave);
        actual = interno->getHijo(idx);
    }

    return (NodoBHoja*)actual;
}
void ArbolB::insertarEnHoja(NodoBHoja* hoja, int clave, NodoGrafo* dato)
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


void ArbolB::insertar(int clave, NodoGrafo* dato)
{
    NodoBHoja* hoja = buscarHoja(clave);

    if (hoja->cant_claves == orden) {
        splitHoja(hoja);
        hoja = buscarHoja(clave);
    }

    insertarEnHoja(hoja, clave, dato);
}

void ArbolB::splitHoja(NodoBHoja* hoja)
{
    int mitad = hoja->cant_claves / 2;
    NodoBHoja* nuevaHoja = new NodoBHoja(hoja->orden);

    nuevaHoja->cant_claves = hoja->cant_claves - mitad;

    for (int i = 0; i < nuevaHoja->cant_claves; i++) {
        nuevaHoja->claves[i] = hoja->claves[mitad + i];
        nuevaHoja->setDato(i, hoja->getDato(mitad + i));
    }

    hoja->cant_claves = mitad;

    nuevaHoja->setSiguiente(hoja->getSiguiente());
    hoja->setSiguiente(nuevaHoja);

    int clavePromovida = nuevaHoja->claves[0];

    if (hoja == raiz)
    {
        NodoBInterno* nuevaRaiz = new NodoBInterno(hoja->orden);

        nuevaRaiz->claves[0] = clavePromovida;
        nuevaRaiz->cant_claves = 1;

        nuevaRaiz->setHijo(0, hoja);
        nuevaRaiz->setHijo(1, nuevaHoja);

        raiz = nuevaRaiz;
        return;
    }

    NodoBInterno* padre = hoja->getPadre();
    int idx = padre->insertarClaveEnInterno(clavePromovida, hoja, nuevaHoja);

    if (padre->cant_claves == orden)
        splitInterno(padre);
}

void ArbolB::splitInterno(NodoBInterno* interno)
{
    int mitad = interno->cant_claves / 2;

    int clavePromovida = interno->claves[mitad];

    NodoBInterno* nuevoInterno = new NodoBInterno(interno->orden);

    nuevoInterno->cant_claves = interno->cant_claves - mitad - 1;

    for (int i = 0; i < nuevoInterno->cant_claves; i++)
        nuevoInterno->claves[i] = interno->claves[mitad + 1 + i];

    for (int i = 0; i <= nuevoInterno->cant_claves; i++)
        nuevoInterno->setHijo(i, interno->getHijo(mitad + 1 + i));

    interno->cant_claves = mitad;

    if (interno == raiz)
    {
        NodoBInterno* nuevaRaiz = new NodoBInterno(interno->orden);

        nuevaRaiz->claves[0] = clavePromovida;
        nuevaRaiz->cant_claves = 1;

        nuevaRaiz->setHijo(0, interno);
        nuevaRaiz->setHijo(1, nuevoInterno);

        raiz = nuevaRaiz;
        return;
    }

    NodoBInterno* padre = interno->getPadre();

    int idx = padre->insertarClaveEnInterno(clavePromovida, interno, nuevoInterno);

    if (padre->cant_claves == orden)
        splitInterno(padre);
}

void ArbolB::remove(int clave) {
    NodoBHoja* hoja = buscarHoja(clave);

    int i = 0;
    while (i < hoja->cant_claves && hoja->claves[i] != clave) i++;
    if (i == hoja->cant_claves) return;

    removeFromLeaf(hoja, clave);
}

void ArbolB::removeFromLeaf(NodoBHoja* hoja, int clave) {
    int i = 0;
    while (hoja->claves[i] != clave) i++;

    for (; i < hoja->cant_claves - 1; i++) {
        hoja->claves[i] = hoja->claves[i + 1];
        hoja->setDato(i, hoja->getDato(i + 1));
    }

    hoja->cant_claves--;

    if (hoja == raiz) return;
    if (hoja->cant_claves < (orden / 2)) fixUnderflow(hoja);
}

void ArbolB::sremoveFromInternal(NodoBInterno* interno, int idx) {
    for (int i = idx; i < interno->cant_claves - 1; i++)
        interno->claves[i] = interno->claves[i + 1];

    for (int i = idx + 1; i < interno->cant_claves; i++)
        interno->hijos[i] = interno->hijos[i + 1];

    interno->cant_claves--;

    if (interno == raiz && interno->cant_claves == 0) {
        raiz = interno->hijos[0];
        raiz->setPadre(nullptr);
        return;
    }

    if (interno->cant_claves < (orden / 2))
        fixUnderflow(interno);
}

void ArbolB::fixUnderflow(NodoBPlusBase* nodo) {
    NodoBInterno* padre = nodo->getPadre();
    if (!padre) return;

    int idx = findChildIndex(padre, nodo);

    if (idx > 0 && padre->hijos[idx - 1]->cant_claves > orden / 2) {
        borrowFromLeft(nodo, idx - 1);
        return;
    }

    if (idx < padre->cant_claves &&
        padre->hijos[idx + 1]->cant_claves > orden / 2) {
        borrowFromRight(nodo, idx + 1);
        return;
        }

    if (idx > 0)
        mergeNodes(padre->hijos[idx - 1], nodo, padre->claves[idx - 1]);
    else
        mergeNodes(nodo, padre->hijos[idx + 1], padre->claves[idx]);
}

void ArbolB::borrowFromLeft(NodoBPlusBase* nodo, int idxHermano) {
    NodoBInterno* padre = nodo->getPadre();
    NodoBPlusBase* hermano = padre->hijos[idxHermano];

    if (nodo->esHoja()) {
        NodoBHoja* h = (NodoBHoja*)hermano;
        NodoBHoja* n = (NodoBHoja*)nodo;

        for (int i = n->cant_claves; i > 0; i--) {
            n->claves[i] = n->claves[i - 1];
            n->setDato(i, n->getDato(i - 1));
        }

        n->claves[0] = h->claves[h->cant_claves - 1];
        n->setDato(0, h->getDato(h->cant_claves - 1));

        h->cant_claves--;
        n->cant_claves++;

        padre->claves[idxHermano] = n->claves[0];
    } else {
        NodoBInterno* h = (NodoBInterno*)hermano;
        NodoBInterno* n = (NodoBInterno*)nodo;

        for (int i = n->cant_claves; i > 0; i--) {
            n->claves[i] = n->claves[i - 1];
            n->hijos[i + 1] = n->hijos[i];
        }
        n->hijos[1] = n->hijos[0];

        n->claves[0] = padre->claves[idxHermano];
        n->hijos[0] = h->hijos[h->cant_claves];

        padre->claves[idxHermano] = h->claves[h->cant_claves - 1];

        h->cant_claves--;
        n->cant_claves++;
    }
}

void ArbolB::borrowFromRight(NodoBPlusBase* nodo, int idxHermano) {
    NodoBInterno* padre = nodo->getPadre();
    NodoBPlusBase* hermano = padre->hijos[idxHermano];

    if (nodo->esHoja()) {
        NodoBHoja* h = (NodoBHoja*)hermano;
        NodoBHoja* n = (NodoBHoja*)nodo;

        n->claves[n->cant_claves] = h->claves[0];
        n->setDato(n->cant_claves, h->getDato(0));

        for (int i = 0; i < h->cant_claves - 1; i++) {
            h->claves[i] = h->claves[i + 1];
            h->setDato(i, h->getDato(i + 1));
        }

        h->cant_claves--;
        n->cant_claves++;

        padre->claves[idxHermano - 1] = h->claves[0];
    } else {
        NodoBInterno* h = (NodoBInterno*)hermano;
        NodoBInterno* n = (NodoBInterno*)nodo;

        n->claves[n->cant_claves] = padre->claves[idxHermano - 1];
        n->hijos[n->cant_claves + 1] = h->hijos[0];

        padre->claves[idxHermano - 1] = h->claves[0];

        for (int i = 0; i < h->cant_claves - 1; i++) {
            h->claves[i] = h->claves[i + 1];
            h->hijos[i] = h->hijos[i + 1];
        }
        h->hijos[h->cant_claves - 1] = h->hijos[h->cant_claves];

        h->cant_claves--;
        n->cant_claves++;
    }
}

void ArbolB::mergeNodes(NodoBPlusBase* izq, NodoBPlusBase* der, int clavePadre) {
    NodoBInterno* padre = izq->getPadre();
    int idx = findChildIndex(padre, izq);

    if (izq->esHoja()) {
        NodoBHoja* L = (NodoBHoja*)izq;
        NodoBHoja* R = (NodoBHoja*)der;

        for (int i = 0; i < R->cant_claves; i++) {
            L->claves[L->cant_claves + i] = R->claves[i];
            L->setDato(L->cant_claves + i, R->getDato(i));
        }
        L->cant_claves += R->cant_claves;
        L->setSiguiente(R->getSiguiente());
    }
    else {
        NodoBInterno* L = (NodoBInterno*)izq;
        NodoBInterno* R = (NodoBInterno*)der;

        L->claves[L->cant_claves] = clavePadre;
        L->cant_claves++;

        for (int i = 0; i < R->cant_claves; i++) {
            L->claves[L->cant_claves + i] = R->claves[i];
            L->hijos[L->cant_claves + i] = R->hijos[i];
        }
        L->cant_claves += R->cant_claves;
    }

    removeFromInternal(padre, idx);
}

int ArbolB::findChildIndex(NodoBInterno* padre, NodoBPlusBase* hijo) {
    for (int i = 0; i <= padre->cant_claves; i++)
        if (padre->hijos[i] == hijo)
            return i;
    return -1;
}