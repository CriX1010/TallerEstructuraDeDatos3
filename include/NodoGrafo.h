#pragma once

class NodoGrafo{
private:
    int id;
public:

    NodoGrafo(int id);
    virtual bool es_directorio();
    int* lista_padres();
    int obtener_id() const {return this->id;};
    ~NodoGrafo();
};

