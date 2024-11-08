#include"Serie.h"
#include<iostream>
#include <vector>
using namespace std;
//constructor
Serie::Serie(int _tamanio){
	longitud=_tamanio;
	actual=0;
	siguiente=1;
}
Serie::~Serie(){
	
}
void Serie::generar_Fibonacci(){
	
	if(longitud>=1){
		secuencia.push_back(actual);
	}
	if(longitud>=2){
		secuencia.push_back(siguiente);
	}
	//codigo si la longitud es mayor a 1
	int temp;
	if(longitud>2){
		for(int i=2;i<longitud;i++){
			temp=siguiente;
			siguiente=actual+siguiente;
			actual=temp;
			
			secuencia.push_back(siguiente);
		}
	}
	
}
void Serie::imprimir_serie(){
	
	    for (int i = 0; i <longitud; i++) {//size halla el tamaño del vector
       
		cout<<secuencia[i] << " ";					//y lo imprimimos con el for
    }
}
