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
        if (c >= '0' && c <= '9') { // Si es un n�mero
            if (i < 9) { // Verifica que no exceda el tama�o del buffer
                cout << c; // Muestra el car�cter
                num[i++] = c; // Agrega al arreglo
            }
        } else if (c == 8 && i > 0) { // Si se presiona Backspace y hay algo que borrar
            cout << "\b \b"; // Retrocede, borra el car�cter en pantalla
            i--; // Reduce el �ndice para eliminar el �ltimo car�cter ingresado
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
                decimal_point = true; // Marcar que se ingres� un punto decimal
            }
            printf("%c", c);       // Mostrar el car�cter ingresado
            cad[i++] = c;         // Guardarlo en el arreglo
        }
        else if (c == 8 && i > 0) { // Si se presiona Backspace y hay algo que borrar
            i--; // Reduce el �ndice para eliminar el �ltimo car�cter ingresado
            if (cad[i] == '.') {
                decimal_point = false; // Si se borr� un punto decimal, permitir otro
            }
            printf("\b \b"); // Retrocede, borra el car�cter en pantalla
        }
    }

    // Agregar .00 si no hay punto decimal
    if (!decimal_point) {
        cad[i++] = '.';
        cad[i++] = '0';
        cad[i++] = '0';
    }

    cad[i] = '\0'; // Cerrar la cadena con null terminator
    printf("\n"); // Salto de l�nea para mantener formato
    return atof(cad); 
}
string ingresar_string(const char* mensaje) {
    char cadena[100]; // Buffer para la cadena
    char c;
    int i = 0;

    cout << mensaje;

    while ((c = _getch()) != 13) { // Mientras no se presione Enter (ASCII 13)
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' ') {
            if (i < 99) { // Verificar que no exceda el tama�o del buffer
                cout << c; // Muestra el car�cter
                cadena[i++] = c; // Agrega el car�cter al arreglo
            }
        } else if (c == 8 && i > 0) { // Si se presiona Backspace y hay algo que borrar
            cout << "\b \b"; // Retrocede, borra el car�cter en pantalla
            i--; // Reduce el �ndice
        }
    }

    cadena[i] = '\0'; // Termina la cadena con el null terminator
    cout << endl; // Salto de l�nea al finalizar

    return string(cadena); // Retorna como un objeto de tipo string
}
string ingresar_cedula(const char* mensaje) {
    char cedula[11]; // Buffer para 10 d�gitos m�s el null terminator
    char c;
    int i = 0;

    cout << mensaje;

    while (true) {
        c = _getch();

        if (c >= '0' && c <= '9') { // Si es un n�mero
            if (i < 10) { // Permitir hasta 10 d�gitos
                cout << c; // Mostrar el car�cter en pantalla
                cedula[i++] = c; // Agregar al arreglo
            }
        } else if (c == 8 && i > 0) { // Si se presiona Backspace y hay algo que borrar
            cout << "\b \b"; // Retrocede y borra el car�cter en pantalla
            i--; // Reduce el �ndice
        } else if (c == 13) { // Si se presiona Enter
            if (i == 10) { // Permitir Enter solo si se ingresaron 10 d�gitos
                break;
            } else {
                // Emitir un sonido para indicar que no se permite Enter
                cout << '\a'; // Beep para indicar error
            }
        }
    }

    cedula[i] = '\0'; // Termina la cadena con el null terminator
    cout << endl; // Salto de l�nea al finalizar

    return string(cedula); // Retorna como un objeto string
}


