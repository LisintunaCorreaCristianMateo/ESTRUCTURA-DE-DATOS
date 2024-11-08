#include"Vector.h"
#include<cmath>
Vector::Vector(float _x,float _y){
	x=_x;
	y=_y;
	modulo=0;
}
Vector::~Vector(){
	
}
float Vector::hallar_modulo(){
	//para hallar el modulo del vector
	//hay que usar la formula de m^2=x^2+y^2
	
	float modulo;
	modulo = sqrt(pow(x, 2) + pow(y, 2));
	return modulo;
}
void Vector::set_modulo(float _modulo){
	modulo=_modulo;
}
float Vector::get_modulo(){
	return modulo;
	}
