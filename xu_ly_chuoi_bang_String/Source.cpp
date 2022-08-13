#include <iostream>
#include <string>
using namespace std;
void chuan_hoa(string& s);
void so_doi_xung_toi_thieu(string& s);

void main()
{

	//string s = "   kI       thUAt laP         triNH     ";
	//chuan_hoa(s);
	//cout << s <<"|" << endl;

	string s = "2321";
	so_doi_xung_toi_thieu(s);
	cout << s << endl;

}
void chuan_hoa(string& s)
{
	//đầu
	while (s[0] == ' ')
	{
		s.erase(s.begin() + 0);
	}
	//cuối
	while (s.back() == ' ')
	{
		s.pop_back();
	}
	//giữa
	int n = s.length();
	for (int i = 1; i < n; i++)
	{
		if (s[i] == ' ' && s[i + 1] == ' ')
		{
			s.erase(s.begin() + i);
			i--;
			n--;
		}
	}
	//in hoa, thường
	if (s[0] >= 97 && s[0] <= 122)
	{
		s[0] -= 32;
	}

	for (int i = 1; i < n; i++)
	{
		if (s[i] == ' ')
		{
			i++;//Nhảy lên vị trí cần in hoa - s[i] cần in hoa
			if (s[i] >= 97 && s[i] <= 122)
			{
				s[i] -= 32;
			}
		}
		else
		{
			if (s[i] >= 65 && s[i] <= 90)
			{
				s[i] += 32;
			}
		}
	}
}
void so_doi_xung_toi_thieu(string& s)
{
	//s: 12345321
	//	 01234567

	int n = s.length();
	for (int i = 0; i < n / 2; i++)
	{
		if (s[i] != s[n - i - 1])//ko bằng
		{
			s.insert(s.begin() + n - i, s[i]);
			n++;
		}
	}

	//s: 2321
	//s1: 2321232
	//s2: 12321


	// back : tra ve giá tri tai n-1
	// begin + end: tra ve con tro quan ly tại vi tri dau va vi tri cuoi n (!=n-1)
}