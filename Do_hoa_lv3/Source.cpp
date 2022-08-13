#include <iostream>
#include "mylib.h"
using namespace std;
//=================================
void main()
{
	ShowCur(0);// ẩn con trỏ
	//---- setting ---
	int x = 10; int y = 0;
	int i = 1;
	int check = 0;//0: chạm biên trên và đi xuống dưới
				  //1: chạm biên dưới và đi lên trên
				  //2: chạm biên trái và đi qua phải
				  //4: chạm biên phải và đi qua trái

	int xcu = -100; int ycu = -100;
	//--- play ---
	while (true)
	{
		//---- clear screen ----
		//system("cls");

		// backspade:
		gotoXY(xcu, ycu);
		cout << "                   ";
		//----- cập nhật xcu,ycu ----
		xcu = x;
		ycu = y;

		//---- màu sắc ---
		SetColor(i);
		i++;
		if (i == 16)
		{
			i = 1;
		}

		//---- in ------
		gotoXY(x, y);
		cout << "Nguyen Khanh Duy ^^";
		//----- Điều khiển để thay đổi hướng ----
		if (_kbhit() == true) {
			char c = _getch();
			if (c == -32) {
				c = _getch();
				if (c == 72) {
					check = 1;
				}
				else if (c == 80) {
					check = 0;
				}
				else if (c == 77) {
					check = 2;
				}
				else if (c == 75) {
					check = 3;
				}
			}
			
		}
		//--- dựa vào hướng để di chuyển ----
		if (check == 0)
		{
			y++;
		}
		else if (check == 1)
		{
			y--;
		}
		else if (check == 2)
		{
			x++;
		}
		else if (check == 3)
		{
			x--;
		}
		//----- kiểm tra biên để thay đổi hướng -----
		if (y == 28)
		{
			check = 1;
		}
		else if (y == 0)
		{
			check = 0;
		}
		else if (x == 0)
		{
			check = 2;
		}
		else if (x == 80)
		{
			check = 3;
		}
		//--- speed ---
		if (check == 2 || check == 3)
		{
			Sleep(30);
		}
		else {
			Sleep(50);
		}

	}


}