#include "Nodo.h"

Nodo::Nodo(const string& pNombre, const string& sNombre, const string& ape, const string& sApe,const string& _cedula,const string& _correo){
	primerNombre=pNombre;
	segundoNombre=sNombre;
	apellido=ape;
	segundoApellido=sApe;
	cedula=_cedula;
	correo=_correo;
	siguiente=NULL;
}


