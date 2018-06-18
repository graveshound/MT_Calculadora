#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <vector>

#define SUMA  1
#define RESTA  2
#define MULTIPLICACION  3
#define DIVISION  4

using namespace std;

void gotoxy(int x, int y);
int menu(bool withAnim);
void color(int color);


//retraso de animacion
int delay = 100 ;

//desplazar cabezal
void moverIzquierda(int y);
void moverDerecha(int y);

//operaciones
void operacion(int opt);
void sumar();
void multiplicar();
void dividir();
void restar();

//estados suma
void sum_q0(vector<string> cinta, int y);
void sum_q1(vector<string> cinta, int y);
void sum_q2(vector<string> cinta, int y);
void sum_q3(vector<string> cinta, int y);
void sum_q4(vector<string> cinta, int y);

//estados multiplicacion
void mul_q0(vector<string> cinta, int y);
void mul_q1(vector<string> cinta, int y);
void mul_q2(vector<string> cinta, int y);
void mul_q3(vector<string> cinta, int y);
void mul_q4(vector<string> cinta, int y);
void mul_q5(vector<string> cinta, int y);
void mul_q6(vector<string> cinta, int y);
void mul_q7(vector<string> cinta, int y);
void mul_q8(vector<string> cinta, int y);
void mul_q9(vector<string> cinta, int y);
void mul_q10(vector<string> cinta, int y);
void mul_q11(vector<string> cinta, int y);
void mul_q12(vector<string> cinta, int y);
void mul_q13(vector<string> cinta, int y);
void mul_q14(vector<string> cinta, int y);
void mul_q15(vector<string> cinta, int y);
void mul_q16(vector<string> cinta, int y);

//estados division
void div_q0(vector<string> cinta, int y);
void div_q1(vector<string> cinta, int y);
void div_q2(vector<string> cinta, int y);
void div_q3(vector<string> cinta, int y);
void div_q4(vector<string> cinta, int y);
void div_q5(vector<string> cinta, int y);
void div_q6(vector<string> cinta, int y);
void div_q7(vector<string> cinta, int y);
void div_q8(vector<string> cinta, int y);
void div_q9(vector<string> cinta, int y);
void div_q10(vector<string> cinta, int y);
void div_q11(vector<string> cinta, int y);
void div_q12(vector<string> cinta, int y);
void div_q13(vector<string> cinta, int y);
void div_q14(vector<string> cinta, int y);
void div_q15(vector<string> cinta, int y);
void div_q16(vector<string> cinta, int y);
void div_q17(vector<string> cinta, int y);
void div_q18(vector<string> cinta, int y);
void div_q19(vector<string> cinta, int y);

//estados resta
void res_q0(vector<string> cinta, int y);
void res_q1(vector<string> cinta, int y);
void res_q2(vector<string> cinta, int y);
void res_q3(vector<string> cinta, int y);
void res_q4(vector<string> cinta, int y);
void res_q5(vector<string> cinta, int y);
void res_q6(vector<string> cinta, int y);
void res_q7(vector<string> cinta, int y);
void res_q8(vector<string> cinta, int y);
void res_q9(vector<string> cinta, int y);
void res_q10(vector<string> cinta, int y);
void res_q11(vector<string> cinta, int y);
void res_q12(vector<string> cinta, int y);
void res_q13(vector<string> cinta, int y);
void res_q14(vector<string> cinta, int y);
void res_q15(vector<string> cinta, int y);
void res_q16(vector<string> cinta, int y);
void res_q17(vector<string> cinta, int y);
void res_q18(vector<string> cinta, int y);
void res_q19(vector<string> cinta, int y);
void res_q20(vector<string> cinta, int y);
void res_q21(vector<string> cinta, int y);
void res_q22(vector<string> cinta, int y);
void res_q23(vector<string> cinta, int y);
void res_q24(vector<string> cinta, int y);
void res_q25(vector<string> cinta, int y);

//variable del cabezal
int cabezal;
int index;
string cabezalSimbolo = "^";


int main(){
	int a;
	while(a != 9){
		cabezal = 13;
		index = 1;
		system("cls");
		a = menu(false);
		operacion(a);
		gotoxy(5,15);color(4);cout<<"Volviendo al menu principal...\n";
		gotoxy(5,16);
		system("pause");
	}	
	gotoxy(0,20);
	system("pause");
	return(0);
}


void operacion(int opt){
	switch(opt){
		case SUMA:
			sumar();
			break;
		case MULTIPLICACION:
			multiplicar();
			break;
		case DIVISION:
			dividir();
			break;
		case RESTA:
			restar();
			break;
	}
}


/////////////////////////////////////////////////////////////////////////////
////////////////////////////////// RESTA ////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

