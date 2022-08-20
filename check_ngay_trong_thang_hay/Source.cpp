#include <iostream>
using namespace std;

int main()
{
	int month, year;
	cout << "Nhap thang: ";
	cin >> month;
	cout << "\nNhap nam: ";
	cin >> year;
	int x = ((month == 4 || month == 6 || month == 9 || month == 11) ? 30 : (month == 2) ? 29 : 31);
	int y = ((month == 4 || month == 6 || month == 9 || month == 11) ? 30 : (month == 2) ? 28 : 31);
	cout << "\nSo ngay trong thang la: " << ((((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0) ? x : y);
	(((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0) ? cout << "\nDay la nam nhuan." : cout << "\nDay la nam khong nhuan.";

	return 0;
}