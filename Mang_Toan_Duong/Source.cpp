#include <iostream>
using namespace std;
#define MAX 100
void Nhap_Mang(int a[], int n);
void KT_Toan_Duong(int a[], int n);
int main()
{
	int a[MAX] = {};
	int n = 0;
	do
	{
		cout << "Nhap n tu ban phim: "; cin >> n;
	} while (n <= 0 || n > MAX);
	Nhap_Mang(a, n);
	KT_Toan_Duong(a, n);
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
void KT_Toan_Duong(int a[], int n)
{
	bool Kt = true;
	for (int i = 0; i < n; i++)
	{
		if (a[i] <= 0)
		{
			Kt = false;
			break;
		}
	}
	if (Kt == true)
	{
		cout << "\nMang toan duong";
	}
	else
	{
		cout << "\nMang khong toan duong";

	}
}