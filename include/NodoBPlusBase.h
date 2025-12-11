#pragma once
using namespace std;
#include <cstddef>

class NodoBPlusBase {
protected:
    int* claves;
    int cant_claves;
    int orden;
    bool es_hoja;

public:
    NodoBPlusBase(int orden, bool es_hoja);
    virtual ~NodoBPlusBase();

    int getCantClaves() const;
    int getClave(int idx) const;
    bool esHoja() const;
    int getOrden() const;

    void setClave(int idx, int valor);
    void incrementarCantClaves();
};