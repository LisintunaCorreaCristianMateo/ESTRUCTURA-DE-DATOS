#ifndef LISTAESTUDIANTES_H
#define LISTAESTUDIANTES_H

#include <string>
#include "Nodo.h"

class ListaEstudiantes {
private:
    Nodo* cabeza;

    string convertirMinusculas(const string& cadena);
    string convertirAString(int numero);
    string eliminarEspacios(const string& cadena);
    string generarCorreoBase(const string& primerNombre, const string& segundoNombre, const string& apellido);
    string generarCorreoUnico(const string& baseCorreo);

public:
    ListaEstudiantes();
    ~ListaEstudiantes();

    void agregarEstudiante(const string& primerNombre, const string& segundoNombre, const string& apellido, const string& segundoApellido,const string& cedula);
    void mostrarLista() const;
    void liberarLista();
};

#endif

