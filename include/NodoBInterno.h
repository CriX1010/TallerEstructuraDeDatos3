#pragma once
#include "NodoBPlusBase.h"



class NodoBInterno : public NodoBPlusBase {
private:
    NodoBPlusBase** punteros;
    int buscar_siguiente();
    NodoBInterno* padre;


public:
    NodoBInterno(int orden);
    ~NodoBInterno();
    int insertarClaveEnInterno(int clave, NodoBPlusBase* hijoIzq, NodoBPlusBase* hijoDer);

    void setHijo(int index, NodoBPlusBase* ptr);
    NodoBPlusBase* getHijo(int idx) const;

    int buscar_siguiente(int clave);
};