#include<iostream>
#include"Validar.h"
#include<conio.h>
#include<stdlib.h>
#include <vector>

using namespace std;

int ingresar(const char  *mensaje){
	char num[10];
	char c;
	int i=0;
	int valor;
	
	cout<<mensaje;
	
	while((c=getch())!=13){
		if(c>='0'&& c <='9'){
			cout<<c;
			num[i++]=c;
		}
	}
	
	num[i]='\0';
	valor=atoi(num);
	
return valor;
}
