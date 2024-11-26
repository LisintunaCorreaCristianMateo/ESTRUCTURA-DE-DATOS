#include "Archivostxt.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip> // Para std::setw
#include <sstream>
#include <stdexcept>
#include <algorithm>

using namespace std;

void Archivostxt::leerDesdeArchivo(const string& nombreArchivo, Listamascota& lista) {
    ifstream archivo(nombreArchivo.c_str(), ios::in); // Abrir archivo para lectura

    if (!archivo) {
        cout << "No se pudo abrir el archivo para leer los datos." << endl;
        return;
    }

    lista.liberarlista(); // Limpia la lista antes de cargar nuevos datos

    string linea;
    while (getline(archivo, linea)) {
    if (linea.empty()) {
        continue; // Ignorar l�neas vac�as
    }

    // Extraer cada campo seg�n su posici�n fija y longitud
    string idStr = linea.substr(0, 10);
    string tipo = linea.substr(10, 15);
    string nombre = linea.substr(25, 20);
    string raza = linea.substr(45, 20);
    string edadStr = linea.substr(65, 15);
    string detalles = linea.substr(80, 30);

    // Eliminar espacios adicionales de cada campo
    idStr = lista.eliminarEspacios(idStr);
    tipo = lista.eliminarEspacios(tipo);
    nombre = lista.eliminarEspacios(nombre);
    raza = lista.eliminarEspacios(raza);
    edadStr = lista.eliminarEspacios(edadStr);
    detalles = lista.eliminarEspacios(detalles);

    // Validar y convertir edad
    int edad;
    try {
        edad = stoi(edadStr); // Convertir edad a entero
        if (edad < 0) throw invalid_argument("Edad negativa");
    } catch (exception &e) {
        cout << "Error: Edad no v�lida en l�nea: '" << edadStr << "' (" << e.what() << ")" << endl;
        continue; // Ignorar esta l�nea si hay error
    }
    
    //Validar y convertir id
        int id;
    try {
        id = stoi(idStr); // Convertir edad a entero
        if (edad < 0) throw invalid_argument("Edad negativa");
    } catch (exception &e) {
        cout << "Error: Edad no v�lida en l�nea: '" << idStr << "' (" << e.what() << ")" << endl;
        continue; // Ignorar esta l�nea si hay error
    }
    

    // Crear y agregar la mascota a la lista
    Mascota* nuevaMascota = new Mascota(id,tipo, nombre, raza, edad, detalles);
    if (lista.getCabeza() == NULL) {
        lista.setCabeza(nuevaMascota);
    } else {
        Mascota* temp = lista.getCabeza();
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevaMascota;
    }
}

}
void Archivostxt::guardarEnArchivo(const string& nombreArchivo, const Listamascota& lista) {
    ofstream archivo(nombreArchivo.c_str(), ios::out | ios::trunc); // Abrir archivo para escritura

    if (!archivo) {
        cout << "No se pudo abrir el archivo para guardar los datos." << endl;
        return;
    }

    Mascota* actual = lista.getCabeza();
    if (actual == NULL) {
        cout << "La lista est� vac�a, no hay datos para guardar." << endl;
        archivo.close();
        return;
    }

    while (actual != NULL) {
		archivo << left << setw(10) << actual->id          // ID (m�ximo 5 caracteres)
        << setw(15) << actual->tipo               // Tipo (m�ximo 15 caracteres)
        << setw(20) << actual->nombre             // Nombre (m�ximo 15 caracteres)
        << setw(20) << actual->raza               // Raza (m�ximo 15 caracteres)
        << setw(15) << actual->edad                // Edad (m�ximo 5 caracteres)
        << setw(30) << actual->detalles           // Detalles (m�ximo 30 caracteres)
        << endl;


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

