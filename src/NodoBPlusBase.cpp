
#include "../include/NodoBPlusBase.h"

NodoBPlusBase::NodoBPlusBase(int orden, bool hoja){
    orden = orden;
    es_hoja = hoja;
    cant_claves = 0;
    claves = new int[orden];
}

NodoBPlusBase::~NodoBPlusBase() {
    delete[] claves;
}

int NodoBPlusBase::getCantClaves() const {
    return cant_claves;
}

int NodoBPlusBase::getClave(int index) const {
    return claves[index];
}

bool NodoBPlusBase::esHoja() const {
    return es_hoja;
}

int NodoBPlusBase::getOrden() const {
    return orden;
}

void NodoBPlusBase::setClave(int index, int valor) {
    claves[index] = valor;
}

void NodoBPlusBase::incrementarCantClaves() {
    cant_claves++;
}