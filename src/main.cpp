#include <iostream>

#include "NodoBInterno.cpp"
#include "NodoBHoja.cpp"
#include "NodoBPlusBase.cpp"
#include "NodoGrafo.cpp"
#include "NodoDirectorio.cpp"
#include "NodoArchivo.cpp"

using namespace std;

int main () {
    cout<<"Hola mundo"<<endl;

    NodoBInterno* Arbol = new NodoBInterno(2);
    NodoBInterno* Rama = new NodoBInterno(2);
    NodoBInterno* Rama2 = new NodoBInterno(2);
    NodoBHoja* Hoja = new NodoBHoja(2);
    NodoBHoja* Hoja1 = new NodoBHoja(2);
    NodoBHoja* Hoja2 = new NodoBHoja(2);

    NodoArchivo* Arch = new NodoArchivo(1,2,2);

    Arbol -> setHijo(0, Rama);
    Arbol -> setHijo(1, Rama2);
    Rama -> setHijo(0, Hoja);
    Rama -> setHijo(1, Hoja1);
    Rama2 -> setHijo(0, Hoja2);

    Hoja2 -> setDato(1,Arch);

    cout << Arch ->obtener_id();;




    cout<<"Hola mundo"<<endl;

    return 0;
}