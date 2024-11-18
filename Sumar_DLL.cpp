#include <iostream>
#include <windows.h>

// Definición de la función Suma de la DLL
typedef int (*SumaFunction)(int, int);

int main() {
    // Cargar la DLL
    HMODULE hDLL = LoadLibrary("MiPrimeraLibreria"); // Reemplaza "TuDLL.dll" con el nombre de tu DLL
    if (!hDLL) {
        std::cerr << "Error: No se pudo cargar la DLL." << std::endl;
        return 1;
    }

    // Obtener la dirección de la función Suma
    SumaFunction Suma = (SumaFunction)GetProcAddress(hDLL, "Suma");
    if (!Suma) {
        std::cerr << "Error: No se pudo encontrar la función Suma." << std::endl;
        FreeLibrary(hDLL);
        return 1;
    }

    // Usar la función Suma
    int resultado = Suma(5, 3);
    std::cout << "El resultado de la suma es: " << resultado << std::endl;

    // Liberar la DLL
    FreeLibrary(hDLL);
    return 0;
}

