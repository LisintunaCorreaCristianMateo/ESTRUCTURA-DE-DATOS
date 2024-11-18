#ifndef DLL_H
#define DLL_H

#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

// Exportar funciones
extern "C" DLL_API int Suma(int a, int b);

// Exportar clase (si es necesario)
class DLL_API DllClass {
public:
    DllClass();
    ~DllClass();
    void Ejemplo(); // Método ejemplo
};

#endif // DLL_H

