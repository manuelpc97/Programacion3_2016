#include <iostream>
#include <ncurses.h>

using std::cout;
using std::endl;
using std::cin;

class pieza{
	public:
		bool blanca;
		bool vacia;
		bool isPeon;
		bool isTorre;
		bool isAlfil;
		bool isCaballo;
		bool isDama;
		bool isRey;
		
		pieza(){}
		pieza(bool b, bool n, bool p, bool t, bool a, bool c, bool d, bool r) : blanca(b), vacia(n), isPeon(p),
		isTorre(t), isAlfil(a), isCaballo(c), isDama(d), isRey(r){}
		
		void setVacia(bool);
		void setPeon(bool);
		void setTorre(bool);
		void setAlfil(bool);
		void setCaballo(bool);
		void setDama(bool);
		void setRet(bool);
};

pieza** crearPiezas();
void llenarTablero(pieza**);
void mostrarTablero(pieza**);
void pedirMovimiento(char*);
int lettersToNumbers(char);
int verifyNextSquare(int, int, pieza**,int);
int verifyCurrentSquare(int, int, int, pieza**);

int main(int argc, char*argv[]){
	pieza** piezas = crearPiezas();
	char* coordenadas;
	bool jugar = true;
	int turno = 1;

	llenarTablero(piezas);	

	while(jugar){
		if(turno==1){
			mostrarTablero(piezas);
			cout<<"-----------------Jugador 1------------------"<<endl;
			pedirMovimiento(coordenadas);
			turno=2;
		}else if(turno=2){
			mostrarTablero(piezas);
			cout<<"-----------------JUgador 2------------------"<<endl;
			pedirMovimiento(coordenadas);
			turno=1;
		}
	}	
	return 0;
}

//Setters de la clase
void pieza :: setVacia(bool m){
	vacia = m;
}

void pieza :: setPeon(bool m){
	isPeon=m;
}

void pieza :: setTorre(bool m){
	isTorre = m;
}

void pieza :: setAlfil(bool m){
	isAlfil = m;
}

void pieza :: setCaballo(bool m){
	isCaballo = m;
}

void pieza :: setDama(bool m){
	isDama = m;
}
		
void pieza :: setRet(bool m){
	isRey = m;
}
//*************************************************************************************

pieza** crearPiezas(){
	pieza** piezas = new pieza*[8];
	for(int i = 0; i<8; i++){
		piezas[i] = new pieza[8];
	}

	return piezas;
}

void llenarTablero(pieza** piezas){
	for(int i = 0; i < 8; i++){
		for(int j = 0; j <8; j++){
			if(i==1){
				piezas[i][j]=pieza(false,false,true,false,false,false,false,false);
			}else if(i==6){
				piezas[i][j]=pieza(true,false,true,false,false,false,false,false);
			}else if((i == 0 && j==0)||(i==0 && j==7)){
				piezas[i][j]=pieza(false,false,false,true,false,false,false,false);
			}else if((i==7 && j==0)||(i==7 && j==7)){
				piezas[i][j]=pieza(true,false,false,true,false,false,false,false);
			}else if((i == 0 && j == 1)||(i == 0 && j == 6)){
				piezas[i][j]=pieza(false,false,false,false,false,true,false,false);
			}else if((i == 7 && j == 1)||(i == 7 && j ==6)){
				piezas[i][j]=pieza(true,false,false,false,false,true,false,false);
			}else if((i == 0 && j == 2)||(i == 0 && j == 5)){
                                piezas[i][j]=pieza(false,false,false,false,true,false,false,false);
                        }else if((i == 7 && j == 2)||(i == 7 && j ==5)){
                                piezas[i][j]=pieza(true,false,false,false,true,false,false,false);
                        }else if((i == 0 && j == 3)){
                                piezas[i][j]=pieza(false,false,false,false,false,false,true,false);
                        }else if((i == 7 && j == 4)){
                                piezas[i][j]=pieza(true,false,false,false,false,false,true,false);
                        }else if((i == 0 && j == 4)){
                                piezas[i][j]=pieza(false,false,false,false,false,false,false,true);
                        }else if((i == 7 && j == 3)){
                                piezas[i][j]=pieza(true,false,false,false,false,false,false,true);
                        }else{
				 piezas[i][j]=pieza(false,true,false,false,false,false,false,false);
			}
		}
	}
}

