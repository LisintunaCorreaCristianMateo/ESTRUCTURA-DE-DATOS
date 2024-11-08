/*

--------------------------------------------------------------------
 Universidad de las Fuerzas Armadas ESPE
         Estructura de Datos
--------------------------------------------------------------------
 Autor: Cristian lisintuña
Modulo:Ordenar Fracciones
Creacion: 05/11/2024
Modificacion:05/11/2024
Tarea:1
--------------------------------------------------------------------

*/

#include <iostream>
#include "Fraccion.h"
#include "utilidades.h"
using namespace std;

int main(){
	float a,b;
	
	
	cout<<"Primer numero: "<<endl<<endl;
	cout<<"Ingresa el numerador: ";
	cin>>a;
	cout<<"Ingresa el denominador ";
	cin>>b;
	
	Fraccion numero1(a,b);
	
	cout<<"\nSegundo numero: "<<endl<<endl;
	cout<<"Ingresa el numerador: ";
	cin>>a;
	cout<<"Ingresa el denominador ";
	cin>>b;
	
	Fraccion numero2(a,b);
	
	cout<<"\nTercer numero: "<<endl<<endl;
	cout<<"Ingresa el numerador: ";
	cin>>a;
	cout<<"Ingresa el denominador ";
	cin>>b;
	
	Fraccion numero3(a,b);
	//Imprimir
	cout<<"\nNumero fraccionarios sin ordenar: ";
	numero1.imprimir();
	numero2.imprimir();
	numero3.imprimir();

	
	
	cout<<"\nNumero fraccionarios ordenados: ";
	ordenar(numero1,numero2,numero3);
	
	numero1.imprimir();
	numero2.imprimir();
	numero3.imprimir();
	
return 0;
}
