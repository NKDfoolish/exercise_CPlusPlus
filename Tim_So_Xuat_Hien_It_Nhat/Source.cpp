#include <iostream>
using namespace std;
#define Max 10
void Tim_So_Xuat_Hien_It_Nhat(int x);
int main()
{
	int x;
	do
	{
		cout << "\nNhap so nguyen x tu ban phim: "; cin >> x;
	} while (x<=0);
	Tim_So_Xuat_Hien_It_Nhat(x);

	return 0;
}
void Tim_So_Xuat_Hien_It_Nhat(int x)
{
	cout << "\nChu so xuat hien it nhat la: ";
	int a[Max] = {};
	int n = x;
	int Min;
	int max = 0;
	while (n!=0)
	{
		int temp = n % 10;
		if (temp >= max)
		{
			max = temp;
		}
		++a[temp];
		n /= 10;
	}
	Min = max;
	for (int i = 0; i < Max; ++i)
	{
		if (a[i] > 0)
		{
			if (a[i] < Min)
			{
				Min = a[i];
			}
		}
	}
	for (int i = 0; i < Max; ++i)
	{
		if (a[i] == Min)
		{
			cout << i << ", ";
		}
	}
}