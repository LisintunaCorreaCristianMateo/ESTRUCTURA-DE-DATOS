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
    

    // Funci�n para agregar un nodo al final
    void agregarAlFinal(const string& valor);

    // Funci�n para mostrar la lista hacia adelante
    void mostrarAdelante() const;

    // Funci�n para mostrar la lista hacia atr�s
    void mostrarAtras() const;
    
 
};
#endif

