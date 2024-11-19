#include "ListaEnlazada.h"
#include <iostream>
#include "Validar.h"
using namespace std;

int main() {
    ListaEnlazada lista;
    int opcion, valor;

    do {
        cout << "\n--- Menú ---\n";
        cout << "1. Insertar elemento al inicio de la lista\n";
        cout << "2 Inserter elemento al final de la lista";
        cout << "3. Imprimir lista\n";
        cout << "4. Eliminar elemento\n";
        cout << "5. Salir\n";
        opcion=ingresar("Elije una opcion: ");

        switch (opcion) {
        case 1:
        	cout<<endl;
        	valor=ingresar("Ingrese el valor a insertar: ");
            lista.insertar_inicio(valor);
            break;
        case 2:
        	cout<<endl;
        	valor=ingresar("Ingrese el valor a insertar: ");
            lista.insertar_final(valor);
            break;
        	
        case 3:
            lista.imprimir();
            break;
        case 4:
        	cout<<endl;
        	valor=ingresar("Ingresa el valor a eliminar: ");
            lista.eliminar(valor);
            break;
        case 5:
        	cout<<endl;
            cout << "Saliendo del programa.\n";
            break;
        default:
        	cout<<endl;
            cout << "Opción inválida, intenta de nuevo.\n";
        }
    } while (opcion != 4);

    return 0;
}

