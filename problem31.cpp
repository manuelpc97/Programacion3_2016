#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int stringSize(string);
bool isPrime(int);
bool leftToRight(string, int, int);
bool rightToLeft(string, int, int);

int main(int argc, char*argv[]){
	string numero;

	cout<<"Ingrese el numero que desea evaluar: "<<endl;
	cin>>numero;	
	
	if(leftToRight(numero,0,stringSize(numero)) && rightToLeft(numero,0,stringSize(numero)-1)){
		cout<<"The number is a truncatable prime"<<endl;
	}else{
		cout<<"The number isn't a truncatable prime"<<endl;
	}
	return 0;
}
//*******************************************************************************************
int stringSize(string word){
	int contador=0;
	int size=0;

	while(word[contador]!='\0'){
		size++;
		contador++;
	}

	return size;
}
//********************************************************************************************
bool isPrime(int num){
	bool primo = true;
	if(num==1||num==2){
		primo=true;
	}else{
		for(int i = 2; i<num-1;i++){
			if(num%i==0){
				primo=false;
			}
		}		
	}
	return primo;
}
//****************************************************************************************
bool leftToRight(string word, int first, int end){
	char evaluar[end-first];
	int contador=0;
	if(first==end-1){
		for(int i = first;i < end;i++){
			evaluar[contador]=word[i];
			contador++;
		}
		contador=0;
		if(isPrime(atoi(evaluar)))
			return true;
		else
			return false;
	}else{
		for(int i = first;i < end;i++){
                        evaluar[contador]=word[i];
                        contador++;
                }
		contador=0;
                if(isPrime(atoi(evaluar))){
                        leftToRight(word,first+1,end);
                }else{
                        return false;
		}
	}

}

bool rightToLeft(string word, int first, int end){
        char evaluar[(end+1)-first];
        int contador=end;
        if(end==first){
                for(int i = end;i >=first;i--){
                        evaluar[contador]=word[i];
                        contador--;
                }
                if(isPrime(atoi(evaluar)))
                        return true;
                else
                        return false;
        }else{
                for(int i = end;i >=first;i--){
                        evaluar[contador]=word[i];
                        contador--;
                }
                if(isPrime(atoi(evaluar))){
                        rightToLeft(word,first,end-1);
                }else{
                        return false;
                }
        }

}

