/*
5. (Tư duy + Xử lý) // Bài thi kết thúc học phần: Tin học cơ sở 2(PTIT HCM)
Cho 1 mảng số nguyên. Sắp xếp các số âm nằm trước giảm dần tiếp đến là số 0 rồi đến các số dương giảm dần
VD: mảng: 12pt:    -4     5      0      6      -1     0      8      3     -11    15    2    1
			 Kết quả:     -1   -4    -11     0       0    15     8      6       5      3     2    1
Gợi ý: Sử dụng mảng phụ
*/
#include <iostream>
using namespace std;
#define MAX 100
void Nhap_Mang(int a[], int);
void Xuat_Mang(int a[], int);
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
	} while (n <= 0 || n > MAX);
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
void Xu_Ly(int a[], int n)
{
	int a1[MAX] = {};
	int a2[MAX] = {};
	int a3[MAX] = {};
	int j = 0, k = 0, l = 0;
	for (int i = 0; i < n; i++)//Tach ra 3 mang
	{
		if (a[i] < 0)
		{
			a1[j] = a[i];
			j++;
		}
		else if (a[i] == 0)
		{
			a2[k] = a[i];
			k++;
		}
		else
		{
			a3[l] = a[i];
			l++;
		}
	}
	for (int i = 0; i < j-1; i++)//Sap giam dan tung mang
	{
		for (int y = i + 1; y < j; y++)
		{
			if (a1[y] > a1[i])
			{
				int temp = a1[i];
				a1[i] = a1[y];
				a1[y] = temp;
			}
		}
	}
	for (int i = 0; i < k - 1; i++)//Sap giam dan tung mang
	{
		for (int y = i + 1; y < k; y++)
		{
			if (a2[y] > a2[i])
			{
				int temp = a2[i];
				a2[i] = a2[y];
				a2[y] = temp;
			}
		}
	}
	for (int i = 0; i < l - 1; i++)//Sap giam dan tung mang
	{
		for (int y = i + 1; y < l; y++)
		{
			if (a3[y] > a3[i])
			{
				int temp = a3[i];
				a3[i] = a3[y];
				a3[y] = temp;
			}
		}
	}
	//Gop 3 mang lai vao cho mang a
	int u = 0;
	for (int i = 0; i < j; i++)
	{
		a[u] = a1[i];
		u++;
	}
	for (int i = 0; i < k; i++)
	{
		a[u] = a2[i];
		u++;
	}
	for (int i = 0; i < l; i++)
	{
		a[u] = a3[i];
		u++;
	}
	cout << "\nMang a sau khi xu ly: ";
	for (int i = 0; i < u; i++)
	{
		cout << a[i] << " ";
	}
}