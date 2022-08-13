#include <iostream>
using namespace std;

int main()
{
	int a[5] = { 1,4,8,3,0 };
	int b[4] = { 4,0,3,8 };
	int n = 4;
	int m = 5;
	int j = 0;
	int dem = 0;
	bool KT = false;
	for (int i = 0; i < m; i++)
	{
		if (a[i] == b[j])
		{
			dem++;
			j++;
			if (dem == n)
			{
				KT = true;
				break;
			}
		}
		else
		{
			KT = false;
			j = 0;
			dem = 0;
		}
	}
	if (KT == true)
	{
		cout << "\nCo ton tai ham con.";
	}
	else
	{
		cout << "\nKhong ton tai ham con.";
	}
	return 0;
}