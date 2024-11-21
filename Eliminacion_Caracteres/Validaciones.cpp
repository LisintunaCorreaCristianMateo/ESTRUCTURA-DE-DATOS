#include<iostream>
#include"Validaciones.h"
#include <conio.h>
#include <stdlib.h>
#include<string>

using namespace std;


int ingresar_entero(const char *mensaje) {
    char num[10];
    char c;
    int i = 0;
    int valor;

    cout << mensaje;

    while ((c = getch()) != 13) { // Mientras no se presione Enter
        if (c >= '0' && c <= '9') { // Si es un número
            if (i < 9) { // Verifica que no exceda el tamaño del buffer
                cout << c; // Muestra el carácter
                num[i++] = c; // Agrega al arreglo
            }
        } else if (c == 8 && i > 0) { // Si se presiona Backspace y hay algo que borrar
            cout << "\b \b"; // Retrocede, borra el carácter en pantalla
            i--; // Reduce el índice para eliminar el último carácter ingresado
        }
    }

    num[i] = '\0'; // Termina la cadena
    valor = atoi(num); // Convierte la cadena a entero

    return valor;
}
float ingresar_float(const char* msj) {
    char cad[20]; 
    char c;
    int i = 0;
    bool decimal_point = false; 

    printf("%s", msj);

    while ((c = _getch()) != 13) { // Mientras no se presione Enter (ASCII 13)
        if ((c >= '0' && c <= '9') || (c == '.' && !decimal_point)) {
            if (c == '.') {
                decimal_point = true; // Marcar que se ingresó un punto decimal
            }
            printf("%c", c);       // Mostrar el carácter ingresado
            cad[i++] = c;         // Guardarlo en el arreglo
        }
        else if (c == 8 && i > 0) { // Si se presiona Backspace y hay algo que borrar
            i--; // Reduce el índice para eliminar el último carácter ingresado
            if (cad[i] == '.') {
                decimal_point = false; // Si se borró un punto decimal, permitir otro
            }
            printf("\b \b"); // Retrocede, borra el carácter en pantalla
        }
    }

    // Agregar .00 si no hay punto decimal
    if (!decimal_point) {
        cad[i++] = '.';
        cad[i++] = '0';
        cad[i++] = '0';
    }

    cad[i] = '\0'; // Cerrar la cadena con null terminator
    printf("\n"); // Salto de línea para mantener formato
    return atof(cad); 
}
string ingresar_string(const char* mensaje) {
    char cadena[100]; // Buffer para la cadena
    char c;
    int i = 0;

    cout << mensaje;

    while ((c = _getch()) != 13) { // Mientras no se presione Enter (ASCII 13)
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' ') {
            if (i < 99) { // Verificar que no exceda el tamaño del buffer
                cout << c; // Muestra el carácter
                cadena[i++] = c; // Agrega el carácter al arreglo
            }
        } else if (c == 8 && i > 0) { // Si se presiona Backspace y hay algo que borrar
            cout << "\b \b"; // Retrocede, borra el carácter en pantalla
            i--; // Reduce el índice
        }
    }

    cadena[i] = '\0'; // Termina la cadena con el null terminator
    cout << endl; // Salto de línea al finalizar

    return string(cadena); // Retorna como un objeto de tipo string
}
string ingresar_cedula(const char* mensaje) {
    char cedula[11]; // Buffer para 10 dígitos más el null terminator
    char c;
    int i = 0;

    cout << mensaje;

    while (true) {
        c = _getch();

        if (c >= '0' && c <= '9') { // Si es un número
            if (i < 10) { // Permitir hasta 10 dígitos
                cout << c; // Mostrar el carácter en pantalla
                cedula[i++] = c; // Agregar al arreglo
            }
        } else if (c == 8 && i > 0) { // Si se presiona Backspace y hay algo que borrar
            cout << "\b \b"; // Retrocede y borra el carácter en pantalla
            i--; // Reduce el índice
        } else if (c == 13) { // Si se presiona Enter
            if (i == 10) { // Permitir Enter solo si se ingresaron 10 dígitos
                break;
            } else {
                // Emitir un sonido para indicar que no se permite Enter
                cout << '\a'; // Beep para indicar error
            }
        }
    }

    cedula[i] = '\0'; // Termina la cadena con el null terminator
    cout << endl; // Salto de línea al finalizar

    return string(cedula); // Retorna como un objeto string
}
int ingresar_unidad(const char *mensaje) {
    char c;
    int valor;

    cout << mensaje;

    while (true) { // Bucle hasta que se ingrese un dígito válido
        c = getch(); // Leer un carácter
        if (c >= '0' && c <= '9') { // Si es un dígito
            cout << c << endl; // Mostrar el carácter ingresado
            valor = c - '0'; // Convertir el carácter a su valor numérico
            break; // Salir del bucle
        } else {
            cout << "\nPor favor, ingresa solo un número entre 0 y 9: ";
        }
    }

    return valor;
}

