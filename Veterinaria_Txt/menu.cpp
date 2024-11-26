#include "Listamascota.h"
#include "menu.h"
#include"Validaciones.h"
#include "Archivostxt.h"
#include <iostream>
#include <conio.h>  // Para _getch()
#include <windows.h> // Para cambiar colores en la consola
#include <limits>


using namespace std;

Listamascota lista;
Archivostxt manejadorArchivos;

void menu(){

	
	
	const int numOpciones = 4;
    string opciones[numOpciones] = {"Agregar Mascota", "Mostrar Macotas", "Eliminar Mascotas", "Salir"};
    int opcionSeleccionada = 0; // Inicializamos la opci�n seleccionada en 0

    while (true) {
        mostrarMenu(opcionSeleccionada, opciones, numOpciones);
        char tecla = _getch(); // Captura una tecla

        if (tecla == 13) { // Detecta Enter (c�digo ASCII 13)
            system("cls"); // Limpia la consola
            procesarSeleccion(opciones[opcionSeleccionada]); // Procesa la opci�n seleccionada
            if (opciones[opcionSeleccionada] == "Salir") {
                break; // Termina el programa si la opci�n es "Salir"
            }
        } else if (tecla == -32) { // Detecta teclas especiales (como flechas)
            tecla = _getch(); // Captura la segunda parte del c�digo de la tecla
            if (tecla == 72) { // Flecha arriba
                opcionSeleccionada = (opcionSeleccionada - 1 + numOpciones) % numOpciones;
            } else if (tecla == 80) { // Flecha abajo
                opcionSeleccionada = (opcionSeleccionada + 1) % numOpciones;
            }
        }
    }
}




// Funci�n para cambiar el color de la consola
void cambiarColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Funci�n para mostrar el men�
void mostrarMenu(int opcionSeleccionada, const string opciones[], int numOpciones) {
    system("cls"); // Limpia la consola
    cout << "=== Registro de mascotas ===\n";
    for (int i = 0; i < numOpciones; ++i) {
        if (i == opcionSeleccionada) {
            cambiarColor(3); // Cambiar el color de la opci�n seleccionada (verde)
            cout << " " << opciones[i] << " \n"; // Opci�n seleccionada resaltada
            cambiarColor(7);  // Volver al color normal (blanco)
        } else {
            cambiarColor(7);  // Color normal para las otras opciones
            cout << "  " << opciones[i] << "\n";
        }
    }
}

// Funci�n para procesar la selecci�n de una opci�n
void procesarSeleccion(const string& opcion) {
	

	
    if (opcion == "Agregar Mascota") {
    	
        //manejadorArchivos.leerDesdeArchivo("Mascotas.txt",lista);
        int edad;
        string tipo,nombre,raza,detalles;
        
        
        tipo=ingresar_string("\n\nIngrese el tipo de mascota: ");
        nombre=ingresar_string("Ingrese el nombre: ");
        raza=ingresar_string("Ingrese la raza: ");
		edad=ingresar_entero("Ingrese la edad: ");
		detalles=ingresar_string("\nEspecifique el motivo de la consulta: ");
  		
		lista.agregar(tipo,nombre,raza,edad,detalles);
        
                
               
       // Guarda en el txt
    	manejadorArchivos.guardarEnArchivo("Mascotas.txt",lista);
    	
    } 
    
	else if (opcion == "Mostrar Macotas") {
		
		
        manejadorArchivos.leerDesdeArchivo("Mascotas.txt",lista);
            	
        //system("cls");
        lista.imprimirLista();
        //system("pause");
    	//system("cls");
    
	}
	 else if (opcion == "Eliminar estudiante") {
        /*
		manejadorArchivos.leerDesdeArchivo("estudiantes.txt",lista);
		lista.mostrarLista();
			
		string cedulaEliminar;
		cedulaEliminar=ingresar_cedula("\nIngrese la cedula del estudiante que desea eliminar: ");
		lista.eliminarEstudiante(cedulaEliminar);
		    
		manejadorArchivos.guardarEnArchivo("estudiantes.txt",lista);
		 */   
    } 
	else if (opcion == "Salir") {
        cout << "Saliendo del programa...\n";
    } else {
        cout << "Opcion no valida.\n";
    }
    system("pause"); // Pausa para permitir que el usuario lea el mensaje
}

