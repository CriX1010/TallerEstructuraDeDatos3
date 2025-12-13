//
// Created by CriX on 11-12-2025.
//

#include "../include/ArbolB.h"

using namespace std;
#include <iostream>


ArbolB::ArbolB(const int Orden)
{
    orden = Orden;
    this->raiz = new NodoBHoja(orden);
}

NodoGrafo* ArbolB::buscar(int clave) const
{
    NodoBPlusBase* actual = raiz;

    while (!actual->esHoja()) {
        auto* interno = (NodoBInterno*)actual;
        int idx = interno->buscar_siguiente(clave);
        actual = interno->getHijo(idx);
    }

    auto* hoja = (NodoBHoja*)actual;

    for (int i = 0; i < hoja->cant_claves; i++) {
        if (hoja->claves[i] == clave)
            return hoja->getDato(i);
    }
    cout << "no se encontro el directorio con ese valor id" << endl;
    return nullptr;
}
NodoBHoja* ArbolB::buscarHoja(int clave) const{

    NodoBPlusBase* actual = raiz;

    while (!actual->esHoja())
    {
        auto* interno = (NodoBInterno*)actual;
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
        splitHojas(hoja);
        hoja = buscarHoja(clave);
    }

    insertarEnHoja(hoja, clave, dato);
}

void ArbolB::splitHojas(NodoBPlusBase *hoja)
{   auto* Aux = (NodoBHoja*)hoja;
    int mitad = hoja->cant_claves / 2;
    auto* nuevaHoja = new NodoBHoja(hoja->orden);

    nuevaHoja->cant_claves = hoja->cant_claves - mitad;

    for (int i = 0; i < nuevaHoja->cant_claves; i++) {
        nuevaHoja->claves[i] = hoja->claves[mitad + i];
        nuevaHoja->setDato(i, Aux->getDato(mitad + i));
    }

    hoja->cant_claves = mitad;

    nuevaHoja->setSiguiente(Aux->getSiguiente());
    Aux->setSiguiente(nuevaHoja);

    int clavePromovida = nuevaHoja->claves[0];

    if (hoja == raiz)
    {
        auto* nuevaRaiz = new NodoBInterno(hoja->orden);

        nuevaRaiz->claves[0] = clavePromovida;
        nuevaRaiz->cant_claves = 1;

        nuevaRaiz->setHijo(0, hoja);
        nuevaRaiz->setHijo(1, (NodoBPlusBase*)nuevaHoja);

        raiz = nuevaRaiz;
        return;
    }

    auto* padre = (NodoBInterno*)Aux->getPadre();
    if (padre ==NULL) {padre = new NodoBInterno(hoja->orden);}
    int idx = padre->insertarClaveEnInterno(clavePromovida, hoja, (NodoBPlusBase*) nuevaHoja);

    if (padre->cant_claves == orden)
        splitInterno(padre);
}

void ArbolB::splitInterno(NodoBInterno* interno)
{
    int mitad = interno->cant_claves / 2;

    int clavePromovida = interno->claves[mitad];

    auto* nuevoInterno = new NodoBInterno(interno->orden);

    nuevoInterno->cant_claves = interno->cant_claves - mitad - 1;

    for (int i = 0; i < nuevoInterno->cant_claves; i++)
        nuevoInterno->claves[i] = interno->claves[mitad + 1 + i];

    for (int i = 0; i <= nuevoInterno->cant_claves; i++)
        nuevoInterno->setHijo(i, interno->getHijo(mitad + 1 + i));

    interno->cant_claves = mitad;

    if (interno == raiz)
    {
        auto* nuevaRaiz = new NodoBInterno(interno->orden);

        nuevaRaiz->claves[0] = clavePromovida;
        nuevaRaiz->cant_claves = 1;

        nuevaRaiz->setHijo(0, interno);
        nuevaRaiz->setHijo(1, nuevoInterno);

        raiz = nuevaRaiz;
        return;
    }

    auto* padre = (NodoBInterno*)interno->getPadre();

    int idx = padre->insertarClaveEnInterno(clavePromovida, interno, nuevoInterno);

    if (padre->cant_claves == orden)
        splitInterno(padre);
}

void ArbolB::remove(int clave) {
    NodoBHoja* hoja = buscarHoja(clave);

    int i = 0;
    while (i < hoja->cant_claves && hoja->claves[i] != clave) i++;
    if (i == hoja->cant_claves) return;

    removeFromLeaf((NodoBPlusBase*)hoja, clave);
}

void ArbolB::removeFromLeaf(NodoBPlusBase* hoja, int clave) {
    int i = 0;
    auto* Aux = (NodoBHoja*)hoja;
    while (hoja->claves[i] != clave) i++;

    for (; i < hoja->cant_claves - 1; i++) {
        hoja->claves[i] = hoja->claves[i + 1];
        Aux->setDato(i, Aux->getDato(i + 1));
    }

    hoja->cant_claves--;

    if (hoja == raiz) return;
    if (hoja->cant_claves < (orden / 2)) fixUnderflow(hoja);
}

