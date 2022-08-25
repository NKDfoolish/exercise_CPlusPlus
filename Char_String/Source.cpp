#include <iostream>
#include <string>
using namespace std;

int do_dai(char c[]);
char* sao_chep(char c2[]);
char* sao_chep_2(char c2[]);
void in_thuong(char c[]);
void in_hoa(char c[]);
void dao_xau(char c[]);
void dao_xau_str(string& s);
void them(char c[], int vt, char x);
void xoa(char c[], int vt);
int ss_co_phan_biet_hoa_thuong(char c1[], char c2[]);
int ss_ko_phan_biet_hoa_thuong(char c1[], char c2[]);

void thong_ke_tan_suat_xuat_hien(char c[]);
void chars_condition(char c[]);
//void Palindrom(char c[]);
void chuan_hoa(string& s);
void chuan_hoa_char(char c[]);
void khop_xau(char c1[], char c2[]);
void so_doi_xung_toi_thieu(string s);

int main() {
	/*char c1[100];
	gets_s(c1);

	char c2[100];
	gets_s(c2);

	khop_xau(c1, c2);*/

	string s;
	getline(cin, s);

	so_doi_xung_toi_thieu(s);

	return 0;
}
int do_dai(char c[]) {
	int i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return i;
}
void sao_chep(char c1[], char c2[]) {
	int nc2 = do_dai(c2);
	for (int i = 0; i <= nc2; i++) // = nc2 de lay luon ki tu ket thuc '\0'
	{
		c1[i] = c2[i];
	}
}
char* sao_chep_2(char c2[]) {
	int nc2 = do_dai(c2);
	char* c1 = new char[nc2 + 1];
	for (int i = 0; i <= nc2; i++) // = nc2 de lay luon ki tu ket thuc '\0'
	{
		c1[i] = c2[i];
	}
	return c1;
}
void in_thuong(char c[]) {
	int n = do_dai(c);
	for (int i = 0; i < n; i++)
	{
		if (c[i] >= 65 && c[i] <= 90) {
			c[i] = c[i] + 32;
		}
	}
}
void in_hoa(char c[]) {
	int n = do_dai(c);
	for (int i = 0; i < n; i++)
	{
		if (c[i] >= 97 && c[i] <= 122) {
			c[i] = c[i] - 32;
		}
	}
}
void dao_xau(char c[]) {
	int n = do_dai(c);
	for (int i = 0; i < n / 2; i++)
	{
		swap(c[i], c[n - i - 1]);
	}
}
void dao_xau_str(string& s) {
	int n = s.length();
	for (int i = 0; i < n / 2; i++)
	{
		swap(s[i], s[n - i - 1]);
	}
}
void them(char c[], int vt, char x) {
	int n = do_dai(c);
	for (int i = n + 1; i > vt; i--)
	{
		c[i] = c[i - 1];
	}
	c[vt] = x;
}
void xoa(char c[], int vt) {
	int n = do_dai(c);
	for (int i = vt; i < n; i++)
	{
		c[i] = c[i + 1];
	}
}
int ss_co_phan_biet_hoa_thuong(char c1[], char c2[]) {
	int nc1 = do_dai(c1);
	int nc2 = do_dai(c2);

	int min = (nc1 < nc2) ? nc1 : nc2;

	for (int i = 0; i < min; i++)
	{
		if (c1[i] != c2[i]) {
			return c1[i] - c2[i];
		}
	}
	return nc1 - nc2;
}
int ss_ko_phan_biet_hoa_thuong(char c1[], char c2[]) {
	char* tam1 = sao_chep_2(c1);
	char* tam2 = sao_chep_2(c2);
	in_thuong(tam1);
	in_thuong(tam2);

	int x = ss_co_phan_biet_hoa_thuong(tam1, tam2);

	delete[] tam1;
	delete[] tam2;
	return x;
}
void thong_ke_tan_suat_xuat_hien(char c[]) {
	int n = do_dai(c);

	for (int i = 0; i < n - 1; i++)
	{
		bool check = false;
		for (int k = 0; k < i; k++)
		{
			if (c[k] == c[i]) {
				check = true;
			}
		}
		if (check == false) {
			int count = 1;
			for (int j = i + 1; j < n; j++) {
				if (c[i] == c[j]) {
					count++;
				}
			}
			cout << "\nKi tu " << c[i] << " xuat hien " << count << " lan";
			count = 1;
		}

	}
}
//void xoa_ki_tu_khoang_trang_o_dau_chuoi(char c[]) {
//	int n = do_dai(c);
//	for (int i = 0; i < n; i++)
//	{
//		if (c[0] == ' ') {
//			xoa(c, 0);
//			//i--
//		}
//
//		/*while (c[0]==' ')
//		{
//			xoa(c, 0);
//		}*/
//	}
//}
//void xoa_ki_tu_khoang_trang_o_cuoi_chuoi(char c[]) {
//	int n = do_dai(c);
//	for (int i = n-1; i >= 0; i--)
//	{
//		//if (c[n-1] == ' ') {
//		//	xoa(c, n-1);
//		//	//i--
//		//}
//
//		while (c[n-1]==' ')
//		{
//			xoa(c, n-1);
//			n--;
//		}
//	}
//}
//void cach_nhau_1_khoang_trang(char c[]) {
//	// Nguyen  Khanh   Duy
//	int n = do_dai(c);
//	for (int i = 0; i < n; i++)
//	{
//		if (c[i] == ' ') {
//			if (c[i + 1] == ' ') {
//				xoa(c, i + 1);
//				i--;
//			}
//		}
//	}
//}
//void viet_hoa_chu_cai_dau_moi_tu(char c[]) {
//	int n = do_dai(c);
//	for (int i = 0; i < n; i++)
//	{
//		if (c[i] == ' ') {
//			if (c[i + 1] >= 97 && c[i + 1] <= 122) {
//				c[i + 1] = c[i + 1] - 32;
//			}
//		}
//		else if (c[0] >= 97 && c[0] <= 122) {
//			c[0] = c[0] - 32;
//		}
//	}
//	cout << c;
//}
//void chars_condition(char c[]) {
//	xoa_ki_tu_khoang_trang_o_dau_chuoi(c);
//	xoa_ki_tu_khoang_trang_o_cuoi_chuoi(c);
//	cach_nhau_1_khoang_trang(c);
//	viet_hoa_chu_cai_dau_moi_tu(c);
//}
//

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

