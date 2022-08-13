#include <iostream> 
using namespace std;

void Xu_li(int n)
{
	int count_500 = 0, count_200 = 0, count_100 = 0, count_50 = 0;

	while (n >= 500)
	{
		n = n - 500;
		count_500++;
	}
	while (n >= 200)
	{
		n = n - 200;
		count_200++;
	}
	while (n >= 100)
	{
		n = n - 100;
		count_100++;
	}
	while (n >= 50)
	{
		n = n - 50;
		count_50++;
	}
	if (count_500 != 0)
	{
		cout << count_500 << " to 500 ";
	}
	if (count_200 != 0)
	{
		cout << count_200 << " to 200 ";
	}
	if (count_100 != 0)
	{
		cout << count_100 << " to 100 ";
	}
	if (count_50 != 0)
	{
		cout << count_50 << " to 50 ";
	}
}

int main()
{
	int MAX = 1000;
	int chon, mat_khau;
	int n;
	char x;
	cout << "\n\n\t\t\t\t\t\tXIN CHAO QUY KHACH\n\n\n";
	cout << "Xin moi quy khach nhap lua chon de thuc hien.\n\n";
	cout << "Nhap 1: Thu hien thao tac rut tien.\n\n";
	cout << "Nhap 2: Thoat.\n\n";
	cout << "Nhap lua chon: ";
	cin >> chon;

	if (chon != 2)
	{
		cout << "\n\n\t\t\tDE DAM BAO AN TOAN CHO QUY KHACH VUI LONG QUY KHACH NHAP MAT KHAU CUA MINH\n\n\n";
		do
		{
			do
			{
				cout << "Nhap mat khau: ";
				cin >> mat_khau;
				if (mat_khau != 123456789 || mat_khau < 9999999)
				{
					cout << "QUY KHACH NHAP SAI MAT KHAU!!!\n\n";
					cout << "VUI LONG KIEM TRA LAI.\n\n";
					cout << "QUY KHACH HAY NHAP LAI MAT KHAU.\n\n\n";
				}
			} while (mat_khau != 123456789 || mat_khau < 9999999);
			cout << "\n\n\t\t\t------------------------- NHAP SO TIEN QUY KHACH CAN RUT -----------------------------\n\n\n";
			do
			{
				cout << "Nhap so tien: ";
				cin >> n;
				if (n < 50 || n % 50 != 0 || n > 1000)
				{
					cout << "\tSO TIEN BAN NHAP KHONG HOP LE.\n\n";
					cout << "\tVUI LONG KIEM TRA LAI.\n\n";
					cout << "\tSO TIEN NHAP PHAI LON HON 50 VA PHAI LA SO CHIA HET CHO 100.\n\n";
					cout << "Nhap lai so tien: ";
				}
			} while (n < 50 || n % 50 != 0 || n > 1000);
			MAX = MAX - n;
			if (MAX < 0)
			{
				cout << "\nCAY ATM DA HET TIEN.\n";
				cout << "QUY KHACH VUI LONG DEN DOT SAU NHE.\n\n";
				break;
			}
			cout << "\nSo tien duoc tra nhu sau.\n\n";
			cout << n << " = ";
			Xu_li(n);
			cout << "\n\n\t\t\t\tBAN CO MUON TIEP TUC RUT TIEN KHONG.\n\n";
			cout << "NEU MUON TIEP TUC RUT TIEN HAY CHON (Y | y).\n\n";
			cout << "NEU KHONG MUON TIEP TUC RUT TIEN HAY CHON (N | n).\n\n";
			cout << "NHAP LUA CHON CUA BAN: ";
			cin >> x;

		} while (MAX >= 0 && (x == 'Y' || x == 'y'));
	}

}