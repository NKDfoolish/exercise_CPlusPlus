/*
@author : Nguyen Khanh Duy
@date: 29/11/2022 ~ 3/12/2022
@purpose: exercises 
*/

#include <iostream>
using namespace std;
#define MAX 100


void nhap_mang(int arr[], int n);
void xuat_mang(int arr[], int n);
int kiem_tra_phan_tu(int arr[], int n, int x);
int check_snt(int x);
int check_mang_nguyen_to(int arr[], int n);
int dem_sl_gt_chan(int arr[], int n);
int tong_pt_chan(int arr[], int n);
int tim_min_max(int arr[], int n, int flag); 
void sx_mang_tang_dan(int arr[], int n);
void sx_mang_giam_dan(int arr[], int n);
void them(int arr[], int& n, int x, int vt);
void sua(int arr[], int n, int _old, int _new);
void xoa(int arr[], int& n, int vt);
bool check_mang_toan_chan(int arr[], int n);
bool check_mang_tang_dan(int arr[], int n);
int so_pt_ch4_kch5(int arr[], int n);
int tong_cac_so_nguyen_to_co_trong_mang(int arr[], int n);
int vtend_pt_x(int arr[], int n, int x);
int mininarr(int a[], int n);
int mininarr_positive(int a[], int n);
void sx_theo_dk(int a[], int& n);
void tach_mang_a_thanh_mang_b_mang_c(int a[], int n, int b[], int c[]);
void tachsonguyento(int a[], int& n, int b[], int& nb);
void sua_snt_sang_so_0(int arr[], int n);
void chen_0_dang_sau_snt(int arr[], int& n);
void xoa_snt(int arr[], int& n);

