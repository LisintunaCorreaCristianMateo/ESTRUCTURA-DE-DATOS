#include "ListaDoblementeEnlazada.h"
#include <iostream>

using namespace std;
	ListaDoblementeEnlazada::ListaDoblementeEnlazada(){
	cabeza=NULL;
	 cola=NULL;
	
	}

    // Destructor para liberar memoria
    ListaDoblementeEnlazada::~ListaDoblementeEnlazada() {
        while (cabeza) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }

    // Función para agregar un nodo al final
    void ListaDoblementeEnlazada::agregarAlFinal(const string& valor) {
        Nodo* nuevoNodo = new Nodo(valor);
        if (!cabeza) {
            cabeza = cola = nuevoNodo;
        } else {
            cola->siguiente = nuevoNodo;
            nuevoNodo->anterior = cola;
            cola = nuevoNodo;
        }
    }

    // Función para mostrar la lista hacia adelante
    void ListaDoblementeEnlazada::mostrarAdelante() const {
        Nodo* actual = cabeza;
        while (actual) {
            cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        cout << endl;
    }
    
    
    // Función para mostrar la lista hacia atrás
    void ListaDoblementeEnlazada::mostrarAtras() const {
        Nodo* actual = cola;
        while (actual) {
            cout << actual->dato << " ";
            actual = actual->anterior;
        }
        cout << endl;
    }
