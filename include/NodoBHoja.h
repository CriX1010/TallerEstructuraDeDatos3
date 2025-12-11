#pragma once

#include "NodoBPlusBase.h"
#include "NodoGrafo.h"

class NodoBHoja : public NodoBPlusBase {
private:
    NodoGrafo** datos;
    NodoBHoja* siguiente_hoja;

public:
    NodoBHoja(int orden);
    ~NodoBHoja();

    void setDato(int idx, NodoGrafo* ptr);
    NodoGrafo* getDato(int idx) const;

    void setSiguiente(NodoBHoja* nxt);
    NodoBHoja* getSiguiente() const;
};