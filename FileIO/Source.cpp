#include <iostream>
#include <fstream>
#define MAX 100
using namespace std;

void load_file_lv1(int a[], int& n);
void xuat(int a[], int n);
void phan_tu_lon_nhat(int a[], int n);
void load_file_lv2(int a[], int& n);
void xuat_so_armstrong(int a[], int n);
void load_file_lv3(int a[], int& n);
void UCLN_BCNN_cua_day_so(int a[], int n);

int main() {
	int a[MAX]; int n = 0;
	load_file_lv3(a, n);
	xuat(a, n);
	UCLN_BCNN_cua_day_so(a, n);
	return 0;
}
void load_file_lv1(int a[], int& n) {
	ifstream fi;
	fi.open("D:\\UIT\\Dream\\BeCoding\\visual studio 2022\\Becoding\\input.txt", ios_base::in);

	if (fi.fail()) {
		cout << "Mo khong duoc! " << endl;
		system("pause");
		return;
	}

	fi >> n;
	for (int i = 0; i < n; i++)
	{
		fi >> a[i];
	}

	fi.close();
}
void xuat(int a[], int n) {
	cout << "\t\t========== Xuat ==========\n";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
void phan_tu_lon_nhat(int a[], int n) {
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i]>max)
		{
			max = a[i];
		}
	}
	cout << "\nPhan tu max : " << max;
}
void load_file_lv2(int a[], int& n) {
	ifstream fi;
	fi.open("D:\\UIT\\Dream\\BeCoding\\visual studio 2022\\Becoding\\input.txt", ios_base::in);

	if (fi.fail()) {
		cout << "Mo khong duoc! " << endl;
		system("pause");
		return;
	}

	while (fi.eof() == false)
	{
		fi >> a[n++];
	}

	fi.close();
}
int CountDigit(int n)
{
	int count = 0;
	while (n > 0)
	{
		n /= 10;
		++count;
	}
	return count;
}
bool IsArmstrong(int n)
{
	int numDigit = CountDigit(n);
	int tmp = n, sum = 0, last;
	while (tmp > 0)
	{
		last = tmp % 10; // lấy chữ số cuối cùng
		tmp /= 10;       // bỏ chữ số cuối cùng
		sum += pow(last, numDigit);
	}
	if (sum == n)
		return true;
	return false;
}
void xuat_so_armstrong(int a[], int n) {
	cout << "\n\t\t ================ Amrstrong ============\n";
	for (int i = 0; i < n; i++)
	{
		if (IsArmstrong(a[i]) == true) {
			cout << a[i] << " ";
		}
	}
}
void load_file_lv3(int a[], int& n) {
	ifstream fi;
	fi.open("D:\\UIT\\Dream\\BeCoding\\visual studio 2022\\Becoding\\input.txt", ios_base::in);

	if (fi.fail()) {
		cout << "Mo khong duoc! " << endl;
		system("pause");
		return;
	}

	while (fi.eof() == false)
	{
		fi >> a[n++];
		fi.ignore();
	}

	fi.close();
}
int UCLN(int a, int b) {
	while (a!=b)
	{
		(a > b) ? a = a - b :b = b - a;
	}
	return a;
}
int BCNN(int a, int b) {
	return ((a * b) / UCLN(a,b));
}
void UCLN_BCNN_cua_day_so(int a[], int n) {
	int ucln = UCLN(a[0], a[1]);
	int bcnn = BCNN(a[0], a[1]);
	for (int i = 2; i < n; i++)
	{
		ucln = UCLN(ucln, a[i]);
		bcnn = BCNN(bcnn, a[i]);
	}
	cout << "\nUCLN: " << ucln;
	cout << "\nBCNN: " << bcnn;
}