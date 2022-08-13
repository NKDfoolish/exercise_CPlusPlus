#include <iostream>
using namespace std;
#define MAX 100
void Nhap_Mang(int a[], int n);
void KT_Tang_Dan(int a[], int n);
int main()
{
	int a[MAX] = {};
	int n = 0;
	do
	{
		cout << "Nhap n tu ban phim: "; cin >> n;
	} while (n <= 0 || n > MAX);
	Nhap_Mang(a, n);
	KT_Tang_Dan(a, n);
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
void KT_Tang_Dan(int a[], int n)
{
	bool kt = true;
	for (int i = 0; i < n-1; i++)
	{
		if (a[i + 1] < a[i])
		{
			kt = false;
			break;
		}
	}
	if (kt == true)
	{
		cout << "\nMang tang dan";
	}
	else
	{
		cout << "\nMang khong tang dan";
	}
}