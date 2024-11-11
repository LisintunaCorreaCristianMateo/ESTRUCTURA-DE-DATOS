#ifndef OPERACION_H
#define OPERACION_H

#include <iostream>
using namespace std;

template <typename T>
class Operacion {
private:
    T numerador;
    T denominador;

public:
    // Constructor
    Operacion(T num1, T num2);

    // Destructor
    ~Operacion();

    // M�todos getter
    T geternumerador();
    T geterdenominador();
};

// Implementaci�n del constructor
template <typename T>
Operacion<T>::Operacion(T num1, T num2) {
    numerador = num1;
    denominador = num2;
}

// Implementaci�n del destructor (aunque no es necesario en este caso)
template <typename T>
Operacion<T>::~Operacion() {
    // No es necesario implementar nada en el destructor
}

// Implementaci�n de los getters
template <typename T>
T Operacion<T>::geternumerador() {
    return numerador;
}

template <typename T>
T Operacion<T>::geterdenominador() {
    return denominador;
}

#endif

