#include <iostream>
#include "Operacion.cpp"
#include "Validar.h"
#include "Sumar.h"

using namespace std;

int main() {
    //con valores enteros
    int a, b;
    cout << "Primera Fraccion\n\n";

    int valor1 = ingresar("Ingrese el numerador: ");
    int valor2 = ingresar("\nIngrese el denominador: ");
    Operacion<int> fraccion1(valor1, valor2);

    cout << "\n\nSegunda Fraccion\n";

    valor1 = ingresar("Ingrese el numerador: ");
    valor2 = ingresar("\nIngrese el denominador: ");
    Operacion<int> fraccion2(valor1, valor2);
	
	cout<<endl;

    // Getters para obtener los atributos
    int numerador1 = fraccion1.geternumerador();
    int denominador1 = fraccion1.geterdenominador();

    int numerador2 = fraccion2.geternumerador();
    int denominador2 = fraccion2.geterdenominador();

    // Sumar fracciones
    suma(numerador1, denominador1, numerador2, denominador2);

    return 0;
}

