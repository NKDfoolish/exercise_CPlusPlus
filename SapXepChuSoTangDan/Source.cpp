#include <iostream>
using namespace std;

void Sap_Xep_Tang_Dan(int n)
{
	int p, q, r, l, m;
	int s = 0;
	int h = 0;
	int max = -1;
	int dem = 0;
	int dem_2 = 0;
	int k = 0;
	int dem_3 = 0;
	m = n;
	p = n;
	q = n;
	r = n;
	l = n;
	while (r != 0)// đếm số chữ số trong số nguyên
	{
		r = r / 10;
		++dem_2;
	}
	while (true)
	{
		while (m != 0) // tìm chữ số max
		{
			int temp = m % 10;
			if (max < temp)
			{
				max = temp;
			}
			m = m / 10;
		}
		while (p != 0) // sắp những chữ số = max vô 1 biến 
		{
			int temp_2 = p % 10;
			if (temp_2 == max)
			{
				++dem;
				s = s * 10 + temp_2;
			}
			p = p / 10;
		}
		while (q != 0) // sắp những số không bằng max vô biến khác
		{
			int temp_3 = q % 10;
			if (temp_3 == max)
			{

			}
			else if (temp_3 == 0)
			{
				++dem_3;
			}
			else
			{
				h = h * 10 + temp_3;
			}
			q = q / 10;
		}
		m = h;
		p = h;
		q = h;
		max = -1;
		h = 0;
		if ((dem + dem_3) == dem_2)
		{
			while (s != 0)
			{
				int temp_4 = s % 10;
				k = k * 10 + temp_4;
				s = s / 10;
			}
			cout << "\nSo sau khi sap la: ";
			for (int i = 1; i <= dem_3; i++)
			{
				cout << "0";
			}
			cout << k;
			break;
		}
	}
}

int main()
{
	int n;
	do
	{
		cout << "Nhap gia tri nguyen duong n: ";
		cin >> n;
		if (n <= 0)
		{
			cout << "\nn khong phai la so nguyen duong. Vui long nhap lai.";
		}
	} while (n <= 0);
	Sap_Xep_Tang_Dan(n);

	return 0;
}