#include "ListaEstudiantes.h"
#include "Archivotxt.h" // Incluimos la nueva clase Archivos
#include "CifradoCesar.h"
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
string ListaEstudiantes::convertirMinusculas( string& cadena) {
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

string ListaEstudiantes::eliminarEspacios( string& cadena) {
    string resultado;
    for (size_t i = 0; i < cadena.length(); ++i) {
        if (cadena[i] != ' ') {
            resultado += cadena[i];
        }
    }
    return resultado;
}



// Métodos relacionados con generación de correos
string ListaEstudiantes::generarCorreoBase( string& primerNombre, string& segundoNombre, string& apellido) {
    char inicial1 = tolower(primerNombre[0]);
    char inicial2 = tolower(segundoNombre[0]);
    string apellidoSinEspacios = eliminarEspacios(apellido);
    string apellidoMinuscula = convertirMinusculas(apellidoSinEspacios);

    return string(1, inicial1) + string(1, inicial2) + apellidoMinuscula;
}


string ListaEstudiantes::generarCorreoUnico( string& baseCorreo) {
    string correoUnico = baseCorreo + "@espe.edu.ec";
    int contador = 1;

    bool existe = true;
    while (existe) {
        existe = false;
        Nodo* actual = cabeza;

        while (actual != NULL) {
        	//actual->correo esta cifrado, debemos decifrar para poder comparar
        	string correoDecifrado;
        	correoDecifrado=descifrarCesar(actual->correo);
        	
            if (correoDecifrado == correoUnico) {
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
void ListaEstudiantes::agregarEstudiante( string& primerNombre, string& segundoNombre,  string& apellido,  string& segundoApellido,  string& cedula) {
	    // Limpiar espacios en los nombres

	
    string correoBase = generarCorreoBase(primerNombre, segundoNombre, apellido);
    string correoUnico = generarCorreoUnico(correoBase);
    
    string correo;
	correo=correoUnico;

	            // Cifrar datos antes de ingresar a la lista
            string nombreCifrado = cifrarCesar(primerNombre);
            string segundoNombreCifrado = cifrarCesar(segundoNombre);
            string apellidoCifrado = cifrarCesar(apellido);
            string segundoApellidoCifrado = cifrarCesar(segundoApellido);
            string cedulaCifrado = cifrarCesar(cedula);
            string correoCifrado = cifrarCesar(correo);
	


    Nodo* nuevo = new Nodo(nombreCifrado, segundoNombreCifrado,apellidoCifrado, segundoApellidoCifrado, cedulaCifrado,correoCifrado);
    
    
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

void ListaEstudiantes::mostrarListaDescifrada() {
    cout << "\n=========================================================================================================" << endl;
    cout << "                                Registro de Estudiantes Descifrado " << endl;
    cout << "=========================================================================================================" << endl;
    cout << left << setw(62) << "Nombres y Apellidos" 
         << setw(25) << "Cedula" 
         << setw(30) << "Correo" << endl;
    cout << "---------------------------------------------------------------------------------------------------------" << endl; 

    Nodo* temp = cabeza;
    
    if (!temp) {
        cout << "La lista esta vacia." << endl;
        return;
    }

    while (temp != NULL) {
        // Descifrar los datos del nodo actual
        string primerNombreDescifrado = descifrarCesar(temp->primerNombre);
        string segundoNombreDescifrado = descifrarCesar(temp->segundoNombre);
        string apellidoDescifrado = descifrarCesar(temp->apellido);
        string segundoApellidoDescifrado = descifrarCesar(temp->segundoApellido);
        string cedulaDescifrado = descifrarCesar(temp->cedula);
        string correoDescifrado = descifrarCesar(temp->correo);

		string nombreCompletoDescifrado = primerNombreDescifrado + " " + segundoNombreDescifrado + " " + apellidoDescifrado + " " + segundoApellidoDescifrado;

        // Imprimir datos descifrados
        cout << left 
             << setw(60) << nombreCompletoDescifrado
             << setw(20) << cedulaDescifrado
             << setw(30) << correoDescifrado << endl;

        // Avanzar al siguiente nodo
        temp = temp->siguiente;
    }

    cout << "---------------------------------------------------------------------------------------------------------" << endl;
}



void ListaEstudiantes::mostrarLista() {
    cout << "\n=========================================================================================================" << endl;
    cout << "                                Registro de Estudiantes  " << endl;
    cout << "=========================================================================================================" << endl;
    cout << left << setw(62) << "Nombres y Apellidos" 
         << setw(25) << "Cedula" 
         << setw(30) << "Correo" << endl;
    cout << "--------------------------------------------------------------------------------------------------------" << endl;

    Nodo* actual = cabeza;
    if (!actual) {
        cout << "La lista esta vacia." << endl;
        
        return;
    }

    while (actual != NULL) {
    	

    	
    	string nombrecompleto;
    		
    		string nombreCompleto = actual->primerNombre + " " + actual->segundoNombre + " " + actual->apellido + " " + actual->segundoApellido;
        
        cout << left 
			 << setw(60) <<nombreCompleto
			 << setw(20)
			 << setw(20)
             << setw(20) << actual->cedula 
             << setw(30) << actual->correo << endl;
        actual = actual->siguiente;
    }

    cout << "---------------------------------------------------------------------------------------------------------" << endl;
 	
 	
 	///////////////Impresion de datos decifrados
 	string clavecorrecta= "miclave";
 	string clave;
 	
 	cout<<endl;
 	
    cout << "Ingrese la clave para descifrar: ";
    getline(cin, clave);
 	cout<<endl; 
 	
 	while(clave!=clavecorrecta){
 		 	cout<<"Clave incorrecta, vuelve a ingresar: ";
 			getline(cin, clave);
	 }
	 mostrarListaDescifrada();  
    
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

void ListaEstudiantes::eliminarEstudiante( string& cedula) {
    if (cabeza == NULL) {
        cout << "\nLa lista esta vacia. No se puede eliminar ningun estudiante." << endl;
        system("pause");
        system("cls");
        return;
    }
    //la cedula esta guardada como cifrada
    //entonces a la cedula que nos proporcionan hay que cifrarle para poder eliminar
    
    string cedulaCifrada=cifrarCesar(cedula);
    

    Nodo* actual = cabeza;
    Nodo* anterior = NULL;

    while (actual != NULL && actual->cedula != cedulaCifrada) {
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


