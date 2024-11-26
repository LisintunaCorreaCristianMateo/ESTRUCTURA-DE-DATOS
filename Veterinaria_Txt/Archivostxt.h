#ifndef ARCHIVOSTXT_H
#define ARCHIVOSTXT_H

#include "Listamascota.h"
#include <string>
#include <iostream>
using namespace std;

class Archivostxt {
public:
    // Constructor y destructor
    Archivostxt() = default;
    ~Archivostxt() = default;

    // Métodos principales
    void leerDesdeArchivo(const string& nombreArchivo, Listamascota& lista);
    void guardarEnArchivo(const string& nombreArchivo, const Listamascota& lista);
};

#endif // ARCHIVOS_H

