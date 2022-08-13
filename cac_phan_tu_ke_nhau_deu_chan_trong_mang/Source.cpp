/*
Bài 9. Cho mảng 1 chiều các số nguyên. 
Viết chương trình in ra các phần tử kề nhau mà cả hai đều chẵn.
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
	cout << "\nCac cap phan tu so le nam lien tiep nhau la: ";
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
	for (int i = 0; i < n-1; i++)
	{
		if (a[i] % 2 == 0 && a[i + 1] % 2 == 0)
		{
			cout << "\n(" << a[i] << "," << a[i + 1] << ")";
		}
	}
}