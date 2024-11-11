#ifndef SUMAR_H
#define SUMAR_H

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void suma(T a, T b, T c, T d) {
    double numer;
    double denom;

    // Verificar si los denominadores son cero
    if (b == 0 || d == 0) {
        cout << "La suma no está definida (denominador igual a 0)" << endl;
        return;
    }
	
    // Sumar fracciones con el mismo denominador
    if (b == d) {
        numer = a + c;
        denom = b;
    } else {
        // Sumar fracciones con diferentes denominadores
        numer = (a * d) + (c * b);
        denom = b * d;
    }

    // Mostrar el resultado como fracción
    cout<<endl;
	cout<<"La suma de las fracciones es: " << numer << " / " << denom << " = " << (numer / denom) << endl;
}

#endif

