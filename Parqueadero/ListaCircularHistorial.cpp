    #include "ListaCircularHistorial.h"
    #include "ListaCircularDoble.h"
	#include<iostream>
	#include <vector>
	#include <ctime>
	#include <iomanip>
	#include <string>
    #include <fstream>
    #include <sstream>


    using namespace std;

ListaCircularHistorial::~ListaCircularHistorial(){
}

void ListaCircularHistorial::limpiarLista() {
    if (!cabeza) {
        return; // La lista ya está vacía
    }

    Historial* actual = cabeza;
    while (actual) {
        Historial* siguiente = actual->getSiguiente(); // Almacenar el siguiente nodo
        delete actual; // Liberar memoria del nodo actual
        actual = siguiente; // Avanzar al siguiente nodo
    }

    cabeza = nullptr; // Después de eliminar todos los nodos, la lista queda vacía
}

void ListaCircularHistorial::ingresarVehiculo(int puesto, string placa, string cedula, string nombre, 
                                      string nombre2, string apellido, string apellido2, 
                                      string fecha, string horaIngreso) {
    // Crear un nuevo nodo con los datos del historial
    Historial* nuevo = new Historial(puesto, placa, cedula, nombre, nombre2, apellido, apellido2, fecha, horaIngreso, "parqueado");

    // Caso: la lista está vacía
    if (!cabeza) {
        cabeza = nuevo;
        nuevo->setSiguiente(nullptr); // Apunta a null ya que es el único elemento
        return;
    }

    // Caso: la lista no está vacía
    Historial* actual = cabeza;

    // Avanzar hasta el final de la lista
    while (actual->getSiguiente() != nullptr) {
        actual = actual->getSiguiente();
    }

    // Actualizar punteros para insertar al final
    actual->setSiguiente(nuevo);
    nuevo->setSiguiente(nullptr); // El nuevo nodo será el último, apunta a null
}

void ListaCircularHistorial::mostrarHistorial() {
    cout << "--- Historial de Vehiculos---" << endl;

    if (!cabeza) { // Verifica si la lista está vacía
        cout << "No hay historial en el parqueadero." << endl;
        return;
    }

    // Encabezados de columnas
    cout << left 
         << setw(10) << "Puesto" 
         << setw(15) << "Placa" 
         << setw(15) << "Cedula" 
         << setw(15) << "Nombre" 
         << setw(15) << "Nombre 2" 
         << setw(15) << "Apellido" 
         << setw(15) << "Apellido 2" 
         << setw(20) << "Fecha"
         << setw(20) << "Hora Ingreso" 
         << setw(20) << "Hora Salida" << endl;

    cout << string(152, '-') << endl;

    Historial* actual = cabeza;

    // Recorrer la lista simple
    while (actual != nullptr) {
        cout << setw(10) << actual->getPuesto()
             << setw(15) << actual->getPlaca()
             << setw(15) << actual->getCedula()
             << setw(15) << actual->getNombre()
             << setw(15) << actual->getSegundoNombre()
             << setw(15) << actual->getApellido()
             << setw(15) << actual->getSegundoApellido()
             << setw(20) << actual->getFecha()
             << setw(20) << actual->gethoraIngreso()
             << setw(20) << actual->gethoraSalida() << endl;

        actual = actual->getSiguiente(); // Avanzar al siguiente nodo
    }
}

void ListaCircularHistorial::buscarPorHoras(const std::string& horaInicio, const std::string& horaFin) {
    if (!cabeza) {
        cout << "El historial está vacío.\n";
        return;
    }

    Historial* actual = cabeza;
    bool encontrado = false;

    std::cout << "Vehículos ingresados entre las " << horaInicio << " y las " << horaFin << ":\n";

    while (actual != nullptr) {
        if (actual->gethoraIngreso() >= horaInicio && actual->gethoraIngreso() <= horaFin) {
            encontrado = true;
            cout << "Puesto: " << actual->getPuesto()
                 << ", Placa: " << actual->getPlaca()
                 << ", Hora de Ingreso: " << actual->gethoraIngreso()
                 << ", Fecha: " << actual->getFecha() << std::endl;
        }
        actual = actual->getSiguiente();
    }

    if (!encontrado) {
        cout << "No se encontraron vehículos en el rango de horas especificado.\n";
    }
}

void ListaCircularHistorial::cambiarFechaSalida(string placa, string hora) {
    if (!cabeza) {
        cout << "Lista historial vacía." << endl;
        return;
    }

    Historial* actual = cabeza;
    bool encontrado = false;

    while (actual != nullptr) {
        if (actual->getPlaca() == placa) {
            actual->setHoraSalida(hora); // Actualiza la hora de salida
            encontrado = true;
            break;
        }
        actual = actual->getSiguiente();
    }

    if (!encontrado) {
        cout << "La placa " << placa << " no fue encontrada en el historial." << endl;
    }
}

bool ListaCircularHistorial::existeVehiculoHistorial(string placa, ListaCircularDoble &parqueadero) {
    if (!cabeza) {
        cout << "Lista historial vacia." << endl;
        return false;
    }

    Historial* actual = cabeza;

    while (actual != nullptr) {
        if (actual->getPlaca() == placa) {
            parqueadero.ingresarVehiculo(actual->getPlaca(), actual->getCedula(), actual->getNombre(),
                                         actual->getSegundoNombre(), actual->getApellido(), actual->getSegundoApellido());
            return true;
        }
        actual = actual->getSiguiente();
    }

    cout << "La placa " << placa << " no fue encontrada en el historial." << endl;
    return false;
}

void ListaCircularHistorial::buscarPorFecha(const string& fechaBuscada) {
    if (!cabeza) {
        cout << "No hay historial registrado." << endl;
        return;
    }

    Historial* actual = cabeza;
    bool encontrado = false;

    while (actual != nullptr) {
        if (actual->getFecha() == fechaBuscada) {
            cout << "Historial encontrado: " << endl;
            cout << "Nombre: " << actual->getNombre() << " " << actual->getApellido() << endl;
            cout << "Cedula: " << actual->getCedula() << endl;
            cout << "Placa: " << actual->getPlaca() << endl;
            cout << "Fecha: " << actual->getFecha() << endl;
            cout << "Hora de ingreso: " << actual->gethoraIngreso() << endl;
            cout << "Hora de salida: " << actual->gethoraSalida() << endl;
            cout << "----------------------------------" << endl;
            encontrado = true;
        }
        actual = actual->getSiguiente();
    }

    if (!encontrado) {
        cout << "No se encontró historial para la fecha: " << fechaBuscada << endl;
    }
}
