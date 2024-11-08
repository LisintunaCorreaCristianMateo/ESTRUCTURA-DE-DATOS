/*

--------------------------------------------------------------------
 Universidad de las Fuerzas Armadas ESPE
         Estructura de Datos
--------------------------------------------------------------------
 Autor: Cristian lisintuña
Modulo:Factorial de un numero
Creacion: 05/11/2024
Modificacion:05/11/2024
Tarea:1
--------------------------------------------------------------------

*/

#include<iostream>
#include"Factorial.h"
using namespace std;
int main(){
	int n;
	cout<<"Factorial:"<<endl;
	cout<<"Ingresa un numero: ";
	cin>>n; 
	
	while(n<0){
		cout<<"Ingresa un numero valido: ";
		cin>>n;
	}	
	Factorial numero1(n);
	
	int resultado_fact;
	resultado_fact=numero1.hallar_facto();
	
	numero1.setresultado(resultado_fact);
	
	cout<<"El resultado es: "<<numero1.getresultado();
	
return 0;
}