void chuan_hoa_char(char c[])
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
void khop_xau(char c1[], char c2[]) {
	int n = do_dai(c1);
	int m = do_dai(c2);
	for (int i = 0; i < n; i++)
	{
		if ((c1[i] == c2[0]) && (n - i >= m)) {
			int start = i;
			bool check = true;
			for (int j = 0; j < m; j++)
			{
				if (c2[j] != c1[start++]) {
					check = false;
					break;
				}
			}
			if (check == true) {
				cout << i << " ";
			}
		}
	}
}

void so_doi_xung_toi_thieu(string s)
{
	//s: 12345321
	//	 01234567
	string s2 = s;
	int n = s.length();
	for (int i = 0; i < n / 2; i++)
	{
		if (s[i] != s[n - i - 1])//ko bằng
		{
			s.insert(s.begin() + n - i, s[i]);
			n++;
		}
	}
	int m = s2.length();
	dao_xau_str(s2);
	for (int i = 0; i < m / 2; i++)
	{
		if (s2[i] != s2[m - i - 1])//ko bằng
		{
			s2.insert(s2.begin() + m - i, s2[i]);
			m++;
		}
	}
	if (s2.length() < s.length()) {
		cout << s2;
	}
	else
	{
		cout << s;
	}

	//s: 2321
	//s1: 2321232
	//s2: 12321


	// back : tra ve giá tri tai n-1
	// begin + end: tra ve con tro quan ly tại vi tri dau va vi tri cuoi n (!=n-1)
}