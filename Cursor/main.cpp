#include <iostream>
#include "menu.h"
#include <conio.h> // Para _getch()

using namespace std;

int main() {
    const int numOpciones = 4;
    string opciones[numOpciones] = {"Opcion 1", "Opcion 2", "Opcion 3", "Salir"};
    int opcionSeleccionada = 0; // Inicializamos la opción seleccionada en 0

    while (true) {
        mostrarMenu(opcionSeleccionada, opciones, numOpciones);
        char tecla = _getch(); // Captura una tecla

        if (tecla == 13) { // Detecta Enter (código ASCII 13)
            system("cls"); // Limpia la consola
            procesarSeleccion(opciones[opcionSeleccionada]); // Procesa la opción seleccionada
            if (opciones[opcionSeleccionada] == "Salir") {
                break; // Termina el programa si la opción es "Salir"
            }
        } else if (tecla == -32) { // Detecta teclas especiales (como flechas)
            tecla = _getch(); // Captura la segunda parte del código de la tecla
            if (tecla == 72) { // Flecha arriba
                opcionSeleccionada = (opcionSeleccionada - 1 + numOpciones) % numOpciones;
            } else if (tecla == 80) { // Flecha abajo
                opcionSeleccionada = (opcionSeleccionada + 1) % numOpciones;
            }
        }
    }

    return 0;
}

