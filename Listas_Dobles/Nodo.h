#ifndef NODO_H
#define NODO_H
#include <string>
#include<iostream>
using namespace std;

class Nodo {
public:
    string dato;
    Nodo* siguiente;
    Nodo* anterior;
public:
	//constructor
    Nodo(const string valor);
    //destructor
    
    ~Nodo();
};
#endif

