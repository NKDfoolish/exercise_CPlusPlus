#include <iostream>
using namespace std;
#define MAX 100

void nhap_Mang(int a[], int n);
void xuat_Mang(int a[], int n);
void kiem_Tra_Mang_Con(int a[], int na, int b[], int nb);
void dem_So_Lan_Xuat_Hien_Cua_Mang_A_Trong_Mang_B(int a[], int na, int b[], int nb);
void liet_Ke_Tat_Ca_Mang_Con(int a[], int n);
void liet_Ke_Day_Con_Tang_Dan(int a[], int n);
void mang_Con_Tong_Bang_M(int a[], int n);
void day_Con_Toan_Duong(int a[], int n);
void day_Con_Toan_Duong_Dai_Nhat(int a[], int n);
void tim_Day_Con_Co_Tong_Lon_Nhat(int a[], int n);

int main() {
	int a[MAX] = {};
	int b[MAX] = {};
	int na;
	int nb;
	cout << "Nhap so luong phan tu cua mang a tu ban phim: "; cin >> na;
	//cout << "Nhap so luong phan tu cua mang b tu ban phim: "; cin >> nb;

	nhap_Mang(a, na);
	//nhap_Mang(b, nb);
	xuat_Mang(a, na);
	//xuat_Mang(b, nb);
	//dem_So_Lan_Xuat_Hien_Cua_Mang_A_Trong_Mang_B(a, na, b, nb);
	//kiem_Tra_Mang_Con(a, na, b, nb);
	//liet_Ke_Tat_Ca_Mang_Con(a, na);
	//liet_Ke_Day_Con_Tang_Dan(a, na);
	mang_Con_Tong_Bang_M(a, na);
	//day_Con_Toan_Duong(a, na);
	//day_Con_Toan_Duong_Dai_Nhat(a, na);
	//tim_Day_Con_Co_Tong_Lon_Nhat(a, na);

	return 0;
}
void nhap_Mang(int a[], int n) {
	cout << "\n\t\t========== Nhap mang ==========\n";
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap gia tri cho phan tu [" << i << "]: "; cin >> a[i];
	}
}
void xuat_Mang(int a[], int n) {
	cout << "\n\t\t========== Xuat mang ==========\n";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
//Nhap mon - cau 1 =====================================================================
void kiem_Tra_Mang_Con(int a[], int na, int b[], int nb) {
	bool check = true;
	for (int i = 0; i < nb; i++) {
		if ((b[i] == a[0]) && (nb - i >= na)) {
			int start = i;
			check = true;
			for (int j = 0; j < na; j++) {
				if (a[j] != b[start++]) {
					check = false;
					break;
				}
			}
		}
	}
	if (check == true) {
		cout << "\nb la mang con cua a.";
	}
	else {
		cout << "\nb khong phai mang con cua a.";
	}
}
//Nhap mon - cau 2 ======================================================================
void dem_So_Lan_Xuat_Hien_Cua_Mang_A_Trong_Mang_B(int a[], int na, int b[], int nb) {
	bool check = true;
	int count = 0;
	for (int i = 0; i < nb; i++) {
		if ((a[0] == b[i]) && (nb - i >= na)) {
			int start = i;
			check = true;
			for (int j = 0; j < na; j++) {
				if (a[j] != b[start++]) {
					check = false;
					break;
				}
			}
			if (check == true) {
				count++;
			}
		}
	}
	cout << "\nSo lan xuat hien cua mang a : " << count;
}
//Chuyen sau - cau 1 =====================================================================
void liet_Ke_Tat_Ca_Mang_Con(int a[], int n) {
	cout << "\nLiet ke mang con:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j+i < n+1; j++) {
			for (int k = i; k <= j+i-1; k++) {
				cout << a[k] << " ";
			}
			cout << endl;
		}
	}
}
//Cau 1.2 ===============================================================================
void xuat(int a[], int n) {
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
bool kiem_Tra_Mang_Tang_Dan(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] > a[i + 1])
			return false;
	}
	return true;
}
void liet_Ke_Day_Con_Tang_Dan(int a[], int n) {
	cout << "\nDay con tang dan :" << endl;
	int nb;
	int b[MAX];
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j+i < n+1; j++) {
			nb = 0;
			for (int k = i; k <= j+i-1; k++) {
				b[nb++] = a[k];
			}
			if (kiem_Tra_Mang_Tang_Dan(b, nb) == true) {
				xuat(b, nb);
				cout << endl;
			}
		}
	}
}
//cau 2 ==============================================================
void mang_Con_Tong_Bang_M(int a[], int n) {
	int M; 
	cout << "\nNhap M tu ban phim: "; cin >> M; 
	cout << "\nMang con tong bang " << M << " la:";
	cout << endl;
	for (int i = 0; i < n; i++) {               //  i: duyệt lần lượt mảng a
		for (int j = 1; j <= n-i; j++) {        //  j: số lượng
			int tong = 0;
			for (int k = i; k < j+i; k++) {  // duyệt mảng con
				tong = tong + a[k];
			}
			if (tong == M) {
				for (int l = i; l < j+i; l++) {
					cout << a[l] << " ";
				}
				cout << endl;
			}
		}
	}
}
//cau 3 =============================================================
bool check_Toan_Duong(int a[], int n) {
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
			return false;
	}
	return true;
}
void day_Con_Toan_Duong(int a[], int n) {
	cout << "\nDay con toan duong :" << endl;
	int nb;
	int b[MAX];
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j+i < n+1; j++) {
			nb = 0;
			for (int k = i; k <= j+i-1; k++) {
				b[nb++] = a[k];
			}
			if (check_Toan_Duong(b, nb) == true) {
				xuat(b, nb);
				cout << endl;
			}
		}
	}
}
//cau 4 ================================================================
void day_Con_Toan_Duong_Dai_Nhat(int a[], int n) {
	int nb;
	int b[MAX];
	int max = 0;
	int vt;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n-i+1; j++)
		{
			nb = 0;
			for (int k = i; k <= j+i-1; k++) {
				b[nb] = a[k];
				nb++;
			}
			if (check_Toan_Duong(b, nb) == true) {
				if (max < nb) {
					max = nb;
					vt = i;
				}
			}
		}
	}
	cout << "\nMang toan duong dai nhat:\n";
	for (int l = vt; l < max + vt; l++)
	{
		cout << a[l] << " ";
	}
}

