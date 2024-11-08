/*

--------------------------------------------------------------------
 Universidad de las Fuerzas Armadas ESPE
         Estructura de Datos
--------------------------------------------------------------------
 Autor: Cristian lisintuña
Modulo:Serie de Fibonacci 
Creacion: 05/11/2024
Modificacion:05/11/2024
Tarea:1
--------------------------------------------------------------------

*/
#include<iostream>
#include"Serie.h"

using namespace std;

int main(){
	
	int numero;
	cout<<"FIBONACCI"<<endl;
	cout<<"Ingresa el numero de terminos que tendra la serie: ";
	cin>>numero;
	
	while(numero<0){
		cout<<"Tamanio de la serie no valida, vuelve a ingresar: ";
		cin>>numero;
	}
	
	Serie fibonacci(numero);
	fibonacci.generar_Fibonacci();
	fibonacci.imprimir_serie();
return 0;
}
