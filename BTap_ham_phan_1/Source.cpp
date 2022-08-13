#include <iostream>
using namespace std;

int Max_x(int n)
{
	int max = 0;
	int s = 0;
	int dem = 0;
	while (n != 0)
	{
		int temp = n % 10;
		if (temp > max)
		{
			max = temp;
		}
		n = n / 10;
	}
	return max;
}

int main()
{
	int n;
	do
	{
		cout << "Nhap  nguyen duong tu ban phim: ";
		cin >> n;
	} while (n <= 0);
	cout << "\nChu so max la: " << Max_x(n);

	return 0;
}