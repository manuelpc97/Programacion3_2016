#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

struct Punto{
	int x;
	int y;	
};


void pedirDatos(int&, int&);
double findMagnitud(Punto, Punto);
bool isRectangle(double, double);
bool compareDistance(double, double, double, double);
double findArea(double, double);
double findPerimeter(double, double);


int main(int argc, char*argv[]){
	
	Punto a,b,c,d;

	pedirDatos(a.x,a.y);
	pedirDatos(b.x,b.y);
	pedirDatos(c.x,c.y);
	pedirDatos(d.x,d.y);
		
	if( isRectangle( findMagnitud(a , d) , findMagnitud(c , b)) ){
		if( compareDistance( findMagnitud(a ,b) , findMagnitud(c , d), findMagnitud(c , a), findMagnitud(d , b))){
			cout << "Los puntos ingresados forman un rectangulo" << endl;
			cout << "El perimetro es: " << findPerimeter( findMagnitud(a , b) , findMagnitud(c , a)) << endl;
			cout<< "El area es: " << findArea( findMagnitud(a , b) , findMagnitud(c , a)) << endl;;
		}else{
			cout << "Los puntos ingresados no forman un triangulo" << endl;
		}
	}else{
		cout << "Los puntos ingresados no forman un rectangulo" << endl;
	}
			
	return 0;

}

void pedirDatos(int& first, int& last){
	cout<<"Ingrese la coordenada x:"<<endl;
	cin>>first;
	cout<<"Ingrese la coordenada y: "<<endl;
	cin>>last;
}


double findMagnitud(Punto a, Punto b){
	return sqrt(pow(b.y-a.y,2)+pow(b.x-a.x,2));
}

bool isRectangle(double num1, double num2){
	if((num1 == num2)){
		return true;	
	}else{
		return false;
	}
}

bool compareDistance(double num1, double num2, double num3, double num4){
	if((num1 == num2) && (num3 == num4)){
		if(num1 > num3 || num4 > num2){
			return true;
		}else{
			return false;
		}	
	}else{
		return false;
	}
}

 
double findArea(double num, double num2){
	return num*num2;

}

double findPerimeter(double num, double num2){
	return num+num+num2+num2;
}
