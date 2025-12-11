#include "../include/NodoDirectorio.h"

NodoDirectorio::NodoDirectorio(int id):NodoGrafo(id) {
    this->lista_hijos = nullptr;
}

NodoDirectorio::~NodoDirectorio() {


}

void NodoDirectorio::agregarHijo(int id_hijo) {

}
