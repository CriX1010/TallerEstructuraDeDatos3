#pragma once

#include "NodoBInterno.h"
#include "NodoBHoja.h"

class ArbolB {
private:
    NodoBPlusBase* raiz;
    int orden;

    NodoBHoja* buscarHoja(int clave);
    void insertarEnHoja(NodoBHoja* hoja, int clave, NodoGrafo* dato);

public:
    ArbolB(int Orden);

    void insertar(int clave, NodoGrafo* dato);
    NodoGrafo* buscar(int clave);

    void splitHojas(NodoBPlusBase* hoja);
    void splitInterno(NodoBInterno* interno);
    void remove(int clave);

    void removeFromLeaf(NodoBPlusBase* hoja, int clave);
    void removeFromInternal(NodoBInterno* interno, int index);
    void fixUnderflow(NodoBPlusBase* nodo);
    void borrowFromLeft(NodoBPlusBase* nodo,int idxHermano);
    void borrowFromRight(NodoBPlusBase* nodo,int idxHermano);
    void mergeNodes(NodoBPlusBase* izq,NodoBPlusBase* der, int clavePadre);
    int findChildIndex(NodoBInterno* padre, NodoBPlusBase* hijo);
};
