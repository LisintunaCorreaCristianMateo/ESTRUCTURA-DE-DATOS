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
        return; // La lista ya est� vac�a
    }

    Historial* actual = cabeza;
    do {
        Historial* siguiente = actual->getSiguiente(); // Almacenar el siguiente nodo
        delete actual; // Liberar memoria del nodo actual
        actual = siguiente; // Avanzar al siguiente nodo
    } while (actual != cabeza); // Repetir hasta volver a la cabeza

    cabeza = nullptr; // Despu�s de eliminar todos los nodos, la lista queda vac�a
}

void ListaCircularHistorial::ingresarVehiculo(int puesto, string placa, string cedula, string nombre, 
                                              string nombre2, string apellido, string apellido2, 
                                              string fecha, string horaIngreso) {
    // Crear un nuevo nodo con los datos del historial
    Historial* nuevo = new Historial(puesto, placa, cedula, nombre, nombre2, apellido, apellido2, fecha, horaIngreso,"parqueado");

    // Caso: la lista está vacía
    if (!cabeza) {
        cabeza = nuevo;
        nuevo->setSiguiente(nuevo); // Apunta a sí mismo
        nuevo->setAnterior(nuevo); // Apunta a sí mismo
        //cout << "Clase historial >> Vehículo ingresado en el puesto " << nuevo->getPuesto() << ". La lista estaba vacía.\n";
        return;
    }

    // Caso: la lista no está vacía
    Historial* ultimo = cabeza->getAnterior(); // Historial al final de la lista

    // Actualizar punteros para insertar al final
    nuevo->setSiguiente(cabeza);  // El nuevo nodo apunta a la cabeza
    nuevo->setAnterior(ultimo);  // El nuevo nodo apunta al último nodo
    ultimo->setSiguiente(nuevo); // El último nodo apunta al nuevo nodo
    cabeza->setAnterior(nuevo);  // La cabeza apunta al nuevo nodo como anterior

    //cout << "Clase historial >> Vehículo ingresado en el puesto " << nuevo->getPuesto() << ".\n";
}
void ListaCircularHistorial::mostrarHistorial() {
    //leerHistorial(); // Cargar datos desde el archivo

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
         
    cout << string(152, '-') << endl; // Separador para mayor claridad

    Historial* actual = cabeza;
    bool historialEncontrado = false;

    // Recorrer la lista circular
    do {
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

        historialEncontrado = true;
        actual = actual->getSiguiente(); // Avanzar al siguiente nodo
    } while (actual != cabeza); // Condición para detener el recorrido circular

    if (!historialEncontrado) {
        cout << "No se ha registrado historial en el parqueadero." << endl;
    }

    cout << endl;
}
void ListaCircularHistorial::buscarPorHoras(const std::string& horaInicio, const std::string& horaFin) {
    if (!cabeza) {
        cout << "El historial está vacío.\n";
        return;
    }

    Historial* actual = cabeza;
    bool encontrado = false;

    std::cout << "Vehículos ingresados entre las " << horaInicio << " y las " << horaFin << ":\n";

    do {
        // Compara las horas (asegurarse de que estén en formato "HH:MM")
        if (actual->gethoraIngreso() >= horaInicio && actual->gethoraIngreso() <= horaFin) {
            encontrado = true;
            // Mostrar los datos del nodo actual
            cout << "Puesto: " << actual->getPuesto()
                      << ", Placa: " << actual->getPlaca()
                      << ", Hora de Ingreso: " << actual->gethoraIngreso()
                      << ", Fecha: " << actual->getFecha() << std::endl;
        }
        actual = actual->getSiguiente();
    } while (actual != cabeza); // La lista es circular, termina cuando regresa a la cabeza

    if (!encontrado) {
        cout << "No se encontraron vehículos en el rango de horas especificado.\n";
    }
}               


void ListaCircularHistorial::cambiarFechaSalida(string placa, string hora) {
    
    if (!cabeza) { // Verifica si la lista está vacía
        cout << "Lista historial vacia." << endl;
        return;
    }

    Historial* actual = cabeza;
    bool encontrado = false;

    do {
        cout << "Revisando placa: " << actual->getPlaca() << endl;
        if (actual->getPlaca() == placa) {
            cout << "Placa encontrada: " << actual->getPlaca() << endl;
            actual->setHoraSalida(hora); // Actualiza la hora de salida
            cout<<"La hora de salida acutalizada es :"<<actual->gethoraSalida();
            encontrado = true;
            break;
        }
        actual = actual->getSiguiente();
    } while (actual != cabeza);

    if (!encontrado) {
        cout << "La placa " << placa << " no fue encontrada en el historial." << endl;
    }
}
bool ListaCircularHistorial::existeVehiculoHistorial(string placa,ListaCircularDoble &parqueadero) {
    if (!cabeza) { // Verifica si la lista está vacía
        cout << "Lista historial vacía." << endl;
        return false;
    }

    Historial* actual = cabeza;

    do {
        cout << "Revisando placa: " << actual->getPlaca() << endl;
        if (actual->getPlaca() == placa) {
            cout << "Placa encontrada: " << actual->getPlaca() << endl;
            
            // Espacio para tu código
            parqueadero.ingresarVehiculo(actual->getPlaca(),actual->getCedula(),actual->getNombre(),actual->getSegundoNombre(),actual->getApellido(),actual->getSegundoApellido());
            
            return true;
        }
        actual = actual->getSiguiente();
    } while (actual != cabeza);

    cout << "La placa " << placa << " no fue encontrada en el historial." << endl;
    return false;
}

void ListaCircularHistorial::agregarAlFinal(Historial* nuevo) {
    Historial* cabeza = getCabeza();

    if (!cabeza) {
        // Si la lista está vacía, el nuevo nodo será la cabeza
        setCabeza(nuevo);
        nuevo->setSiguiente(nuevo); // Apuntando al mismo nodo (circularidad)
        nuevo->setAnterior(nuevo);
        //cout<<"El nuevo elemento sera la cabeza \n";
    } 
    else {
        // Si no está vacía, insertar el nodo al final
        Historial* ultimo = cabeza->getAnterior(); // Nodo anterior a la cabeza

        // Actualizar los punteros
        ultimo->setSiguiente(nuevo);
        nuevo->setAnterior(ultimo);
        nuevo->setSiguiente(cabeza);
        cabeza->setAnterior(nuevo);
        //cout<<"Anadido a la lista el propietario : " << ultimo->getNombre;

    }

}
void ListaCircularHistorial::buscarPorFecha(const string& fechaBuscada) {
    if (!cabeza) {
        cout << "No hay historial registrado." << endl;
        return;
    }

    Historial* actual = cabeza;
    bool encontrado = false;

    // Recorrer la lista circular para buscar coincidencias de fecha
    do {
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
    } while (actual != cabeza);

    if (!encontrado) {
        cout << "No se encontró historial para la fecha: " << fechaBuscada << endl;
    }
}
                    

