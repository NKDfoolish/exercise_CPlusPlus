/*
8. Cho mảng 1 chiều các số nguyên. Hãy tìm giá trị trong mảng các số nguyên xa giá trị x nhất(x nhập từ bàn phím)
VD: 24 45 23 13 43 -12
x = 15
==> giá trị trong mảng xa x nhất là: 45
*/
#include <iostream>
using namespace std;
#define MAX 100
#include <math.h>
void Nhap_Mang(int a[], int);
void Xuat_Mang(int a[], int);
void Xu_Ly(int a[], int, int);
int main()
{
	int a[MAX];
	int n, x;
	cout << "\nNhap so luong phan tu n tu ban phim: "; cin >> n;
	cout << "\nNhap gia tri X: "; cin >> x;
	Nhap_Mang(a, n);
	Xuat_Mang(a, n);
	cout << "\nPhan tu xa X nhat la: ";
	Xu_Ly(a, n, x);
	return 0;
}
void Nhap_Mang(int a[], int n)
{
	cout << "\n\t\t========== Nhap Mang ==========\n";
	for (int i = 0; i < n; i++)
	{
		cout << "\nnhap phan tu thu " << i + 1 << " : "; cin >> a[i];
	}
}
void Xuat_Mang(int a[], int n)
{
	cout << "\n\t\t========== Xuat Mang ==========\n";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
void Xu_Ly(int a[], int n, int x)
{
	int Max = 0;
	int i = 0;
	int m = 0;
	for (i; i < n; i++)
	{
		if (abs(a[i] - x) > Max)
		{
			Max = abs(a[i] - x);
			m = a[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (Max == abs(a[i] - x))
		{
			cout << a[i] << ", ";
		}
	}
}