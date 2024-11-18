#define EXPORTAR_DLL
#include "dll2.h"
#include <conio.h>
#include <cstdlib> // Para atoi
#include<iostream>

using namespace std;

// Implementaci�n de la funci�n exportada
extern "C" VALIDAR_API int ingresar(const char* mensaje) {
    char num[10];
    char c;
    int i = 0;
    int valor;

    cout << mensaje;

    // Leer entrada del usuario car�cter por car�cter
    while ((c = getch()) != 13) { // Enter (ASCII 13)
        if (c >= '0' && c <= '9') { // Aceptar solo n�meros
            cout << c;
            num[i++] = c;
        }
    }

    num[i] = '\0'; // Terminar la cadena
    valor = atoi(num); // Convertir cadena a entero

    return valor;
}

// Implementaci�n de la funci�n DllMain
#include <windows.h>

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    switch (fdwReason) {
        case DLL_PROCESS_ATTACH:
            // C�digo para inicializaci�n
            break;
        case DLL_PROCESS_DETACH:
            // C�digo para limpieza
            break;
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
            break;
    }
    return TRUE;
}
