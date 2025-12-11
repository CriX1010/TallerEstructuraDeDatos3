#pragma once
#include "NodoGrafo.h"

class NodoDirectorio: public NodoGrafo {
private:
    int* lista_hijos;
    int cant_hijos;

public:
    NodoDirectorio(int id);
    ~NodoDirectorio();
    bool es_directorio() { return true; }
    void agregarHijo(int id_hijo);
    void eliminarHijo(int id_hijo);
    int cantidad_hijos();
    int* devolver_lista_hijos();
};