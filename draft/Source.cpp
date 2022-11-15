/*
* @author: Nguyen Khanh Duy
* @Date: 1/11/2022
* @Purpose: Exercises in class
*/
#include <iostream>
using namespace std;

// Nguyen mau ham
void bai_1a();
void bai_1b();
void bai_1c();
void bai_1d();
void bai_1e();
void bai_2a();
void bai_2b();
void bai_2c();
void bai_2d();
void bai_2e();
void bai_3();
void bai_4();
void bai_7();
void bai_8();
void bai_9();
void bai_10();

// Xu ly
int main() {
	
	while (true)
	{
		system("cls");
		cout << "\n====================================== MENU ===============================================================================\n";
		cout << "Nhap 1 so nguyen duong n. Hay cho biet\n";
		cout << "1. Co phai la so doi xung\n";
		cout << "2. Co phai la so chinh phuong\n";
		cout << "3. Co phai la so nguyen to\n";
		cout << "4. Chu so lon nhat va nho nhat\n";
		cout << "5. Cac chu so co tang dan hay giam dan khong.\n";
		cout << "               --------------------                 \n";
		cout << "Nhap 1 so nguyen duong n ,tinh:\n";
		cout << "6. S = 1 + 2 + ... + n\n";
		cout << "7. S = 1^2 + 2^2 + ... + n^2\n";
		cout << "8. S = 1 + 1/2 + ... + 1/n\n";
		cout << "9. S = 1 * 2 * 3 * ... * n = n!\n";
		cout << "10. S = 1! + 2! + ... + n!\n";
		cout << "               --------------------                 \n";
		cout << "11. Nhap 3 so nguyen a,b voi a,b < n. Tinh tong cac so nguyen duong nho hon n chia het cho a nhung khong chia het cho b.\n";
		cout << "               --------------------                 \n";
		cout << "12. Tinh tong cac so nguyen to nho hon n.\n";
		cout << "               --------------------                 \n";
		cout << "13. Nhap 1 so nguyen duong n, xuat ra so nguoc lai.\n";
		cout << "               --------------------                 \n";
		cout << "14. In ra cac so nguyen duong tu 10 - 99 thoa man dieu kien tich cua 2 chu so bang 2 lan tong hai chu so\n";
		cout << "               --------------------                 \n";
		cout << "15. Tim uoc so chung lon nhat cua 2 so nguyen duong a,b.\n";
		cout << "               --------------------                 \n";
		cout << "16. Nhap n, in ra so dau tien trong day Fibonacy\n";
		cout << "               --------------------                 \n";
		cout << "0.Thoat khoi chuong trinh.\n";
		cout << "==========================================================================================================================\n\n\n";
		int choice;
		cout << "Nhap lua chon cua ban: "; cin >> choice; cout << endl;
		switch (choice)
		{
		case 1: 
			bai_1a();
			cout << endl;
			system("pause");
			break;
		case 2: 
			bai_1b();
			cout << endl;
			system("pause");
			break;
		case 3:
			bai_1c();
			cout << endl;
			system("pause");
			break;
		case 4:
			bai_1d();
			cout << endl;
			system("pause");
			break;
		case 5:
			bai_1e();
			cout << endl;
			system("pause");
			break;
		case 6:
			bai_2a();
			cout << endl;
			system("pause");
			break;
		case 7:
			bai_2b();
			cout << endl;
			system("pause");
			break;
		case 8:
			bai_2c();
			cout << endl;
			system("pause");
			break;
		case 9:
			bai_2d();
			cout << endl;
			system("pause");
			break;
		case 10:
			bai_2e();
			cout << endl;
			system("pause");
			break;
		case 11:
			bai_3();
			cout << endl;
			system("pause");
			break;
		case 12:
			bai_4();
			cout << endl;
			system("pause");
			break;
		case 13:
			bai_7();
			cout << endl;
			system("pause");
			break;
		case 14:
			bai_8();
			cout << endl;
			system("pause");
			break;
		case 15:
			bai_9();
			cout << endl;
			system("pause");
			break;
		case 16:
			bai_10();
			cout << endl;
			system("pause");
			break;
		case 0: return 0;
		default:
			cout << "Xin vui long nhap lai\n";
			cout << endl;
			system("pause");
			break;
		}
	}

	return 0;
}

// Ham

void bai_1a() {
	/*
	So doi xung
	*/
	int n, r, sum = 0, temp;

	cout << "Nhap n: ";
	cin >> n;

	for (temp = n; n != 0; n = n / 10) {
		r = n % 10;
		sum = sum * 10 + r;
	}
	if (temp == sum)
		cout << temp << " la so doi xung";
	else
		cout << temp << " khong la so doi xung";
}

void bai_1b() {
	/*
	So chinh phuong
	*/
	int n;
	cout << "Nhap n: ";
	cin >> n;
	int i = 0;
	while (i * i <= n) {
		if (i * i == n) {
			cout << n << " la so chinh phuong!\n";
			return;
		}
		i++;
	}
	cout << n << " khong phai so chinh phuong!\n";
}

void bai_1c() {
	/*
	So nguyen to
	*/
	int n;
	cout << "Nhap n: ";
	cin >> n;
	if (n < 2) {
		cout << n << " khong phai la so nguyen to";
		return;
	}
	int count = 0;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			count++;
		}
	}
	if (count == 0) {
		printf("\n%d la so nguyen to", n);
	}
	else {
		printf("\n%d khong phai so nguyen to", n);
	}
}

