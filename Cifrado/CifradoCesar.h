#ifndef CIFRADOCESAR_H
#define CIFRADOCESAR_H

#include <string>

using namespace std;

// Declaraciones de funciones
string cifrarCesar(string texto, int desplazamiento);
string descifrarCesar(string texto, int desplazamiento);
void solicitarClaveYDescifrar(string textoCifrado, int desplazamiento);

#endif

