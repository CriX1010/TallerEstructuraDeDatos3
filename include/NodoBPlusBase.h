#pragma once
using namespace std;
#include <cstddef>
#include "NodoGrafo.h"

class NodoBPlusBase {
protected:

    int orden;
    bool es_hoja;
    int cant_claves;
    int* claves;

public:
    NodoBPlusBase(int orden, bool es_hoja);
    virtual ~NodoBPlusBase();

    bool esHoja() const;
    int getOrden() const;

    void setCantClaves(int cant);
    int getCantClaves() const;

    int getClave(int idx) const;
    void setClave(int idx, int valor);
};