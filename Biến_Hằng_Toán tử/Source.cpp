#include <iostream>
using namespace std;
#define MAX 100
int main()
{
	int a, b;
	cout << "\nNhap vao so nguyen a: ";
	cin >> a;
	cout << "\nNhap vao so nguyen b: ";
	cin >> b;
	cout << "\nTong la: " << a + b;
	cout << "\nDia chi o nho cua bien a la: " << &a;
	cout << "\nDia chi o nho cua bien b la: " << &b << endl;;
	cout << MAX;
	const float PI = 3.14;

	return 0;
}