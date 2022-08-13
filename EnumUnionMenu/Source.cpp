#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
#define PI 3.1412

int main()
{

	int b = 4;
	b = b++ + ++b;
	cout << b;
	/*
		enum Mycolor { red, blue, yellow, pink, green };
		Mycolor box;
		box = blue;
		if (box == blue)
			box = pink;
		cout << box;


		union Math
		{
			int i;
			float f;
			char c;
		};

		Math x;
		x.c = 'A';
		x.i = 5;
		x.f = 3.9;
		cout << x.c << endl;
		cout << x.i << endl;
		cout << x.f;

		int luachon;
		float a, b;
		while (1)
		{
			system("cls");
			cout << "\n\n\t\t===============MENU==============";
			cout << "\n\t1. Ting tong";
			cout << "\n\t2. Tinh hieu";
			cout << "\n\t3. Tinh tich";
			cout << "\n\t4. Tinh thuong";
			cout << "\n\t0. Ket thuc";
			cout << "\n\n\t\t===============END===============";

			cout << "\nNhap lua chon cua ban: ";
			cin >> luachon;

			if (luachon == 1)
			{
				cout << "\nNhap gia tri cho a: ";
				cin >> a;
				cout << "\nNhap gia tri cho b: ";
				cin >> b;
				cout << "\nTong: " << a + b << endl;
				system("pause");
			}
			else if (luachon == 2)
			{
				cout << "\nNhap gia tri cho a: ";
				cin >> a;
				cout << "\nNhap gia tri cho b: ";
				cin >> b;
				cout << "\nHieu: " << a - b << endl;
				system("pause");
			}
			else if (luachon == 3)
			{
				cout << "\nNhap gia tri cho a: ";
				cin >> a;
				cout << "\nNhap gia tri cho b: ";
				cin >> b;
				cout << "\nTich: " << a * b << endl;
				system("pause");
			}
			else if (luachon == 4)
			{
				cout << "\nNhap gia tri cho a: ";
				cin >> a;
				cout << "\nNhap gia tri cho b: ";
				cin >> b;
				cout << "\nThuong: " << a / b << endl;
				system("pause");
			}
			else
			{
				break;
			}
		}
	*/
	return 0;
}