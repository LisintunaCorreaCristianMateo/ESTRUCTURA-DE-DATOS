#include "ListaCircular.h"
#include <iostream>

using namespace std;

int main() {
    ListaCircular lista;

    // Agregar elementos a la lista circular
    lista.agregarAlFinal("uno");
    lista.agregarAlFinal("dos");
    lista.agregarAlFinal("tres");

    // Mostrar la lista
    cout << "Lista circular inicial: ";
    lista.mostrar();

    // Buscar un elemento
    cout << "Buscando 'dos': " << (lista.buscar("dos") ? "Encontrado" : "No encontrado") << endl;

    // Eliminar un elemento
    lista.eliminarNodo("dos");
    cout << "Lista después de eliminar 'dos': ";
    lista.mostrar();

    // Insertar en una posición
    lista.insertarEnPosicion("cuatro", 1);
    cout << "Lista después de insertar 'cuatro' en posición 1: ";
    lista.mostrar();

    // Contar los elementos
    cout << "Número de elementos en la lista: " << lista.contarElementos() << endl;

    // Verificar si la lista está vacía
    cout << "¿La lista está vacía? " << (lista.estaVacia() ? "Sí" : "No") << endl;

    return 0;
}

