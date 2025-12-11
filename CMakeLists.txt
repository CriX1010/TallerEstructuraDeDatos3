cmake_minimum_required(VERSION 4.0)
project(Taller_3)

set(CMAKE_CXX_STANDARD 14)

add_executable(Taller_3
        src/main.cpp
        src/NodoGrafo.cpp
        include/NodoGrafo.h
        src/NodoBPlusBase.cpp
        include/NodoBPlusBase.h)
