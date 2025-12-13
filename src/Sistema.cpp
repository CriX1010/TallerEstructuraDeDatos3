#include "../include/Sistema.h"
#include <iostream>
#include <ostream>


Sistema::Sistema(int n) {
    Arbol = new ArbolB(n);
    this->Id = 0;
    Arbol -> insertar(-1,new NodoDirectorio(-1));
}

Sistema::~Sistema() {
    delete Arbol;
};

void Sistema::crear_Directorio(int id_padre) {
    NodoGrafo* padreBase = Arbol -> buscar(id_padre);
    if (!padreBase) {
        cout << "No se pudo crear: el directorio padre no existe.\n";
        return;
    }
    if (!padreBase->es_directorio()) {
        cout << "No se pudo crear: el padre no es un directorio.\n";
        return;
    }
    int nuevo_id_directorio = Id;
    auto* Nuevo = new NodoDirectorio(nuevo_id_directorio);

    if (Arbol -> buscar(nuevo_id_directorio) != nullptr) {
        cout << "No se pudo crear: ID duplicado (" << nuevo_id_directorio << ").\n";
        delete Nuevo;
        return;
    }

    Arbol->insertar(nuevo_id_directorio, Nuevo);

    auto* padre = static_cast<NodoDirectorio*>(padreBase);
    padre -> agregarHijo(nuevo_id_directorio);
    cout << "creaste el directorio con la ID: " << nuevo_id_directorio << endl;
    Id++;

}

void Sistema::crear_Archivo(int tamaño, int tipo, int id_padre) {
    NodoGrafo* padreBase = Arbol->buscar(id_padre);
    if (!padreBase) {
        cout << "No se pudo crear: el directorio padre no existe.\n";
        return;
    }
    if (!padreBase->es_directorio()) {
        cout << "No se pudo crear: el padre no es un directorio.\n";
        return;
    }

    if (tamaño < 0) {
        cout << "No se pudo crear: tamano invalido.\n";
        return;
    }
    if (tipo < 0 || tipo > 4) {
        cout << "No se pudo crear: tipo invalido.\n";
        return;
    }

    int nuevo_id_archivo = Id;
    auto* Nuevo = new NodoArchivo(nuevo_id_archivo,tamaño,tipo);

    if (Arbol -> buscar(nuevo_id_archivo) != nullptr) {
        cout << "No se pudo crear: ID duplicado (" << nuevo_id_archivo << ").\n";
        delete Nuevo;
        return;
    }


    Arbol -> insertar(nuevo_id_archivo, Nuevo);
    auto* padre = static_cast<NodoDirectorio*>(padreBase);
    padre->agregarHijo(nuevo_id_archivo);
    cout << "creaste el Archivo con la id " << nuevo_id_archivo << endl;
    Id++;
}

void Sistema::eliminar_Directorio(int id_padre, int id_propio) {
    auto* Aux = (NodoDirectorio*)Arbol -> buscar(id_padre);
    auto* Aux2 = (NodoDirectorio*)Arbol -> buscar(id_propio);
    if (Aux && Aux2) {
        Aux -> eliminarHijo(id_propio);
        Arbol -> remove(id_propio);
        cout << "eliminaste el Directorio con la id: " << id_propio << endl;
    } else if (!Aux2) {
        cout << "el directorio con id " << id_propio<< " no existe" << endl;
    } else {cout << "No se pudo eliminar el directorio" << endl;}
}

void Sistema::eliminar_Archivo(int id_padre, int id_propio) const{
    auto* Aux = (NodoDirectorio*)Arbol -> buscar(id_padre);
    auto* Aux2 = (NodoArchivo*)Arbol -> buscar(id_propio);
    if (Aux && Aux2) {
        Aux -> eliminarHijo(id_propio);
        Arbol -> remove(id_propio);
        cout << "eliminaste el Archivo con la id: " << id_propio << endl;
    } else if (!Aux2) {
        cout << "el Archivo con id " << id_propio << " no existe" << endl;
    } else {cout << "No se pudo eliminar el Archivo" << endl;}
}

void Sistema::listar_contenido(int id_directorio) {
    NodoGrafo* nodoBase = Arbol->buscar(id_directorio);
    if (!nodoBase) {
        cout << "No se encontró el directorio.\n";
        return;
    }
    if (!nodoBase->es_directorio()) {
        cout << "El ID " << id_directorio << " no corresponde a un directorio.\n";
        return;
    }

    auto* dir = static_cast<NodoDirectorio*>(nodoBase);

    int* hijos = dir->lista_hijos();
    int n = dir->cantidad_hijos();   // <-- ESTA ES LA CLAVE

    cout << "El directorio con id: " << id_directorio << " contiene:\n";

    if (!hijos || n == 0) {
        cout << "No contiene contenido el directorio.\n";
        return;
    }

    for (int i = 0; i < n; ++i) {
        int idHijo = hijos[i];

        NodoGrafo* hijo = Arbol->buscar(idHijo);
        if (!hijo) {
            cout << "Elemento (ID " << idHijo << ") no encontrado en el árbol.\n";
            continue;
        }

        if (hijo->es_directorio()) {
            cout << "Directorio con id " << hijo->obtener_id() << "\n";
        } else {
            cout << "Archivo con id " << hijo->obtener_id() << "\n";
        }
    }
}


std::string *Sistema::obtener_rutas_completas(int id_archivo) {
    //no alcanzamos a hacerlo

    return nullptr;
}

int Sistema::calcular_espacio_ocupado(int id_directorio) {
    //no se pudo hacer

    return 0;
}

ArbolB* Sistema::GetArbol() const {
    return Arbol;
}





