// Fraccion.h
#ifndef FRACCION_H
#define FRACCION_H

class Fraccion {
    private:
        float numerador;
        float denominador;

    public:
        Fraccion(int, int);      // Constructor
        void imprimir();         // Método para imprimir la fracción
        float dividir();         // Método para obtener el valor decimal de la fracción
};

#endif

