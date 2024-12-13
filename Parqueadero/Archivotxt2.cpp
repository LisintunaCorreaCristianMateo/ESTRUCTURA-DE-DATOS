#include "Archivotxt2.h"
#include "ListaCircularHistorial.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include<iostream>
using namespace std;



void Archivotxt2::guardarHistorial(ListaCircularHistorial &hist) {
    // Abrir el archivo en modo sobrescritura
    ofstream archivo("Historial.txt", ios::out | ios::trunc);

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo para guardar el historial." << endl;
        return;
    }

    Historial* actual = hist.getCabeza();
    

    // Verifica que la lista no está vacía
    if (actual==NULL) {
        cout << "La lista historial esta vacia." << endl;
        archivo.close();
        return;
    }

    // Recorrer la lista circular y guardar los datos en el archivo
    do {
        archivo << actual->getNombre() << ","
                << actual->getSegundoNombre() << ","
                << actual->getApellido() << ","
                << actual->getSegundoApellido() << ","
                << actual->getCedula() << ","
                << actual->getPuesto() << ","
                << actual->getPlaca() << ","
                << actual->getFecha() << ","
                << actual->gethoraIngreso() << ","
                << actual->gethoraSalida() << endl;

        cout << "/nGuardado: " << actual->getNombre() << " " << actual->getPlaca() << endl;  // Depuración
                if (!archivo) {
                    cout << "Error al escribir en el archivo." << endl;
                    archivo.close();
                    return;
                }
        actual = actual->getSiguiente();
    } while (actual != NULL);

    archivo.flush();  // Asegurar que se escriban los datos
    archivo.close();
    cout << "Datos guardados correctamente en el archivo: " << "Historial.txt" << endl;
}




void Archivotxt2::leerHistorial(ListaCircularHistorial &hist) {
    // Limpiar la lista antes de agregar nuevos datos

    ifstream archivo("Historial.txt", ios::in);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo: " << "Historial.txt" << endl;
        return;
    }
    hist.limpiarLista();

    string linea;
    while (getline(archivo, linea)) {
        // Parsear cada línea del archivo
        istringstream flujo(linea);
        string nombre, segundoNombre, apellido, segundoApellido, cedula, placa, fecha, horaIngreso, horaSalida;
        int puesto;

        // Leer los valores separados por comas
        if (!getline(flujo, nombre, ',') || 
            !getline(flujo, segundoNombre, ',') || 
            !getline(flujo, apellido, ',') ||
            !getline(flujo, segundoApellido, ',') || 
            !getline(flujo, cedula, ',') || 
            !(flujo >> puesto) || !flujo.ignore() ||
            !getline(flujo, placa, ',') || 
            !getline(flujo, fecha, ',') || 
            !getline(flujo, horaIngreso, ',') ||
            !getline(flujo, horaSalida, ',')) {
            cerr << "Error al leer los datos de la línea: " << linea << endl;
            continue; // Saltar esta línea si hubo un error en la lectura
        }

        // Crear un nuevo nodo con los datos leídos
        Historial* nuevo = new Historial(puesto, placa, cedula, nombre, segundoNombre, apellido, segundoApellido, fecha, horaIngreso, horaSalida);

        // Agregar el nodo a la lista
        if ( hist.getCabeza() == NULL) {
             hist.setCabeza(nuevo);
             cout<<"La cabeza estuvo vacia, este elemento "<<nuevo->getNombre()<<" sera la cabeza ";
        } else {
            Historial* temp =  hist.getCabeza();
            while (temp->getSiguiente() != NULL) {
                temp = temp->getSiguiente();
            }
            
            temp->setSiguiente(nuevo);

            nuevo->setSiguiente(NULL);
            
            cout<<"Este propietario fue agregado al final de la lista: "<<nuevo->getNombre();
            cout<<endl;
        }
    }

    archivo.close(); // Cerrar el archivo
    
    cout << "Datos cargados correctamente desde el archivo: " << "Historial.txt" << endl;
}