void restar(){
	char title[] = "# # # Resta # # # ";
	system("cls");
	int key;
	int xaxis = 12;
	string mult = "-";
	bool isNotPlus;
	vector<string> cinta(0);
	cinta.push_back("#");
	
	gotoxy(5,1);
	for(int x = 0; x<20; x++){
		color(x%5);cout<<"- ";
	}
	gotoxy(5, 3);
	for(int x = 1; x<=20; x++){
		color(x%5);cout<<"- ";
	}	
	for(int i=20; i>15; i--)
		for(int j=0; j<strlen(title); j++){
			Sleep(4);
			gotoxy(i,2);color(4);cout<<title;
		}
	gotoxy(5,5);color(4);cout<<"Cinta";
	gotoxy(xaxis++,6);color(6);cout<<cinta[0];
	while(1){
		key = getch();
		if(key == 0x31){
			cinta.push_back("1");
			gotoxy(xaxis++,6);cout<<"1";			
		}
		else if(key == 0x08){			
			if(xaxis-1>12){
				if(cinta[cinta.size()-1] == "-"){
					isNotPlus = true;
				}
				cinta.pop_back();
				gotoxy(--xaxis, 6);cout<<" ";			
			}
		}
		else if(key == 0x2D){
			for(int i=0;i<cinta.size(); i++)
				if(cinta[i] == mult) {
					isNotPlus = false;
					break;
				}					
			if(isNotPlus){
				cinta.push_back("-");
				gotoxy(xaxis++,6);cout<<"-";
			}

		}
		else if(key == 0x0D){
			cinta.push_back("#");
			gotoxy(xaxis++, 6);cout<<"#";
			break;
		}
	}
	gotoxy(5,8);color(4);cout<<"Procesando...";
	gotoxy(12,9);color(6);
	for(int i=0; i<cinta.size();i++)
		cout<<cinta[i];
	
	gotoxy(11,10);cout<<" "<<cabezalSimbolo;
	Sleep(delay);
	gotoxy(12,10);cout<<" "<<cabezalSimbolo;
	res_q0(cinta, 10);
}

void res_q0(vector<string> cinta, int y){
	while(cinta[index] == "1" || cinta[index] == "-"){
		moverDerecha(y);
	}
	if(cinta[index] == "#"){
		cinta[index] = "=";
		cinta.push_back("#");
		gotoxy(cabezal, y-1);cout<<"=";
		gotoxy(cabezal+1,y-1);cout<<"#";
		moverIzquierda(y);
		res_q1(cinta, y);
	}
}

void res_q1(vector<string> cinta, int y){
	if(cinta[index] == "1"){
		cinta[index] = "X";
		gotoxy(cabezal, y-1);cout<<"X";
		moverIzquierda(y);
		res_q2(cinta, y);
	}else if(cinta[index] == "-"){
		moverIzquierda(y);
		res_q6(cinta, y);
	}
}

void res_q2(vector<string> cinta, int y){
	while(cinta[index] == "1" || cinta[index] == "-"){
		moverIzquierda(y);
	}
	if(cinta[index] == "Y" || cinta[index] == "#"){
		moverDerecha(y);
		res_q3(cinta, y);
	}
}

void res_q3(vector<string> cinta, int y){
	if(cinta[index] == "-"){
		moverDerecha(y);
		res_q17(cinta, y);
	}else if(cinta[index] == "1"){
		cinta[index] = "Y";
		gotoxy(cabezal, y-1);cout<<"Y";
		moverDerecha(y);
		res_q4(cinta, y);
	}
}

void res_q4(vector<string> cinta, int y){
	while(cinta[index] == "-" || cinta[index] == "1"){
		moverDerecha(y);
	}
	if(cinta[index] == "X"){
		moverIzquierda(y);
		res_q5(cinta, y);
	}
}

void res_q5(vector<string> cinta, int y){
	if(cinta[index] == "1"){
		cinta[index] = "X";
		gotoxy(cabezal, y-1);cout<<"X";
		moverIzquierda(y);
		res_q2(cinta, y);
	}else if(cinta[index] == "-"){
		moverIzquierda(y);
		res_q6(cinta, y);
	}
}

void res_q6(vector<string> cinta, int y){
	while(cinta[index] == "1"){
		moverIzquierda(y);
	}
	if(cinta[index] == "#" || cinta[index] == "Y"){
		moverDerecha(y);
		res_q7(cinta, y);
	}
}

void res_q7(vector<string> cinta, int y){
	if(cinta[index] == "1"){
		cinta[index] = "0";
		gotoxy(cabezal, y-1);
		moverDerecha(y);
		res_q8(cinta, y);
	}else if(cinta[index] == "-"){
		moverDerecha(y);
		res_q15(cinta, y);
	}
}

