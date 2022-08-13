#include <iostream>
using namespace std;
#define MAX 100
void Nhap_Mang(int a[], int);
void Xuat_Mang(int a[], int);
void Xoa_1_Phan_Tu(int a[], int&, int);
void Xu_Ly(int a[], int&, int);
int main()
{
	int a[MAX] = {};
	int n = 0;
	int m = 0;
	do
	{
		cout << "\nNhap so luong phan tu n tu ban phim: "; cin >> n;
		if (n <= 0 || n > MAX)
		{
			cout << "\nSo luong phan tu phai lon hon 0 vui long nhap lai!";
		}
	} while (n <= 0 || n > MAX);
	cout << "\nTim phan tu lon thu :"; cin >> m;
	Nhap_Mang(a, n);
	Xuat_Mang(a, n);
	Xu_Ly(a, n, m);
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
void Xoa_1_Phan_Tu(int a[], int& n, int x)
{
	for (int i = x; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}
void Xu_Ly(int a[], int& n, int m)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] > a[i])// sap mang giam dan
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
			if (a[j] == a[i])// tranh th cac phan tu bi trung
			{
				Xoa_1_Phan_Tu(a, n, j);
			}
		}
	}
	if (m > n)
	{
		cout << "\nPhan tu lon thu " << m << " khong ton tai";
	}
	else
	{
		cout << "\nPhan tu lon thu " << m << " la: "; cout << a[m - 1];
	}
}