#ifndef LISTAMASCOTA_H
#define LISTAMASCOTA_H
#include "Mascota.h"

class Listamascota{
	private:
		Mascota *cabeza;
	public:
		Listamascota();
		~Listamascota();
		
		void liberarlista();
		
		void agregar(const string &tipo,const string &nombre,const string &raza,const int &edad,const string &detalles);
		void eliminar();
		void imprimirLista();
		
		        // M?todos para manejar la cabeza de la lista
    	Mascota *getCabeza() const { 
        	return cabeza; 
  		  }

    	void setCabeza(Mascota* nuevaCabeza) { 
       	 cabeza = nuevaCabeza; 
    	}
		
		
		//Metodos auxiliares
		 string eliminarEspacios(const string& cadena);
		 
		 
		
};

#endif
