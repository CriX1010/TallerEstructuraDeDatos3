#pragma once

class NodoGrafo{
private:
    int id;
public:
    NodoGrafo(int id);
    virtual bool es_directorio();
    virtual int* lista_padres();
    virtual int obtener_id();
    virtual ~NodoGrafo();
};

