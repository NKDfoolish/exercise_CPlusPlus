#include <iostream>
using namespace std;
#include <math.h>
#define MAX 100

void nhap(int a[], int n);
void xuat(int a[], int n);
void gopDau(int a[], int na, int b[], int& nb);
void gopCuoi(int a[], int na, int b[], int& nb);
void tachPhanTuAm(int a[], int& na, int b[], int& nb);
void ptit(int a[], int n);
void tron(int a[], int na, int b[], int nb, int c[], int& nc);
void ptMaxThuK(int a[], int n);
void uclnCuaMang(int a[], int n);
void kcMax(int a[], int n);
void daoMang(int a[], int n);
void dichPhai(int a[], int n);
void capPhanTuKeNhauDeuChan(int a[], int n);
//=========================================================
int main() {
	int a[MAX] = {};
	int n;
	cout << "Nhap so luong phan tu cho mang tu ban phim: "; cin >> n;
	nhap(a, n);
	xuat(a, n);
	//them_So_0_Truoc_So_Doi_Xung(a, n);
	//xoa_Phan_Tu_La_So_Hoan_Thien(a, n);
	daoMang(a, n);
	xuat(a, n);
	return 0;
}
//==========================================================
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
void xoa(int a[], int& n, int vt) {
	for (int i = vt; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}
void them(int a[], int& n, int vt, int x) {
	for (int i = n; i > vt; i--)
	{
		a[i] = a[i - 1];
	}
	a[vt] = x;
	n++;
}
//Cau 1 ====================================================
void gopDau(int a[], int na, int b[], int& nb) {
	for (int i = na-1; i >= 0; i--)
	{
		them(b, nb, 0, a[i]);
	}
}
//Cau 2 ====================================================
void gopCuoi(int a[], int na, int b[], int& nb) {
	for (int i = 0; i < na; i++)
	{
		b[nb++] = a[i];
	}
}
//Cau 4 ====================================================
void tachPhanTuAm(int a[], int& na, int b[], int& nb) {
	for (int i = 0; i < na; i++)
	{
		if (a[i] < 0) {
			b[nb++] = a[i];

			xoa(a, na, i);
			i--;
		}
	}
}
//Cau 5 ================================================
void sapxeptang(int a[], int n) {
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++) {
			if (a[j]<a[i])
			{
				swap(a[j], a[i]);
			}
		}
	}
}
void ptit(int a[], int n) {
	sapxeptang(a, n);
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++) {
			if ((a[j] < 0 && a[i] < 0) || (a[j] > 0 && a[i] > 0)) {
				if (a[j] > a[i]) {
					swap(a[i], a[j]);
				}
			}
		}
	}
}
//Cau 3 =============================================
void tron(int a[], int na, int b[], int nb, int c[], int& nc) {
	nc = na + nb;
	int ia = 0;
	int ib = 0;
	for (int ic = 0; ic < nc; ic++) {
		if (ia == na) {
			c[ic] = b[ib++];
		}
		else if (ib == nb) {
			c[ic] = a[ia++];
		}
		else if (a[ia] <= b[ib]) {
			c[ic] = a[ia++];
		}
		else if (b[ib] < a[ia]) {
			c[ic] = b[ib++];
		}
	}
}
//Cau 6 ===========================================
void sapxepgiam(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i = 1; j < n; j++) {
			if (a[j] > a[i])
			{
				swap(a[j], a[i]);
			}
		}
	}
}
void ptMaxThuK(int a[], int n) {
	int k; cout << "Nhap k: "; cin >> k;
	sapxepgiam(a, n);
	int max = a[0];
	int dem = 1;
	if (k == 1) {
		cout << "phan tu max thu " << k << " la " << max << endl;
	}
	else {
		for (int i = 1; i < n; i++)
		{
			if (max != a[i]) {
				max = a[i];
				dem++;
				if (dem == k) {
					cout << "phan tu max thu " << k << " la " << max << endl;
					return;
				}
			}
		}
		cout << "Khong tim thay!" << endl;
	}
}
//Cau 7 ==============================================
int ucln(int a, int b) {
	while (a != b) {
		(a > b) ? a = a - b : b = b - a;
	}
	return a;
}

void uclnCuaMang(int a[], int n) {
	int uc = a[0];
	for (int i = 1; i < n; i++)
	{
		uc = ucln(uc, a[i]);
	}
	cout << "UCLN cua mang la: " << uc << endl;
}

//cau 8 =============================================
void kcMax(int a[], int n)
{
	int x; cout << "nhap x:"; cin >> x;
	int min = a[0];
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] < min) {
			min = a[i];
		}
		else if (a[i] > max) {
			max = a[i];
		}
	}
	int khoangcachtumindenx = abs(min - x);
	int khoangcachtumaxdenx = abs(max - x);
	if ((khoangcachtumindenx > khoangcachtumaxdenx) || (min == max)) {
		cout << "gia tri xa x nhat la " << min << endl;
	}else if (khoangcachtumindenx < khoangcachtumaxdenx) {
		cout << "gia tri xa x nhat la " << max << endl;
	}
	else {
		cout << "gia tri xa x nhat la " << min << endl;
		cout << "gia tri xa x nhat la " << max << endl;
	}
}
//cau 10 =============================================
void daoMang(int a[], int n) {
	for (int i = 0; i < n/2; i++)
	{
		int temp = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = temp;
	}
}
//cau 11 =============================================
void dichPhai(int a[], int n) {
	int k; cout << "nhap k: "; cin >> k;
	for (int i = 1; i <= k%n; i++)
	{
		them(a, n, 0, a[n - 1]);
		n--;
	}
}

//Cau 9 ==============================================
void capPhanTuKeNhauDeuChan(int a[], int n) {
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0 && a[i + 1] % 2 == 0) {
			cout << "(" << a[i] << "," << a[i + 1] << "); ";
		}
	}
}
