#include "menu.h"
#include <iostream>
#include <conio.h>  // Para _getch()
#include <windows.h> // Para limpiar la consola con system("cls")

using namespace std;

// Funci�n para mostrar el men�
void mostrarMenu(int opcionSeleccionada, const string opciones[], int numOpciones) {
    system("cls"); // Limpia la consola
    cout << "=== Menu ===\n";
    for (int i = 0; i < numOpciones; ++i) {
        if (i == opcionSeleccionada) {
            cout << "> " << opciones[i] << " <\n"; // Resalta la opci�n seleccionada
        } else {
            cout << "  " << opciones[i] << "\n";
        }
    }
}

// Funci�n para procesar la selecci�n de una opci�n
void procesarSeleccion(const string& opcion) { // Opci�n pasada por referencia constante
    if (opcion == "Opcion 1") {
        cout << "Has seleccionado la Opcion 1.\n";
    } else if (opcion == "Opcion 2") {
        cout << "Has seleccionado la Opcion 2.\n";
    } else if (opcion == "Opcion 3") {
        cout << "Has seleccionado la Opcion 3.\n";
    } else if (opcion == "Salir") {
        cout << "Saliendo del programa...\n";
    } else {
        cout << "Opcion no valida.\n";
    }
    system("pause"); // Pausa para permitir que el usuario lea el mensaje
}

