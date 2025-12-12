#pragma once
#include "NodoBPlusBase.h"
#include "NodoBHoja.h"
#include "NodoBInterno.h"

class ArbolBPlus {
private:
    NodoBPlusBase* raiz;
    int orden;

    NodoBHoja* buscarHoja(int clave);
    void insertarEnHoja(NodoBHoja* hoja, int clave, NodoGrafo* dato);
    void splitHoja(NodoBHoja* hoja);
    void splitInterno(NodoBInterno* interno);

public:
    ArbolBPlus(int orden);

    void insertar(int clave, NodoGrafo* dato);
    NodoGrafo* buscar(int clave);
};
