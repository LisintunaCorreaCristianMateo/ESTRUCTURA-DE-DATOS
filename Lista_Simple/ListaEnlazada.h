#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H

#include "Nodo.h"

class ListaEnlazada {
private:
    Nodo* cabeza; // Puntero a la cabeza de la lista

public:
    // Constructor
    ListaEnlazada();

    // Métodos para manejar la lista
    void insertar_inicio(int valor);    // Insertar un nodo al inicio
    void insertar_final(int valor);    // Insertar un nodo al final
    void imprimir();             // Imprimir todos los elementos
    void eliminar(int valor);    // Eliminar un nodo por valor
    ~ListaEnlazada();            // Destructor para liberar memoria
};

#endif

