#include "ListaEstudiantes.h"
#include <iostream>
#include <sstream>
#include <cctype>
#include <iomanip> // Para setw

using namespace std;

ListaEstudiantes::ListaEstudiantes() : cabeza(NULL) {}

ListaEstudiantes::~ListaEstudiantes() {
    liberarLista();
}

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

void ListaEstudiantes::agregarEstudiante(const string& primerNombre, const string& segundoNombre, const string& apellido, const string& segundoApellido,const string& cedula) {
    string correoBase = generarCorreoBase(primerNombre, segundoNombre, apellido);
    string correoUnico = generarCorreoUnico(correoBase);

    Nodo* nuevo = new Nodo(primerNombre, segundoNombre, apellido, segundoApellido,cedula);
    nuevo->correo = correoUnico;

    nuevo->siguiente = cabeza;
    cabeza = nuevo;

    cout << "\nEstudiante agregado exitosamente." << endl;
    system("pause");
    system("cls");
}

void ListaEstudiantes::mostrarLista() const {
    // Imprimir cabecera
    cout << "\n======================================================================================" << endl;
    cout << "                                Registro de Estudiantes  " << endl;
    cout << "====================================================================================" << endl;
    
    // Imprimir encabezados de columnas
    cout << left << setw(42) << "Nombres y Apellidos" 
         << setw(20) << "Cedula"  // Ampliar espacio aquí
         << setw(30) << "Correo" << endl;
    
    cout << "---------------------------------------------------------------------------------------" << endl;
    
    Nodo* actual = cabeza;
    if (!actual) {
        cout << "La lista esta vacia." << endl;
        system("pause");
        system("cls");
        return;
    }

    while (actual != NULL) {
        string nombreCompleto = actual->primerNombre + " " + actual->segundoNombre + " " + actual->apellido + " " + actual->segundoApellido;

        // Imprimir los datos en formato de columnas
        cout << left << setw(42) << nombreCompleto 
             << setw(20) << actual->cedula  // Ampliar espacio aquí
             << setw(30) << actual->correo << endl;

        // Avanzar al siguiente estudiante
        actual = actual->siguiente;
    }

    cout << "------------------------------------------------------------------------------------------" << endl;
    system("pause");
    system("cls");
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

