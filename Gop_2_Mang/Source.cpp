/*
	Ta có 2 mảng
a: 1 2 3 4
b: 5 6 7 
1. Viết chương trình gộp mảng a vào đầu mảng b
=> b: 1 2 3 4 5 6 7
2. Viết chương trình gộp mảng a vào cuối mảng b
=> b: 5 6 8 1 2 3 4
*/
#include <iostream>
using namespace std;
#define MAX 100
void Nhap_Mang(int a[], int b[], int, int);
void Xuat_Mang(int a[], int b[], int, int);
void gop_Mang(int a[], int b[], int, int);
int main()
{
	int n, m;
	int a[MAX];
	int b[MAX];
	do
	{
		cout << "\nNhap so luong phan tu cua mang a: "; cin >> n;
	} while (n<=0||n>MAX);
	do
	{
		cout << "\nNhap so luong phan tu cua mang b: "; cin >> m;
	} while (m <= 0 || m > MAX);
	Nhap_Mang(a, b, n, m);
	Xuat_Mang(a, b, n, m);
	gop_Mang(a, b, n, m);
	return 0;
}
void Nhap_Mang(int a[], int b[], int n, int m)
{
	cout << "\n\t\t===================Nhap Mang A===================\n";
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap gia tri phan tu thu " << i + 1 << " : "; cin >> a[i];
	}
	cout << "\n\t\t===================Nhap Mang B===================\n";
	for (int i = 0; i < m; i++)
	{
		cout << "\nNhap gia tri phan tu thu " << i + 1 << " : "; cin >> b[i];
	}
}
void Xuat_Mang(int a[], int b[], int n, int m)
{
	cout << "\n\t\t===================Xuat Mang A===================\n";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n\t\t===================Xuat Mang B===================\n";
	for (int i = 0; i < m; i++)
	{
		cout << b[i] << " ";
	}
}
void gop_Mang(int a[], int b[], int n, int m)
{
	int c[MAX];
	int i = 0;
	for (i; i < n; i++)
	{
		c[i] = a[i];
	}
	for (int j = 0; j < m; j++)
	{
		c[i] = b[j];
		++i;
	}
	cout << "\nMang sau khi gop la: ";
	for (int k = 0; k < n+m; k++)
	{
		cout << c[k] << " ";
	}

}