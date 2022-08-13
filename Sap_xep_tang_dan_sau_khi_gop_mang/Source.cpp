/*
3. có 2 mảng a, b đã được sắp xếp TĂNG DẦN. Trộng mảng a, b vào c sao cho mảng c tăng dần.
VD: a: 1 2 7
b: 0 2 6 9
=> c: 0 1 2 2 6 7 9
*/
#include <iostream>
using namespace std;
#define MAX 100
void Nhap_Mang(int a[], int b[], int, int);
void Xuat_Mang(int a[], int b[], int, int);
void mang_Sap_Tang_Dan(int a[], int b[], int, int);
int main()
{
	int n, m;
	int a[MAX];
	int b[MAX];
	do
	{
		cout << "\nNhap so luong phan tu cua mang a: "; cin >> n;
	} while (n <= 0 || n > MAX);
	do
	{
		cout << "\nNhap so luong phan tu cua mang b: "; cin >> m;
	} while (m <= 0 || m > MAX);
	Nhap_Mang(a, b, n, m);
	Xuat_Mang(a, b, n, m);
	mang_Sap_Tang_Dan(a, b, n, m);
	return 0;
}
void Nhap_Mang(int a[], int b[], int n, int m)
{
	cout << "\n\t\t===========================Nhap Mang Tang Dan A===========================\n";
	bool flag = true;
	do//KTra xem cac phan tu trong mang co bi trung hay sap xep khong tang dan
	{
		flag = true;
		for (int i = 0; i < n; i++)
		{
			cout << "\nNhap gia tri phan tu thu " << i + 1 << " : "; cin >> a[i];
		}
		for (int i = 0; i < n-1; i++)
		{
			if (a[i] >= a[i + 1])
			{
				flag = false;
				break;
			}
		}
		if (flag == false)
		{
			cout << "\nXin hay nhap cac phan tu theo gia tri tang dan! Cac gia tri phai khac nhau.";
		}
	} while (flag == false);
	cout << "\n\t\t===========================Nhap Mang Tang Dan B===========================\n";
	do//KTra xem cac phan tu trong mang co bi trung hay sap xep khong tang dan
	{
		flag = true;
		for (int i = 0; i < m; i++)
		{
			cout << "\nNhap gia tri phan tu thu " << i + 1 << " : "; cin >> b[i];
		}
		for (int i = 0; i < m-1; i++)
		{
			if (b[i] >= b[i + 1])
			{
				flag = false;
				break;
			}
		}
		if (flag == false)
		{
			cout << "\nXin hay nhap cac phan tu theo gia tri tang dan! Cac gia tri phai khac nhau.";
		}
	} while (flag == false);
}
void Xuat_Mang(int a[], int b[], int n, int m)
{
	cout << "\n\t\t===========================Xuat Mang A===========================\n";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n\t\t===========================Xuat Mang B===========================\n";
	for (int i = 0; i < m; i++)
	{
		cout << b[i] << " ";
	}
}
void mang_Sap_Tang_Dan(int a[], int b[], int n, int m)
{
	int k = 0, h = 0, l = 0;
	int c[MAX];
	for (int i = 0; i < n+m; i++)
	{
		if (k >= n)//TH: da do het mang a vao trong mang c
		{
			c[i] = b[h];
			h++;
		}
		else if (h >= m)//TH: da do het mang b vao trong mang c
		{
			c[i] = a[k];
			k++;
		}
		if (a[k] <= b[h] && k < n && h < m)//TH: ca 2 mang a va b van chua do het vao mang c
		{
			c[i] = a[k];
			++k;
		}
		else if (a[k] >= b[h] && h < m && k < n)//TH: ca 2 mang a va b van chua do het vao mang c
		{
			c[i] = b[h];
			++h;
		}
	}
	cout << "\n\t\t===========================Mang sau khi sap tang dan===========================\n\n";
	for (int i = 0; i < n+m; i++)
	{
		cout << c[i] << " ";
	}
}