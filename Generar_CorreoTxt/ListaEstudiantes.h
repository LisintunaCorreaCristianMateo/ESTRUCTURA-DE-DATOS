#ifndef LISTAESTUDIANTES_H
#define LISTAESTUDIANTES_H

#include <string>
#include "Nodo.h"
using namespace std;

class ListaEstudiantes {
private:
    Nodo* cabeza;



public:
	//Constructores y destructores
    ListaEstudiantes();
    ~ListaEstudiantes();
    
    //Metodo auxiliares
    void liberarLista();
    
    string eliminarEspacios(const string& cadena);
    string convertirMinusculas(const string& cadena);
    string convertirAString(int numero);
    string generarCorreoBase(const string& primerNombre, const string& segundoNombre, const string& apellido);
    string generarCorreoUnico(const string& baseCorreo);
    
     // Métodos para trabajar con la lista
	void eliminarEstudiante(const string& cedula);
    void agregarEstudiante(const string& primerNombre, const string& segundoNombre, const string& apellido, const string& segundoApellido,const string& cedula);
	void mostrarLista() const;
    
    
        // Métodos para manejar la cabeza de la lista
    Nodo* getCabeza() const { 
        return cabeza; 
    }

    void setCabeza(Nodo* nuevaCabeza) { 
        cabeza = nuevaCabeza; 
    }
	
};






#endif

