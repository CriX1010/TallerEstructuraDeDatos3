#pragma once
#include "NodoGrafo.h"

class NodoArchivo: public NodoGrafo {

private:
    int tamaño;
    int tipo; // 0: Imagen; 1: Documento; 2: ejecutable; 3: Video; 4: Comprimido
    int* lista_padres;
    int cant_padres;
public:
    NodoArchivo(int id, int tamaño, int tipo);
    ~NodoArchivo();
    bool es_directorio() { return false; }
    int devolver_tipo();
    int devolver_tamaño();
    int* devolver_lista_padres();
    void agregar_padre(int id_padre);
    void eliminar_padre(int id_padre);
};