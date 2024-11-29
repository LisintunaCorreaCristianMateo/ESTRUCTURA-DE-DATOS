#include <iostream>
#include <string>
#include "ListaDoblementeEnlazada.h"

using namespace std;

// Clase Nodo para una lista doblemente enlazada


// Clase ListaDoblementeEnlazada


int main() {
    ListaDoblementeEnlazada lista;

    // Agregar elementos a la lista
    lista.agregarAlFinal("uno");
    lista.agregarAlFinal("dos");
    lista.agregarAlFinal("tres");

    // Mostrar la lista hacia adelante
    cout << "Lista hacia adelante: ";
    lista.mostrarAdelante();

    // Mostrar la lista hacia atrás
    cout << "Lista hacia atrás: ";
    lista.mostrarAtras();

    return 0;
}

