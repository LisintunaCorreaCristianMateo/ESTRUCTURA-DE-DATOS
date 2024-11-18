#include <iostream>
#include <windows.h>

// Definici�n de la funci�n Suma de la DLL
typedef int (*SumaFunction)(int, int);

int main() {
    // Cargar la DLL
    HMODULE hDLL = LoadLibrary("MiPrimeraLibreria"); // Reemplaza "TuDLL.dll" con el nombre de tu DLL
    if (!hDLL) {
        std::cerr << "Error: No se pudo cargar la DLL." << std::endl;
        return 1;
    }

    // Obtener la direcci�n de la funci�n Suma
    SumaFunction Suma = (SumaFunction)GetProcAddress(hDLL, "Suma");
    if (!Suma) {
        std::cerr << "Error: No se pudo encontrar la funci�n Suma." << std::endl;
        FreeLibrary(hDLL);
        return 1;
    }

    // Usar la funci�n Suma
    int resultado = Suma(5, 3);
    std::cout << "El resultado de la suma es: " << resultado << std::endl;

    // Liberar la DLL
    FreeLibrary(hDLL);
    return 0;
}

