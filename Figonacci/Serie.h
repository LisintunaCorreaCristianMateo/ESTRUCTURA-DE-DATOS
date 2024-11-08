#ifndef SERIE_H
#define SERIE_H
#include <vector>
using namespace std;

class Serie{
	private:
		int longitud;
		int actual;
		int siguiente;
		vector<int> secuencia;
	
	public:
		Serie(int);//Constructor
		~Serie();//Destructor
	
		void generar_Fibonacci();
		void imprimir_serie();
	
};



#endif
