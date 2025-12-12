#pragma once

#include "NodoBPlusBase.h"
#include "NodoGrafo.h"

class NodoBHoja : public NodoBPlusBase {
private:
    NodoGrafo** datos;
    NodoBHoja* siguiente_hoja;


public:
    explicit NodoBHoja(int orden);
    ~NodoBHoja() override;

    void setDato(int idx, NodoGrafo* ptr) const;
    [[nodiscard]] NodoGrafo* getDato(int idx) const;

    void setSiguiente(NodoBHoja* nxt);
    [[nodiscard]] NodoBHoja* getSiguiente() const;


};