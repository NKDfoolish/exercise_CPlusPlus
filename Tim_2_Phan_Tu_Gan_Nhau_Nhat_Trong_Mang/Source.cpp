/*
Cho mảng số nguyen có nhiều hơn 2 giá trị và các giá trị trong mảng khác nhau từng đôi một. 
Hãy viết hàm tìm 2 giá trị gần nhau nhất trong mảng 
(Lưu ý: Mảng có các giá trị khác nhau từng đôi một còn có tên là mảng phân biệt)
*/
#include <iostream>
using namespace std;
#define MAX 100
#include <math.h>
void Nhap_Mang(int a[], int n);
void Tim_Cap_GT_Min(int a[], int n);
int main()
{
	int a[MAX];
	int n;
	do
	{
		cout << "\nNhap so luong phan tu n tu ban phim: "; cin >> n;
		if (n <= 2)
		{
			cout << "\nSo luong phan tu phai lon hon 2. Vui long nhap lai!";
		}
	} while (n<=2);
	Nhap_Mang(a, n);
	Tim_Cap_GT_Min(a, n);
	return 0;
}
void Nhap_Mang(int a[], int n)
{
	cout << "\n\t\t======================Nhap Mang======================\n";
	bool Check = true;
	do
	{
		Check = true;
		for (int i = 0; i < n; i++)
		{
			cout << "\nNhap phan tu thu " << i + 1 << " : "; cin >> a[i];
			if (a[i] == a[i - 1] || a[i] <= 0)
			{
				Check = false;
			}
		}

	} while (Check==false);
}
void Tim_Cap_GT_Min(int a[], int n)
{
	cout << "\nCap gia tri gan nhau nhat la: ";
	//Tim Khoang cach Min nhat giua 2 phan tu
	int min = abs(a[0] - a[1]);
	int s = a[0];
	int f = a[1];
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (abs(a[i] - a[j]) < min)
			{
				min = abs(a[i] - a[j]);
				s = a[i];
				f = a[j];
			}
		}
	}
	//Xuat ra cac cap gia tri co cung khoang cach Min
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (abs(a[i] - a[j]) == min)
			{
				s = a[i];
				f = a[j];
				cout << "\n(" << s << ", " << f << ")";
			}
		}
	}
}