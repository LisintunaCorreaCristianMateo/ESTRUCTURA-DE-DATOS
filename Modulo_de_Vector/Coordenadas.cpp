#include<iostream>
using namespace std;

class Punto{
		//atriburos
	private:
		int x;
		int y;
	public:
		//constructor
		Punto(int,int);
		//destructor
		~Punto();
		
		//metodos
		void mostrar();
		
		//seter 
		void setx(int);
	//	int geter_x();
	//	int geter_y();
		
		int geter_x(){
		return x;
		}
		
		int geter_y(){
		return y;
		}
		
};

Punto::Punto(int _x,int _y){
	x=_x;
	y=_y;	
}
Punto::~Punto(){
	
}

void Punto::mostrar(){
	cout<<"La cooerdenada del punto es: ("<<x<<";"<<y<<")"<<endl;	
}
void Punto::setx(int x_){
	x=x_;
}


int main (){
	int X,Y;
	cout<<"Ingresa la coordenada x:";
	cin>>X;
	cout<<"Ingresa la coordenada y: ";
	cin>>Y;
	
	Punto p1(X,Y);
	p1.mostrar();
	
	//modificar el atributo x
	int x_modificado;
	cout<<"Ingresa el nuevo valor de x: ";
	cin>>x_modificado;
	p1.setx(x_modificado);
	//imprimir el cambio
	p1.mostrar();
	 //imprimir x con getter
	 cout<<"Imprimir con geter el eje x: "<<p1.geter_x()<<endl;	
	 
	 //imprimir y con getter
	 cout<<"Imprimir con geter el eje y: "<<p1.geter_y()<<endl;
	 

	
return 0;
}
