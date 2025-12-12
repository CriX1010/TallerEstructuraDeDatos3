#pragma once
#include "NodoGrafo.h"

class NodoArchivo: public NodoGrafo {

private:
    int tamaño;
    int tipo; // 0: Imagen; 1: Documento; 2: ejecutable; 3: Video; 4: Comprimido
    int* lista_padres_propio;
    int cant_padres;

public:
    NodoArchivo(int id, int tamaño, int tipo);
    ~NodoArchivo() override;
    bool es_directorio() override { return false; }
    int devolver_tipo() const;
    int devolver_tamaño() const;
    int* lista_padres() override;
    void agregar_padre(int id_padre);
    void eliminar_padre(int id_padre);
    int* lista_hijos() override { return nullptr;};
};