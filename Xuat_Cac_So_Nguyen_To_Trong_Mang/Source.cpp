#include <iostream>
using namespace std;
#define MAX 100
void Nhap_Mang(int a[], int n);
void Xuat_Mang_SNT(int a[], int n);
bool KT_SNT(int x);
int main()
{
	int a[MAX] = {};
	int n = 0;
	do
	{
		cout << "Nhap so luong phan tu tu ban phim: "; cin >> n;
	} while (n <= 0 || n > MAX);
	Nhap_Mang(a, n);
	Xuat_Mang_SNT(a, n);

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
bool KT_SNT(int x)
{
	if (x < 2)
	{
		return false;
	}
	else if (x == 2)
	{
		return true;
	}
	else if (x > 2)
	{
		for (int i = 2; i < x; i++)
		{
			if (x % i == 0)
			{
				return false;
			}
			return true;
		}
	}
}
void Xuat_Mang_SNT(int a[], int n)
{
	cout << "\n\t\t===========Xuat Mang===========\n";
	for (int i = 0; i < n; i++)
	{
		if (KT_SNT(a[i])==true)
		{
			cout << a[i] << " ";
		}
	}
}