#include "../include/Sistema.h"
#include "../include/ArbolB.h"

Sistema::Sistema(int n) {
    ArbolBPlus* Arbol = new ArbolBPlus(n);
}

Sistema::~Sistema() {}

void Sistema::crear_Directorio(int id_padre) {

}

void Sistema::crear_Archivo(int tamaño, int tipo, int id_padre) {

}

void Sistema::eliminar_Directorio(int id_padre, int id_propio) {

}

void Sistema::eliminar_Archivo(int id_padre, int id_propio) {

}

void Sistema::listar_contenido(int id_directorio) {

}

std::string *Sistema::obtener_rutas_completas(int id_archivo) {

}

int Sistema::calcular_espacio_ocupado(int id_directorio) {

}






