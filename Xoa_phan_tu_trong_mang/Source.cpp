/*
4. Cho 1 mảng các số nguyên a. Viết chương trình tách các số âm ra mảng b và xóa khỏi a
VD: mảng a:   1   -2   3   4   -6   0
Xuất:
mảng a:   1   3    4   0
mảng b:  -2    -6
*/
#include <iostream>
using namespace std;
#define MAX 100
void Nhap_Mang(int a[], int);
void Xuat_Mang(int a[], int);
void Xoa_1_Phan_Tu(int a[], int&, int);
void Xu_Ly(int a[], int);
int main()
{
	int a[MAX] = {};
	int n = 0;
	do
	{
		cout << "\nNhap so luong phan tu n tu ban phim: "; cin >> n;
		if (n <= 0 || n > MAX)
		{
			cout << "\nSo luong phan tu phai lon hon 0 vui long nhap lai!";
		}
	} while (n<=0||n>MAX);
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
void Xoa_1_Phan_Tu(int a[], int &n, int x)
{
	for (int i = x; i < n-1; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}
void Xu_Ly(int a[], int n)
{
	int b[MAX] = {};
	int m = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			b[m] = a[i];
			m++;
			Xoa_1_Phan_Tu(a, n, i);
			i--;
		}
	}
	cout << "\nMang a sau khi xu ly:";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\nMang b sau khi xu ly:";
	for (int i = 0; i < m; i++)
	{
		cout << b[i] << " ";
	}
}