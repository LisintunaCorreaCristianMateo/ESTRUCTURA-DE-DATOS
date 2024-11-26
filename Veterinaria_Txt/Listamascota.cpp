#include"Listamascota.h"
#include<iostream>
#include <sstream>  // Para trabajar con flujos de texto en memoria
#include <iomanip>  // Para formatear la salida de números y texto
#include <cctype>   // Para analizar y manipular caracteres individuales

using namespace std;
int generarId();

//constructor
Listamascota::Listamascota(){
	cabeza=NULL;
}

//destructor
Listamascota::~Listamascota(){
	liberarlista();
}

void Listamascota::liberarlista(){
	Mascota* actual = cabeza;
	
    while (actual != NULL) {
        Mascota* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
    cabeza = NULL;
}

void Listamascota::agregar(const string &tipo,const string &nombre,const string &raza,const int &edad,const string &detalles){

	int id=generarId();
	Mascota * nuevo=new Mascota(id,tipo,nombre,raza,edad,detalles);
	
	if(nuevo==NULL){
		cout<<"Error al crear el objeto"<<endl;
	}
	
	 nuevo->siguiente = NULL;

    if (cabeza == NULL) {
        cabeza = nuevo;
    } else {
        Mascota* actual = cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
    cout<<" Objeto creado ";
}
void Listamascota::imprimirLista(){
	cout << "\n===================================================================================================" << endl;
    cout << "                                Registro de Mascotas  " << endl;
    cout << "===================================================================================================" << endl;
    cout << left << setw(10) << "ID" 
         << setw(15) << "Tipo" 
         << setw(20) << "Nombre"
         << setw(20)<< "Raza"
         << setw(15) << "Edad"
         << setw(30) << "Detalles"<<endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;

    Mascota* actual = cabeza;
    if (actual==NULL) {
        cout << "La lista esta vacia." << endl;
        system("pause");
        system("cls");
        return;
    }

    while (actual != NULL) {
        
        cout << left << setw(10) << actual->id
             << setw(15) << actual->tipo
			 << setw(20) << actual->nombre
			 << setw(20) << actual->raza
			 << setw(15) << actual->edad
			 << setw(30) << actual->detalles<<endl;
        actual = actual->siguiente;
    }

    cout << "---------------------------------------------------------------------------------------------------" << endl;
}
string Listamascota::eliminarEspacios(const string& cadena) {
 size_t inicio = cadena.find_first_not_of(' '); // Encuentra el primer carácter no espacio
    if (inicio == string::npos) {
        return ""; // Si solo hay espacios, devuelve una cadena vacía
    }
    size_t fin = cadena.find_last_not_of(' '); // Encuentra el último carácter no espacio
return cadena.substr(inicio, fin - inicio + 1); // Devuelve la subcadena sin espacios iniciales y finales
}

	int generarId() {
    // Inicializar la semilla para números aleatorios
    srand(static_cast<unsigned int>(time(0)));
    
    // Generar un número aleatorio entre 0 y 9999
    return rand() % 10000;
}
