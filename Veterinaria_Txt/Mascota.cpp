#include "Mascota.h"
#include <iostream>
#include <cstdlib> // Para srand y rand
#include <ctime>   // Para time


using namespace std;

int generarId();

Mascota::Mascota(int _id,string _tipo,string _nombre,string _raza,int _edad,string _detalles){
	id=_id;
	tipo=_tipo;
	nombre=_nombre;
	raza=_raza;
	edad=_edad;
	detalles=_detalles;
	siguiente=NULL;
}
Mascota::~Mascota(){
	
}




