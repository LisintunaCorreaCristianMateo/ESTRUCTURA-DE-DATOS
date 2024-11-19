#include<iostream>
#include"Validar.h"
#include<conio.h>
#include<stdlib.h>
#include <vector>

using namespace std;

int ingresar(const char *mensaje) {
    char num[10];  // Array para almacenar los d�gitos ingresados
    char c;        // Variable para capturar las teclas
    int i = 0;     // �ndice para el array
    int valor;

    cout << mensaje;

    while (true) {
        c = getch();

        if (c == 13) {  // Si presiona Enter (c�digo ASCII 13), termina la entrada
            break;
        } else if (c == 8) {  // Si presiona Backspace (c�digo ASCII 8)
            if (i > 0) {  // Si hay caracteres para borrar
                cout << "\b \b";  // Retrocede, borra el car�cter en pantalla, y retrocede de nuevo
                i--;  // Decrementa el �ndice
            }
        } else if (c >= '0' && c <= '9') {  // Si es un d�gito v�lido
            if (i < 9) {  // Limita la entrada a 9 d�gitos (para evitar desbordamiento)
                cout << c;  // Muestra el car�cter en pantalla
                num[i++] = c;  // Almacena el car�cter en el array
            }
        }
    }

    num[i] = '\0';  // Agrega el terminador nulo al final del array
    valor = atoi(num);  // Convierte la cadena a un entero

    return valor;
}

