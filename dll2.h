#ifndef DLL_H
#define DLL_H

#ifdef VALIDAR_EXPORTS
    #define VALIDAR_API __declspec(dllexport)
#else
    #define VALIDAR_API __declspec(dllimport)
#endif

// Prototipo de la función exportada
extern "C" VALIDAR_API int ingresar(const char* mensaje);

#endif // DLL_H

