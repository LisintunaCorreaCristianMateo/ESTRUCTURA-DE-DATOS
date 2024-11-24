#include <iostream>
#include <limits>
#include "ListaEstudiantes.h"
#include"Validaciones.h"


using namespace std;


int main() {
	
    ListaEstudiantes lista;
    int opcion;

    do {
        cout << "\n----- Generador de Correos Institucionales -----" << endl;
        cout << "1. Agregar estudiante" << endl;
        cout << "2. Mostrar lista de estudiantes" << endl;
        cout << "3. Eliminar estudiante"<<endl;
        cout << "4. Salir" << endl;
		
		opcion=ingresar_entero("Ingrese una opcion ");
       

        switch (opcion) {
            case 1: {
            	lista.leerDesdeArchivo("estudiantes.txt");
                string primerNombre, segundoNombre, apellido, segundoApellido,cedula;
            	primerNombre=ingresar_string("\n\nIngrese el primer nombe: ");
                segundoNombre=ingresar_string("Ingrese el segundo nombre: ");
				apellido=ingresar_string("Ingrese el primer apellido: ");
				segundoApellido=ingresar_string("Ingrese el segundo apellido: ");
  				cedula=ingresar_cedula("Ingrese su numero de cedula: ");
					
                lista.agregarEstudiante(primerNombre, segundoNombre, apellido, segundoApellido,cedula);
                
               
                //Guarda en el txt
                lista.guardarEnArchivo("estudiantes.txt");
                
                break;
            }
            case 2:
            	
            	lista.leerDesdeArchivo("estudiantes.txt");
            	
            	system("cls");
                lista.mostrarLista();
                break;
                
			case 3: { // Nueva opción en el menú
			lista.leerDesdeArchivo("estudiantes.txt");
			
		    string cedulaEliminar;
		    cedulaEliminar=ingresar_cedula("\nIngrese la cedula del estudiante que desea eliminar: ");
		    lista.eliminarEstudiante(cedulaEliminar);
		    
		    lista.guardarEnArchivo("estudiantes.txt");
		    break;
		}
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);

    return 0;
    
}

