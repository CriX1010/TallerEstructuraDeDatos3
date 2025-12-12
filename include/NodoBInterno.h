#pragma once
#include "NodoBPlusBase.h"



class NodoBInterno : public NodoBPlusBase {
public:

    NodoBPlusBase** punteros;

    NodoBInterno(int orden);
    ~NodoBInterno();
    int insertarClaveEnInterno(int clave, NodoBPlusBase* hijoIzq, NodoBPlusBase* hijoDer);

    void setHijo(int index, NodoBPlusBase* ptr) const;
    [[nodiscard]] NodoBPlusBase* getHijo(int idx) const;

    int buscar_siguiente(int clave);


};