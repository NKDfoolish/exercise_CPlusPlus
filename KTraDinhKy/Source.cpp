#include <iostream>
using namespace std;
#define MAX 100

void nhap_Mang(int a[], int n);
void xuat_Mang(int a[], int n);
void them_So_0_Truoc_So_Doi_Xung(int a[], int& n);
void xoa_Phan_Tu_La_So_Hoan_Thien(int a[], int& n);
void dao_Mang(int a[], int n);
void thongKeTanSuat(int a[], int n);

int main() {
	int a[MAX] = {};
	int n;
	do
	{
		cout << "Nhap so luong phan tu cho mang tu ban phim: "; cin >> n;
		if (n <= 0) {
			cout << "\nSo luong phan tu phai lon hon 0. Vui long nhap lai ^^\n\n";
		}
	} while (n<=0);
	nhap_Mang(a, n);
	xuat_Mang(a, n);
	//them_So_0_Truoc_So_Doi_Xung(a, n);
	//xoa_Phan_Tu_La_So_Hoan_Thien(a, n);
	//dao_Mang(a, n);
	xuat_Mang(a, n);
	//thongKeTanSuat(a, n);

	return 0;
}
void nhap_Mang(int a[], int n) {
	cout << "\n\t\t=====Nhap=====\n";
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap phan tu thu " << i + 1 << " : "; cin >> a[i];
	}
}
void xuat_Mang(int a[], int n) {
	cout << "\n\t\t=====Xuat=====\n";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
//Cau 1 =============================
void them(int a[], int& n, int x, int vt) {
	for (int i = n; i > vt; i--)
	{
		a[i] = a[i - 1];
	}
	a[vt] = x;
	n++;
}
bool check_So_Doi_Xung(int x) {
	int temp = x;
	int hold = 0;
	while (x!=0)
	{
		int m = x % 10;
		hold = hold * 10 + m;
		x = x / 10;
	}
	if (temp == hold) {
		return true;
	}
	return false;
}
void them_So_0_Truoc_So_Doi_Xung(int a[], int &n) {
	for (int i = 0; i < n; i++)
	{
		if (check_So_Doi_Xung(a[i]) == true) {
			them(a, n, 0, i);
			i++;
		}
	}
}
//Cau 2 ========================================
void xoa(int a[], int& n, int vt) {
	for (int i = vt; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}
bool check_So_Hoan_Thien(int x) {
	int sum = 0;
	
	for (int i = 1; i <= x/2; i++)
	{
		if (x % i == 0) {
			sum = sum + i;
		}
	}
	
	if (sum == x) {
		return true;
	}
	return false;
}
void xoa_Phan_Tu_La_So_Hoan_Thien(int a[], int& n) {
	for (int i = 0; i < n; i++)
	{
		if (check_So_Hoan_Thien(a[i]) == true) {
			xoa(a, n, i);
			i--;
		}
		
	}
}
// cau 3 =================================================
void dao_Mang(int a[], int n) {
	for (int i = 0; i < n/2; i++)
	{
		int temp = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = temp;
	}
}
//Cau 4 ==============================================
void thongKeTanSuat(int a[], int n) {
	cout << "\nThong ke tan suat\n";
	for (int i = 0; i < n; i++)
	{
		bool kt = false;
		for (int k = 0; k < i; k++)
		{
			if (a[k] == a[i]) {
				kt = true;
				break;
			}
		}
		if (kt == false) {
			int dem = 1;
			for (int j = i + 1; j < n; j++)
			{
				if (a[i] == a[j]) {
					dem++;
				}
			}
			cout << a[i] << " lap " << dem << " lan. " << endl;
		}
	}
}