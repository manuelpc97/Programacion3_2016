
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;
using std::remove;

bool probarPalindromo(string, int, int);
int medirCadena(string);
void imprimirArreglo(int[], int, int);
int minimoRecursivo(int[], int, int, int);

int main(int argc, char*argv[]){
string palabra;
const int sizeArray= 10;
int SIZE;
bool seguir=true;
int opcion=0;
int inicio = 0;
bool isPalindromo;
int arreglo[sizeArray] ;
int genesis=0;
int apocalipsis=0;

while(seguir){
	cout<<"Elija que desea hacer: "<<endl
	<<"1.Evaluar palindromo"<<endl
	<<"2. Imprimir un arreglo"<<endl
	<<"3.Mostrar minimo numero de un arreglo"<<endl
	<<"4. Para salir"<<endl;
	cin>>opcion;

	if(opcion==1){
		cout<<"Escriba la palabra que desea evaluar: "<<endl;
		cin>>palabra;
		SIZE= medirCadena(palabra);
		isPalindromo = probarPalindromo(palabra, inicio, SIZE-1);

		if(isPalindromo==true)
			cout<<"La palabra es palindromo "<<endl;
		else
			cout<<"La palabra no es palindromo"<<endl;
		cout<<endl;
	}else if(opcion==2){

		for(int i = 0;i<sizeArray;i++){
			cout<<"Ingrese un numero: "<<endl;
			cin>>arreglo[i];
		}
		
		cout<<"Ingrese la posicion inicial que desea imprimir"<<endl;
		cin>>genesis;
		
		while(genesis>=sizeArray||genesis<0){
			cout<<"Numero incorrecto, ingrese otro valor: "<<endl;
			cin>>genesis;
		}
		cout<<"Ingrese la posicion final que desea escribir"<<endl;
		cin>>apocalipsis;
		
		while(apocalipsis>=sizeArray || apocalipsis<0){
			cout<<"Numero demasiado grande, ingrese otro numero"<<endl;
			cin>>apocalipsis;
		}

		while(genesis>=apocalipsis){
			cout<<"El primer numero no puede ser mayor que el ultimo y tampoco pueden ser iguales, ingrese valores de nuevo"<<endl;
			cout<<"Primer valor:"<<endl;
			cin>>genesis;
			cout<<"Segundo valor"<<endl;
			cin>>apocalipsis;
		}
		
		imprimirArreglo(arreglo, genesis, apocalipsis);			
	}else if(opcion==3){
		 for(int i = 0;i<sizeArray;i++){
                        cout<<"Ingrese un numero: "<<endl;
                        cin>>arreglo[i];
                }

                cout<<"Ingrese la posicion inicial que desea evaluar"<<endl;
                cin>>genesis;

                while(genesis>=sizeArray||genesis<0){
                        cout<<"Numero incorrecto, ingrese otro valor: "<<endl;
                        cin>>genesis;
                }
                cout<<"Ingrese la posicion final que desea evaluar"<<endl;
                cin>>apocalipsis;

                while(apocalipsis>=sizeArray || apocalipsis<0){
                        cout<<"Numero demasiado grande, ingrese otro numero"<<endl;
                        cin>>apocalipsis;
                }

                while(genesis>=apocalipsis){
                        cout<<"El primer numero no puede ser mayor que el ultimo y tampoco pueden ser iguales, ingrese valores de nuevo"<<endl;
                        cout<<"Primer valor:"<<endl;
                        cin>>genesis;
                        cout<<"Segundo valor"<<endl;
                        cin>>apocalipsis;
                }

		cout<<"El menor numero es: "<<minimoRecursivo(arreglo, genesis, apocalipsis, arreglo[genesis])<<endl;

	}else if(opcion==4){
		seguir=false;
	}
}
return 0;
}

bool probarPalindromo(string word, int first, int last){
	
	if(first==last){
		if(word[first]==word[last]){
			return true;
		}else if(word[first]!=word[last]){
			return false;
		}
	}else if(first!=last){
		if(word[first]==word[last]){
			probarPalindromo(word, first+1, last-1);
                }else if(word[first]!=word[last]){
                        return false;
                }
	}
	
}

int medirCadena(string a){
	int size = 0;

	while(a[size]!='\0'){
		size++;
	}

	return size;
}



void imprimirArreglo(int lista[], int posInicial, int posFinal){
	if(posInicial==posFinal){
		cout<<lista[posFinal]<<endl;
	}else if(posInicial!=posFinal){
		cout<<lista[posInicial]<<endl;
		imprimirArreglo(lista, posInicial+1, posFinal);
	}	
}

int minimoRecursivo(int list[], int prin, int fin, int comparar){
		if(prin==fin){
                	return comparar;
        }else if(prin!=fin){		
                if(comparar<list[prin]){
			minimoRecursivo(list,prin+1,fin,comparar);
		}else if(comparar>=list[prin]){
			comparar=list[prin];
			minimoRecursivo(list, prin+1,fin,comparar);
		}
        	
	}	

}
