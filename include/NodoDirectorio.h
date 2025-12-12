#pragma once
#include "NodoGrafo.h"

class NodoDirectorio: public NodoGrafo {
private:
    int* lista_hijos_propio;
    int cant_hijos;

public:
    NodoDirectorio(int id);
    ~NodoDirectorio();
    bool es_directorio() override { return true; }
    void agregarHijo(int id_hijo);
    void eliminarHijo(int id_hijo);
    int cantidad_hijos();
    int* lista_hijos() override;
    int* lista_padres() override{return nullptr;}
};