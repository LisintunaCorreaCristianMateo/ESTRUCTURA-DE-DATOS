#include<iostream>
#include "Sumar.h"
#include"Operacion.h"
using namespace std;

template <typename T>
suma(T a,T b,T c,T d){
	double numer;
	double denom;
	double result;
	if(b=0||d=0){
		cout<<"La suma no esta definida";
	}
	else{
		if(b=d){
			numer=a+c;
			denom=b;
		}
		else{
			numer=(a*d)+(c*d);
			denom=(b*d);
		}
		int resultado=numer/denom;
		cout<<"La suma de las fracciones es: "<<numer<<" /"<<denom<<" -> "<<resultado;
		
	}
}
