#include <iostream>
using namespace std;
#define MAX 100
void Nhap_Mang(int a[], int n);
void Tim_Doan_AB(int a[], int n);
int main()
{
	int a[MAX] = {};
	int n = 0;
	do
	{
		cout << "Nhap n tu ban phim: "; cin >> n;
	} while (n <= 0 || n > MAX);
	Nhap_Mang(a, n);
	Tim_Doan_AB(a, n);
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
void Tim_Doan_AB(int a[], int n)
{
	int Max = a[0]; int Min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > Max)
		{
			Max = a[i];
		}
		else if (a[i] < Min)
		{
			Min = a[i];
		}
	}
	cout << "\nDoan (A,B) can tim: (" << Min << "," << Max << ")";
}