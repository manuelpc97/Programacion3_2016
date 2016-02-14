#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void ordenarArreglo(int[], int, int);

int main(int argv, char*argc[]){
int size;

cout<<"Ingrese el amaño de su areglo: "<<endl;
cin>>size;
int arreglo[size];

for(int i = 0; i<size;i++){
	cout<<"Ingrese un numero: "<<endl;
	cin>>arreglo[i];
}

ordenarArreglo(arreglo, size, 0);

for(int i =0; i<size; i++){
	cout<<arreglo[i]<<endl;
}
return 0;
}

void ordenarArreglo(int lista[], int apocalipsis, int genesis){
	int menor=0;
	int posicion =0;
	if(genesis==(apocalipsis-1)){
		menor=lista[genesis];
                for(int i = genesis; i<apocalipsis; i++){
                        if(menor>lista[i]){
                                menor=lista[i];
                                posicion=i;
                        }
                }

		if(lista[genesis]!=menor){
                	lista[posicion]=lista[genesis];
                	lista[genesis]=menor;
		}
		

	}else if(genesis<apocalipsis){
			menor=lista[genesis];
		for(int i = genesis; i<apocalipsis; i++){
			if(menor>lista[i]){
				menor=lista[i];
				posicion=i;		
			}		
		}
		
		if(lista[genesis]!=menor){
			lista[posicion]=lista[genesis];
			lista[genesis]=menor;
		}
		ordenarArreglo(lista, apocalipsis, genesis+1);
	}
}
