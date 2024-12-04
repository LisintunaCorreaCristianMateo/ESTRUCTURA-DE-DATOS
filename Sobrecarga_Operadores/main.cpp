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

    // M�todo para imprimir la fracci�n
    void imprimir() {
        cout << numerador << "/" << denominador << endl;
    }
};

int main() {
    auto simplificarFraccion = [](Fraccion f) {
        // Aqu� puedes agregar l�gica para simplificar fracciones (m�ximo com�n divisor, etc.)
        return f; // Por simplicidad, no hacemos nada aqu�.
    };

    Fraccion f1(1, 2);
    Fraccion f2(1, 3);

    Fraccion resultado = f1 + f2;
    resultado = simplificarFraccion(resultado);  // Lambda para simplificar fracci�n
    resultado.imprimir();                        // Salida: 5/6

    return 0;
}

