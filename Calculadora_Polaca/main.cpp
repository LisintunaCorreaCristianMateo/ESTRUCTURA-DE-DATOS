#include <iostream>
#include <stack>
#include <algorithm>
#include <cctype>

using namespace std;

// Funci�n para verificar la prioridad de los operadores
int prioridad(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Conversi�n de infija a postfija
string infijaAPostfija(const string &exp) {
    stack<char> operadores;
    string resultado;

    for (char c : exp) {
        if (isalnum(c)) { // Si es operando, lo a�adimos al resultado
            resultado += c;
        } else if (c == '(') { // Si es par�ntesis de apertura, lo apilamos
            operadores.push(c);
        } else if (c == ')') { // Si es par�ntesis de cierre, vaciamos la pila hasta '('
            while (!operadores.empty() && operadores.top() != '(') {
                resultado += operadores.top();
                operadores.pop();
            }
            operadores.pop(); // Quita el '(' de la pila
        } else { // Si es un operador, maneja la prioridad
            while (!operadores.empty() && prioridad(operadores.top()) >= prioridad(c)) {
                resultado += operadores.top();
                operadores.pop();
            }
            operadores.push(c);
        }
    }

    // Vaciamos la pila al final
    while (!operadores.empty()) {
        resultado += operadores.top();
        operadores.pop();
    }

    return resultado;
}

// Conversi�n de infija a prefija
string infijaAPrefija(string exp) {
    reverse(exp.begin(), exp.end()); // Invertir la expresi�n
    for (char &c : exp) {
        if (c == '(') c = ')';      // Intercambia par�ntesis de apertura
        else if (c == ')') c = '('; // Intercambia par�ntesis de cierre
    }

    string postfija = infijaAPostfija(exp); // Convertir a postfija
    reverse(postfija.begin(), postfija.end()); // Invertir para obtener prefija
    return postfija;
}

int main() {
    string expresion;
    char c;

    cout << "Ingrese la expresion infija (sin espacios): ";

    // Leer car�cter por car�cter y construir la expresi�n, ignorando espacios
    while ((c = cin.get()) != '\n') {
        if (c != ' ') { // Ignorar espacios
            expresion += c;
        }
    }

    // Convertir a postfija y prefija
    string postfija = infijaAPostfija(expresion);
    string prefija = infijaAPrefija(expresion);

    // Mostrar resultados
    cout << "Notacion Postfija: " << postfija << endl;
    cout << "Notacion Prefija: " << prefija << endl;

    return 0;
}

