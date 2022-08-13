#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int convert_str_to_int(char c[]);
void convert_int_to_str(int a);
void chuan_hoa_ngay_thang_nam(char c[], int& count, bool& check, int& day, int& month, int& year);
void kiem_tra_thang_co_bnh_ngay();
void tinh_lich_cong_ngay(char c[], int& count, bool& check);
void tinh_khoang_cach(int day_1, int month_1, int year_1, int day_2, int month_2, int year_2);
void cong_tru(char a[], char b[]);
void sap_xap_chuoi_so_tang_dan(char c[]);
void tinh_tong_cac_so_trong_chuoi(char c[]);
void tong(string s);
string tong_cung_duong(string x, string y);

int main() {
	int day = 0; int month = 0; int year = 0;
	int day2 = 0; int month2 = 0; int year2 = 0;
	char c[100];
	char c2[100];
	int a;
	int a2;
	int count;
	int count2;
	bool check = true;
	bool check2 = true;

	/*cout << "nhap a:" << endl;
	cin >> a;*/


	/*do
	{
		count = 0;
		cout << "Nhap chuoi: ";
		gets_s(c);
		chuan_hoa_ngay_thang_nam(c, count, check, day, month, year);
		if (count != 2) {
			cout << "\nChi co duy nhat 2 ki tu \"/\" trong chuoi ";
		}
	} while ((count != 2) || (check == false));

	do
	{
		count2 = 0;
		cout << "Nhap chuoi: ";
		gets_s(c2);
		chuan_hoa_ngay_thang_nam(c2, count2, check2, day2, month2, year2);
		if (count2 != 2) {
			cout << "\nChi co duy nhat 2 ki tu \"/\" trong chuoi ";
		}
	} while ((count2 != 2) || (check2 == false));

	tinh_khoang_cach(day, month, year, day2, month2, year2);*/

	//gets_s(c);
	//sap_xap_chuoi_so_tang_dan(c);
	//tinh_tong_cac_so_trong_chuoi(c);
	//cout << c;
	/*gets_s(c2);
	cong_tru(c, c2);*/

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
int so_chu_so(int a) {
	int count = 0;
	while (a!=0)
	{
		count++;
		a /= 10;
	}
	return count;
}
int convert_str_to_int(char c[]) {
	int n = strlen(c);
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		num = num * 10 + (int(c[i])-48);
	}
	return num;
}
void convert_int_to_str(int a) {
	int n = so_chu_so(a);
	char* c = new char[n+1];
	int i;
	for (i = n-1; i >= 0; i--)
	{
		int temp = a % 10;
		c[i] = temp+48;
		a /= 10;
	}
	c[n] = '\0';
	cout << c;
	
}

void xu_ly_ngay_thang_nam(char c[],int &day, int &month, int &year) {
	int k = 0;
	int l = 0;
	char d[50];
	char m[50];
	char y[50];
	while (c[k] != '/')
	{
		d[l++] = c[k++];
	}
	d[l] = '\0';
	day = convert_str_to_int(d);

	k++;
	l = 0;
	while (c[k] != '/')
	{
		m[l++] = c[k++];
	}
	m[l] = '\0';
	month = convert_str_to_int(m);

	k++;
	l = 0;
	while (c[k] != '\0')
	{
		y[l++] = c[k++];
	}
	y[l] = '\0';
	year = convert_str_to_int(y);
}

void calendar(int &day, int &month, int &year, bool &check, int &day_max_of_month) {
	switch (month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (day >= 1 && day <= 31) {
			cout << "Ngay hop le" << endl;
			cout << "Thang " << month << " co 31 ngay" << endl;
			day_max_of_month = 31;
		}
		else
		{
			cout << "Ngay khong hop le" << endl;
			check = false;
		}
		break;
	case 2:
		if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && (day >= 1 && day <= 29))
		{
			cout << "Ngay hop le" << endl;
			cout << "Thang " << month << " co 29 ngay" << endl;
			day_max_of_month = 29;
		}
		else if (day >= 1 && day <= 28)
		{
			cout << "Ngay hop le" << endl;
			cout << "Thang " << month << " co 28 ngày" << endl;
			day_max_of_month = 28;
		}
		else
		{
			cout << "Ngay khong hop le" << endl;
			check = false;
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (day >= 1 && day <= 30) {
			cout << "Ngay hop le" << endl;
			cout << "Thang " << month << " co 30 ngay" << endl;
			day_max_of_month = 30;
		}
		else
		{
			cout << "Ngay khong hop le" << endl;
			check = false;
		}
		break;
	default:
		cout << "Thang khong hop le" << endl;
		check = false;
	}
}

