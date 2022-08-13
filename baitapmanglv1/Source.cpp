#include <iostream>
using namespace std;

void nhap(int a[], int n);
void xuat(int a[], int n);
void xoaPhanTuLaSoDoiXung(int a[], int& n);
void them0TruocSoHoanThien(int a[], int& n);
void xoaTrung(int a[], int& n);
void thongKeTanSuat(int a[], int n);

int main() {

	return 0;
}
void nhap(int a[], int n) {
	cout << "\n\t\t=======Nhap======\n";
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap phan tu a[" << i << "]="; cin >> a[i];
	}
}
void xuat(int a[], int n) {
	cout << "\n\t\t======Xuat========\n";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
//Cau 1 ========================================
int daoSo(int x) {
	int a = 0;
	while (x!=0)
	{
		int du = x % 10;
		a = a * 10 + du;
		x = x / 10;
	}
	return a;
}
bool ktSdx(int x) {
	if (x <= 0) {
		return false;
	}
	if (daoSo(x) == x) {
		return true;
	}
	else {
		return false;
	}
}
void xoa(int a[], int& n, int vt) {
	for (int i = vt; i < n-1; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}
void xoaPhanTuLaSoDoiXung(int a[], int& n) {
	for (int i = 0; i < n; i++)
	{
		if (ktSdx(a[i]) == true) {
			xoa(a, n, i);
			i--;
		}
	}
}
//Cau 2 ==========================================
void them(int a[], int& n, int vt, int x) {
	for (int i = n; i > vt; i--)
	{
		a[i] = a[i - 1];
	}
	a[vt] = x;
	n++;
}
int tongCacUoc(int x) {
	int tong = 0;
	for (int i = 1; i <= x; i++)
	{
		if (x % i == 0) {
			tong = tong + i;
		}
	}
	return tong;
}
bool ktSoHoanThien(int x) {
	if (x <= 1) {
		return false;
	}
	if (tongCacUoc(x) - x == x) {
		return true;
	}
	else {
		return false;
	}
}
void them0TruocSoHoanThien(int a[], int& n) {
	for (int i = 0; i < n; i++)
	{
		if (ktSoHoanThien(a[i])==true)
		{
			them(a, n, i, 0);
			i++;
		}
	}
}
//Cau 3 ========================================
void xoaTrung(int a[], int& n) {
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++) {
			if (a[i] == a[j]) {
				xoa(a, n, j);
				j--;
			}
		}
	}
}
//Cau 4 =======================================
void thongKeTanSuat(int a[], int n) {
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
			cout << a[i] << "lap" << dem << "lan." << endl;
		}
	}
}
