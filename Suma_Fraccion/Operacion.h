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

    // Métodos getter
    T geternumerador();
    T geterdenominador();
};

// Implementación del constructor
template <typename T>
Operacion<T>::Operacion(T num1, T num2) {
    numerador = num1;
    denominador = num2;
}

// Implementación del destructor (aunque no es necesario en este caso)
template <typename T>
Operacion<T>::~Operacion() {
    // No es necesario implementar nada en el destructor
}

// Implementación de los getters
template <typename T>
T Operacion<T>::geternumerador() {
    return numerador;
}

template <typename T>
T Operacion<T>::geterdenominador() {
    return denominador;
}

#endif

