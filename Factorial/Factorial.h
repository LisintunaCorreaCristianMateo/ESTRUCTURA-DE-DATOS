#ifndef FACTORIAL_H
#define FACTORIAL_H
#include<iostream>
using namespace std;

class Factorial{
	private:
		int numero;//numero del cual vamos hallar el factorial
		int resultado;//resultado del factorial
		
	public:
		Factorial(int);
		~Factorial();
		
		void setresultado(int);
		int getresultado();
		
	int hallar_facto();
};

#endif
