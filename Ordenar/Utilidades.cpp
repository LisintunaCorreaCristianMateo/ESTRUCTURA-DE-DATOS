// utilidades.cpp
#include <utility>    // Para std::swap
#include "Fraccion.h"

// Función para ordenar las fracciones
void ordenar(Fraccion &numero1, Fraccion &numero2, Fraccion &numero3) {
    if (numero1.dividir() > numero2.dividir()) {
        std::swap(numero1, numero2);
    }
    if (numero2.dividir() > numero3.dividir()) {
        std::swap(numero2, numero3);
    }
    if (numero1.dividir() > numero2.dividir()) {
        std::swap(numero1, numero2);
    }
}

