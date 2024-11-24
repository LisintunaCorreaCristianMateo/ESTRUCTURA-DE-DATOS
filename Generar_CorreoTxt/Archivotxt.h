#ifndef ARCHIVOTXT_H
#define ARCHIVOTXT_H

#include "ListaEstudiantes.h"
#include <string>
using namespace std;

class Archivotxt {
public:
    // Constructor y destructor
    Archivotxt() = default;
    ~Archivotxt() = default;

    // Métodos principales
    void leerDesdeArchivo(const string& nombreArchivo, ListaEstudiantes& lista);
    void guardarEnArchivo(const string& nombreArchivo, const ListaEstudiantes& lista);
};

#endif // ARCHIVOS_H

