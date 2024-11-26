#ifndef MASCOTA_H
#define MASCOTA_H
#include <iostream>
#include<string>

using namespace std;

class Mascota{//es el nodo
	public:
		int id;
		string tipo;
		string nombre;
		string raza;
		int edad;
		string detalles;
		Mascota* siguiente;
		
	public:
		Mascota(int,string,string,string,int,string);
		~Mascota();
};

#endif
