#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

void printData(double[], int);
void readData(double[], int);
double media(double[], int);
double moda(double[], int);
double mediana(double[], int);
double desviacion(double[],int);

int main(int argc, char*argv[]){

	if(argv!=2){
	cerr<<"Numero incorrecto de parametros"<<endl;
	cerr<<argv[0]<<" n "<<endl;
	cerr<<"N = NUMERO DE ELEMENTOS DEL ARREGLO"<<endl;
	exit(1);

	}
	
	int n = atoi(argv[1]);
	if(n==0){
		cerr<<"0 el numero es invalido o puso cero"<<endl
		<<"En cualquier caso favor corrijalo"<<endl;
		exit(1);
		
	}
	const int SIZE = 100;
	double numeros[SIZE];
	
	srand(time(NULL));

	for(int i = 0;i<SIZE;i++){
		numeros[i]= 1+rand()%(301-1);		
	}

	for(int i = 0; i<SIZE;i++){
		cout<<numeros[i]<<endl;
	}
	cout<<"La media es: "<<media(numeros, SIZE)<<endl;
	cout<<"La moda es: "<<moda(numeros, SIZE)<<endl;	
	cout<<"La mediana es: "<<mediana(numeros, SIZE)<<endl;
	cout<<"La desviacion estandar es: "<<desviacion(numeros, SIZE)<<endl;
	return 0;
}


double media(double grupo[], int num){
	double resp=0;

	for(int i = 0;i<num;i++){
		resp+=grupo[i]/num;
	}
	
	return resp;
}


double moda(double numbers[], int a){
	double answer, preAnswer;
	int contador1=0;
	int contador2=0;

	for(int i = 0; i<a;i++){
		for(int j=0;j<a;j++){
			if(numbers[i]==numbers[j]){
				contador1++;
				preAnswer=numbers[j];
			}
		}
		
		if(contador1>contador2&&contador1!=1){
			contador2=contador1;
			contador1=0;
			answer=preAnswer;
		}
		
		contador1=0;
	}

	return answer;
}


double mediana(double x[], int y){
	int contador=0;
	double nuevoArreglo[y];

	for(int i=0;i<300;i++){
		for(int j = 0;j<y;j++){
			if(i==x[j]){
				nuevoArreglo[contador]=i;
				contador++;
			}
		}	
	}
	
	if(y%2==0)
		return (nuevoArreglo[(y/2)-1]+nuevoArreglo[y/2])/2;
	else if(y%2!=0)
		return(nuevoArreglo[((y+1)/2)-1]);
}


double desviacion(double group[],int s){
	double desv;
	double promedio = media(group, s);	
	for(int i = 0; i<s;i++){
		desv+=pow(group[i]-promedio,2)/(s-1);
	}
 
	return sqrt(desv);
}


void readData(double[], int)
