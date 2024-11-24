#include "Archivotxt.h"
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

void Archivotxt::leerDesdeArchivo(const string& nombreArchivo, ListaEstudiantes& lista) {
    ifstream archivo(nombreArchivo.c_str(), ios::in); // Abrir archivo para lectura

    if (!archivo) {
        cout << "No se pudo abrir el archivo para leer los datos." << endl;
        return;
    }

    lista.liberarLista(); // Limpia la lista antes de cargar nuevos datos

    string linea;
    while (getline(archivo, linea)) {
        // Verificar si la línea tiene la longitud suficiente antes de continuar
        if (linea.length() < 90) {  // Longitud esperada según los datos
            cout << "Línea con formato incorrecto: " << linea << endl;
            continue;
        }

        // Extraer campos con las posiciones y anchos establecidos
        string primerNombre = linea.substr(0, 15);
        string segundoNombre = linea.substr(15, 15);
        string apellido = linea.substr(30, 15);
        string segundoApellido = linea.substr(45, 15);
        string cedula = linea.substr(60, 15);
        string correo = linea.substr(75, 30);

        // Eliminar espacios sobrantes en los campos
        primerNombre = lista.eliminarEspacios(primerNombre);
        segundoNombre = lista.eliminarEspacios(segundoNombre);
        apellido = lista.eliminarEspacios(apellido);
        segundoApellido = lista.eliminarEspacios(segundoApellido);
        cedula = lista.eliminarEspacios(cedula);
        correo = lista.eliminarEspacios(correo);

        // Agregar el estudiante a la lista
        Nodo* nuevo = new Nodo(primerNombre, segundoNombre, apellido, segundoApellido, cedula);
        nuevo->correo = correo;

        if (lista.getCabeza() == NULL) {
            lista.setCabeza(nuevo);
        } else {
            Nodo* temp = lista.getCabeza();
            while (temp->siguiente != NULL) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevo;
        }
    }

    archivo.close(); // Cerrar el archivo
   // cout << "Datos cargados desde el archivo: " << nombreArchivo << endl;
}

void Archivotxt::guardarEnArchivo(const string& nombreArchivo, const ListaEstudiantes& lista) {
    ofstream archivo(nombreArchivo.c_str(), ios::out | ios::trunc); // Abrir archivo para escritura

    if (!archivo) {
        cout << "No se pudo abrir el archivo para guardar los datos." << endl;
        return;
    }

    Nodo* actual = lista.getCabeza();
    if (actual == NULL) {
        cout << "La lista está vacía, no hay datos para guardar." << endl;
        archivo.close();
        return;
    }

    while (actual != NULL) {
        archivo << left << setw(15) << actual->primerNombre
                << setw(15) << actual->segundoNombre
                << setw(15) << actual->apellido
                << setw(15) << actual->segundoApellido
                << setw(15) << actual->cedula
                << setw(30) << actual->correo << endl;

        if (!archivo) {
            cout << "Error al escribir en el archivo." << endl;
            archivo.close();
            return;
        }

        actual = actual->siguiente;
    }

    archivo.close();
    cout << "Datos guardados en el archivo: " << nombreArchivo << endl;
}

