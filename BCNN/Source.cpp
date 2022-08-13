#include<iostream>
using namespace std;

/* Tìm bội chung nhỏ nhất của 2 số nguyên
CV1 - Nhập 2 số nguyên a và b
CV2 - Tìm ước chung lớn nhất của a và b
CV3 - Tìm bội chung nhỏ nhất của a và b

*/

// hàm tìm ước chung lớn nhất với 2 tham số hình thức là a và b
int Tim_UCLN(int a, int b)
{
	// thuật toán euclid
	while (a != b)
	{
		if (a > b)
		{
			a = a - b;
		}
		else if (a < b)
		{
			b = b - a;
		}
	}
	return a;
}

// hàm tìm bội chung nhỏ nhất với 2 tham số hình thức là a và b
int Tim_BCNN(int a, int b)
{
	return (a * b) / Tim_UCLN(a, b);
}
int main()
{
	int a;
	int b;
	cout << "\nNhap so nguyen a: ";
	cin >> a;
	cout << "\nNhap so nguyen b: ";
	cin >> b;

	//cout << "\nUoc chung lon nhat la: " << Tim_UCLN(a, b);
	cout << "\nBoi chung nho nhat la: " << Tim_BCNN(a, b);
	return 0;
}