void res_q8(vector<string> cinta, int y){
	while(cinta[index] == "1"){
		moverDerecha(y);
	}
	if(cinta[index] == "-"){
		moverDerecha(y);
		res_q9(cinta, y);
	}
}

void res_q9(vector<string> cinta, int y){
	while(cinta[index] == "X"){
		moverDerecha(y);
	}
	if(cinta[index] == "="){
		moverDerecha(y);
		res_q10(cinta, y);
	}
}

void res_q10(vector<string> cinta, int y){
	while(cinta[index] == "1"){
		moverDerecha(y);
	}
	if(cinta[index] == "#"){
		cinta[index] = "1";
		cinta.push_back("#");
		gotoxy(cabezal, y-1);cout<<"1";
		gotoxy(cabezal+1, y-1);cout<<"#";
		moverIzquierda(y);
		res_q11(cinta, y);
	}
}

void res_q11(vector<string> cinta, int y){
	while(cinta[index] == "1"){
		moverIzquierda(y);
	}
	if(cinta[index] == "="){
		moverIzquierda(y);
		res_q12(cinta, y);
	}
}

void res_q12(vector<string> cinta, int y){
	while(cinta[index] == "X"){
		moverIzquierda(y);
	}
	if(cinta[index] == "-"){
		moverIzquierda(y);
		res_q13(cinta, y);
	}
}

void res_q13(vector<string> cinta, int y){
	while(cinta[index] == "1"){
		moverIzquierda(y);
	}
	if(cinta[index] == "0"){
		moverDerecha(y);
		res_q7(cinta, y);
	}
}

void res_q14(vector<string> cinta, int y){
	if(cinta[index] == "#"){
		cinta[index] = "1";
		cinta.push_back("#");
		gotoxy(cabezal, y-1);cout<<"1";
		gotoxy(cabezal+1, y-1);cout<<"#";
		moverIzquierda(y);
		res_q21(cinta, y);
	}
}

void res_q15(vector<string> cinta, int y){
	while(cinta[index] == "X"){
		moverDerecha(y);
	}
	if(cinta[index] == "="){
		moverDerecha(y);
		res_q16(cinta, y);
	}
}

void res_q16(vector<string> cinta, int y){
	gotoxy(5, y+2);color(2);cout<<"Cinta procesada\n" ;	
}

void res_q17(vector<string> cinta, int y){
	if(cinta[index] == "1"){
		cinta[index] = "0";
		gotoxy(cabezal, y-1);cout<<"0";
		moverDerecha(y);
		res_q18(cinta, y);
	}else if(cinta[index] == "X"){
		cinta[index] = "0";
		gotoxy(cabezal, y-1);cout<<"0";
		moverDerecha(y);
		res_q19(cinta, y);
	}
}

void res_q18(vector<string> cinta, int y){
	while(cinta[index] == "1"){
		moverDerecha(y);
	}if(cinta[index] == "X"){
		cinta[index] = "1";
		gotoxy(cabezal, y-1);cout<<"1";
		moverDerecha(y);
		res_q19(cinta, y);
	}
}

void res_q19(vector<string> cinta, int y){
	while(cinta[index] == "1" || cinta[index] == "X"){
		moverDerecha(y);
	}
	if(cinta[index] == "="){
		moverDerecha(y);
		res_q20(cinta, y);
	}
}

void res_q20(vector<string> cinta, int y){
	while(cinta[index] == "-"){
		moverDerecha(y);
	}
	if(cinta[index] == "1"){
		moverDerecha(y);
		res_q25(cinta, y);
	}else if(cinta[index] == "#"){
		cinta[index] = "-";
		cinta.push_back("#");
		gotoxy(cabezal, y-1);cout<<"-";
		gotoxy(cabezal+1, y-1);cout<<"#";
		moverDerecha(y);
		res_q14(cinta, y);
	}	
}

void res_q21(vector<string> cinta, int y){
	while(cinta[index] == "-" || cinta[index] == "1"){
		moverIzquierda(y);
	}
	if(cinta[index] == "="){
		moverIzquierda(y);
		res_q22(cinta, y);
	}
}

void res_q22(vector<string> cinta, int y){
	while(cinta[index] == "X" || cinta[index] == "1"){
		moverIzquierda(y);
	}
	if(cinta[index] == "0"){
		moverDerecha(y);
		res_q23(cinta, y);
	}
}

void res_q23(vector<string> cinta, int y){
	if(cinta[index] == "="){
		moverDerecha(y);
		res_q16(cinta, y);
	}else if(cinta[index] == "0" || cinta[index] == "X"){
		moverDerecha(y);
		res_q24(cinta, y);
	}else if(cinta[index] == "1"){
		cinta[index] = "0";
		gotoxy(cabezal, y-1);cout<<"0";
		moverDerecha(y);
		res_q19(cinta, y);
	}
}

