#include "ListaEnlazada.h"
#include <iostream>
using namespace std;

// Constructor
ListaEnlazada::ListaEnlazada() : cabeza(NULL) {}

// Insertar un nodo al inicio de la lista
void ListaEnlazada::insertar_inicio(int valor) {
    Nodo* nuevo = new Nodo(valor);
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
}

// Insertar un nodo al final de la lista
void ListaEnlazada::insertar_final(int valor) {
    Nodo* nuevo = new Nodo(valor);
    if (cabeza == NULL) {
        // Si la lista está vacía, el nuevo nodo es la cabeza
        cabeza = nuevo;
    } else {
        // Recorremos la lista hasta llegar al último nodo
        Nodo* temp = cabeza;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        // Enlazamos el nuevo nodo al final
        temp->siguiente = nuevo;
    }
}

// Imprimir todos los elementos de la lista
void ListaEnlazada::imprimir() {
    if (cabeza == NULL) {
        cout << "La lista está vacía.\n";
        return;
    }

    Nodo* actual = cabeza;
    while (actual != NULL) {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }
    cout << "NULL\n";
}

// Eliminar un nodo por valor
void ListaEnlazada::eliminar(int valor) {
    if (cabeza == NULL) {
        cout << "La lista está vacía, no se puede eliminar.\n";
        return;
    }

    // Si el nodo a eliminar está en la cabeza
    if (cabeza->dato == valor) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
        cout << "Elemento " << valor << " eliminado.\n";
        return;
    }

    // Buscar el nodo a eliminar
    Nodo* actual = cabeza;
    Nodo* anterior = NULL;
    while (actual != NULL && actual->dato != valor) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        cout << "Elemento " << valor << " no encontrado en la lista.\n";
        return;
    }

    // Eliminar el nodo
    anterior->siguiente = actual->siguiente;
    delete actual;
    cout << "Elemento " << valor << " eliminado.\n";
}

// Destructor para liberar memoria
ListaEnlazada::~ListaEnlazada() {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        Nodo* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
}

