#include<iostream>
#include "Validaciones.h"
#include <cstdlib> // Para system()

using namespace std;
int main(){
	int opcion;
	do{
	system("cls");
	cout<<"\n\n############Validacion de datos Primitivos###################";
	cout<<"\nMenu: \n";
	cout<<"1.- Ingresa enteros\n";
	cout<<"2.- Ingresa float\n";
	cout<<"3.-Ingresa string \n";
	cout<<"4.-Ingresa cedula\n";
	cout<<"5.-Salir";
	opcion=ingresar_entero("\nIngresa una opcion: ");
	
	int entero;
	float flotante;
	string cadena,cedula;
	
	switch(opcion){
		case 1:
			entero=ingresar_entero("\nIngesa valores enteros: ");
			cout<<"\nEl valor es : "<<entero;
			
			cout<<endl;
			system("pause");
			break;
		case 2:
			flotante=ingresar_float("\nIngresa valores decimales: ");
			printf("El valor es: %.2f",flotante);
			cout<<endl;
			system("pause");
			break;
		case 3:
			cadena=ingresar_string("\nIngresa solo texto: ");
			cout<<"La cadena de texto ingresada es: "<<cadena;
			cout<<endl;
			system("pause");
			break;
		case 4:
			cedula=ingresar_cedula("\nIngresa tu cedula: ");
			cout<<"\nLa cedula ingresada es: "<<cedula;
			cout<<endl;
			system("pause");
	}
	
	}while(opcion !=5);

return 0;
}
