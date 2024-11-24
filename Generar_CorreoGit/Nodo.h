#ifndef NODO_H
#define NODO_H

#include <string>
using namespace std;

class Nodo {
public:
    string primerNombre;
    string segundoNombre;
    string apellido;
    string segundoApellido;
    string correo;
    string cedula;
    Nodo* siguiente;

    Nodo(const string& pNombre, const string& sNombre, const string& ape, const string& sApe,const string& _cedula);
};

#endif

