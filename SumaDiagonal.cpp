#include <iostream>
#include <stdlib.h>
#include <time.h>
#define MAX 3

/*
Suma de la diagonal de una matriz recursivamente
*/

using namespace std;

int sumaRecursivaDiagonal(int[MAX][MAX], int);

int sumaRecursivaDiagonal(int mat[MAX][MAX], int f) {
    if (f == 0)
        return mat[f][f];  // Caso base: sumar el elemento en la posición [0][0]
    else
        return mat[f][f] + sumaRecursivaDiagonal(mat, f - 1);  // Recursión
}

int main(int argc, char** argv) {
    int mat[MAX][MAX];
    srand(time(NULL));

    // Generar valores aleatorios para la matriz
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            mat[i][j] = (int)((rand() / 32768.1) * 1000);
        }
    }

    // Imprimir la matriz
    cout << "Matriz generada:\n";
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // Llamada a la función recursiva para sumar la diagonal
    cout << "Suma de la diagonal es: " << sumaRecursivaDiagonal(mat, MAX - 1) << endl;

    return 0;
}

