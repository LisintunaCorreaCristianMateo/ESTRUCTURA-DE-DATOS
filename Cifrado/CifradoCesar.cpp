#include "CifradoCesar.h"
#include <iostream>

using namespace std;

// Definición de la función para cifrar el mensaje
string cifrarCesar(string texto, int desplazamiento) {
    string resultado = "";

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
        // Otros caracteres no se cifran
        resultado += c;
    }

    return resultado;
}

// Definición de la función para descifrar el mensaje
string descifrarCesar(string texto, int desplazamiento) {
    string resultado = "";

    for (int i = 0; i < texto.length(); i++) {
        char c = texto[i];

        // Descifrar letras mayúsculas
        if (isupper(c)) {
            c = char(int(c - desplazamiento - 65 + 26) % 26 + 65);
        }
        // Descifrar letras minúsculas
        else if (islower(c)) {
            c = char(int(c - desplazamiento - 97 + 26) % 26 + 97);
        }
        // Descifrar números
        else if (isdigit(c)) {
            c = char(int(c - desplazamiento - 48 + 10) % 10 + 48);
        }
        // Otros caracteres no se descifran
        resultado += c;
    }

    return resultado;
}

// Definición de la función que solicita la clave y realiza el descifrado
void solicitarClaveYDescifrar(string textoCifrado, int desplazamiento) {
	
    string contrasena;
    string claveCorrecta = "miClaveSegura";
    int opc;

    // Solicitar la clave para descifrar
    cout << "Introduce la clave para descifrar: ";
    cin >> contrasena;

    // Si la clave es incorrecta, ofrecer opciones hasta que se ingrese correctamente o salir
    while (contrasena != claveCorrecta) {
        cout << "\nClave incorrecta.\n";
        cout << "1. Volver a ingresar la clave\n";
        cout << "2. Salir\n";
        cout << "Elija una opción: ";
        cin >> opc;

        switch (opc) {
            case 1:
                cout << "Introduce la clave para descifrar: ";
                cin >> contrasena;
                break;
            case 2:
                cout << "Saliendo del programa...\n";
                return; // Salir de la función
            default:
                cout << "Opción inválida. Intente de nuevo.\n";
                break;
        }

        // Limpiar la pantalla (opcional, solo funciona en Windows)
        system("cls"); // Para Linux o MacOS, cambiar a "clear"
    }

    // Si la clave es correcta, descifrar el texto
    string textoDescifrado = descifrarCesar(textoCifrado, desplazamiento);
    cout << "Texto descifrado: " << textoDescifrado << endl;
}

