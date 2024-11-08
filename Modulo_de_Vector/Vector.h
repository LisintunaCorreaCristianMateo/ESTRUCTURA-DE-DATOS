#ifndef VECTOR_H
#define VECTOR_H

class Vector{
	private:
		float x;
		float y;
		float modulo;
		
	public:
		//contructor
		Vector(float,float);
		//destructor
		~Vector();
		
		float hallar_modulo();
		//seter
		void set_modulo(float);
		//geter
		float get_modulo();
};

#endif
