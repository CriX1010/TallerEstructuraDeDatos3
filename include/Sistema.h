#pragma once
#include <string>

#include "ArbolB.h"
#include "NodoArchivo.h"
#include "NodoDirectorio.h"

class Sistema {
public:

    int Id;
    ArbolB* Arbol;
    Sistema(int n );
    ~Sistema();
    void crear_Directorio(int id_padre);
    void eliminar_Directorio(int id_padre, int id_propio);
    void crear_Archivo(int tamaño, int tipo, int id_padre);
    void eliminar_Archivo(int id_padre, int id_propio);

    void listar_contenido(int id_directorio);
    std::string* obtener_rutas_completas(int id_archivo);
    int calcular_espacio_ocupado(int id_directorio);

    ArbolB* GetArbol();
};
