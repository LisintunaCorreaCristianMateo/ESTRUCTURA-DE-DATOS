//########Universidad de las fuerzas Armadas ESPE ######
//Nombre: Cristian Lisintuña
//Fecha: 07/11/2024

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


float ingresar(const char*);
float ingresar(const char* msj) {
    char cad[20]; 
    char c;
    int i = 0;
    bool decimal_point = false; 

    printf("%s", msj);

    while ((c = _getch()) != 13) {
     
        if (c >= '0' && c <= '9') {
            printf("%c", c);
            cad[i++] = c;
        }
        else if (c == '.' && !decimal_point) {
            printf("%c", c);
            cad[i++] = c;
            decimal_point = true; 
        }
    }

 
    if (!decimal_point) {
        printf("\nError: Debe ingresar un número flotante (con punto decimal).\n");
        return ingresar(msj);
    }

    cad[i] = '\0'; 
    return atof(cad); 
}

int main() {
    float numero = ingresar("Ingrese un valor flotante: ");
    //printf("\nEl valor ingresado es: %f\n", numero);
    float numero2=ingresar("Ingresa otro numero flotante");
    
    sum
    
    return 0;
}
