#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void escribirUno(int**, int, int);
void escribirMatriz(int**, int);
int** declararMatriz(int);

int main(int argc, char*argv[]){
	int numero;
	
	cout<<"Ingrese la cantidad de filas de su triangulo:"<<endl;
	cin>>numero;

	int** triangulo = declararMatriz(numero*2);
	escribirUno(triangulo,0,numero);
	escribirMatriz(triangulo, numero*2);	
	
	
	return 0;
}

void escribirUno(int** matriz, int x, int y){
	
	if(y==0){
		matriz[x][y]=1;
	}else{
		matriz[x][y]=1;
		matriz[y][y]=1;
		escribirUno(matriz,x+1, y-1);
	}

}

void escribirMatriz(int** mat, int size){
	for(int i = 0;  i<size; i++){
		for(int j = 0; j<size/2;j++){
			if(mat[i][j]==1)
				cout<<"1";
			else	
				cout<<"0";
		}
		cout<<endl;
	}

}

int** declararMatriz(int size){
	int** h = new int*[size];

	for(int i = 0; i<size; i++){
		h[i]=new int[size/2];
	}
	return h;

}
