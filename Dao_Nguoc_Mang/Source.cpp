/*
Bài 10. 
Cho mảng 1 chiều các số nguyên. 
Viết chương trình đảo ngược mảng. VD:  1 5 6 2  => 2 6 5 1
*/
#include <iostream>
using namespace std;
#define MAX 100
#include <math.h>
void Nhap_Mang(int a[], int);
void Xuat_Mang(int a[], int);
void Xu_Ly(int a[], int);
int main()
{
	int a[MAX];
	int n;
	cout << "\nNhap so luong phan tu n tu ban phim: "; cin >> n;
	Nhap_Mang(a, n);
	Xuat_Mang(a, n);
	Xu_Ly(a, n);
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
void Xu_Ly(int a[], int n)
{
	int x = n / 2;
	int k = 1;
	for (int i = 0; i <= x; i++)
	{
		int temp =a[i];
		a[i] = a[n - k];
		a[n - k] = temp;
		k++;
	}
	cout << "\nMang sau khi xu ly: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}