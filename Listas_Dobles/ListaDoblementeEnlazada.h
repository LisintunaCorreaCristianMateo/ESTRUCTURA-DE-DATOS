#ifndef ListaDoblementeEnlazada_h
#define ListaDoblementeEnlazada_h
#include "Nodo.h"

class ListaDoblementeEnlazada {
private:
    Nodo* cabeza;
    Nodo* cola;

public:
    ListaDoblementeEnlazada();
       // Destructor para liberar memoria
    ~ListaDoblementeEnlazada();
    

    // Función para agregar un nodo al final
    void agregarAlFinal(const string& valor);

    // Función para mostrar la lista hacia adelante
    void mostrarAdelante() const;

    // Función para mostrar la lista hacia atrás
    void mostrarAtras() const;
    
 
};
#endif

