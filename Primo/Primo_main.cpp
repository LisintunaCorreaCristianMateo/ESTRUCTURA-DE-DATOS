/*

--------------------------------------------------------------------
 Universidad de las Fuerzas Armadas ESPE
         Estructura de Datos
--------------------------------------------------------------------
 Autor: Cristian lisintuña
Modulo:Numero Primo
Creacion: 05/11/2024
Modificacion:05/11/2024
Tarea:1
--------------------------------------------------------------------

*/
#include<iostream>
#include<string>
#include"Numero.h"//nombre del .h es el nombre que tendra la clase
using namespace std;

int main(){
	int valor;
	
	
	cout<<"Ingresa el valor para verificar que sea primo: ";
	cin>>valor;
	while(valor<0){
		cout<<"\nIngresa un valor positivo: ";
		cin>>valor;
	}
	
	Numero numero1(valor);
	int primo_;
		primo_=numero1.verificar_primo();
		
	if(primo_==0){//llamamos a la funcion y si lo que retorna es 0 el numero es primo
		string primo;//usar geter para editar el atributoj
		numero1.setesPrimo("Es primo");
			
	}
	else if(primo_!=0){ // si no es 0 el numero no es primo
		numero1.setesPrimo("No es primo");
	}
	
	numero1.imprimir();//Imprime
return 0;
 }
