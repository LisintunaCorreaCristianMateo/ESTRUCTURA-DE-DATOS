#include <iostream>
#include <string>
#include <sstream>
#include "Validaciones.h"
using namespace std;

// Función plantilla para eliminar una letra de una cadena
template <typename T>
T eliminarLetra(const T& cadena, char letra) {
    T nuevaCadena;
    for (size_t i = 0; i < cadena.size(); ++i) { // Bucle clásico
        if (cadena[i] != letra) {
            nuevaCadena += cadena[i]; // Solo añade el carácter si no es la letra a eliminar
        }
    }
    return nuevaCadena;
}

int main() {
    int opcion, numeros;
    string cadena;
    char letra;

    do {
        cout << "Menu: \n\n";
        cout << "1.-Ingrese una cadena de texto ";
        cout << "\n2.-Ingrese una cadena de enteros ";
        cout << "\n3.-Ingrese una cadena de flotantes ";
        cout << "\n4.-Salir" << endl;
        opcion = ingresar_entero("Elije una opcion: ");

        switch (opcion) {
            case 1: {
                cadena = ingresar_string("\nIngrese el texto: ");
                cout << "Introduce la letra que deseas eliminar: ";
                cin >> letra;
                break;
            }
            case 2: {
                numeros = ingresar_entero("\nIngresa solo numeros: ");
                ostringstream convertir;
                convertir << numeros;
                cadena = convertir.str();

                cout << "\nIntroduce el numero que deseas eliminar: ";
                cin >> letra;
                break;
            }
            case 3: {
                float numeroDecimal = ingresar_float("\nIngresa valores decimales: ");
                ostringstream convertir;
                convertir << numeroDecimal;
                cadena = convertir.str();

                cout << "\nIntroduce la letra que deseas eliminar: ";
                cin >> letra;
                break;
            }
        }

        if (opcion == 1 || opcion == 2 || opcion == 3) {
            string resultado = eliminarLetra(cadena, letra);
            cout << "\n\nCadena resultante es: " << resultado << endl;
        }

    } while (opcion != 4);

    return 0;
}

