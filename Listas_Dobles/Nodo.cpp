#include "Nodo.h"
#include <iostream>
using namespace std;

Nodo::Nodo(const string valor) {
    	dato=valor;
		siguiente=NULL;
		anterior=NULL;
}
Nodo::~Nodo(){
	
}

