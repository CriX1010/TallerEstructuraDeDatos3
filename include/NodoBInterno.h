#pragma once
#include "NodoBPlusBase.h"



class NodoBInterno : public NodoBPlusBase {
private:
    NodoBPlusBase** hijos;

public:
    NodoBInterno(int orden);
    ~NodoBInterno();

    void setHijo(int idx, NodoBPlusBase* ptr);
    NodoBPlusBase* getHijo(int idx) const;

    int buscar_siguiente(int clave);
};