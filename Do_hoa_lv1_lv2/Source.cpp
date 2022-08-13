#include <iostream>
#include "Header.h"
using namespace std;
//=================================
void main()
{
	ShowCur(0);
	//---- setting ---
	int x = 10; int y = 0;
	int i = 1;
	int check = 0;//0: chạm biên trên và đi xuống dưới
				  //1: chạm biên dưới và đi lên trên

	int xcu = -100; int ycu = -100;
	//--- play ---
	while (true)
	{
		//---- clear screen ----
		//system("cls");

		// backspade:
		gotoXY(xcu, ycu);
		cout << "                      ";
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
		cout << "Hoc lap trinh that de!";
		//----- Điều khiển để thay đổi hướng ----

		//--- dựa vào hướng để di chuyển ----
		if (check == 0)
		{
			y++;
		}
		else if (check == 1)
		{
			y--;
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
		//--- speed ---
		Sleep(100);

	}


}