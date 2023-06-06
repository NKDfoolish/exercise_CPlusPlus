/*
* @author: NguyenKhanhDuy
* @Date: 20/12/2022
* @Purpose: Exam final 1 & 2
*/
#include <iostream>
using namespace std;

bool check_sht(int n);
void list_uoc_so_le(int n);
bool check_snt(int x);
void list_snt_be_hon_n(int n);
int dem_sl_chu_so_nn(int n);
void nhap(int a[], int& n);
void xuat(int a[], int& n);
void lietkevatinhtongscp(int a[], int& n);
int gtnntrongmang(int a[], int& n);
void lietkevitrigtnn(int a[], int n);
void sxmangtangdan(int a[], int n);
void Menu();

int main() {
	Menu();
	cout << "\n\nSEE YOU AGAIN <3\n\n";
	cout << endl << endl;
	return 0;
}

void Menu() {
	int n, choose, m;
	int a[100];
	do
	{
		cout << "Nhap vao so nguyen duong n tu ban phim: "; cin >> n;
		if (n <= 0) {
			cout << "n la so nguyen duong. Xin vui long nhap lai !!!";
		}
	} while (n <= 0);
	while (true)
	{
		system("cls");
		cout << "n = " << n << endl;
		cout << "\n================ MENU ==================\n";
		cout << "1. Kiem tra n co phai la so hoan thien hay ko.\n";
		cout << "2. Liet ke tat ca cac uoc so le cua n.\n";
		cout << "3. Liet ke tat ca cac so nguyen to nho hon n.\n";
		cout << "4. Dem so luong chu so nho nhat cua n.\n";
		cout << "5. Xuat mang vua nhap.\n";
		cout << "6. Liet ke va tinh tong cac so chinh phuong co trong mang.\n";
		cout << "7. Liet ke vi tri cua gia tri nho nhat trong mang.\n";
		cout << "8. Sap xep mang tang dan.\n";
		cout << "9. Nhap mang.\n";
		cout << "0. Thoat khoi chuong trinh.\n";
		cout << "\n================ END ===================\n";
		cout << "Nhap lua chon cua ban tu ban phim: "; cin >> choose;
		switch (choose)
		{
		case 1:
			if (check_sht(n) == true) {
				cout << "n la so hoan thien.";
			}
			else
			{
				cout << "n khong phai la so hoan thien.";
			}
			cout << endl;
			system("pause");

			break;
		case 2:
			list_uoc_so_le(n);
			cout << endl;
			system("pause");

			break;
		case 3:
			list_snt_be_hon_n(n);
			cout << endl;
			system("pause");

			break;
		case 4:
			cout << "So luong chu so nho nhat cua n la " << dem_sl_chu_so_nn(n);
			cout << endl;
			system("pause");

			break;
		case 5:
			xuat(a, m);
			cout << endl;
			system("pause");
			break;
		case 6:
			lietkevatinhtongscp(a, m);
			cout << endl;
			system("pause");

			break;
		case 7:
			lietkevitrigtnn(a, m);
			cout << endl;
			system("pause");

			break;
		case 8:
			sxmangtangdan(a, m);
			cout << endl;
			system("pause");

			break;
		case 9:
			cout << "Nhap so luong phan tu cho mang: "; cin >> m;
			nhap(a, m);
			break;
		case 0:
			return;
		}

	}
}
bool check_sht(int n) {
	int sum = 0;
	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			sum = sum + i;
		}
	}
	if (sum == n) {
		return true;
	}
	else
	{
		return false;
	}
}
void list_uoc_so_le(int n) {
	for (int i = 1; i < n; i+=2) {
		if (n % i == 0) {
			cout << i << " ";
		}
	}
}
bool check_snt(int x) {
	if (x < 2) {
		return false;
	}
	for (int i = 2; i < sqrt(x); i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}
void list_snt_be_hon_n(int n) {
	for (int i = 2; i < n; i++) {
		if (check_snt(i) == true) {
			cout << i << " ";
		}
	}
}
int dem_sl_chu_so_nn(int n) {
	int temp = n;
	int min = n % 10;
	int quantity = 0;
	while (n!=0)
	{
		if ((n % 10) < min) {
			min = n % 10;
		}
		n = n / 10;
	}
	while (temp!=0)
	{
		if (temp % 10 == min) {
			quantity++;
		}
		temp = temp / 10;
	}
	return quantity;
}
void nhap(int a[], int& n)
{
	cout << "**********NHAP**********\n";
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap pt thu " << i << ": "; cin >> a[i];
	}
	cout << endl;
}

void xuat(int a[], int& n)
{
	cout << "**********XUAT**********\n";
	for (int i = 0; i < n; i++)
	{
		cout << "Pt thu " << i << " la: " << a[i] << endl;
	}
	cout << endl;
}

void lietkevatinhtongscp(int a[], int& n)
{
	int S = 0;
	cout << "Liet ke cac so chinh phuong: ";
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < a[i]; j++)
		{
			if (a[i] == (j * j))
			{
				cout << a[i] << "\t";
				S = S + a[i];
				break;
			}
		}
	}
	cout << "\nTong cac so chinh phuong: " << S;
}

int gtnntrongmang(int a[], int& n)
{
	int min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (min > a[i])
			min = a[i];
	}
	return min;
}

void lietkevitrigtnn(int a[], int n)
{
	cout << "Ket qua vi tri: ";
	int min = gtnntrongmang(a, n);
	for (int i = 0; i < n; i++)
	{
		if (a[i] == min)
		{
			cout << i << " ";
		}
	}
}

void sxmangtangdan(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[i])
			{
				int tam = a[i];
				a[i] = a[j];
				a[j] = tam;
			}
		}
	}
}