int main() {
	int arr[MAX];
	int b[MAX];
	int c[MAX];
	int n, x, vt;
	int nb = 0;

	cout << "Nhap so luong phan tu n: "; cin >> n;
	nhap_mang(arr, n);

	while (true)
	{
		system("cls");// clear terminal
		cout << "---------------------------------------- MENU ----------------------------------\n";
		cout << "1. Nhap phan tu cho mang\n";
		cout << "2. Xuat phan tu trong mang\n";
		cout << "3. Tim phan tu trong mang\n";
		cout << "4. Kiem tra mang co toan so nguyen to hay khong\n";
		cout << "5. Dem so luong gia tri chan\n";
		cout << "6. Tong cac phan tu chan trong mang\n";
		cout << "7. Tim gia tri min va max trong mang\n";
		cout << "8. Sap xep mang tang dan\n";
		cout << "9. Sap xep mang giam dan\n";
		cout << "10. Them 1 phan tu vao mang\n";
		cout << "11. Sua 1 phan tu trong mang\n";
		cout << "12. Xoa 1 phan tu trong mang\n";
		cout << "13. Kiem tra mang co phai mang toan chan\n";
		cout << "14. Kiem tra mang co phai mang tang dan\n";
		cout << "15. So phan tu chia het cho 4 ma khong chia het cho 5 trong mang\n";
		cout << "16. Tong cac so nguyen to co trong mang\n";
		cout << "17. Vi tri phan tu x cuoi cung trong mang\n";
		cout << "18. Tim so nho nhat trong mang\n";
		cout << "19. Tim so duong nho nhat trong mang\n";
		cout << "20. Sap xep theo dieu kien (duong giam dan - am tang dan - 0)\n";
		cout << "21. Tach mang a thanh mang b duong va mang c con lai.\n";
		cout << "22. tach so nguyen to tu mang a sang mang b\n";
		cout << "23. Sua so nguyen to thanh so 0\n";
		cout << "24. Chen them so 0 dang sau so nguyen to\n";
		cout << "25. Xoa so nguyen to trong mang\n";
		cout << "0. Thoat khoi chuong trinh\n";
		cout << "---------------------------------------- END -----------------------------------\n";

		int choose;
		cout << "Nhap lua chon cua ban tu ban phim: "; cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "Nhap so luong phan tu n: "; cin >> n;
			nhap_mang(arr, n);
			break;
		case 2:
			xuat_mang(arr, n);
			cout << endl;
			system("pause");
			break;
		case 3:
			cout << "\nNhap x: "; cin >> x;
			if (kiem_tra_phan_tu(arr, n, x) >= 0) {
				cout << "Co ton tai phan tu mang gia tri " << x << " trong mang, tai vi tri a[" << kiem_tra_phan_tu(arr, n, x) << "]";
			}
			else
			{
				cout << "Khong ton tai phan tu mang gia tri " << x;
			}
			cout << endl;
			system("pause");
			break;
		case 4:
			if (check_mang_nguyen_to(arr, n) == 1) {
				cout << "Mang toan so nguyen to";
			}
			else
			{
				cout << "Mang khong phai la mang toan so nguyen to";
			}
			cout << endl;
			system("pause");
			break;
		case 5:
			cout << "So luong gia tri chan trong mang la: " << dem_sl_gt_chan(arr, n);
			cout << endl;
			system("pause");
			break;
		case 6:
			cout << "Tong cac phan tu chan trong mang: " << tong_pt_chan(arr, n);
			cout << endl;
			system("pause");
			break;
		case 7:
			cout << "Gia tri min trong mang: " << tim_min_max(arr, n, 0) << endl;
			cout << "Gia tri max trong mang: " << tim_min_max(arr, n, 1);
			cout << endl;
			system("pause");
			break;
		case 8:
			sx_mang_tang_dan(arr, n);
			break;
		case 9:
			sx_mang_giam_dan(arr, n);
			break;
		case 10:
			cout << "Nhap gia tri can them: "; cin >> x;
			cout << "Nhap vi tri can them: "; cin >> vt;
			them(arr, n, x, vt);
			break;
		case 11:
			cout << "Nhap gia tri can sua: "; cin >> x;
			cout << "Nhap gia tri moi: "; cin >> vt;
			sua(arr, n, x, vt);
			break;
		case 12:
			cout << "Nhap gia tri can xoa: "; cin >> x;
			xoa(arr, n, x);
			break;
		case 13:
			if (check_mang_toan_chan(arr, n) == true)cout << "Mang toan chan.";
			else { cout << "Mang khong toan chan"; }
			cout << endl;
			system("pause");
			break;
		case 14:
			if (check_mang_tang_dan(arr, n) == true)cout << "Mang tang dan.";
			else { cout << "Mang khong phai mang tang dan"; }
			cout << endl;
			system("pause");
			break;
		case 15:
			cout << "So phan tu chia het cho 4 ma khong chia het cho 5: " << so_pt_ch4_kch5(arr, n);
			cout << endl;
			system("pause");
			break;
		case 16:
			cout << "Tong cac so nguyen to trong mang: " << tong_cac_so_nguyen_to_co_trong_mang(arr, n);
			cout << endl;
			system("pause");
			break;
		case 17:
			cout << "Nhap gia tri can tim: "; cin >> x;
			if (vtend_pt_x(arr, n, x) == -1) {
				cout << "Khong ton tai vi tri cua gia tri can tim.";
			}
			else
			{
				cout << "Vi tri cuoi cung cua phan tu " << x << " la: " << vtend_pt_x(arr, n, x);

			}
			cout << endl;
			system("pause");
			break;
		case 18:
			cout << "So nho nhat trong mang la: " << mininarr(arr, n);
			cout << endl;
			system("pause");
			break;
		case 19:
			if (mininarr_positive(arr, n) <= 0) {
				cout << "Khong co so duong nho nhat trong mang.";
			}
			else
			{
				cout << "So duong nho nhat trong mang la: " << mininarr_positive(arr, n);
			}
			cout << endl;
			system("pause");
			break;
		case 20:
			sx_theo_dk(arr, n);
			break;
		case 21:
			tach_mang_a_thanh_mang_b_mang_c(arr, n, b, c);
			cout << endl;
			system("pause");
			break;
		case 22:
			tachsonguyento(arr, n, b, nb);
			cout << endl;
			system("pause");
			break;
		case 23:
			sua_snt_sang_so_0(arr, n);
			break;
		case 24:
			chen_0_dang_sau_snt(arr, n);
			break;
		case 25:
			xoa_snt(arr, n);
			break;
		case 0:
			cout << "See you later!!! <3<3";
			cout << endl;
			return 0;
		}
	}

	return 0;
}

void nhap_mang(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Nhap phan tu thu arr[" << i << "]: "; cin >> arr[i];
	}
}
void xuat_mang(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}
}

int kiem_tra_phan_tu(int arr[], int n, int x) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == x) {
			return i;
		}
	}
	return -1;
}
int check_snt(int x) {
	/*if (x == 2) {
		return 1;
	}
	else if(x < 2) {
		return 0;
	}
	else
	{
		for (int i = 3; i < x; i++) {
			if (x % i == 0) return 0;
		}
	}
	return 1;*/

	if (x < 2) return false;
	else
	{
		for (int i = 2; i <= sqrt(x); i++) {
			if (x % i == 0) return false;
		}
	}
	return true;
}

int check_mang_nguyen_to(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		if (check_snt(arr[i]) == 0) return 0;
	}
	return 1;
}

