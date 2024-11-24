#include "ListaEstudiantes.h"
#include <iostream>
#include <sstream>
#include <cctype>
#include <iomanip> // Para setw
#include <fstream> // Para manejo de archivos
#include <iomanip>



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

void ListaEstudiantes::agregarEstudiante(const string& primerNombre, const string& segundoNombre, const string& apellido, const string& segundoApellido, const string& cedula) {
    string correoBase = generarCorreoBase(primerNombre, segundoNombre, apellido);
    string correoUnico = generarCorreoUnico(correoBase);

    Nodo* nuevo = new Nodo(primerNombre, segundoNombre, apellido, segundoApellido, cedula);
    nuevo->correo = correoUnico;
    nuevo->siguiente = NULL; // Como será el último nodo, apunta a nullptr.

    if (cabeza == NULL) {
        // Si la lista está vacía, el nuevo nodo será la cabeza.
        cabeza = nuevo;
    } else {
        // Si la lista no está vacía, recorrer hasta el último nodo.
        Nodo* actual = cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        // Enlazar el nuevo nodo al final.
        actual->siguiente = nuevo;
    }

    cout << "\nEstudiante agregado exitosamente." << endl;
    system("pause");
    system("cls");
}


void ListaEstudiantes::mostrarLista() const {
    // Imprimir cabecera
    cout << "\n=========================================================================================" << endl;
    cout << "                                Registro de Estudiantes  " << endl;
    cout << "=========================================================================================" << endl;
    
    // Imprimir encabezados de columnas
    cout << left << setw(42) << "Nombres y Apellidos" 
         << setw(20) << "Cedula"  // Ampliar espacio aquí
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

        // Imprimir los datos en formato de columnas
        cout << left << setw(42) << nombreCompleto 
             << setw(20) << actual->cedula  // Ampliar espacio aquí
             << setw(30) << actual->correo << endl;

        // Avanzar al siguiente estudiante
        actual = actual->siguiente;
    }

    cout << "-----------------------------------------------------------------------------------------" << endl;
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
void ListaEstudiantes::eliminarEstudiante(const string& cedula) {
    if (cabeza == NULL) {
        cout << "\nLa lista esta vacia. No se puede eliminar ningun estudiante." << endl;
        system("pause");
        system("cls");
        return;
    }

    Nodo* actual = cabeza;
    Nodo* anterior = NULL;

    // Buscar el nodo con la cédula especificada
    while (actual != NULL && actual->cedula != cedula) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        // No se encontró un estudiante con esa cédula
        cout << "\nNo se encontro ningun estudiante con la cedula: " << cedula << endl;
    } else {
        // Eliminar el nodo
        if (anterior == NULL) {
            // Si es el primer nodo de la lista
            cabeza = actual->siguiente;
        } else {
            // Si no es el primer nodo
            anterior->siguiente = actual->siguiente;
        }

        delete actual;
        cout << "\nEstudiante eliminado exitosamente." << endl;
    }

    system("pause");
    system("cls");
}
void ListaEstudiantes::leerDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo.c_str(), ios::in); // Abrir archivo para lectura

    if (!archivo) {
        cout << "No se pudo abrir el archivo para leer los datos." << endl;
        return;
    }

    liberarLista(); // Limpia la lista antes de cargar nuevos datos

    string linea;

    // Leer el archivo línea por línea
    while (getline(archivo, linea)) {
        // Verificar si la línea tiene la longitud suficiente antes de continuar
        if (linea.length() < 90) {  // La longitud total esperada es de 90 caracteres
            cout << "Línea con formato incorrecto: " << linea << endl;
            continue;  // Saltar esta línea si es muy corta
        }

        // Las posiciones y anchos son los mismos que usaste para guardar
        string primerNombre = linea.substr(0, 15);      // Ancho 15
        string segundoNombre = linea.substr(15, 15);    // Ancho 15
        string apellido = linea.substr(30, 15);         // Ancho 15
        string segundoApellido = linea.substr(45, 15);  // Ancho 15
        string cedula = linea.substr(60, 15);           // Ancho 15
        string correo = linea.substr(75, 30);           // Ancho 30

        // Eliminar espacios en blanco sobrantes
        primerNombre = eliminarEspacios(primerNombre);
        segundoNombre = eliminarEspacios(segundoNombre);
        apellido = eliminarEspacios(apellido);
        segundoApellido = eliminarEspacios(segundoApellido);
        cedula = eliminarEspacios(cedula);
        correo = eliminarEspacios(correo);

        // Crear un nuevo nodo con los datos leídos y agregarlo a la lista
        Nodo* nuevo = new Nodo(primerNombre, segundoNombre, apellido, segundoApellido, cedula);
        nuevo->correo = correo;
        
        if(cabeza==NULL){
        	cabeza=nuevo;
		}
		else {
			
			Nodo*temp;
        	temp=cabeza;
       		while(temp->siguiente!=NULL){
        	temp=temp->siguiente;
        	
		}
        temp->siguiente=nuevo;
        
        
		}


    }

    archivo.close();  // Cerrar el archivo
    //cout << "Datos cargados desde el archivo: " << nombreArchivo << endl;
}




void ListaEstudiantes::guardarEnArchivo(const string& nombreArchivo) {
    // Abrir archivo para escritura, con truncado para sobrescribir si ya existe
    ofstream archivo(nombreArchivo.c_str(), ios::out | ios::trunc);

    if (!archivo) {
        cout << "No se pudo abrir el archivo para guardar los datos." << endl;
        return;
    }

    // Recorrer la lista enlazada y escribir los datos de cada nodo en el archivo
    Nodo* actual = cabeza;

    if (actual == NULL) {
        cout << "La lista está vacía, no hay datos para guardar." << endl;
        archivo.close();
        return;
    }

    while (actual != NULL) {
        // Mostrar en consola el estudiante que se está guardando (para depuración)
        cout << "Guardando estudiante: " << actual->primerNombre << " " << actual->apellido << endl;

        // Escribir los datos en el archivo, con formato específico
		archivo << left << setw(15) << actual->primerNombre  // Ancho uniforme para todos
        << setw(15) << actual->segundoNombre
        << setw(15) << actual->apellido
        << setw(15) << actual->segundoApellido
        << setw(15) << actual->cedula
        << setw(30) << actual->correo << endl;
        
        // Verificar si hubo error al escribir en el archivo
        if (!archivo) {
            cout << "Error al escribir en el archivo." << endl;
            archivo.close();
            return;
        }

        // Pasar al siguiente nodo
        actual = actual->siguiente;
    }

    archivo.close();  // Cerrar el archivo al finalizar la escritura
    cout << "Datos guardados en el archivo: " << nombreArchivo << endl;
}



