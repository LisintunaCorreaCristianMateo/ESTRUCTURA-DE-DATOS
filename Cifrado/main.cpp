#include "CifradoCesar.h"
#include <iostream>

using namespace std;

int main() {
    string texto;
    int desplazamiento = 3; // Desplazamiento quemado en el código
    
    // Solicitar el texto a cifrar
    cout << "Introduce el texto a cifrar (incluye letras y números): ";
    getline(cin, texto);
    
    // Cifrar el texto con el desplazamiento quemado
    string textoCifrado = cifrarCesar(texto, desplazamiento);
    cout << "Texto cifrado: " << textoCifrado << endl;

    // Solicitar clave y cifrar
    solicitarClaveYDescifrar(textoCifrado, desplazamiento);

    return 0;
}

