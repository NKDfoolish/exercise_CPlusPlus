#include <iostream>
using namespace std;

int main()
{
	int a[9] = { 1,4,8,3,0,1,4,8,3 };
	int b[4] = { 1,4,8,3 };
	int n = 4;
	int m = 9;
	int j = 0;
	int dem = 0;
	bool KT = false;
	int count = 0;
	for (int i = 0; i < m; i++)
	{
		if (a[i] == b[j])
		{
			dem++;
			j++;
			if (dem == n)
			{
				count++;
			}
		}
		else
		{
			j = 0;
			dem = 0;
		}
	}
	if (count > 0)
	{
		cout << "\nCo ton tai ham con. voi so lan xuat hien la: ";
		cout << count;
	}
	else
	{
		cout << "\nKhong ton tai ham con.";
	}
	return 0;
}