int dem_sl_gt_chan(int arr[], int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			count = count + 1;
		}
	}
	return count;
}
int tong_pt_chan(int arr[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			sum = sum + arr[i];
		}
	}
	return sum;
}
int tim_min_max(int arr[], int n, int flag) {
	// 0: min   1: max
	int min = arr[0];
	int max = arr[0];
	/*for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] < arr[j]) {
				max = arr[j];
			}
			else if (arr[i] > arr[j])
			{
				min = arr[j];
			}
		}
	}*/
	for (int i = 1; i < n; i++) {
		if (arr[i] > max) max = arr[i];
		else if (arr[i] < min) min = arr[i];
	}
	if (flag == 0) {
		return min;
	}
	else if ( flag == 1)
	{
		return max;
	}
}
void sx_mang_tang_dan(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[i]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
void sx_mang_giam_dan(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[j] > arr[i]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
void them(int arr[], int& n,int x, int vt) {
	for (int i = n; i > vt; i--) {
		arr[i] = arr[i - 1];
	}
	arr[vt] = x;
	n = n + 1;
}
void sua(int arr[], int n, int _old, int _new) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == _old) arr[i] = _new;
	}
}
void xoa(int arr[], int& n, int vt) {
	for (int i = vt; i < n; i++) {
		arr[i] = arr[i + 1];
	}
	n = n - 1;
}
bool check_mang_toan_chan(int arr[], int n) {
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 != 0) return false;
	}
	return true;
}
bool check_mang_tang_dan(int arr[], int n){
	for (int i = 1; i < n; i++) {
		if (arr[i] < arr[i - 1]) return false;
	}
	return true;
}
int so_pt_ch4_kch5(int arr[], int n) {
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 4 == 0 && arr[i] % 5 != 0) count = count + 1;
	}
	return count;
}
int tong_cac_so_nguyen_to_co_trong_mang(int arr[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (check_snt(arr[i]) == true) sum = sum + arr[i];
	}
	return sum;
}
int vtend_pt_x(int arr[], int n, int x) {
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] == x) return i;
	}
	return -1;
}
int mininarr(int a[], int n) {
	int min = a[0];
	for (int i = 1; i < n; ++i) {
		if (a[i] < min) {
			min = a[i];
		}
	}
	return min;
}
int mininarr_positive(int a[], int n) {
	int min = a[0];
	for (int i = 1; i < n; ++i) {
		if (a[i] < min && a[i] > 0) {
			min = a[i];
		}
	}
	return min;
}
 // duong giam dan -> am tang dan -> 0
void sx_theo_dk(int a[], int &n) {
	int count = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[j] > a[i] && a[j] > 0) {
				int temp1 = a[i];
				a[i] = a[j];
				a[j] = temp1;
			}
			else if (a[j] < a[i] && a[j] < 0 && a[i] < 0) {
				int temp2 = a[i];
				a[i] = a[j];
				a[j] = temp2;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0) {
			xoa(a, n, i);
			i--;
			count++;
		}
	}
	for (int i = 1; i <= count; i++)
	{
		them(a, n, 0, n);
	}
}
void tach_mang_a_thanh_mang_b_mang_c(int a[], int n, int b[], int c[]) {
	int bi = 0;
	int ci = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] > 0) {
			b[bi++] = a[i];
		}
		else {
			c[ci++] = a[i];
		}
	}

	cout << "mang a: " << endl;
	for (int i = 0; i < n; i++) {
		cout << "arr[" << i << "] = " << a[i] << endl;
	}
	cout << "mang b: " << endl;
	for (int i = 0; i < bi; i++) {
		cout << "b[" << i << "] = " << b[i] << endl;
	}
	cout << "mang c: " << endl;
	for (int i = 0; i < ci; i++) {
		cout << "b[" << i << "] = " << c[i] << endl;
	}
}
void tachsonguyento(int a[], int& n, int b[], int& nb) {
	for (int i = 0; i < n; i++) {
		if (check_snt(a[i])) {
			b[nb] = a[i];
			nb++;
			xoa(a, n, i);
		}
	}
	cout << "mang a: " << endl;
	for (int i = 0; i < n; i++) {
		cout << "arr[" << i << "] = " << a[i] << endl;
	}
	cout << "mang b: " << endl;
	for (int i = 0; i < nb; i++) {
		cout << "b[" << i << "] = " << b[i] << endl;
	}
}
void sua_snt_sang_so_0(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		if (check_snt(arr[i]) == true) sua(arr, n, arr[i], 0);
	}
}
void chen_0_dang_sau_snt(int arr[], int &n) {
	for (int i = 0; i < n; i++) {
		if (check_snt(arr[i]) == true) them(arr, n, 0, i + 1);
	}
}
void xoa_snt(int arr[], int &n) {
	for (int i = 0; i < n; i++)
	{
		if (check_snt(arr[i]) == true) {
			xoa(arr, n, i); 
			i = i - 1;
		}
	}
}