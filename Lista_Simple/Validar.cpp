#include<iostream>
#include"Validar.h"
#include<conio.h>
#include<stdlib.h>
#include <vector>

using namespace std;

int ingresar(const char *mensaje) {
    char num[10];  // Array para almacenar los dígitos ingresados
    char c;        // Variable para capturar las teclas
    int i = 0;     // Índice para el array
    int valor;

    cout << mensaje;

    while (true) {
        c = getch();

        if (c == 13) {  // Si presiona Enter (código ASCII 13), termina la entrada
            break;
        } else if (c == 8) {  // Si presiona Backspace (código ASCII 8)
            if (i > 0) {  // Si hay caracteres para borrar
                cout << "\b \b";  // Retrocede, borra el carácter en pantalla, y retrocede de nuevo
                i--;  // Decrementa el índice
            }
        } else if (c >= '0' && c <= '9') {  // Si es un dígito válido
            if (i < 9) {  // Limita la entrada a 9 dígitos (para evitar desbordamiento)
                cout << c;  // Muestra el carácter en pantalla
                num[i++] = c;  // Almacena el carácter en el array
            }
        }
    }

    num[i] = '\0';  // Agrega el terminador nulo al final del array
    valor = atoi(num);  // Convierte la cadena a un entero

    return valor;
}

