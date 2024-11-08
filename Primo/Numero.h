#ifndef NUMERO_H
#define NUMERO_H
#include<iostream>
#include<string>
using namespace std;

	class Numero{
		private:
			int valor;
			string esPrimo;//atributo que almacenara si el numero es primo o no
			
		public:
			//constructor;
			Numero(int);
			~Numero();
			int verificar_primo();
			void setesPrimo(string);
			
			void imprimir();
	};
	

#endif

