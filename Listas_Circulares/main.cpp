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
    cout << "Lista despu�s de eliminar 'dos': ";
    lista.mostrar();

    // Insertar en una posici�n
    lista.insertarEnPosicion("cuatro", 1);
    cout << "Lista despu�s de insertar 'cuatro' en posici�n 1: ";
    lista.mostrar();

    // Contar los elementos
    cout << "N�mero de elementos en la lista: " << lista.contarElementos() << endl;

    // Verificar si la lista est� vac�a
    cout << "�La lista est� vac�a? " << (lista.estaVacia() ? "S�" : "No") << endl;

    return 0;
}

