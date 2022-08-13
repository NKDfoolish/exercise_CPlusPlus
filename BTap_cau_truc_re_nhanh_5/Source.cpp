#include <iostream>
using namespace std;

int main()
{
	float n,m;
	cout << "Nhap so thuc thu nhat: ";
	cin >> n;
	cout << "\nNhap so thuc thu hai: ";
	cin >> m;
	if (n < m)
	{
		n = m;
	}
	cout << "\nNhap so thuc thu ba: ";
	cin >> m;
	if (n < m)
	{
		n = m;
	}
	cout << "\nNhap so thuc thu tu: ";
	cin >> m;
	if (n < m)
	{
		n = m;
	}
	cout << "\nSo lon nhat la: " << n;


	return 0;
}