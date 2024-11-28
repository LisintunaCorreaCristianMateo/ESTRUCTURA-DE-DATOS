#include "CifradoCesar.h"
#include <iostream>


using namespace std;

// Definición de la función para cifrar el mensaje
string cifrarCesar(string texto) {
    int desplazamiento = 3; // Desplazamiento para el cifrado
    string resultado = "";

    // Recorrer cada carácter de la cadena
    for (int i = 0; i < texto.length(); i++) {
        char c = texto[i];

        // Cifrar letras mayúsculas
        if (isupper(c)) {
            c = char(int(c + desplazamiento - 65) % 26 + 65);
        }
        // Cifrar letras minúsculas
        else if (islower(c)) {
            c = char(int(c + desplazamiento - 97) % 26 + 97);
        }
        // Cifrar números
        else if (isdigit(c)) {
            c = char(int(c + desplazamiento - 48) % 10 + 48);
        }

        // No cifrar otros caracteres (como espacios y signos de puntuación)
        // Los caracteres se agregan tal cual al resultado
        resultado += c;
    }

    return resultado;
}


// Definición de la función para descifrar el mensaje
string descifrarCesar(string texto) {
    int desplazamiento = 3;
    string resultado = "";

    for (int i = 0; i < texto.length(); i++) {
        char c = texto[i];

        // Mantener los espacios sin cambios
        if (c == ' ') {
            resultado += c;
        }
        // Descifrar letras mayúsculas
        else if (isupper(c)) {
            c = char(int(c - desplazamiento - 65 + 26) % 26 + 65);
            resultado += c;
        }
        // Descifrar letras minúsculas
        else if (islower(c)) {
            c = char(int(c - desplazamiento - 97 + 26) % 26 + 97);
            resultado += c;
        }
        // Descifrar números
        else if (isdigit(c)) {
            c = char(int(c - desplazamiento - 48 + 10) % 10 + 48);
            resultado += c;
        }
        // Otros caracteres no se descifran
        else {
            resultado += c;
        }
    }

    return resultado;
}






