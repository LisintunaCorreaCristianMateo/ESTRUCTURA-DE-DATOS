#ifndef LISTAESTUDIANTES_H
#define LISTAESTUDIANTES_H

#include <string>
#include "Nodo.h"
#include <iostream>
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
    
    string eliminarEspacios( string& cadena);
    string convertirMinusculas(string& cadena);
    string convertirAString(int numero);
    string generarCorreoBase( string& primerNombre, string& segundoNombre,  string& apellido);
    string generarCorreoUnico( string& baseCorreo);
    
     // Métodos para trabajar con la lista
	void eliminarEstudiante( string& cedula);
    void agregarEstudiante(string& primerNombre,  string& segundoNombre, string& apellido, string& segundoApellido,string& cedula);
	void mostrarLista() ;
	void mostrarListaDescifrada();
	
	
	
    
    
        // Métodos para manejar la cabeza de la lista
    Nodo* getCabeza() const { 
        return cabeza; 
    }

    void setCabeza(Nodo* nuevaCabeza) { 
        cabeza = nuevaCabeza; 
    }
	
};






#endif

