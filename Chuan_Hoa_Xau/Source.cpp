#include <iostream>
using namespace std;
int do_dai(char c[]);
void thong_ke(char c[]);
void xoa(char c[], int vt);
void chuan_hoa(char c[]);

void main()
{
	char c[50] = "   kI       thUAt laP         triNH     ";
	//cout << "nhap c: "; gets_s(c);
	cout << c << "|" << endl;

	//cout << do_dai(c) << endl;
	//thong_ke(c);
	chuan_hoa(c);

	cout << c << "|" << endl;
}
void thong_ke(char c[])
{
	int  n = do_dai(c);
	//cong thanh
	for (int i = 0; i < n; i++)
	{
		//---- Kiểm tra pt c[i] đã thống kê chưa ---
		bool kt = false;//Chưa thống kê
		for (int j = 0; j < i; j++)
		{
			if (c[j] == c[i])
			{
				kt = true;//ĐÃ THỐNG KÊ
				break;
			}
		}
		if (kt == false)
		{
			//---- Thống kê ----
			int dem = 1;
			for (int j = i + 1; j < n; j++)
			{
				if (c[j] == c[i])
				{
					dem++;
				}
			}
			cout << "Ki tu " << c[i] << ": lap " << dem << " lan." << endl;
		}
	}
}
int do_dai(char c[])
{
	int i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return i;
}
void xoa(char c[], int vt)
{
	int n = do_dai(c);
	for (int i = vt; i < n; i++)
	{
		c[i] = c[i + 1];
	}
}
void chuan_hoa(char c[])
{
	//c = "   kI       thUAt laP         triNH     "

	//---- cắt khoảng trắng ở đầu ---
	while (c[0] == ' ')
	{
		xoa(c, 0);
	}
	//--- Cắt khoảng trắng ở cuối --
	int n = do_dai(c);
	while (c[n - 1] == ' ')
	{
		c[n - 1] = '\0';//xoá cuối
		n--;//Theo dõi sl pt hiệu tại của xâu
	}
	//--- Cắt khoảng trắng ở giữa ---
	for (int i = 1; i < n; i++)
	{
		if (c[i] == ' ' && c[i + 1] == ' ')
		{
			xoa(c, i);
			n--;//Theo dõi sl pt hiện tại

			i--;//Lùi tránh sót pt
		}
	}
	//--- in hoa, thường ----
	if (c[0] >= 97 && c[0] <= 122)
	{
		c[0] -= 32;
	}

	for (int i = 1; i < n; i++)
	{
		if (c[i] == ' ')
		{
			i++;//Nhảy lên vị trí cần in hoa - c[i] cần in hoa
			if (c[i] >= 97 && c[i] <= 122)
			{
				c[i] -= 32;
			}
		}
		else
		{
			if (c[i] >= 65 && c[i] <= 90)
			{
				c[i] += 32;
			}
		}
	}
}