void res_q24(vector<string> cinta, int y){
	while(cinta[index] == "X"){
		moverDerecha(y);
	}
	if(cinta[index] == "="){
		res_q16(cinta, y);	
	}
}

void res_q25(vector<string> cinta, int y){
	while(cinta[index] == "1"){
		moverDerecha(y);
	}
	if(cinta[index] == "#"){
		cinta[index] = "1";
		cinta.push_back("#");
		gotoxy(cabezal, y-1);cout<<"1";
		gotoxy(cabezal+1, y-1);cout<<"#";
		moverIzquierda(y);
		res_q21(cinta, y);
	}
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////// DIVISION ////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////


void dividir(){
	char title[] = "# # # Division # # # ";
	system("cls");
	int key;
	int xaxis = 12;
	string mult = "/";
	bool isNotPlus;
	vector<string> cinta(0);
	cinta.push_back("#");
	
	gotoxy(5,1);
	for(int x = 0; x<20; x++){
		color(x%5);cout<<"- ";
	}
	gotoxy(5, 3);
	for(int x = 1; x<=20; x++){
		color(x%5);cout<<"- ";
	}	
	for(int i=20; i>15; i--)
		for(int j=0; j<strlen(title); j++){
			Sleep(4);
			gotoxy(i,2);color(4);cout<<title;
		}
	gotoxy(5,5);color(4);cout<<"Cinta";
	gotoxy(xaxis++,6);color(6);cout<<cinta[0];
	while(1){
		key = getch();
		if(key == 0x31){
			cinta.push_back("1");
			gotoxy(xaxis++,6);cout<<"1";			
		}
		else if(key == 0x08){			
			if(xaxis-1>12){
				if(cinta[cinta.size()-1] == "/"){
					isNotPlus = true;
				}
				cinta.pop_back();
				gotoxy(--xaxis, 6);cout<<" ";			
			}
		}
		else if(key == 0x2F){
			for(int i=0;i<cinta.size(); i++)
				if(cinta[i] == mult) {
					isNotPlus = false;
					break;
				}					
			if(isNotPlus){
				cinta.push_back("/");
				gotoxy(xaxis++,6);cout<<"/";
			}

		}
		else if(key == 0x0D){
			cinta.push_back("#");
			gotoxy(xaxis++, 6);cout<<"#";
			break;	
		}
	}
	gotoxy(5,8);color(4);cout<<"Procesando...";
	gotoxy(12,9);color(6);
	for(int i=0; i<cinta.size();i++)
		cout<<cinta[i];
	
	gotoxy(11,10);cout<<" "<<cabezalSimbolo;
	Sleep(delay);
	gotoxy(12,10);cout<<" "<<cabezalSimbolo;
	div_q0(cinta, 10);
}

void div_q0(vector<string> cinta, int y){
	if(cinta[index] == "1"){
		moverDerecha(y);
		div_q1(cinta, y);
	}else if(cinta[index] == "/"){
		moverDerecha(y);
		div_q19(cinta, y);
	}
}

void div_q1(vector<string> cinta, int y){
	while(cinta[index] == "1" || cinta[index] == "/"){
		moverDerecha(y);
	}
	if(cinta[index] == "#"){
		cinta[index] = "=";
		cinta.push_back("#");
		gotoxy(cabezal, y-1);cout<<"=";
		gotoxy(cabezal+1, y-1);cout<<"#";
		moverIzquierda(y);
		div_q2(cinta, y);
	}
}

void div_q2(vector<string> cinta, int y){
	if(cinta[index] == "/"){
		moverDerecha(y);
		div_q6(cinta, y);
	}else if(cinta[index] == "1"){
		cinta[index] = "X";
		gotoxy(cabezal, y-1);cout<<"X";
		moverIzquierda(y);
		div_q3(cinta, y);
	}
}

void div_q3(vector<string> cinta, int y){
	while(cinta[index] == "1" || cinta[index] == "/"){
		moverIzquierda(y);
	}
	if(cinta[index] == "Y" || cinta[index] == "#"){
		moverDerecha(y);
		div_q4(cinta, y);
	}
}

void div_q4(vector<string> cinta, int y){
	if(cinta[index] == "/"){
		moverDerecha(y);
		div_q9(cinta, y);
	}else if(cinta[index] == "1"){
		cinta[index] = "Y";
		gotoxy(cabezal, y-1);cout<<"Y";
		moverDerecha(y);
		div_q5(cinta, y);
	}
}

void div_q5(vector<string> cinta, int y){
	while(cinta[index] == "1" || cinta[index] == "/"){
		moverDerecha(y);
	}	
	if(cinta[index] == "X"){
		moverIzquierda(y);		
	}
	div_q2(cinta, y);
}

void div_q6(vector<string> cinta, int y){
	while(cinta[index] == "X"){
		cinta[index] = "1";
		gotoxy(cabezal, y-1);cout<<"1";
		moverDerecha(y);
	}
	if(cinta[index] == "="){
		moverDerecha(y);
		div_q7(cinta, y);
	}
}

void div_q7(vector<string> cinta, int y){
	while(cinta[index] == "1"){
		moverDerecha(y);
	}
	if(cinta[index] == "#"){
		cinta[index] = "1";
		cinta.push_back("#");
		gotoxy(cabezal, y-1);cout<<"1";
		gotoxy(cabezal+1, y-1);cout<<"#";
		moverIzquierda(y);
		div_q8(cinta, y);
	}
}

void div_q8(vector<string> cinta, int y){
	while(cinta[index] == "1"){
		moverIzquierda(y);
	}
	if(cinta[index] == "="){
		moverIzquierda(y);
		div_q2(cinta, y);
	}
}

void div_q9(vector<string> cinta, int y){
	while(cinta[index] == "1"){
		moverDerecha(y);
	}
	if(cinta[index] == "X"){
		cinta[index] = "1";
		gotoxy(cabezal, y-1);cout<<"1";
		moverDerecha(y);
		div_q10(cinta, y);
	}
}

void div_q10(vector<string> cinta, int y){
	while(cinta[index] == "X"){
		moverDerecha(y);
	}
	if(cinta[index] == "="){
		moverDerecha(y);
		div_q11(cinta, y);
	}
}

void div_q11(vector<string> cinta, int y){
	while(cinta[index] == "1"){
		moverDerecha(y);
	}
	if(cinta[index] == "#"){
		cinta[index] = "R";
		cinta.push_back("#");
		gotoxy(cabezal, y-1);cout<<"R";
		gotoxy(cabezal+1, y-1);cout<<"#";
		moverIzquierda(y);
		div_q12(cinta, y);
	}
}

void div_q12(vector<string> cinta, int y){
	while(cinta[index] == "1"  || cinta[index] == "=" || cinta[index] == "R"){
		moverIzquierda(y);
	}	
	if(cinta[index] == "X"){
		moverIzquierda(y);
		div_q13(cinta, y);
	}else if(cinta[index] == "/"){
		moverDerecha(y);
		div_q17(cinta, y);
	}
}

void div_q13(vector<string> cinta, int y){
	while(cinta[index] == "X"){
		moverIzquierda(y);
	}
	if(cinta[index] == "1"){
		moverDerecha(y);
		div_q16(cinta, y);
	}
}

void div_q14(vector<string> cinta, int y){
	while(cinta[index] == "1" || cinta[index] == "R"){
		moverDerecha(y);
	}
	if(cinta[index] == "#"){
		cinta[index] = "1";
		cinta.push_back("#");
		gotoxy(cabezal, y-1);cout<<"1";
		gotoxy(cabezal+1, y-1);cout<<"#";
		moverIzquierda(y);
		div_q12(cinta, y);
	}
}

void div_q15(vector<string> cinta, int y){
	while(cinta[index] == "X"){
		moverDerecha(y);
	}
	if(cinta[index] == "="){
		moverDerecha(y);
		div_q14(cinta, y);
	}
}

void div_q16(vector<string> cinta, int y){
	if(cinta[index] == "X"){
		cinta[index] = "1";
		gotoxy(cabezal, y-1);cout<<"1";
		moverDerecha(y);
		div_q15(cinta, y);
	}
}

void div_q17(vector<string> cinta, int y){
	while(cinta[index] == "1"){
		moverDerecha(y);
	}
	if(cinta[index] == "="){
		div_q18(cinta, y);
	}
}

void div_q18(vector<string> cinta, int y){
	gotoxy(5, y+2);color(2);cout<<"Cinta procesada\n" ;	
}

void div_q19(vector<string> cinta, int y){
	while(cinta[index] == "1"){
		moverDerecha(y);
	}
	if(cinta[index] == "#"){
		cinta[index] = "=";
		cinta.push_back("#");
		gotoxy(cabezal, y-1);cout<<"=";
		gotoxy(cabezal+1, y-1); cout<<"#";
		moverDerecha(y);
		div_q18(cinta, y);
	}
}

/////////////////////////////////////////////////////////////////////////////
///////////////////////// MULTIPLICACION ////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

void multiplicar(){
	char title[] = "# # # Multiplicacion # # # ";
	system("cls");
	int key;
	int xaxis = 12;
	string mult = "*";
	bool isNotPlus;
	vector<string> cinta(0);
	cinta.push_back("#");
	
	gotoxy(5,1);
	for(int x = 0; x<20; x++){
		color(x%5);cout<<"- ";
	}
	gotoxy(5, 3);
	for(int x = 1; x<=20; x++){
		color(x%5);cout<<"- ";
	}	
	for(int i=20; i>10; i--)
		for(int j=0; j<strlen(title); j++){
			Sleep(4);
			gotoxy(i,2);color(4);cout<<title;
		}
	gotoxy(5,5);color(4);cout<<"Cinta";
	gotoxy(xaxis++,6);color(6);cout<<cinta[0];
	while(1){
		key = getch();
		if(key == 0x31){
			cinta.push_back("1");
			gotoxy(xaxis++,6);cout<<"1";			
		}
		else if(key == 0x08){			
			if(xaxis-1>12){
				if(cinta[cinta.size()-1] == "*"){
					isNotPlus = true;
				}
				cinta.pop_back();
				gotoxy(--xaxis, 6);cout<<" ";			
			}
		}
		else if(key == 0x2A){
			for(int i=0;i<cinta.size(); i++)
				if(cinta[i] == mult) {
					isNotPlus = false;
					break;
				}					
			if(isNotPlus){
				cinta.push_back("*");
				gotoxy(xaxis++,6);cout<<"*";
			}

		}
		else if(key == 0x0D){
			cinta.push_back("#");
			gotoxy(xaxis++, 6);cout<<"#";
			break;		
		}
	}
	gotoxy(5,8);color(4);cout<<"Procesando...";
	gotoxy(12,9);color(6);
	for(int i=0; i<cinta.size();i++)
		cout<<cinta[i];
	
	gotoxy(11,10);cout<<" "<<cabezalSimbolo;
	Sleep(delay);
	gotoxy(12,10);cout<<" "<<cabezalSimbolo;
	mul_q0(cinta, 10);
}

void mul_q0(vector<string> cinta, int y){
	while(cinta[index] == "1"){
		moverDerecha(y);
	}
	if(cinta[index] == "*"){
		moverDerecha(y);
		mul_q1(cinta, y);
	}		
}

void mul_q1(vector<string> cinta, int y){
	while(cinta[index] == "1"){
		moverDerecha(y);
	}
	if(cinta[index] == "#"){
		cinta[index] = "=";
		cinta.push_back("#");
		gotoxy(cabezal,y-1);cout<<"=";
		gotoxy(cabezal+1, y-1);cout<<"#";
		moverIzquierda(y);
	}else if(cinta[index] == "X"){
		moverIzquierda(y);
	}
	mul_q2(cinta,y);
}

void mul_q2(vector<string> cinta, int y){
	if(cinta[index] == "1"){
		cinta[index] = "X";
		gotoxy(cabezal,y-1);cout<<"X";
		moverIzquierda(y);
		mul_q3(cinta, y);
	}else if(cinta[index] == "*"){
		moverDerecha(y);
		mul_q14(cinta, y);
	}
}

void mul_q3(vector<string> cinta, int y){
	while(cinta[index] == "1"){
		moverIzquierda(y);
	}
	if(cinta[index] == "*"){
		moverIzquierda(y);
		mul_q4(cinta, y);
	}	
}

void mul_q4(vector<string> cinta, int y){
	while(cinta[index] == "1"){
		moverIzquierda(y);
	}
	if(cinta[index] == "#"){
		moverDerecha(y);
		mul_q5(cinta, y);
	}
}

void mul_q5(vector<string> cinta, int y){
	if(cinta[index] == "1"){
		cinta[index] = "Y";
		gotoxy(cabezal, y-1);cout<<"Y";
		moverDerecha(y);
		mul_q6(cinta, y);
	}else if(cinta[index] == "*"){
		moverDerecha(y);
		mul_q16(cinta, y);
	}
}

void mul_q6(vector<string> cinta, int y){
	while(cinta[index] == "1"){
		moverDerecha(y);
	}
	if(cinta[index] == "*"){
		moverDerecha(y);
		mul_q7(cinta, y);
	}
}

void mul_q7(vector<string> cinta, int y){
	while(cinta[index] == "1" || cinta[index] == "X"){
		moverDerecha(y);
	}
	if(cinta[index] == "="){
		moverDerecha(y);
		mul_q8(cinta, y);
	}
}

void mul_q8(vector<string> cinta, int y){
	while(cinta[index] == "1"){
		moverDerecha(y);
	}
	if(cinta[index] == "#"){
		cinta[index] = "1";
		cinta.push_back("#");
		gotoxy(cabezal, y-1);cout<<"1";
		gotoxy(cabezal+1,y-1);cout<<"#";
		moverIzquierda(y);
		mul_q9(cinta, y);
	}
}

void mul_q9(vector<string> cinta, int y){
	while(cinta[index] == "1"){
		moverIzquierda(y);
	}
	if(cinta[index] == "="){
		moverIzquierda(y);
		mul_q10(cinta, y);
	}
}

void mul_q10(vector<string> cinta, int y){
	while(cinta[index] == "1" || cinta[index] == "X"){
		moverIzquierda(y);
	}
	if(cinta[index] == "*"){
		moverIzquierda(y);
		mul_q12(cinta, y);
	}
}

void mul_q11(vector<string> cinta, int y){
	if(cinta[index] == "1"){
		cinta[index] = "Y";
		gotoxy(cabezal, y-1);cout<<"Y";
		moverDerecha(y);
		mul_q6(cinta, y);
	}else if(cinta[index] == "*"){
		moverIzquierda(y);
		mul_q13(cinta, y);
	}
}

void mul_q12(vector<string> cinta, int y){
	while(cinta[index] == "1"){
		moverIzquierda(y);
	}
	if(cinta[index] == "Y"){
		moverDerecha(y);
		mul_q11(cinta, y);
	}
}

void mul_q13(vector<string> cinta, int y){
	while(cinta[index] == "Y"){
		cinta[index] = "1";
		gotoxy(cabezal, y-1);cout<<"1";
		moverIzquierda(y);
	}
	if(cinta[index] == "#"){
		moverDerecha(y);
		mul_q0(cinta, y);
	}
}

void mul_q14(vector<string> cinta, int y){
	while(cinta[index] == "X"){
		moverDerecha(y);
	}
	if(cinta[index] == "="){
		moverDerecha(y);
		mul_q15(cinta, y);
	}		
}

void mul_q15(vector<string> cinta, int y){
	gotoxy(5, y+2);color(2);cout<<"Cinta procesada\n" ;
}

void mul_q16(vector<string> cinta, int y){
	while(cinta[index] == "1" || cinta[index] == "X"){
		if(cinta[index] == "X"){
			cinta[index] = "1";
			gotoxy(cabezal, y-1);cout<<"1";
			moverDerecha(y);
		}else{
			moverDerecha(y);
		}
	}
	if(cinta[index] == "="){
		moverDerecha(y);
		mul_q15(cinta, y);
	}
}

/////////////////////////////////////////////////////////////////////////////
////////////////////////////// SUMA /////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

void sumar(){
	char title[] = "# # # Suma # # # ";
	system("cls");
	int key;
	int xaxis = 12;
	string plus = "+";
	bool isNotPlus;
	vector<string> cinta(0);
	cinta.push_back("#");
	
	gotoxy(5,1);
	for(int x = 0; x<20; x++){
		color(x%5);cout<<"- ";
	}
	gotoxy(5, 3);
	for(int x = 1; x<=20; x++){
		color(x%5);cout<<"- ";
	}	
	for(int i=20; i>15; i--)
		for(int j=0; j<strlen(title); j++){
			Sleep(4);
			gotoxy(i,2);color(4);cout<<title;
		}
	gotoxy(5,5);color(4);cout<<"Cinta";
	gotoxy(xaxis++,6);color(6);cout<<cinta[0];
	while(1){
		key = getch();
		if(key == 0x31){
			cinta.push_back("1");
			gotoxy(xaxis++,6);cout<<"1";			
		}
		else if(key == 0x08){			
			if(xaxis-1>12){
				if(cinta[cinta.size()-1] == "+"){
					isNotPlus = true;
				}
				cinta.pop_back();
				gotoxy(--xaxis, 6);cout<<" ";			
			}
		}
		else if(key == 0x2B){
			for(int i=0;i<cinta.size(); i++)
				if(cinta[i] == plus) {
					isNotPlus = false;
					break;
				}					
			if(isNotPlus){
				cinta.push_back("+");
				gotoxy(xaxis++,6);cout<<"+";
			}

		}
		else if(key == 0x0D){
			cinta.push_back("#");
			gotoxy(xaxis++, 6);cout<<"#";
			break;			
		}
	}
	gotoxy(5,8);color(4);cout<<"Procesando...";
	gotoxy(12,9);color(6);
	for(int i=0; i<cinta.size();i++)
		cout<<cinta[i];
	
	gotoxy(11,10);cout<<" "<<cabezalSimbolo;
	Sleep(delay);
	gotoxy(12,10);cout<<" "<<cabezalSimbolo;
	sum_q0(cinta, 10);
}

void sum_q0(vector<string> cinta, int y){
	while(cinta[index] == "1" || cinta[index] == "+"){
		moverDerecha(y);	
	}
	cinta[index] = "=";
	cinta.push_back("#");
	gotoxy(cabezal,y-1);cout<<"=";
	gotoxy(cabezal+1,y-1);cout<<"#";
	sum_q1(cinta, y);
}

void sum_q1(vector<string> cinta, int y){
	while(cinta[index] == "=" || cinta[index] == "1" || cinta[index] == "+"){
		moverIzquierda(y);
	}
	if(cinta[index] == "#" || cinta[index] == "X"){
		moverDerecha(y);
		sum_q2(cinta, y);
	}
}

void sum_q2(vector<string> cinta, int y){
	while(cinta[index] == "+"){
		moverDerecha(y);
	}if(cinta[index] == "="){
		sum_q4(cinta, y);
	}
	else if(cinta[index] == "1"){
		cinta[index] = "X";
		gotoxy(cabezal, y-1);cout<<"X";
		moverDerecha(y);
		sum_q3(cinta, y);
	}
}

void sum_q3(vector<string> cinta, int y){
	while(cinta[index] == "=" || cinta[index] == "+" || cinta[index] == "1"){
		moverDerecha(y);
	}
	cinta[index] = "1";
	cinta.push_back("#");
	gotoxy(cabezal, y-1);cout<<"1";
	gotoxy(cabezal+1, y-1);cout<<"#";
	moverIzquierda(y);
	sum_q1(cinta, y);
}

void sum_q4(vector<string> cinta, int y){
	gotoxy(5, y+2);color(2);cout<<"Cinta procesada\n" ;
}

/////////////////////////////////////////////////////////////////////////////
/////////////////// OPERACIONES DE MANIPULACION  ////////////////////////////
/////////////////////////////////////////////////////////////////////////////

void moverIzquierda(int y){
	Sleep(delay);
	index--;
	gotoxy(cabezal, y);cout<<" ";
	gotoxy(--cabezal,y);cout<<cabezalSimbolo;
}

void moverDerecha(int y){
	Sleep(delay);
	index++;
	gotoxy(cabezal,y);cout<<" ";
	gotoxy(++cabezal,y);cout<<cabezalSimbolo;
}

 void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 } 
 
