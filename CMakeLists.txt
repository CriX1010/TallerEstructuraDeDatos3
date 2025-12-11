cmake_minimum_required(VERSION 4.0)
project(Taller_3)

set(CMAKE_CXX_STANDARD 14)

add_executable(Taller_3
        src/main.cpp
        src/NodoGrafo.cpp
        src/NodoArchivo.cpp
        src/NodoDirectorio.cpp
        src/NodoBPlusBase.cpp
        src/NodoBHoja.cpp
        src/NodoBInterno.cpp
        include/NodoGrafo.h
        include/NodoArchivo.h
        include/NodoDirectorio.h
        include/NodoBPlusBase.h
        include/NodoBHoja.h
        include/NodoBInterno.h
)