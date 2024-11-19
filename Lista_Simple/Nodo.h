#ifndef NODO_H
#define NODO_H

#include <cstddef> // Incluye esta librería para NULL

class Nodo {
public:
    int dato;        // Valor del nodo
    Nodo* siguiente; // Puntero al siguiente nodo

    // Constructor
    Nodo(int valor) : dato(valor), siguiente(NULL) {}
};

#endif