void ArbolB::removeFromInternal(NodoBInterno* interno, int idx) {
    for (int i = idx; i < interno->cant_claves - 1; i++)
        interno->claves[i] = interno->claves[i + 1];

    for (int i = idx + 1; i < interno->cant_claves; i++)
        interno->punteros[i] = interno->punteros[i + 1];

    interno->cant_claves--;

    if (interno == raiz && interno->cant_claves == 0) {
        raiz = interno->punteros[0];
        raiz->setPadre(nullptr);
        return;
    }

    if (interno->cant_claves < (orden / 2))
        fixUnderflow(interno);
}

void ArbolB::fixUnderflow(NodoBPlusBase* nodo) {
    auto* padre = (NodoBInterno*)nodo->getPadre();
    if (!padre) return;

    int idx = findChildIndex(padre, nodo);

    if (idx > 0 && padre->punteros[idx - 1]->cant_claves > orden / 2) {
        borrowFromLeft(nodo, idx - 1);
        return;
    }

    if (idx < padre->cant_claves &&
        padre->punteros[idx + 1]->cant_claves > orden / 2) {
        borrowFromRight(nodo, idx + 1);
        return;
        }

    if (idx > 0)
        mergeNodes((NodoBInterno*)padre->punteros[idx - 1], nodo, padre->claves[idx - 1]);
    else
        mergeNodes(nodo, (NodoBInterno*)padre->punteros[idx + 1], padre->claves[idx]);
}

void ArbolB::borrowFromLeft(NodoBPlusBase* nodo,int idxHermano) {

    auto* padre = (NodoBInterno*)nodo->getPadre();
    NodoBPlusBase* hermano = padre->punteros[idxHermano];

    if (nodo->esHoja()) {
        auto* h = (NodoBHoja*)hermano;
        auto* n = (NodoBHoja*)nodo;

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
        auto* h = (NodoBInterno*)hermano;
        auto* n = (NodoBInterno*)nodo;

        for (int i = n->cant_claves; i > 0; i--) {
            n->claves[i] = n->claves[i - 1];
            n->punteros[i + 1] = n->punteros[i];
        }
        n->punteros[1] = n->punteros[0];

        n->claves[0] = padre->claves[idxHermano];
        n->punteros[0] = h->punteros[h->cant_claves];

        padre->claves[idxHermano] = h->claves[h->cant_claves - 1];

        h->cant_claves--;
        n->cant_claves++;
    }
}

void ArbolB::borrowFromRight(NodoBPlusBase* nodo, int idxHermano) {

    auto* padre = (NodoBInterno*)nodo->getPadre();
    NodoBPlusBase* hermano = padre->punteros[idxHermano];

    if (nodo->esHoja()) {
        auto* h = (NodoBHoja*)hermano;
        auto* n = (NodoBHoja*)nodo;

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
        auto* h = (NodoBInterno*)hermano;
        auto* n = (NodoBInterno*)nodo;

        n->claves[n->cant_claves] = padre->claves[idxHermano - 1];
        n->punteros[n->cant_claves + 1] = h->punteros[0];

        padre->claves[idxHermano - 1] = h->claves[0];

        for (int i = 0; i < h->cant_claves - 1; i++) {
            h->claves[i] = h->claves[i + 1];
            h->punteros[i] = h->punteros[i + 1];
        }
        h->punteros[h->cant_claves - 1] = h->punteros[h->cant_claves];

        h->cant_claves--;
        n->cant_claves++;
    }
}

void ArbolB::mergeNodes(NodoBPlusBase* izq, NodoBPlusBase* der, int clavePadre) {

    auto* padre = (NodoBInterno*)izq->getPadre();
    int idx = findChildIndex(padre, izq);

    if (izq->esHoja()) {
        auto* L = (NodoBHoja*)izq;
        auto* R = (NodoBHoja*)der;

        for (int i = 0; i < R->cant_claves; i++) {
            L->claves[L->cant_claves + i] = R->claves[i];
            L->setDato(L->cant_claves + i, R->getDato(i));
        }
        L->cant_claves += R->cant_claves;
        L->setSiguiente(R->getSiguiente());
    }
    else {
        auto* L = (NodoBInterno*)izq;
        auto* R = (NodoBInterno*)der;

        L->claves[L->cant_claves] = clavePadre;
        L->cant_claves++;

        for (int i = 0; i < R->cant_claves; i++) {
            L->claves[L->cant_claves + i] = R->claves[i];
            L->punteros[L->cant_claves + i] = R->punteros[i];
        }
        L->cant_claves += R->cant_claves;
    }

    removeFromInternal(padre, idx);
}

int ArbolB::findChildIndex(NodoBInterno* padre, NodoBPlusBase* hijo) {
    for (int i = 0; i <= padre->cant_claves; i++)
        if (padre->punteros[i] == hijo)
            return i;
    return -1;
}