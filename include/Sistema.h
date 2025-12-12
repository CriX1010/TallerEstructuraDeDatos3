#pragma once
#include <string>
class Sistema {
public:
    Sistema(){};
    ~Sistema();
    void crear_Directorio(int id_padre);
    void eliminar_Directorio(int id_padre, int id_propio);
    void crear_Archivo(int tamaño, int tipo, int id_padre);
    void eLiminar_Archivo(int id_padre, int id_propio);

    void listar_contenido(int id_directorio);
    std::string* obtener_rutas_completas(int id_archivo);
    int calcular_espacio_ocupado(int id_directorio);
};
