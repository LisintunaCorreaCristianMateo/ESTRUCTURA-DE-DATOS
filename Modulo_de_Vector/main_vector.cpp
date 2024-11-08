/*

--------------------------------------------------------------------
 Universidad de las Fuerzas Armadas ESPE
         Estructura de Datos
--------------------------------------------------------------------
 Autor: Cristian lisintuña
Modulo: Modulo de un vector
Creacion: 05/11/2024
Modificacion:05/11/2024
Tarea:1
--------------------------------------------------------------------

*/
#include<iostream>
#include"Vector.h"
using namespace std;

int main(){
	float a,b;
	cout<<"Ingrese el valor de x del vector: ";
	cin>>a;
	cout<<"\nIngrese el valor de y del vector:";
	cin>>b;
	
	Vector vector1(a,b);
	
	float modulo;
	//pasamos el valor del modulo a la variable modulo
	modulo=vector1.hallar_modulo();
	
	//mediante el seter modificamos el valor del modulo
	vector1.set_modulo(modulo);
	//mediante el getter obtenemos el valor del modulo para mostrar 
	//el resultado
	
	cout<<"El modulo del vector es: "<<vector1.get_modulo();
	
return 0;

}
