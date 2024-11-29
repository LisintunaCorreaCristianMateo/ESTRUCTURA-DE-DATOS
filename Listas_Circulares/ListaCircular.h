#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H

#include "Nodo.h"

// Clase ListaCircular
class ListaCircular {
private:
    Nodo* cabeza;

public:
    ListaCircular();
    ~ListaCircular();
    void agregarAlFinal(const string& valor);
    void insertarEnPosicion(const string& valor, int posicion);
    void eliminarNodo(const string& valor);
    bool buscar(const string& valor) const;
    void mostrar() const;
    int contarElementos() const;
    bool estaVacia() const;
};

#endif

