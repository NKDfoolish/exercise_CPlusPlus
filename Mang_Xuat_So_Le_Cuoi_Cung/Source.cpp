#include <iostream>
using namespace std;
#define MAX 100
void Nhap_Mang(int a[], int n);
void Xuat_So_Le_Cuoi_Cung(int a[], int n);
int main()
{
	int a[MAX] = {};
	int n = 0;
	do
	{
		cout << "Nhap n tu ban phim: "; cin >> n;
	} while (n <= 0 || n > MAX);
	Nhap_Mang(a, n);
	Xuat_So_Le_Cuoi_Cung(a, n);
	return 0;
}
void Nhap_Mang(int a[], int n)
{
	cout << "\n\t\t==========Nhap Mang==========";
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap phan tu thu " << i + 1 << " :"; cin >> a[i];
	}
}
void Xuat_So_Le_Cuoi_Cung(int a[], int n)
{
	int So_Le = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 != 0)
		{
			So_Le = a[i];
		}
	}
	cout << "\nSo le cuoi cung la: " << So_Le;
}