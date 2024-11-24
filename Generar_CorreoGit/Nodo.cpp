#include "Nodo.h"

Nodo::Nodo(const string& pNombre, const string& sNombre, const string& ape, const string& sApe,const string& _cedula)
    : primerNombre(pNombre), segundoNombre(sNombre), apellido(ape), segundoApellido(sApe),cedula(_cedula), siguiente(NULL) {}

