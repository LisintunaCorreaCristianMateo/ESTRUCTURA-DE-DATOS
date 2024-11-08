// Fraccion.cpp
#include <iostream>
#include "Fraccion.h"
using namespace std;

// Constructor de Fraccion
Fraccion::Fraccion(int _a, int _b) {
    numerador = _a;
    denominador = _b;
}

// Método para imprimir la fracción
void Fraccion::imprimir() {
    cout << numerador << "/" << denominador << " ";
}

// Método para dividir el numerador por el denominador
float Fraccion::dividir() {
    return numerador / denominador;
}

