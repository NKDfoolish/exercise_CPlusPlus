#include <iostream>
#include "mylib.h"
#define MAX 100
using namespace std;
int toa_dox[MAX] = {};
int toa_doy[MAX] = {};
int sl = 4;
int x_Qua = -1;
int y_Qua = -1;
//---------------------------------
void ve_Tuong();
void play();
void khoi_Tao_Ran();
void ve_Ran();
void di_Chuyen_Ran(int x, int y);
bool game_Over();
void tao_Qua();
void ve_Qua();
bool kiem_Tra_Ran_An_Qua();
void xu_Ly_Ran_An_Qua();
bool kt_Ran_Cham_Than();
//---------------------------------
void main()
{
	/*
	- random trong doan [1;20]

	srand(time(NULL)); //tao hat giong cho rand() - dam bao moi lan chay chuong trinh rand() se khac nhau
	for (int i = 0; i <= 10; i++)
	{
		int b = rand() % (20 - 10 + 1) + 10;
		cout << b << endl;
	}
	*/

	srand(time(NULL)); //tao hat giong cho rand() - dam bao moi lan chay chuong trinh rand() se khac nhau
	play();
	_getch();
}
void ve_Tuong() {
	char c_1 = 205;
	char c_2 = 186;
	char c_3 = 200;
	char c_4 = 188;
	char c_5 = 187;
	char c_6 = 201;
	for (int x = 10; x <= 95; x++)
	{
		gotoXY(x, 1);
		cout << c_1;
		gotoXY(x, 25);
		cout << c_1;
	}
	for (int y = 1; y <= 25; y++) {
		gotoXY(10, y);
		cout << c_2;
		gotoXY(95, y);
		cout << c_2;
	}
	// xu ly cac goc tuong (tham my)
	gotoXY(10, 25);
	cout << c_3;
	gotoXY(95, 25);
	cout << c_4;
	gotoXY(95, 1);
	cout << c_5;
	gotoXY(10, 1);
	cout << c_6;
}
void play() {
	ShowCur(0);// an con tro
	SetColor(13);// doi mau
	//BUILD GAME
	//---------------- SETTING -----------------
	ve_Tuong();
	khoi_Tao_Ran();
	tao_Qua();
	ve_Qua();
	// x,y la huong di chuyen ke tiep cua ran
	int x = toa_dox[0];
	int y = toa_doy[0];
	int check = 2;  //0: di xuong
					//1: di len
					//2: di qua phai
					//3: di qua trai
	//-------------------- Play -----------------
	while (true) {
		//---------- clear data cu -----------
		gotoXY(toa_dox[sl], toa_doy[sl]);
		cout << " ";
		//------ in --------
		ve_Ran();
		//------- dieu khien ------
		if (_kbhit()) {
			char c = _getch();
			if (c == -32) {
				c = _getch();
				if (c == 72 && check != 0) {
					check = 1;
				}
				else if (c == 80 && check != 1) {
					check = 0;
				}
				else if (c == 75 && check != 2) {
					check = 3;
				}
				else if (c == 77 && check != 3) {
					check = 2;
				}
			}
		}
		//--------- di chuyen ----------
		if (check == 0) {
			y++;
		}
		else if (check == 1) {
			y--;
		}
		else if (check == 2) {
			x++;
		}
		else if (check == 3) {
			x--;
		}
		//------------- bien -------------
		if (game_Over()) {
			break;
		}
		xu_Ly_Ran_An_Qua();
		//-------- xu ly ran ----------
		di_Chuyen_Ran(x, y);
		//--------- speed --------
		if (check == 2 || check == 3)
		{
			Sleep(50);
		}
		else {
			Sleep(125);
		}
	}
}
void khoi_Tao_Ran() {
	//cho con ran chay bat dau tu giua man hinh
	int x_khoi_tao = 50;
	int y_khoi_tao = 13;
	//moi vo con ran se nam ngang theo chieu tu trai sang phai
	for (int i = 0; i < sl; i++) {
		toa_dox[i] = x_khoi_tao--;
		toa_doy[i] = y_khoi_tao;
	}
}
void ve_Ran() {
	char head = 3;// dau con ran
	for (int i = 0; i < sl; i++) {
		gotoXY(toa_dox[i], toa_doy[i]);
		if (i == 0) {
			cout << head;
		}
		else {
			cout << "*";
		}
	}
}
void di_Chuyen_Ran(int x, int y) {
	for (int i = sl; i > 0; i--) {
		toa_dox[i] = toa_dox[i-1];
		toa_doy[i] = toa_doy[i-1];
	}
	toa_dox[0] = x;
	toa_doy[0] = y;
}
bool kt_Ran_Cham_Than() {
	for (int i = 1; i <= sl - 1; i++) {
		if (toa_dox[0] == toa_dox[i] && toa_doy[0] == toa_doy[i]) {
			return true;
		}
	}
	return false;
}
bool game_Over() {
	if (toa_dox[0] == 10 || toa_dox[0] == 95 || toa_doy[0] == 1 || toa_doy[0] == 25) {
		return true;
	}
	return kt_Ran_Cham_Than();
}
bool kt_Ran_De_Qua() {
	for (int i = 0; i < sl; i++) {
		if (x_Qua == toa_dox[i] && y_Qua == toa_doy[i]) {
			return true;
		}
	}
	return false;
}
void tao_Qua() {
	do
	{
		x_Qua = rand() % (94 - 11 + 1) + 11;
		y_Qua = rand() % (24 - 2 + 1) + 2;
	} while (kt_Ran_De_Qua());

}
void ve_Qua() {
	gotoXY(x_Qua, y_Qua);
	cout << "*";
}
bool kiem_Tra_Ran_An_Qua() {
	return (toa_dox[0] == x_Qua && toa_doy[0] == y_Qua);
}
void xu_Ly_Ran_An_Qua() {
	if (kiem_Tra_Ran_An_Qua()) {
		sl++;// tang dot
		// tao qua moi
		tao_Qua();
		ve_Qua();
	}
}
/*
"Hành trình vạn dặm bắt đầu từ một bước chân" ~ lão Tử
*/