void bai_1d() {
	/*
	Chu so lon nhat va nho nhat
	*/
	int i, n, temp1, temp2;
	int max = 0;
	int min;
	cout << "\nNhap n: ";
	cin >> n;
	temp1 = n;
	temp2 = n;
	do {
		i = n % 10;
		if (i > max)
		{
			max = i;
		}
	} while (n /= 10);
	cout << "\nChu sao lon nhat " << temp1 << " la: " << max;
	do {
		i = temp2 % 10;
		min = i;
	} while (n /= 10);
	cout << " \nChu so nho nhat " << temp1 << " la: " << min;
}

void bai_1e() {
	/*
	Chu so tang dan hay giam dan
	*/
	int n;
	cout << "Nhap vao n: ";
	cin >> n;
	int a;
	int i = 0;
	int m = n;
	int arr[100];
	int count = 0;
	int count2 = 0;
	int count3 = 0;

	while (n != 0)
	{
		a = n % 10;
		arr[i] = a;
		i++;
		count++;
		n = n / 10;
	}

	for (i = 0; i < count; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (arr[i] < arr[j])
			{
				count2++;

			}
			else if (arr[i] > arr[j])
			{
				count3++;
			}

		}
	}

	if (count2 == 0)
	{
		cout << "So nguyen duong " << m << " tang dan tu trai qua phai";
	}
	else if (count3 == 0)
	{
		cout << "So nguyen duong " << m << " giam dan tu trai sang phai";
	}
	else {
		cout << "So nguyen duong " << m << " khong tang dan hay giam dan";
	}
}

void bai_2a() {
	int n;
	cout << "Nhap vao n: ";
	cin >> n;
	int S = 0;
	for (int i = 0; i <= n; i++)
	{
		S = S + i;
	}
	cout << "Tong la: " << S;
}

void bai_2b() {

	int n;
	cout << "Nhap vao n: ";
	cin >> n;
	int S = 0;

	for (int i = 0; i <= n; i++)
	{
		S = S + i * i;
	}
	cout << "Tong la: " << S;
}

void bai_2c() {

	int n;
	cout << "Nhap vao n: ";
	cin >> n;
	float S = 0;
	for (int i = 1; i <= n; i++)
	{
		S = S + (float)1 / i;
	}
	cout << "Tong la: " << S;
}

void bai_2d() {

	int n;
	cout << "Nhap vao n: ";
	cin >> n;
	int T = 1;
	for (int i = 1; i <= n; i++)
	{
		T = T * i;
	}
	cout << "Tich la: " << T;
}

void bai_2e() {
	int n;
	cout << "Nhap vao n: ";
	cin >> n;
	int S = 0;
	int var = 1;
	for (int i = 1; i <= n; i++)
	{
		var = var * i;
		S = S + var;
	}
	cout << "Tong la: " << S;
}

void bai_3() {
	/*
	Tinh tong cac so nguyen duong nho hon n chia het cho a nhung khong chia het cho b
	*/
	int a, b, n;
	do
	{
		cout << "Nhap so nguyen a: "; cin >> a;
		cout << "Nhap so nguyen b: "; cin >> b;
		cout << "Nhap so nguyen n: "; cin >> n;
	} while (a > n || b > n);
	int tong = 0;
	for (int i = a; i < n; i++)
	{
		if (i % a == 0 && i % b != 0)
		{
			tong = tong + i;
		}
	}
	cout << "Tong la: " << tong;
}

void bai_4() {
	/*
	Tinh tong cac so nguyen to nho hon n.
	*/
	int n;
	do
	{
		cout << "Nhap n: "; cin >> n;
	} while (n <= 0 || n >= 50);
	int tong = 0;
	for (int i = 2; i < n; i++)
	{
		for (int j = 2; j <= i; j++)
		{
			if (i % j == 0 && i != j)
			{
				break;
			}
			else if (i == j)
			{
				tong = tong + i;
			}
		}
	}
	cout << "Tong la: " << tong;
}

void bai_7() {
	/*
	xuat ra so nguoc lai
	*/
	int n;
	cin >> n;
	while (n) {
		cout << n % 10;
		n = n / 10;
		if (n == 0) {
			break;
		}
	}
}

void bai_8() {
	/*
	In ra cac so nguyen duong tu 10 - 99 thoa man dieu kien tich cua 2 chu so bang 2 lan tong hai chu so
	*/
	cout << "Tat cac cac so nguyen trong pham vi tu 10 - 99 thoa man dieu kien: ";
	for (int i = 10; i <= 99; i++) {
		if (((i % 10) * (i / 10)) == (2 * (i % 10 + i / 10))) {
			cout << i << " ";
		}
	}
}

void bai_9() {
	/*
	Tim uoc so chung lon nhat cua 2 so nguyen duong a,b
	*/
	int num_1, num_2;
	do
	{
		cout << "Nhap so nguyen duong thu nhat: "; cin >> num_1;
		cout << "Nhap so nguyen duong thu hai: "; cin >> num_2;
		if (num_1 < 0 || num_2 < 0)
		{
			cout << "Xin vui lai nhap lai 2 so nguyen duong\n";
		}
	} while (num_1 < 0 || num_2 < 0);
	while (num_1 != num_2)
	{
		if (num_1 > num_2) num_1 = num_1 - num_2;
		else if (num_2 > num_1) num_2 = num_2 - num_1;
	}
	cout << "Uoc so chung lon nhat cua hai so la: " << num_1;
}

void bai_10() {
	/*
	in ra so dau tien trong day Fibonacy
	*/
	int n;
	cout << "Nhap n";
	cin >> n;
	int f0 = 1;
	int f1 = 1;
	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			cout << f0 << " ";
		}
		else if (i == 1) {
			cout << f1 << " ";
		}
		else {
			int fn = f0 + f1;
			f0 = f1;
			f1 = fn;
			cout << fn << " ";
		}
	}
}