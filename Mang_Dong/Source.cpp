#include <iostream>
#include <stdlib.h>
using namespace std;

void nhap_Mang(int n, int* p);
void xuat_Mang(int n, int* p);
void tim_X_Ton_Tai(int n, int* p, int x);
void tong_Cac_Phan_Tu_Am(int* p, int n);
void liet_Ke_SDX(int* p, int n);
void kiem_tra_mang_toan_duong(int* p, int n);
void them_0_truoc_sdx(int* p, int &n);

int main() {
	int n, x = 0;
	int* p = NULL;
	do
	{
		cout << "\nNhap so luong phan tu n tu ban phim: "; cin >> n;
	} while (n<=0);
	p = (int*)calloc(n, sizeof(int));
	nhap_Mang(n, p);
	xuat_Mang(n, p);

	//cout << "\nNhap gia tri can tim x tu ban phim: "; cin >> x;
	cout << endl;
	//tim_X_Ton_Tai(n, p, x);
	//tong_Cac_Phan_Tu_Am(p, n);
	//liet_Ke_SDX(p, n);
	//kiem_tra_mang_toan_duong(p, n);
	them_0_truoc_sdx(p, n);
	xuat_Mang(n, p);
	return 0;
}
void nhap_Mang(int n, int* p) {
	cout << "\n\n\t\t================ Nhap Mang =================\n";
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap phan tu thu " << i + 1 << " : "; cin >> *(p + i);
	}
}
void xuat_Mang(int n, int* p) {
	cout << "\n\n\t\t================ Xuat Mang =================\n";
	for (int i = 0; i < n; i++)
	{
		cout << *(p + i) << " ";
	}
}
//Cau1===============================================
void tim_X_Ton_Tai(int n, int* p, int x) {
	for (int i = 0; i < n; i++)
	{
		if (*(p + i) == x) {
			cout << x << " co ton tai trong mang";
			return;
		}
	}
	cout << x << " khong ton tai trong mang";
}
//Cau2================================================
void tong_Cac_Phan_Tu_Am(int* p, int n) {
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		if (*(p + i) < 0) {
			tong = tong + *(p + i);
		}
	}
	cout << "\nTong cac phan tu am la: " << tong;
}
//Cau3=================================================
bool check_SDX(int x) {
	int temp = x;
	int box = 0;
	while (x!=0)
	{
		box = box * 10 + (x%10);
		x = x / 10;
	}
	if (temp == box) {
		return true;
	}
	else {
		return false;
	}
}
void liet_Ke_SDX(int* p, int n) {
	cout << "\nSo doi xung la: ";
	for (int i = 0; i < n; i++)
	{
		if (check_SDX(*(p + i)) == true) {
			cout << *(p + i) << " ";
		}
	}
}
//Cau4==============================================
void kiem_tra_mang_toan_duong(int* p, int n) {
	bool flag = true;
	for (int i = 0; i < n; i++)
	{
		if (*(p + i) <= 0) {
			flag = false;
			break;
		}
	}
	if (flag == true) {
		cout << "\nMang toan duong";
	}
	else if (flag == false) {
		cout << "\nMang khong toan duong";
	}
}
//Cau5=============================================
void them(int* p, int& n,int x, int vt) {
	for (int i = n; i > vt; i--)
	{
		*(p + i) = *(p + i - 1);
	}
	*(p + vt) = x;
	n++;
}
void them_0_truoc_sdx(int* p, int &n) {
	for (int i = 0; i < n; i++)
	{
		if (check_SDX(*(p + i)) == true) {
			them(p, n, 0, i);
			i++;
		}
	}
}