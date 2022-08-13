#include <iostream>
using namespace std;
#include <math.h>

int main()
{
	int a, b;
	cout << "Nhap a,b nguyen duong: ";
	cin >> a >> b;
	if (a > 0 && b > 0)
	{
		a = ((a + b) + abs(a - b)) / 2;
		cout << "\nSo lon nhat la: " << a;
	}
	else
	{
		cout << "\nSo da nhap khong hop le ! Khong phai so nguyen duong , vui long nhap lai.";
	}

	return 0;
}