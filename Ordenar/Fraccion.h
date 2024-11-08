// Fraccion.h
#ifndef FRACCION_H
#define FRACCION_H

class Fraccion {
    private:
        float numerador;
        float denominador;

    public:
        Fraccion(int, int);      // Constructor
        void imprimir();         // M�todo para imprimir la fracci�n
        float dividir();         // M�todo para obtener el valor decimal de la fracci�n
};

#endif

