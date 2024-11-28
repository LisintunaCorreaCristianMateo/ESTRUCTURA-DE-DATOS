#include "menu.h"
#include "CifradoCesar.h"
#include <iostream>
#include <conio.h>  // Para _getch()
#include <windows.h> // Para cambiar colores en la consola
#include <limits>
#include "ListaEstudiantes.h"
#include"Validaciones.h"
#include "Archivotxt.h"

using namespace std;
    ListaEstudiantes lista;
    Archivotxt manejadorArchivos;
void menu(){
	const int numOpciones = 4;
    string opciones[numOpciones] = {"Agregar estudiante", "Mostrar lista de estudiantes", "Eliminar estudiante", "Salir"};
    int opcionSeleccionada = 0; // Inicializamos la opción seleccionada en 0

    while (true) {
        mostrarMenu(opcionSeleccionada, opciones, numOpciones);
        char tecla = _getch(); // Captura una tecla

        if (tecla == 13) { // Detecta Enter (código ASCII 13)
            system("cls"); // Limpia la consola
            procesarSeleccion(opciones[opcionSeleccionada]); // Procesa la opción seleccionada
            if (opciones[opcionSeleccionada] == "Salir") {
                break; // Termina el programa si la opción es "Salir"
            }
        } else if (tecla == -32) { // Detecta teclas especiales (como flechas)
            tecla = _getch(); // Captura la segunda parte del código de la tecla
            if (tecla == 72) { // Flecha arriba
                opcionSeleccionada = (opcionSeleccionada - 1 + numOpciones) % numOpciones;
            } else if (tecla == 80) { // Flecha abajo
                opcionSeleccionada = (opcionSeleccionada + 1) % numOpciones;
            }
        }
    }
}




// Función para cambiar el color de la consola
void cambiarColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Función para mostrar el menú
void mostrarMenu(int opcionSeleccionada, const string opciones[], int numOpciones) {
    system("cls"); // Limpia la consola
    cout << "\n----- Generador de Correos Institucionales -----\n\n";
    for (int i = 0; i < numOpciones; ++i) {
        if (i == opcionSeleccionada) {
            cambiarColor(3); // Cambiar el color de la opción seleccionada (verde)
            cout << " " << opciones[i] << " \n"; // Opción seleccionada resaltada
            cambiarColor(7);  // Volver al color normal (blanco)
        } else {
            cambiarColor(7);  // Color normal para las otras opciones
            cout << "  " << opciones[i] << "\n";
        }
    }
}

// Función para procesar la selección de una opción
void procesarSeleccion(const string& opcion) {
    if (opcion == "Agregar estudiante") {
        manejadorArchivos.leerDesdeArchivo("estudiantes.txt",lista);
        
        string primerNombre, segundoNombre, apellido, segundoApellido,cedula;
        primerNombre=ingresar_string("\n\nIngrese el primer nombre: ");
        segundoNombre=ingresar_string("Ingrese el segundo nombre: ");
		apellido=ingresar_string("Ingrese el primer apellido: ");
		segundoApellido=ingresar_string("Ingrese el segundo apellido: ");
		cedula=ingresar_cedula("Ingrese su numero de cedula: ");
				
		bool cedula_existente = true;
		
		while (cedula_existente) {
			
		    cedula_existente = false;  // Asumimos que la cédula no existe inicialmente
		    
		    Nodo* temp = lista.getCabeza();  // Reiniciamos la búsqueda desde el primer nodo
		    while (temp != NULL) {
		    	//tenemos que descifrar la cedula para poder comparar con la ingresada
		    		string cedulaDecifrada=descifrarCesar(temp->cedula);
		    	
		        if (cedulaDecifrada == cedula) {
		            cout<<endl;
		            cedula = ingresar_cedula("La cedula ya existe, vulve a ingresar: ");  // Solicita una nueva cédula
		            cedula_existente = true;  // Marcamos que la cédula ya existe
		            break;  // Salimos del ciclo interno y volvemos a verificar con la nueva cédula
		        }
		        temp = temp->siguiente;  // Avanzamos al siguiente nodo
		    }
		}

		
					
        lista.agregarEstudiante(primerNombre, segundoNombre, apellido, segundoApellido,cedula);
                
               
        //Guarda en el txt
        manejadorArchivos.guardarEnArchivo("estudiantes.txt",lista);
    } 
	else if (opcion == "Mostrar lista de estudiantes") {
		
		manejadorArchivos.leerDesdeArchivo("estudiantes.txt",lista);
            	
        system("cls");
        lista.mostrarLista();
    
  		system("pause");
    }
	else if (opcion == "Eliminar estudiante") {
        manejadorArchivos.leerDesdeArchivo("estudiantes.txt",lista);
		lista.mostrarLista();
			
		string cedulaEliminar;
		cedulaEliminar=ingresar_cedula("\nIngrese la cedula del estudiante que desea eliminar: ");
		lista.eliminarEstudiante(cedulaEliminar);
		    
		manejadorArchivos.guardarEnArchivo("estudiantes.txt",lista);
        
    }
	else if (opcion == "Salir") {
        cout << "Saliendo del programa...\n";
    } else {
        cout << "Opcion no valida.\n";
    }
    //system("pause"); // Pausa para permitir que el usuario lea el mensaje
}

