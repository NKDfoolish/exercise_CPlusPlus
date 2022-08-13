#include <iostream>
#include <string>
using namespace std;

string hieu_TH1(string x, string y);
void main()
{
	string x;
	string y;
	cout << "Nhap x: "; getline(cin, x);
	cout << "Nhap y: "; getline(cin, y);
	string c = hieu_TH1(x, y);
	cout << c << endl;
	system("pause");
}
string hieu_TH1(string x, string y)//x,y cùng dương và x > y
{
	int i = x.length() - 1;
	int j = y.length() - 1;
	string c = "";
	int nho = 0;
	while (i >= 0 || j >= 0)
	{
		int so;
		if (j < 0)//y het pt
		{
			so = (x[i] - 48) - nho;
			nho = 0;
		}
		else
		{
			int gtx = x[i] - 48;
			int gty = y[j] - 48;
			if (gtx >= (gty + nho))//đủ để trừ
			{
				so = (x[i] - 48) - (y[j] - 48) - nho;
				nho = 0;
			}
			else//thiếu => mượn
			{
				so = 10 + (x[i] - 48) - (y[j] - 48) - nho;
				nho = 1;
			}
		}
		//--- thêm số vào đầu c ----
		c.insert(c.begin() + 0, (so + 48)); i--; j--;
	}
	if (c[0] == '0')
	{
		c.erase(c.begin() + 0);
	}
	return c;
}