#include "Archivotxt.h"
#include "CifradoCesar.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>


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
        istringstream flujo(linea);
        string primerNombre, segundoNombre, apellido, segundoApellido, cedula, correo;

        // Usar getline con delimitador de coma para extraer cada campo
        if (!getline(flujo, primerNombre, ',') ||
            !getline(flujo, segundoNombre, ',') ||
            !getline(flujo, apellido, ',') ||
            !getline(flujo, segundoApellido, ',') ||
            !getline(flujo, cedula, ',') ||
            !getline(flujo, correo, ',')) {
            cout << "Línea con formato incorrecto: " << linea << endl;
            continue;
        }

        // Crear un nodo con los datos leídos
        Nodo* nuevo = new Nodo(primerNombre, segundoNombre, apellido, segundoApellido, cedula, correo);

        // Agregar el nodo a la lista
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
    cout << "Datos cargados desde el archivo: " << nombreArchivo << endl;
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
        // Escribir los datos separados por comas
        archivo << actual->primerNombre << ","
                << actual->segundoNombre << ","
                << actual->apellido << ","
                << actual->segundoApellido << ","
                << actual->cedula << ","
                << actual->correo << endl;

        // Verificar si ocurrió un error al escribir
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




