#include "ListaCircular.h"
#include <iostream>

using namespace std;

// Constructor de la lista circular
ListaCircular::ListaCircular() : cabeza(nullptr) {}

// Destructor de la lista circular
ListaCircular::~ListaCircular() {
    if (!cabeza) return;

    Nodo* actual = cabeza;
    do {
        Nodo* siguienteNodo = actual->siguiente;
        delete actual;
        actual = siguienteNodo;
    } while (actual != cabeza);
}

// Funci�n para agregar un nodo al final
void ListaCircular::agregarAlFinal(const string& valor) {
    Nodo* nuevoNodo = new Nodo(valor);
    if (!cabeza) {
        cabeza = nuevoNodo;
        nuevoNodo->siguiente = cabeza;  // Apunta a s� mismo
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente != cabeza) {  // Encuentra el �ltimo nodo
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
        nuevoNodo->siguiente = cabeza;  // Cierra el ciclo
    }
}

// Funci�n para mostrar la lista circular
void ListaCircular::mostrar() const {
    if (!cabeza) return;

    Nodo* actual = cabeza;
    do {
        cout << actual->dato << " ";
        actual = actual->siguiente;
    } while (actual != cabeza);
    cout << endl;
}

// Funci�n para buscar un valor en la lista
bool ListaCircular::buscar(const string& valor) const {
    if (!cabeza) return false;

    Nodo* actual = cabeza;
    do {
        if (actual->dato == valor)
            return true;
        actual = actual->siguiente;
    } while (actual != cabeza);
    
    return false;
}

// Funci�n para eliminar un nodo espec�fico por valor
void ListaCircular::eliminarNodo(const string& valor) {
    if (!cabeza) return;

    Nodo* actual = cabeza;
    Nodo* anterior = nullptr;

    // Si la cabeza es el nodo que se quiere eliminar
    if (cabeza->dato == valor) {
        while (actual->siguiente != cabeza) {
            actual = actual->siguiente;
        }
        Nodo* nodoAEliminar = cabeza;
        actual->siguiente = cabeza->siguiente;  // Cerrar el ciclo
        cabeza = cabeza->siguiente;
        delete nodoAEliminar;
        return;
    }

    anterior = cabeza;
    actual = cabeza->siguiente;
    while (actual != cabeza && actual->dato != valor) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual != cabeza) {  // Se encontr� el nodo a eliminar
        anterior->siguiente = actual->siguiente;
        delete actual;
    }
}

// Funci�n para insertar un nodo en una posici�n espec�fica
void ListaCircular::insertarEnPosicion(const string& valor, int posicion) {
    Nodo* nuevoNodo = new Nodo(valor);
    if (!cabeza || posicion == 0) {
        nuevoNodo->siguiente = cabeza ? cabeza : nuevoNodo;
        if (!cabeza) {
            cabeza = nuevoNodo;
        } else {
            Nodo* actual = cabeza;
            while (actual->siguiente != cabeza) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevoNodo;
            cabeza = nuevoNodo;
        }
        return;
    }

    Nodo* actual = cabeza;
    for (int i = 1; i < posicion && actual->siguiente != cabeza; i++) {
        actual = actual->siguiente;
    }
    nuevoNodo->siguiente = actual->siguiente;
    actual->siguiente = nuevoNodo;
}

// Funci�n para contar el n�mero de elementos en la lista
int ListaCircular::contarElementos() const {
    if (!cabeza) return 0;

    int contador = 0;
    Nodo* actual = cabeza;
    do {
        contador++;
        actual = actual->siguiente;
    } while (actual != cabeza);

    return contador;
}

// Funci�n para verificar si la lista est� vac�a
bool ListaCircular::estaVacia() const {
    return cabeza == nullptr;
}

