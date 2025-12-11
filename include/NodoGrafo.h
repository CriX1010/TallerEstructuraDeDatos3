#pragma once

class NodoGrafo{
private:
    int id;
public:

    NodoGrafo(int id);
    bool es_directorio();
    int* lista_padres();
    int obtener_id();
    ~NodoGrafo();
};

