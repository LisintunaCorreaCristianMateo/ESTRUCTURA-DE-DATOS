#ifndef NODO_H
#define NODO_H

#include <string>
using namespace std;

// Clase Nodo para una lista circular
class Nodo {
public:
    string dato;
    Nodo* siguiente;

    Nodo(const string& valor);
};

#endif

