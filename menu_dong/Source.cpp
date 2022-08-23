#include <iostream>
#include <string>
#include "mylib.h"
using namespace std;

int x = 40, y = 5;

void box(int x, int y, int w, int h, int t_color, int b_color, string text);
void n_box(int x, int y, int w, int h, int t_color, int b_color, string text, int sl_box);
void menu();
void thanh_sang(int x, int y, int w, int h, int b_color, string text);

int main() {
	menu();
	
	_getch();
}
void menu() {
	ShowCur(0);
	//========== setting =============
	int w = 20;
	int h = 2;
	int t_color = 11;
	int b_color = 1;
	int b_color_sang = 75;
	string text = "Hello";
	int sl_box = 4;
	n_box(x, y, w, h, t_color, b_color, text, sl_box);
	//=================================
	int xp = x; int yp = y;// tọa độ thanh sáng
	int xcu = xp; int ycu = yp;
	bool kt = true;
	while (true)
	{
		//------- in --------
		if (kt == true) {
			//---- backspace ----
			//gotoXY(xcu, ycu);
			thanh_sang(xcu, ycu, w, h, b_color, text);
			xcu = xp; ycu = yp;
			//-------------------------------------------
			thanh_sang(xp, yp, w, h, b_color_sang, text);
			kt = false;
		}
		//--- điều khiển ----
		if (_kbhit()) {
			char c = _getch();
			if (c == -32) {
				kt = true;
				c = _getch();
				if (c == 72) {
					if (yp != y) {
						yp -= 2;
					}
					else {
						yp = y + h * (sl_box - 1);
					}
				}
				else if (c == 80)
				{
					if (yp != y + h * (sl_box - 1)) {
						yp += 2;
					}
					else {
						yp = y;
					}
				}
			}
		}
	}
}
void thanh_sang(int x, int y, int w, int h, int b_color, string text) {
	textcolor(b_color);
	for (int iy = y + 1; iy <= y + h - 1; iy++) {
		for (int ix = x + 1; ix <= x + w - 1; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	gotoXY(x + 1, y + 1); cout << text;
}
void box(int x, int y, int w, int h, int t_color, int b_color, string text) {
	//=========== màu nền =============
	textcolor(b_color);
	for (int iy = y + 1; iy <= y + h - 1; iy++) {
		for (int ix = x + 1; ix <= x + w - 1; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	//============= text ==============
	SetColor(7);
	gotoXY(x + 1, y + 1); cout << text;
	//============ vẽ viền =============
	textcolor(1);
	SetColor(t_color);
	if (h <= 1 || w <= 1)return;
	for (int ix = x; ix <= x + w; ix++) {
		gotoXY(ix, y);
		cout << char(196);
		gotoXY(ix, y + h);
		cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++) {
		gotoXY(x, iy);
		cout << char(179);
		gotoXY(x + w, iy);
		cout << char(179);
	}
	//-- xử lý bo 4 góc --
	gotoXY(x, y); cout << char(218);
	gotoXY(x + w, y); cout << char(191);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y + h); cout << char(217);
}
void n_box(int x, int y, int w, int h, int t_color, int b_color, string text, int sl_box) {
	for (int i = 0; i < sl_box; i++) {
		box(x, y + (i * 2), w, h, t_color, b_color, text);
		if (i != 0) { //-- xử lý khi các ô gần nhau bị đè mất nét ( với n ô sẽ có n-1 cặp vt bị đè nét) --
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
}