//void day_Con_Toan_Duong_Dai_Nhat(int a[], int n) {
//	int maxIdx = 0, maxLen = 0, currLen = 0, currIdx = 0;
//
//	for (int k = 0; k < n; k++) {
//		if (a[k] > 0) {
//			currLen++;
//
//			if (currLen == 1)
//				currIdx = k;
//
//			if (k == n - 1) {
//				if (currLen > maxLen) {
//					maxLen = currLen;
//					maxIdx = currIdx;
//				}
//			}
//		}
//		else {
//			if (currLen > maxLen) {
//				maxLen = currLen;
//				maxIdx = currIdx;
//			}
//			currLen = 0;
//		}
//	}
//
//	if (maxLen > 0) {
//		cout << "\nMang con toan duong dai nhat:\n";
//		for (int l = maxIdx; l < maxLen; l++)
//		{
//			cout << a[l] << " ";
//		}
//	}
//	else
//		cout << "\nKhong ton tai mang con toan duong" << endl;
//}

//cau 5 ====================================================================
void tim_Day_Con_Co_Tong_Lon_Nhat(int a[], int n) {
	cout << "\nDanh sach mang con co tong lon nhat la:" << endl;
	int M = a[0];
	for (int i = 0; i < n; i++) {
		for (int j = 1; j + i < n+1; j++) {
			int tong = 0;
			for (int k = i; k <= j+i-1; k++) {
				tong = tong + a[k];
			}
			if (tong > M) {
				M = tong;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 1; j + i < n + 1; j++) {
			int tong = 0;
			for (int k = i; k <= j+i-1; k++) {
				tong = tong + a[k];
			}
			if (tong == M) {
				for (int l = i; l <= j+i-1; l++)
				{
					cout << a[l] << " ";
				}
				cout << endl;
			}
		}
	}
}