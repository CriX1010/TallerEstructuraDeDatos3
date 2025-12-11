#pragma once
#include "NodoBPlusBase.h"



class NodoBInterno : public NodoBPlusBase {
private:
    NodoBPlusBase** punteros;
    int buscar_siguiente();

public:
    NodoBInterno(int orden);
    ~NodoBInterno();

    void setHijo(int index, NodoBPlusBase* ptr);
    NodoBPlusBase* getHijo(int idx) const;

    int buscar_siguiente(int clave);
};