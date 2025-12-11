#pragma once
#include "NodoGrafo.h"

class NodoArchivo: public NodoGrafo {

private:

    int tamaño;
    int tipo; // 0: Imagen; 1: Documento; 2: ejecutable; 3: Video; 4: Comprimido
public:
    NodoArchivo(int id, int tamaño, int tipo);
    ~NodoArchivo();
    bool es_directorio() { return false; }
};