//ordenar 3  fracionarios con POO
#include<iostream>
using namespace std;



class Fraccion{
	private://atributos
		float numerador;
		float denominador;
		
	public:
		Fraccion(int,int);//constructor
		void imprimir();
		float dividir();//metodo para ordenar
};

Fraccion::Fraccion(int _a,int _b){
	numerador=_a;
	denominador=_b;
}

void Fraccion::imprimir(){
	cout<<numerador<<"/"<<denominador<<" ";
}

float Fraccion::dividir(){
	float resultado;
	resultado=numerador/denominador;
	return resultado;
}

void ordenar(Fraccion &numero1,Fraccion &numero2,Fraccion &numero3);

int main(){
	float a,b;
	
	
	cout<<"Primer numero: "<<endl<<endl;
	cout<<"Ingresa el numerador: ";
	cin>>a;
	cout<<"Ingresa el denominador ";
	cin>>b;
	
	Fraccion numero1(a,b);
	
	cout<<"\nSegundo numero: "<<endl<<endl;
	cout<<"Ingresa el numerador: ";
	cin>>a;
	cout<<"Ingresa el denominador ";
	cin>>b;
	
	Fraccion numero2(a,b);
	
	cout<<"\nTercer numero: "<<endl<<endl;
	cout<<"Ingresa el numerador: ";
	cin>>a;
	cout<<"Ingresa el denominador ";
	cin>>b;
	
	Fraccion numero3(a,b);
	//Imprimir
	cout<<"\nNumero fraccionarios sin ordenar: ";
	numero1.imprimir();
	numero2.imprimir();
	numero3.imprimir();

	
	
	cout<<"\nNumero fraccionarios ordenados: ";
	ordenar(numero1,numero2,numero3);
	
	numero1.imprimir();
	numero2.imprimir();
	numero3.imprimir();
	
return 0;
}
void ordenar(Fraccion &numero1,Fraccion &numero2,Fraccion &numero3){
    // Usar burbujeo simple para ordenar las fracciones
    if (numero1.dividir() > numero2.dividir()) {
        swap(numero1, numero2);
    }
    if (numero2.dividir() > numero3.dividir()) {
        swap(numero2, numero3);
    }
    if (numero1.dividir() > numero2.dividir()) {
        swap(numero1, numero2);
    }
}


