#pragma once

class NodoGrafo{
private:
    int id;
public:
    explicit NodoGrafo(int id);
    virtual bool es_directorio();
    virtual int* lista_padres() = 0;
    virtual int* lista_hijos() = 0;
    virtual int obtener_id();
    virtual ~NodoGrafo();
};

