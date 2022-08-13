#include <iostream>
using namespace std;
#define MAX 100
void Nhap_Mang(int a[], int n);
void SCNN(int a[], int n);
int main()
{
	int a[MAX] = {}; int n = 0;
	do
	{
		cout << "\nNhap so luong phan tu tu ban phim: "; cin >> n;
	} while (n<=0&&n>MAX);
	Nhap_Mang(a, n);
	SCNN(a, n);
	return 0;
}
void Nhap_Mang(int a[], int n)
{
	cout << "\n\t\t===========Nhap Mang===========\n";
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu thu " << i + 1 << " :"; cin >> a[i];
	}
}
void SCNN(int a[], int n)
{
	int Max_khac_chan = -1;//bien giu gia tri khac so chan lon nhat
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 != 0 && a[i] > Max_khac_chan)
		{
			Max_khac_chan = a[i];
		}
	}
	int Max_chan = -1;// bien giu gia tri chan lon nhat
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0 && a[i] > Max_chan)
		{
			Max_chan = a[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] > Max_khac_chan && a[i]<Max_chan)
		{
			Max_chan = a[i];
		}
	}
	cout << "\nSo chan nho nhat la " << Max_chan;
}