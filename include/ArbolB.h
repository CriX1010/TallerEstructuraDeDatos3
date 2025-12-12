#pragma once
#include "NodoBPlusBase.h"
#include "NodoBHoja.h"
#include "NodoBInterno.h"

class ArbolB {
private:
    NodoBPlusBase* raiz;
    int orden;

    NodoBHoja* buscarHoja(int clave);
    void insertarEnHoja(NodoBHoja* hoja, int clave, NodoGrafo* dato);

public:
    ArbolB(int orden);

    void splitHoja(NodoBHoja * hoja);

    void insertar(int clave, NodoGrafo* dato);
    NodoGrafo* buscar(int clave);

    void splitHojas(NodoBHoja* hoja);
    void splitInterno(NodoBInterno* interno);
    void remove(int clave);
    void removeFromLeaf(NodoBHoja* hoja, int clave);
    void removeFromInternal(NodoBInterno* interno, int index);
    void fixUnderflow(NodoBPlusBase* nodo);
    void borrowFromLeft(NodoBPlusBase* nodo,int idxHermano);
    void borrowFromRight(NodoBPlusBase* nodo,int idxHermano);
    void mergeNodes(NodoBPlusBase* izq,NodoBPlusBase* der, int clavePadre);
    int findChildIndex(NodoBInterno* padre, NodoBPlusBase* hijo);
};
