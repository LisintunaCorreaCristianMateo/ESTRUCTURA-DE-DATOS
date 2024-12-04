#include <iostream>
#include <functional>
using namespace std;

class Fraccion {
private:
    int numerador;
    int denominador;

public:
    // Constructor
    Fraccion(int num, int den) : numerador(num), denominador(den) {}

    // Sobrecarga del operador +
    Fraccion operator+(const Fraccion& otra) {
        auto sumarFracciones = [](int n1, int d1, int n2, int d2) {
            return Fraccion(n1 * d2 + n2 * d1, d1 * d2);
        };
        return sumarFracciones(numerador, denominador, otra.numerador, otra.denominador);
    }

    // Método para imprimir la fracción
    void imprimir() {
        cout << numerador << "/" << denominador << endl;
    }
};

int main() {
    auto simplificarFraccion = [](Fraccion f) {
        // Aquí puedes agregar lógica para simplificar fracciones (máximo común divisor, etc.)
        return f; // Por simplicidad, no hacemos nada aquí.
    };

    Fraccion f1(1, 2);
    Fraccion f2(1, 3);

    Fraccion resultado = f1 + f2;
    resultado = simplificarFraccion(resultado);  // Lambda para simplificar fracción
    resultado.imprimir();                        // Salida: 5/6

    return 0;
}