void chuan_hoa_ngay_thang_nam(char c[], int &count, bool &check, int &day, int &month, int &year) {
	int day_max = 0;
	int n = do_dai(c);
	for (int i = 0; i < n; i++) {
		if (c[i] == '/') {
			count++;
		}
		if (c[i] == ' ') {
			xoa(c, i);
			i--;
			n--;
		}
	}
	cout << c << endl;
	xu_ly_ngay_thang_nam(c,day,month,year);

	calendar(day, month, year, check, day_max);
	
}
void kiem_tra_thang_co_bnh_ngay() {
	int thang, nam;

	cout << "Thang: ";
	cin >> thang;
	cout << "\nNam: ";
	cin >> nam;

	switch (thang) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		cout << "Thang " << thang << " co 31 ngay" << endl;
		break;
	case 2:
		if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0)
		{
			cout << "Thang " << thang << " co 29 ngay" << endl;
		}
		else
		{
			cout << "Thang " << thang << " co 28 ngày" << endl;
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		cout << "Thang " << thang << " co 30 ngay" << endl;
		break;
	default:
		cout << "Thang khong hop le" << endl;
	}
}
void tinh_lich_cong_ngay(char c[], int& count, bool& check) {
	int temp = 0;
	int num;
	int day = 0; int month = 0; int year = 0; int day_max = 0;
	int n = do_dai(c);
	for (int i = 0; i < n; i++) {
		if (c[i] == '/') {
			count++;
		}
		if (c[i] == ' ') {
			xoa(c, i);
			i--;
			n--;
		}
	}
	cout << c << endl;
	xu_ly_ngay_thang_nam(c, day, month, year);

	calendar(day, month, year, check, day_max);
	cout << "\nNhap so ngay muon cong: "; cin >> num;

	temp = day + num;
	while (temp>=day_max)
	{
		month++;
		temp = temp - day_max;
	}
	day = temp;

	cout << "\nKet qua: " << day << "/" << month << "/" << year;
}
void tinh_khoang_cach(int day_1, int month_1, int year_1, int day_2, int month_2, int year_2) {
	int distance_month = 0;
	int distance_day = 0;
	int distance_year = 0;
	distance_month = abs(month_1 - month_2);
	distance_day = abs(day_1 - day_2);
	distance_year = abs(year_1 - year_2);
	cout << "\n Khoang cach la: " << distance_year << " nam " << distance_month << " thang " << distance_day << " ngay.";
}
void cong_tru(char a[], char b[]) {
	int a_num = convert_str_to_int(a);
	int b_num = convert_str_to_int(b);
	int sum = a_num + b_num;
	int difference = a_num - b_num;
	cout << "\ntong: " << sum << " ; hieu: " << difference;
}
void sap_xap_chuoi_so_tang_dan(char c[]) {
	int n = do_dai(c);
	for (int i = 0; i < n - 1; i++)
	{
		if (c[i] == 48) {
			xoa(c, i);
			i--;
			n--;
		}
		else {
			for (int j = i + 1; j < n; j++)
			{
				if (c[i] > 48 && c[i] <= 57 && c[j] > 48 && c[j] <= 57) {
					if (c[j] < c[i]) {
						swap(c[i], c[j]);
					}
				}
			}
		}
	}
}
void tinh_tong_cac_so_trong_chuoi(char c[]) {
	int n = do_dai(c);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (c[i] >= 48 && c[i] <= 57) {
			sum = sum + (int(c[i]) - 48);
		}
	}
	cout << "\ntong gia tri so trong chuoi: " << sum;
}
void tong(string s)
{
	//s = "abc2456d123e7gf1"
	//                    i
	//		               j
	int n = s.length();
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] >= 48 && s[i] <= 57)
		{
			int so = s[i] - 48;//2
			for (int j = i + 1; j < n; j++)//j<n tránh trường hợp i đang ở pt cuối
			{
				if (s[j] < 48 || s[j] > 57)//khong phai so
				{
					i = j;
					break;
				}
				else//số
				{
					int x = s[j] - 48;//4
					so = so * 10 + x;//2*10 + 4 = 24
				}
			}
			tong += so;//kỹ thuật tính tổng
		}
	}
	cout << "Tong = " << tong << endl;
}
string tong_cung_duong(string x, string y)
{
	int i = x.length() - 1;
	int j = y.length() - 1;

	int nho = 0;
	string c = "";
	while (i >= 0 || j >= 0)
	{
		//---- tính s ------
		int s = 0;
		if (i < 0)//x hết pt
		{
			s = (y[j] - 48) + nho;
		}
		else if (j < 0)//y hết pt
		{
			s = (x[i] - 48) + nho;
		}
		else//2 thằng còn pt
		{
			s = (x[i] - 48) + (y[j] - 48) + nho;
		}
		//---- xử lý thêm vào kq ----
		if (s < 10)
		{
			c.insert(c.begin() + 0, s + 48);//chuyển s thành kí tự rồi thêm đầu c
			nho = 0;//giá trị cho lần lặp tiếp theo
		}
		else
		{
			int du = s % 10;
			c.insert(c.begin() + 0, du + 48);
			nho = 1;//giá trị cho lần lặp tiếp theo
		}
		//----- xét pt tiếp theo ---
		i--;
		j--;
	}
	if (nho == 1)
	{
		c.insert(c.begin() + 0, '1');
	}
	return c;
}
