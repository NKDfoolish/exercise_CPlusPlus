#include <iostream>
using namespace std;
#define MAX 100

void nhap_Mang(int a[], int n, int* p);
void xuat_Mang(int a[], int n, int* p);
void min_max_Trong_Mang(int a[], int n, int* p);
void snt_Trong_Mang(int a[], int n, int* p);
void xoa_Phan_Tu(int a[], int& n, int* p, int vt);
void them_Phan_Tu(int a[], int& n, int* p, int vt, int gt);
void sap_Xep_Increase(int a[], int n, int* p);

int main() {
	int a[MAX];
	int n, vtx, vtt, gt;
	int* p = a;
	do
	{
		cout << "Nhap n nguyen duong tu ban phim: "; cin >> n;
	} while (n<=0);
	nhap_Mang(a, n, p);
	xuat_Mang(a, n, p);
	/*cout <<	endl;
	min_max_Trong_Mang(a, n, p);
	snt_Trong_Mang(a, n, p);
	cout << "\nNhap vi tri can xoa: "; cin >> vtx; cout << endl;
	xoa_Phan_Tu(a, n, p, vtx);
	xuat_Mang(a, n, p);
	cout << "\nNhap vi tri can them: "; cin >> vtt;
	cout << "\nNhap gia tri can them vao mang: "; cin >> gt; cout << endl;
	them_Phan_Tu(a, n, p, vtt, gt);
	xuat_Mang(a, n, p);*/
	/*cout << endl;
	sap_Xep_Increase(a, n, p);
	xuat_Mang(a, n, p);*/

	return 0;
}
void nhap_Mang(int a[], int n, int* p) {
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap a[" << i << "] = "; cin >> *(p + i); 
		cout << endl;
	}
}
void xuat_Mang(int a[], int n, int* p) {
	for (int i = 0; i < n; i++)
	{
		cout << *(p + i) << " ";
	}
}
//Cau 1 ================================================
void min_max_Trong_Mang(int a[], int n, int* p) {
	int min = *p;
	int max = *p;
	for (int i = 1; i < n; i++)
	{
		if (*(p + i) < min) {
			min = *(p + i);
		}
		else if (*(p + i) > max) {
			max = *(p + i);
			}
	}
	cout << "Max la: " << max << " ;Min la: " << min << endl;
}
//Cau 2 ================================================
bool check_SNT(int x) {
	for (int i = 2; i < x; i++)
	{
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}
void snt_Trong_Mang(int a[], int n, int* p) {
	cout << "\nSo nguyen to trong mang: ";
	for (int i = 0; i < n; i++)
	{
		if (check_SNT(*(p + i)) == true) {
			cout << *(p + i) << " ";
		}
	}
}
//Cau 3  ================================================
void xoa_Phan_Tu(int a[], int& n, int* p, int vtx) {
	for (int i = vtx; i < n-1; i++)
	{
		*(p+i) = *(p + i + 1);
	}
	n--;
}
//Cau 4 =================================================
void them_Phan_Tu(int a[], int& n, int* p, int vtt, int gt) {
	for (int i = n; i > vtt; i--)
	{
		*(p + i) = *(p + i - 1);
	}
	*(p + vtt) = gt;
	n++;
}
//Cau 5 =================================================
void sap_Xep_Increase(int a[], int n, int* p) {
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++) {
			if (*(p + j) < *(p + i)) {
				swap(*(p + j), *(p + i));
			}
		}
	}
}