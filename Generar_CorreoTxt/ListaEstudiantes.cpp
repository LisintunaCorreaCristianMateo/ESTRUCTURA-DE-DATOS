#include "ListaEstudiantes.h"
#include "Archivotxt.h" // Incluimos la nueva clase Archivos
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cctype> // Para funciones de manipulación de caracteres

using namespace std;

// Constructor
ListaEstudiantes::ListaEstudiantes() : cabeza(NULL) {}

// Destructor
ListaEstudiantes::~ListaEstudiantes() {
    liberarLista();
}

// Métodos de manipulación de cadenas
string ListaEstudiantes::convertirMinusculas(const string& cadena) {
    string resultado = cadena;
    for (size_t i = 0; i < cadena.length(); ++i) {
        resultado[i] = tolower(cadena[i]);
    }
    return resultado;
}

string ListaEstudiantes::convertirAString(int numero) {
    stringstream ss;
    ss << numero;
    return ss.str();
}

string ListaEstudiantes::eliminarEspacios(const string& cadena) {
    string resultado;
    for (size_t i = 0; i < cadena.length(); ++i) {
        if (cadena[i] != ' ') {
            resultado += cadena[i];
        }
    }
    return resultado;
}

// Métodos relacionados con generación de correos
string ListaEstudiantes::generarCorreoBase(const string& primerNombre, const string& segundoNombre, const string& apellido) {
    char inicial1 = tolower(primerNombre[0]);
    char inicial2 = tolower(segundoNombre[0]);
    string apellidoSinEspacios = eliminarEspacios(apellido);
    string apellidoMinuscula = convertirMinusculas(apellidoSinEspacios);

    return string(1, inicial1) + string(1, inicial2) + apellidoMinuscula;
}

string ListaEstudiantes::generarCorreoUnico(const string& baseCorreo) {
    string correoUnico = baseCorreo + "@espe.edu.ec";
    int contador = 1;

    bool existe = true;
    while (existe) {
        existe = false;
        Nodo* actual = cabeza;

        while (actual != NULL) {
            if (actual->correo == correoUnico) {
                existe = true;
                break;
            }
            actual = actual->siguiente;
        }

        if (existe) {
            correoUnico = baseCorreo + convertirAString(contador) + "@espe.edu.ec";
            contador++;
        }
    }

    return correoUnico;
}

// Métodos de manejo de la lista enlazada
void ListaEstudiantes::agregarEstudiante(const string& primerNombre, const string& segundoNombre, const string& apellido, const string& segundoApellido, const string& cedula) {
    string correoBase = generarCorreoBase(primerNombre, segundoNombre, apellido);
    string correoUnico = generarCorreoUnico(correoBase);

    Nodo* nuevo = new Nodo(primerNombre, segundoNombre, apellido, segundoApellido, cedula);
    nuevo->correo = correoUnico;
    nuevo->siguiente = NULL;

    if (cabeza == NULL) {
        cabeza = nuevo;
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }

    cout << "\nEstudiante agregado exitosamente." << endl;
    system("pause");
    system("cls");
}

void ListaEstudiantes::mostrarLista() const {
    cout << "\n=========================================================================================" << endl;
    cout << "                                Registro de Estudiantes  " << endl;
    cout << "=========================================================================================" << endl;
    cout << left << setw(42) << "Nombres y Apellidos" 
         << setw(20) << "Cedula" 
         << setw(30) << "Correo" << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;

    Nodo* actual = cabeza;
    if (!actual) {
        cout << "La lista esta vacia." << endl;
        system("pause");
        system("cls");
        return;
    }

    while (actual != NULL) {
        string nombreCompleto = actual->primerNombre + " " + actual->segundoNombre + " " + actual->apellido + " " + actual->segundoApellido;
        cout << left << setw(42) << nombreCompleto 
             << setw(20) << actual->cedula 
             << setw(30) << actual->correo << endl;
        actual = actual->siguiente;
    }

    cout << "-----------------------------------------------------------------------------------------" << endl;
    //system("pause");
    //system("cls");
}

void ListaEstudiantes::liberarLista() {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
    cabeza = NULL;
}

void ListaEstudiantes::eliminarEstudiante(const string& cedula) {
    if (cabeza == NULL) {
        cout << "\nLa lista esta vacia. No se puede eliminar ningun estudiante." << endl;
        system("pause");
        system("cls");
        return;
    }

    Nodo* actual = cabeza;
    Nodo* anterior = NULL;

    while (actual != NULL && actual->cedula != cedula) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        cout << "\nNo se encontro ningun estudiante con la cedula: " << cedula << endl;
    } else {
        if (anterior == NULL) {
            cabeza = actual->siguiente;
        } else {
            anterior->siguiente = actual->siguiente;
        }
        delete actual;
        cout << "\nEstudiante eliminado exitosamente." << endl;
    }

    system("pause");
    system("cls");
}

