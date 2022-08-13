#include <iostream>
#include <vector>
#include <string>
using namespace std;
int lay_so(string& s, int& i, int& n);
string sap_xep(string s);
void xuat(vector<int> a);
void sap_xep_giam(vector<int>& a);
void xu_ly_them(string& s, vector<int> gt, vector<int> cs);
void main()
{
	//abc24d0123e07gf1
	//      i

	//abc1d7e24gf123

	string s = "abc204dddd00001203e070gf1";
	string c = sap_xep(s);
	cout << c << endl;
	system("pause");
}
string sap_xep(string s)
{
	//abc24d0000123e07gf1
	//      i

	vector<int> gt;
	vector<int> cs;
	int n = s.length();
	for (int i = 0; i < n; i++)
	{
		//------ xử lý số 0 ----
		if (s[i] == '0')
		{
			s.erase(s.begin() + i);//xóa
			n--;//giảm
			i--;//lùi
		}
		//---- lấy đủ số -----
		else if (s[i] >= 48 && s[i] <= 57)//lấy ichữ số đầu tên
		{
			//cout << lay_so(s, i,n) <<"   "<<i<< endl;
			int x = lay_so(s, i, n);
			gt.push_back(x);
			cs.push_back(i);
		}
	}
	//============ đã có 2 mảng + 1 chuỗi rỗng số =====
	//gt: 204 1203 70 1
	//cs: 3 7 8 10

	//gt: 1203 204 70 1
	//cs: 10   8   7  3

	sap_xep_giam(gt);
	sap_xep_giam(cs);
	xuat(gt);
	xuat(cs);
	//---- Duyệt theo mảng cs để xử lý thêm ------
	xu_ly_them(s, gt, cs);
	return s;
}
void xu_ly_them(string& s, vector<int> gt, vector<int> cs)
{
	int n = cs.size();
	for (int i = 0; i < n; i++)
	{
		string y = to_string(gt.at(i));
		int x = cs.at(i);
		s.insert(x, y);//thêm chuỗi y tại vt x
	}
}
void sap_xep_giam(vector<int>& a)
{
	int n = a.size();
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a.at(j) > a.at(i))//a.at() chỉ xem thôi  a[i] tương tác vùng nhớ
			{
				swap(a[i], a[j]);//lưu
			}
		}
	}
}
void xuat(vector<int> a)
{
	int n = a.size();
	for (int i = 0; i < n; i++)
	{
		cout << a.at(i) << "   ";
	}
	cout << endl;
}
int lay_so(string& s, int& i, int& n)
{
	int so = s[i] - 48;

	for (int j = i + 1; j < n; j++)//lấy các số còn lại
	{
		if (s[j] < 48 || s[j]>57)//j ko phải số
		{
			break;
		}
		else
		{
			int x = s[j] - 48;
			so = so * 10 + x;
			//xóa
			s.erase(s.begin() + j); n--;
			j--;//lùi
		}
	}
	s.erase(s.begin() + i); n--;
	//abcdddd1203e70gf1
	//   i
	//    j

	//so = 204

	return so;
}