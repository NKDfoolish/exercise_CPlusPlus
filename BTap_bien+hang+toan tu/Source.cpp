#include <iostream>
using namespace std;

int main()
{
	/*
	int a, b;
	cout << "Nhap vao so nguyen a: ";
	cin >> a;
	cout << "\nNhap vao so nguyen b: ";
	cin >> b;
	cout << "\nSo lon nhat la: " << (((a - b) > 0) ? a : b);
	*/

	/*
	int a, b;
	cout << "Nhap vao so nguyen a: ";
	cin >> a;
	cout << "\nNhap vao so nguyen b: ";
	cin >> b;
	int c = (((a - b) > 0) ? a : b);
	cout << "\nSo lon nhat la :" << c;
	*/

	int a, b;
	cout << "Nhap vao so nguyen a: ";
	cin >> a;
	cout << "\nNhap vao so nguyen b: ";
	cin >> b;
	cout << "\nSo lon nhat la: " << ((a > b) ? a : b);

	return 0;
}