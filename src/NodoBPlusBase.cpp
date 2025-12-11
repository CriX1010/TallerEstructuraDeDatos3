
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

int NodoBPlusBase::getOrden() const {
    return orden;
}
bool NodoBPlusBase::esHoja() const {
    return es_hoja;
}

void NodoBPlusBase::setCantClaves(int cant) {
    cant_claves = cant;
}
int NodoBPlusBase::getCantClaves() const {
    return cant_claves;
}


int NodoBPlusBase::getClave(int index) const {
    return claves[index];
}
void NodoBPlusBase::setClave(int index, int valor) {
    claves[index] = valor;
}

