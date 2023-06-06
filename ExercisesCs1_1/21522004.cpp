#include <iostream>
using namespace std;

int so_nghich_dao(int n);
bool check_so_nguyen_to(int n);
bool check_so_chinh_phuong(int n);
int tong_uoc(int n);
int tong_cac_chu_so(int n);


int main() {
	int n;
	cout << "Nhap n tu ban phim : ";
	cin >> n;
	while (true)
	{
		system("cls");
		int choose;
		cout << "n = " << n << endl;
		cout << "----------------------------- Menu -----------------------------\n";
		cout << "1. Kiem tra n co phai so nguyen to hay khong?\n";
		cout << "2. Kiem tra n co phai so chinh phuong hay khong?\n";
		cout << "3. Tinh tong uoc so cua n\n";
		cout << "4. Tinh tong cac chu so cua n\n";
		cout << "5. in ra so nghich dao cua n\n";
		cout << "0. Thoat khoi chuong trinh\n";
		cout << "----------------------------- End ------------------------------\n";
		cout << "Nhap lua chon cua ban (1-5): ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			if (check_so_nguyen_to(n) == true) {
				cout << n << " la so nguyen to";
			}
			else
			{
				cout << n << " khong la so nguyen to";
			}
			system("pause");
			break;
		case 2:
			if (check_so_chinh_phuong(n) == true) {
				cout << n << " la so chinh phuong";
			}
			else
			{
				cout << n << " khong la so chinh phuong";
			}
			system("pause");
			break;
		case 3:
			cout << "Tong uoc so cua n: " << tong_uoc(n);
			system("pause");
			break;
		case 4:
			cout << "Tong cac chu so cua n: " << tong_cac_chu_so(n);
			system("pause");
			break;
		case 5:
			cout << "So nghich dao cua n: " << so_nghich_dao(n);
			system("pause");
			break;
		case 0:

			return 0;

		}
	}
	return 0;
}


bool check_so_nguyen_to(int n) {
	if (n < 2) {
		return 0;
	}
	else {
		for (int i = 2; i <= sqrt(n); ++i) {
			if (n % i == 0) {
				return 0;
			}
		}
	}
	return 1;
}

bool check_so_chinh_phuong(int n) {
	int k = sqrt(n);
	if (k * k == n) {
		return 1;
	}
	else {
		return 0;
	}
}

int tong_uoc(int n) {
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		if (n % i == 0) {
			sum += i;
		}
	}
	return sum;
}

int tong_cac_chu_so(int n) {
	int sum = 0;
	while (n != 0) {
		int k = n % 10;
		sum += k;
		n /= 10;
	}
	return sum;
}

int so_nghich_dao(int n) {
	int temp = 0;
	while (n != 0) {
		temp = temp * 10 + n % 10;
		n = n / 10;
	}
	return temp;
}