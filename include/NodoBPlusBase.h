#pragma once
using namespace std;
#include <cstddef>

class NodoBPlusBase {
protected:

    NodoBPlusBase* padre;
    bool es_hoja;

public:

    int orden;
    int cant_claves;
    int* claves;

    NodoBPlusBase* getPadre();
    void setPadre(NodoBPlusBase* ptr);

    NodoBPlusBase(int orden, bool es_hoja);
    virtual ~NodoBPlusBase();

    [[nodiscard]] bool esHoja() const;
    [[nodiscard]] int getOrden() const;

    void setCantClaves(int cant);
    [[nodiscard]] int getCantClaves() const;

    [[nodiscard]] int getClave(int idx) const;
    void setClave(int idx, int valor) const;
};