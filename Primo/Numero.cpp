#include"Numero.h"
#include<iostream>
#include<string>
using namespace std;

Numero::Numero(int n){
	valor=n;
}
Numero::~Numero(){
	
}
int Numero::verificar_primo(){
	int e=0;
	// el numero esta guardado en el atributo valor
	if(valor==0||valor==1){
		e++;
		
	}
	else{
		for(int i=2;i<valor;i++){
			if(valor%i==0){
			e++;
			}
		
		}
	}

return e;	
}
void Numero::setesPrimo(string x){ //x almacena la inf de si es primo o no
esPrimo=x;
}
void Numero::imprimir(){
	cout<<"El numero: "<<valor<<" "<<esPrimo;
}

