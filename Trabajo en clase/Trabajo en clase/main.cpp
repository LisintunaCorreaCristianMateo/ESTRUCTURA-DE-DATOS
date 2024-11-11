#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int ingresar(const char*);//char esta almacendo un arreglo
void sum(int valor1,int valor2);
char* ingresar_char(const char* msj);

int ingresar(const char* msj) {

    char cad[10];  // Cadena para almacenar los n�meros
    char c;
    int i = 0;
    int valor;  // Declarar la variable 'valor'

    printf("%s", msj);  // Mostrar el mensaje

    // Leer caracteres hasta que se presione Enter (ASCII 13)
    while ((c = _getch()) != 13) {
        if (c >= '0' && c <= '9') {  // Aceptar solo d�gitos
            printf("%c", c);  // Mostrar el car�cter ingresado
            cad[i++] = c;  // Almacenar el car�cter en la cadena
        }
    }

    cad[i] = '\0';  // Terminar la cadena con un car�cter nulo
    valor = atoi(cad);  // Convertir la cadena de caracteres a entero

    return valor;  // Retornar el valor convertido
}

int main() {

    int numero = ingresar("Ingrese un valor entero: ");  // Llamar a la funci�n e imprimir el valor
    //cout << "\nEl valor ingresado es: " << numero << endl;
	

	int numero2=ingresar("\nIngresa otro numero: ");
	


	sum(numero,numero2);

	
	
	char* nombre=ingresar_char("\nIngrese su nombre: ");
	cout<<"\nEl nombre es: "<<nombre<<endl;
    return 0;
}
void sum(int valor1,int valor2){
	int sum=valor1 + valor2;
	cout<<endl;
	cout<<"La suma es: ";
	cout<<sum;
}
char* ingresar_char(const char* msj) {

    static char cad[100];  // Cadena para almacenar las letras ingresadas (amplio el tama�o si es necesario)
    char c;
    int i = 0;

    printf("%s", msj);  // Mostrar el mensaje

    // Leer caracteres hasta que se presione Enter (ASCII 13)
    while ((c = _getch()) != 13) {//13 es el c�digo ASCII para la tecla "Enter"
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {  // Aceptar solo letras may�sculas y min�sculas
            printf("%c", c);  // Mostrar el car�cter ingresado
            cad[i++] = c;  // Almacenar el car�cter en la cadena
        }
    }

    cad[i] = '\0';  // Terminar la cadena con un car�cter nulo
    				//Muestra el null al final de la cadena

    return cad;  // Retornar la cadena de letras ingresadas
}
