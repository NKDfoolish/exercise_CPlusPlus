#include <iostream>
using namespace std;
void Tim_so_lon_thu_k(int n, int k)
{
	int p, h, max, temp;
	int m = n;
	int t = n;
	int count = 0;
	int dem = 0;
	int w = 0;
	int l = 10;
	while (true)
	{
		h = 0;
		max = 0;
		while (m != 0)
		{
			temp = m % 10;
			if (max < temp)
			{
				max = temp;
			}
			m = m / 10;
		}
		++count;
		while (n != 0)
		{
			p = (n % 10);
			if (p == max)
			{

			}
			else
			{
				h = h * 10 + p;
			}

			n = n / 10;
		}
		m = h;
		n = h;
		while (t != 0)
		{
			int v = t % 10;
			if (v != l)
			{
				++dem;
			}
			l = v;
			t = t / 10;
		}
		if (count == k)
		{
			cout << "\nSo lon thu " << count << " la: " << max;
			break;
		}
		if (k > dem)
		{
			cout << "\nKhong co vi chu so lon thu " << k;
			break;
		}
	}

}
int main()
{
	int n, k;
	do
	{
		cout << "\nNhap so nguyen duong n: ";
		cin >> n;
		cout << "\nNhap vao chu so lon thu k: ";
		cin >> k;
		if (n <= 0)
		{
			cout << "\nBan da nhap sai so nguyen duong! Vui long nhap lai.\n";
		}
	} while (n <= 0);
	Tim_so_lon_thu_k(n, k);
	return 0;
}