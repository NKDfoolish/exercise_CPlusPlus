#include <iostream>
using namespace std;
void xu_ly(int n, int& k, int a[])
{
	while (n > 0)
	{
		for (int i = k; i < n; i++)
		{
			cout << a[i];
		}
		n--;
		cout << endl;
	}
}
int main()
{
	int a[5] = { 1,5,2,8,9 };
	int n = 5;
	int m = n;
	int k = 0;
	for (int j = 0; j < n; j++)
	{
		xu_ly(n, k, a);
		cout << "\n===============================\n";
		k++;
		if (k > m)
			break;
	}
	return 0;
}