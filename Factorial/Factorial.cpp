#include<iostream>
#include "Factorial.h"
using namespace std;
Factorial::Factorial(int valor){
	numero=valor;
	resultado=1;
}
Factorial::~Factorial(){
}
int Factorial::hallar_facto(){
	int resul=1;

	if(numero!=0){
		for(int i=numero;i>0;i--)//numero es el atrivuto
		resul=resul*i;
	}
	
return resul;	
}
void Factorial::setresultado(int resul){
	resultado=resul;
}
int Factorial::getresultado(){
	return resultado;
}
