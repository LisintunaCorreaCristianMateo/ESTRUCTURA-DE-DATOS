/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  
 * Proposito:                      Matrices dinámicas                      
 * Autor:                          Cristian Lisintuaña                                 
 * Fecha de creacion:              06/12/2024                                           
 * Fecha de modificacion:          06/12/2024                                           
 * Materia:                        Estructura de datos                                 
 * NRC :                           1978                                                
 **************************************************************************************/
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "Matriz.h"

using namespace std;

int main(int argc, char** argv) {
    // Crear matrices dinámicas
    int** mat1 = new int*[3];
    int** mat2 = new int*[3];
    for (int i = 0; i < 3; i++) {
        *(mat1 + i) = new int[3];
        *(mat2 + i) = new int[3];
    }

    // Inicializar matrices con valores aleatorios
    srand(time(NULL));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            *(*(mat1 + i) + j) = rand() % 100; // Valores entre 0 y 99
            *(*(mat2 + i) + j) = rand() % 100;
        }
    }

    // Imprimir la primera matriz
    cout << "Matriz 1:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << *(*(mat1 + i) + j) << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // Imprimir la segunda matriz
    cout << "Matriz 2:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << *(*(mat2 + i) + j) << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // Crear un objeto de la clase Matriz
    Matriz matriz;

    // Llamar al método sumaRecursivaMatrices
    cout << "Suma de las matrices es: "
         << matriz.sumaRecursivaMatrices(mat1, mat2, 2, 2)
         << endl;

    // Liberar memoria dinámica
    for (int i = 0; i < 3; i++) {
        delete[] *(mat1 + i);
        delete[] *(mat2 + i);
    }
    delete[] mat1;
    delete[] mat2;

    system("pause");
    return 0;
}

