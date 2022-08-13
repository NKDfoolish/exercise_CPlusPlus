/*
Cho mảng số nguyen có nhiều hơn 2 giá trị và các giá trị trong mảng khác nhau từng đôi một.
Hãy viết hàm liệt kê tất cả các cặp giá trị (a, b) trong mảng 
thỏa điều kiện a <= b
*/
#include <iostream>
using namespace std;
#define MAX 100
void Nhap_Mang(int a[], int);
void Liet_Ke(int a[], int);
int main()
{
	int a[MAX] = {};
	int n = 0;
	do
	{
		cout << "\nNhap so luong phan tu n tu ban phim: "; cin >> n;
	} while (n<=2);
	Nhap_Mang(a, n);
	Liet_Ke(a, n);

	return 0;
}
void Nhap_Mang(int a[], int n)
{
	cout << "\n\t\t===================Nhap Mang==================\n";
	//Kiem tra hai phan tu nam lien tiep nhau phai khac nhau (cac phan tu doi mot khac nhau)
	bool kt = true;
	do
	{
		kt = true;
		for (int i = 0; i < n; i++)
		{
			cout << "\nNhap phan tu thu " << i + 1 << " : "; cin >> a[i];
			if (a[i] == a[i - 1])
			{
				kt = false;
			}
		}

	} while (kt==false);
}

//Liet ke cac cap phan tu thoa man yeu cau de bai
void Liet_Ke(int a[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (a[i] <= a[j])
			{
				cout << "\n(" << a[i] << ", " << a[j] << ")";
			}
		}
	}
}