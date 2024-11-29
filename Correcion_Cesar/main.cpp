#include <iostream>
#include <string>

using namespace std;

// Clase Nodo que representa un nodo de la lista doblemente enlazada
class Nodo {
private:
    string palabra;
    Nodo* siguiente;
    Nodo* anterior;

public:
    // Constructor
    Nodo(const string& p) : palabra(p), siguiente(nullptr), anterior(nullptr) {}

    // Métodos para acceder a los datos privados
    string& getPalabra() { return palabra; }
    Nodo* getSiguiente() const { return siguiente; }
    Nodo* getAnterior() const { return anterior; }

    // Métodos para modificar los punteros
    void establecerSiguiente(Nodo* nodo) { siguiente = nodo; }
    void establecerAnterior(Nodo* nodo) { anterior = nodo; }
};

// Clase que representa la lista doblemente enlazada
class ListaDoblementeEnlazada {
private:
    Nodo* cabeza;
    Nodo* cola;

public:
    ListaDoblementeEnlazada() : cabeza(nullptr), cola(nullptr) {}

    // Función para agregar un nodo al final de la lista
    void agregar(const string& palabra) {
        Nodo* nuevoNodo = new Nodo(palabra);
        if (!cabeza) {  // Si la lista está vacía
            cabeza = cola = nuevoNodo;
        } else {
            cola->establecerSiguiente(nuevoNodo);
            nuevoNodo->establecerAnterior(cola);
            cola = nuevoNodo;
        }
    }

    // Función para cifrar las palabras en la lista
    void cifrar(char objetivo, int desplazamiento) {
        Nodo* actual = cabeza;
        while (actual) {
            string& palabra = actual->getPalabra();
            for (char& c : palabra) {
                if (c == objetivo && isalpha(c)) {
                    char base = islower(c) ? 'a' : 'A';
                    c = (c - base + desplazamiento) % 26 + base;
                }
            }
            actual = actual->getSiguiente();
        }
    }

    // Función para mostrar la lista
    void mostrar() const {
        Nodo* actual = cabeza;
        while (actual) {
            cout << actual->getPalabra() << ' ';
            actual = actual->getSiguiente();
        }
        cout << endl;
    }

    // Destructor para liberar memoria
    ~ListaDoblementeEnlazada() {
        Nodo* actual = cabeza;
        while (actual) {
            Nodo* siguiente = actual->getSiguiente();
            delete actual;
            actual = siguiente;
        }
    }
};

int main() {
    ListaDoblementeEnlazada lista;
    char objetivo;
    int desplazamiento;

    // Agregar palabras a la lista
    lista.agregar("ana");
    lista.agregar("lana");
    lista.agregar("ariana");

    // Obtener entradas del usuario
    cout << "Ingresa el carácter a cifrar: ";
    cin >> objetivo;
    cout << "Ingresa el número de desplazamiento: ";
    cin >> desplazamiento;

    // Cifrar la lista
    lista.cifrar(objetivo, desplazamiento);

    // Imprimir el resultado
    cout << "Lista cifrada: ";
    lista.mostrar();

    return 0;
}

