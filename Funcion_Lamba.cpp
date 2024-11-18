#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <string.h>

/* 
FUNCION LAMBDA:  [captura de datos para ser manipulados](parametros){cuerpo};

int (*suma)(int)=[](int n){
		return n*5;
};*/

using namespace std;

int (*suma)(int)=[](int n){
		return n*5;
};

void listar(int i){
	std::cout<<i<<std::endl;
}

int main(int argc, char** argv) {
	int x=5,z=3,r=2;
	int j=-1,k=-1;
	vector<int> vec{3,6,1,3,7};
	for_each(vec.begin(),vec.end(),[&](int i){
		x=x+10;
		cout << i*x+z+r << endl;
		//cout << "k " << i*(k+1) << "\nj " << i*(j+1);
	});
	
	cout << "\n\n\n"; 
	
	[&](int i){
		cout << "hola";
	};
	
	//std::cout << suma(10);
	return 0;
}