/*void mostrarTablero(pieza** tablero){
	int row, column;
	initscr();
	getyx(stdscr,row,column);
	start_color();
	init_pair(0, COLOR_BLACK,COLOR_WHITE);
	init_pair(7,COLOR_WHITE,COLOR_BLACK);
	for(int i = 0; i<8; i++){
		for(int j = 0; j < 8; j++){
			if(tablero[i][j].isPeon && tablero[i][j].blanca){
				attron(COLOR_PAIR(7));
				printw("[P]");
				attroff(COLOR_PAIR(7));
			}else if(tablero[i][j].isAlfil && tablero[i][j].blanca){
				attron(COLOR_PAIR(7));
                                printw("[A]");
                                attroff(COLOR_PAIR(7));
			}else if(tablero[i][j].isCaballo && tablero[i][j].blanca){
                                attron(COLOR_PAIR(7));
                                printw("[C]");
                                attroff(COLOR_PAIR(7));
                        }else if(tablero[i][j].isTorre && tablero[i][j].blanca){
                                attron(COLOR_PAIR(7));
                                printw("[T]");
                                attroff(COLOR_PAIR(7));
                        }else if(tablero[i][j].isDama && tablero[i][j].blanca){
                                attron(COLOR_PAIR(7));
                                printw("[D]");
                                attroff(COLOR_PAIR(7));
                        }else if(tablero[i][j].isRey && tablero[i][j].blanca){
                                attron(COLOR_PAIR(7));
                                printw("[R]");
                                attroff(COLOR_PAIR(7));
                        }else if(tablero[i][j].vacia){
                                attron(COLOR_PAIR(7));
                                printw("[ ]");
                                attroff(COLOR_PAIR(7));
                        }else if(tablero[i][j].isPeon && tablero[i][j].blanca==false){
                                attron(COLOR_PAIR(0));
                                printw("[P]");
                                attroff(COLOR_PAIR(0));
                        }else if(tablero[i][j].isAlfil && tablero[i][j].blanca==false){
                                attron(COLOR_PAIR(0));
                                printw("[A]");
                                attroff(COLOR_PAIR(0));
                        }else if(tablero[i][j].isCaballo && tablero[i][j].blanca==false){
                                attron(COLOR_PAIR(0));
                                printw("[C]");
                                attroff(COLOR_PAIR(0));
                        }else if(tablero[i][j].isTorre && tablero[i][j].blanca==false){
                                attron(COLOR_PAIR(0));
                                printw("[T]");
                                attroff(COLOR_PAIR(0));
                        }else if(tablero[i][j].isDama && tablero[i][j].blanca==false){
                                attron(COLOR_PAIR(0));
                                printw("[D]");
                                attroff(COLOR_PAIR(0));
                        }else if(tablero[i][j].isRey && tablero[i][j].blanca==false){
                                attron(COLOR_PAIR(0));
                                printw("[R]");
                                attroff(COLOR_PAIR(0));
                        }else if(tablero[i][j].vacia){
                                attron(COLOR_PAIR(0));
                                printw("[ ]");
                                attroff(COLOR_PAIR(0));
                        }

		}
		column++;
		move(column,row);
	}
	getch();
	endwin();
}*/

void mostrarTablero(pieza** tablero){
	int contador=8;
	for(int i = 0; i < 8; i++){
		cout<<contador<<" ";
		contador--;
		for(int j = 0; j < 8; j++){
			if(tablero[i][j].isPeon){
                                cout<<"[P]"; 
                        }else if(tablero[i][j].isAlfil){
                                cout<<"[A]";
                        }else if(tablero[i][j].isCaballo){
                                cout<<"[C]";
                        }else if(tablero[i][j].isTorre){
                                cout<<"[T]";
                        }else if(tablero[i][j].isDama){
                                cout<<"[D]";
                        }else if(tablero[i][j].isRey){
                                cout<<"[R]";
                        }else if(tablero[i][j].vacia){
                                cout<<"[ ]";
                        }			
		}
		cout<<endl;	
	}
	cout<<"   A  B  C  D  E  F  G  H"<<endl;	
}

void pedirMovimiento(char* coordenadas){
	cout<<"Ingrese su movimiento"<<endl
	<<"Primero la coordenada donde esta seguido de adonde quiere mover, sin espacios"<<endl;
	cin>>coordenadas;
}

int lettersToNumbers(char letra){
	if(letra=='A'){
		return 0;
	}if(letra=='B'){
		return 1;
        }if(letra=='C'){
		return 2;
        }if(letra=='D'){
		return 3;
        }if(letra=='E'){
		return 4;
        }if(letra=='F'){
		return 5;
        }if(letra=='G'){
		return 6;
        }if(letra=='H'){
		return 7;
        }
}

int verifyNextSquare(int x, int y, pieza** tablero, int jugador){
	if(jugador==1){
		if(tablero[x][y].vacia){
			return 1;
		}else if(tablero[x][y].vacia==false && tablero[x][y].blanca==false){
			return 2;
		}else if(tablero[x][y].vacia==false && tablero[x][y].blanca){
			return 3;
		}
	}else if(jugador==2){
		if(tablero[x][y].vacia){
                        return 1;
                }else if(tablero[x][y].vacia==false && tablero[x][y].blanca){
                        return 2;
                }else if(tablero[x][y].vacia==false && tablero[x][y].blanca==false){
                        return 3;
                }

	}	
}

int verifyCurrentSquare(int x, int y, int jugador, pieza** tablero){

}