void color(int color){
    HWND CurrentWin;
    CurrentWin = GetForegroundWindow();
    HANDLE consol;
    consol = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consol,
		color == 0 ? FOREGROUND_RED ://RED
		color == 1 ? FOREGROUND_BLUE ://BLUE
		color == 2 ? FOREGROUND_GREEN: //GREEN
		color == 3 ? FOREGROUND_GREEN | FOREGROUND_BLUE : //DARKCYAN
		color == 4 ? FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN :	//YELLOW
		color == 5 ? FOREGROUND_INTENSITY | FOREGROUND_BLUE ://BLUE
		FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//WHITE;
}

void ejecutar(){
	system("cls");
}

int menu(bool withAnim){
	char title[]= "# # # Maquinas de turing # # # ";
	int key = 0, row = 5;
		
	gotoxy(5,1);
	for(int x = 0; x<20; x++){
		color(x%5);cout<<"- ";
	}
	gotoxy(5, 3);
	for(int x = 1; x<=20; x++){
		color(x%5);cout<<"- ";
	}

	gotoxy(8,5);color(0);cout<<"[ ] ";color(4);cout<<"Suma";gotoxy(9,5);color(2);cout<<"1";
	gotoxy(8,6);color(0);cout<<"[ ] ";color(4);cout<<"Resta";gotoxy(9,6);color(2);cout<<"2";
	gotoxy(8,7);color(0);cout<<"[ ] ";color(4);cout<<"Multiplicacion";gotoxy(9,7);color(2);cout<<"3";
	gotoxy(8,8);color(0);cout<<"[ ] ";color(4);cout<<"Division";gotoxy(9,8);color(2);cout<<"4";
	gotoxy(8,9);color(0);cout<<"[ ] ";color(4);cout<<"Salir";gotoxy(9,9);color(2);cout<<"5";
	if(withAnim){
		for(int i=20; i>9; i--)
			for(int j=0; j<strlen(title); j++){
				Sleep(3);
				gotoxy(i,2);color(4);cout<<title;
			}	
	}else{
		gotoxy(9,2);color(4);cout<<title;
	}
	gotoxy(35,5);cout<<"<-";
	if(GetKeyState('A')){
		gotoxy(35, 5);cout<<" ";
	}
	while(1){
		key=getch();
		if(key == 224){
			key = getch();
			if(key == 0x48){
				gotoxy(35,row);cout<<"  ";
				row = row-1 < 5 ? 5:row-1;
				gotoxy(35,row);cout<<"<-";	//UP	
			}				
			else if(key == 0x50){
				gotoxy(35,row);cout<<"  ";
				row = row+1 > 9 ? 9:row+1;
				gotoxy(35,row);cout<<"<-";	//DOWN
			}
		}
		else if(key == 0x0D){
			switch(row){
				case 5: return SUMA;
				case 6: return RESTA;
				case 7:	return MULTIPLICACION;
				case 8:	return DIVISION;
				case 9: exit(0);
			}
		}			
	}
}
