#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct bdiem {
	float diem_Mac_Lenin = NULL;
	float diem_dai_so = NULL;
	float diem_c_plusplus = NULL;
};
typedef struct bdiem bdiem;

struct sv {
	string ma_sv;
	string ho_ten;
	string phai;
	string ngay_sinh;
	bdiem bang_diem;
};
typedef struct sv sv;

void nhap_1_sv(sv& a);
void xuat_1_sv(sv a);
void xuat_ds_sv(sv ds[], int n);
void load_file1(sv ds[], int& n);
void load_file2(sv ds[], int& n);
void ghi_file(sv ds[], int n);
bool check_ma_sv(string a, sv ds[], int n);
void xoa_sv(sv ds[], int& n, int vt);
void tim_masv(sv ds[], int& n, string name);
void xoa_sv_thong_qua_mssv(sv ds[], int& n);
string tach_ten(string name, int th);
void sx_sv_tang_theo_ho_ten(sv ds[], int n);
void nhap_bang_diem_cho_sinh_vien(sv ds[], int& n);
int tach_ngay_thang_nam_sinh(string date, int st);
void sx_sv_tang_dan_theo_ngay_thang_nam_sinh(sv ds[], int n);
void xu_ly_ngay_thang_nam(string c, int& day, int& month, int& year);
void calendar(int& day, int& month, int& year, bool& check, int& day_max_of_month);
void xoa(string c, int vt);
void chuan_hoa_ngay_thang_nam(string& c, int& count, bool& check, int& day, int& month, int& year);
void nhap_ngay_thang_nam_sinh(string& c);
void chuan_hoa_ho_ten(string& s);

istream& operator >>(istream& is, sv& a);
ostream& operator <<(ostream& os, sv a);

int main() {
	sv ds[100] = {}; int n = 0;
	bool kt_menu = true;

	while (kt_menu == true)
	{
		system("cls");
		cout << "1. Nhap sinh vien" << endl;
		cout << "2. Xuat danh sanh sinh vien" << endl;
		cout << "3. Load file" << endl;
		cout << "4. Ghi file" << endl;
		cout << "5. Xoa sinh vien" << endl;
		cout << "6. Sap xep sinh vien tang dan theo ho ten" << endl;
		cout << "7. Nhap bang diem cho sinh vien" << endl;
		cout << "8. Sap xep sinh vien tang dan theo ngay thang nam sinh" << endl;
		cout << "0. Thoat" << endl;
		int lc;
		cout << "Nhap lua chon: "; cin >> lc;
		switch (lc)
		{
		case 1:
		{
			int sl;
			cout << "Nhap sl sinh vien can them: ";
			cin >> sl;
			for (int i = 0; i < sl; i++)
			{
				cin.ignore();
				sv a;
				cout << "\t\t----- Nhap sv thu " << i + 1 << " -----" << endl;
				cin >> a;
				bool check_masv = true;
				while (check_masv == true) {
					if (check_ma_sv(a.ma_sv, ds, n) == true) {
						cout << "\nMa so sinh vien da ton tai. Vui long nhap lai.\n";
						cin.ignore();
						cin >> a;
					}
					else
					{
						ds[n++] = a;
						check_masv = false;
					}
				}
			}
			break;
		}
		case 2:
		{
			xuat_ds_sv(ds, n);
			system("pause");
			break;
		}
		case 3:
		{
			load_file2(ds, n);
			break;
		}
		case 4:
		{
			ghi_file(ds, n);
			break;
		}
		case 5:
		{
			cin.ignore();
			xoa_sv_thong_qua_mssv(ds, n);
			system("pause");
			break;
		}
		case 6:
		{
			sx_sv_tang_theo_ho_ten(ds, n);
			break;
		}
		case 7:
		{
			nhap_bang_diem_cho_sinh_vien(ds, n);
			system("pause");
			break;
		}
		case 8:
		{
			sx_sv_tang_dan_theo_ngay_thang_nam_sinh(ds, n);
			break;
		}
		case 0:
		{
			kt_menu = false;
			break;
		}
		}
	}
	return 0;
}
void nhap_1_sv(sv& a) {
	string s;
	cout << "Nhap ma sinh vien: "; getline(cin, a.ma_sv);
	cout << "Nhap ho ten sinh vien: "; getline(cin, s);
	chuan_hoa_ho_ten(s);
	a.ho_ten = s;
	cout << "Nhap gioi tinh sinh vien: "; getline(cin, a.phai);
	nhap_ngay_thang_nam_sinh(a.ngay_sinh);
}
istream& operator >>(istream& is, sv& a) {
	string s;
	cout << "Nhap ma sinh vien: "; getline(cin, a.ma_sv);
	cout << "Nhap ho ten sinh vien: "; getline(cin, s);
	chuan_hoa_ho_ten(s);
	a.ho_ten = s;
	cout << "Nhap gioi tinh sinh vien: "; getline(cin, a.phai);
	nhap_ngay_thang_nam_sinh(a.ngay_sinh);
	return is;
}
void xuat_1_sv(sv a) {
	cout << "Ma sinh vien: " << a.ma_sv << endl;
	cout << "Ho ten sinh vien: " << a.ho_ten << endl;
	cout << "Gioi tinh sinh vien: " << a.phai << endl;
	cout << "Ngay sinh cua sinh vien: " << a.ngay_sinh << endl;
	cout << "Bang diem sinh vien: " << endl;
	cout << "Diem Mac Lenin: " << a.bang_diem.diem_Mac_Lenin << endl;
	cout << "Diem dai so: " << a.bang_diem.diem_dai_so << endl;
	cout << "Diem c++: " << a.bang_diem.diem_c_plusplus << endl;
}
ostream& operator <<(ostream& os, sv a) {
	cout << "Ma sinh vien: " << a.ma_sv << endl;
	cout << "Ho ten sinh vien: " << a.ho_ten << endl;
	cout << "Gioi tinh sinh vien: " << a.phai << endl;
	cout << "Ngay sinh cua sinh vien: " << a.ngay_sinh << endl;
	cout << "Bang diem sinh vien: " << endl;
	cout << "Diem Mac Lenin: " << a.bang_diem.diem_Mac_Lenin << endl;
	cout << "Diem dai so: " << a.bang_diem.diem_dai_so << endl;
	cout << "Diem c++: " << a.bang_diem.diem_c_plusplus << endl;
	return os;
}
void xuat_ds_sv(sv ds[], int n) {
	cout << "\t\t======= Xuat danh sach sinh vien =======" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Sinh vien thu " << i << " : " << endl;
		cout << ds[i];
	}
}
void load_file1(sv ds[], int& n) {
	ifstream fi;
	fi.open("input.txt", ios_base::in);

	fi >> n;
	fi.ignore();// bỏ '\n'
	for (int i = 0; i < n; i++)
	{
		sv a;
		getline(fi, a.ma_sv, ',');
		getline(fi, a.ho_ten, ',');
		getline(fi, a.phai, ',');
		getline(fi, a.ngay_sinh, ',');
		fi >> a.bang_diem.diem_Mac_Lenin;
		fi.ignore();
		fi >> a.bang_diem.diem_dai_so;
		fi.ignore();
		fi >> a.bang_diem.diem_c_plusplus;
		fi.ignore();// bỏ '\n'

		ds[i] = a;
	}

	fi.close();
}
void load_file2(sv ds[], int& n) {
	ifstream fi;
	fi.open("input.txt", ios_base::in);

	while (fi.eof() == false) {
		sv a;
		getline(fi, a.ma_sv, ',');
		getline(fi, a.ho_ten, ',');
		getline(fi, a.phai, ',');
		getline(fi, a.ngay_sinh, ',');
		fi >> a.bang_diem.diem_Mac_Lenin;
		fi.ignore();
		fi >> a.bang_diem.diem_dai_so;
		fi.ignore();
		fi >> a.bang_diem.diem_c_plusplus;
		fi.ignore();

		ds[n++] = a;
	}

	fi.close();
}
void ghi_file(sv ds[], int n) {
	ofstream fo;
	fo.open("output.txt", ios_base::out);

	for (int i = 0; i < n; i++)
	{
		fo << ds[i].ma_sv << "," << ds[i].ho_ten << "," << ds[i].phai << ",";
		fo << ds[i].ngay_sinh << "," << ds[i].bang_diem.diem_Mac_Lenin << ",";
		fo << ds[i].bang_diem.diem_dai_so << "," << ds[i].bang_diem.diem_c_plusplus;

		if (i != n - 1) {
			fo << endl;
		}
	}

	fo.close();
}
bool check_ma_sv(string a, sv ds[], int n) {
	for (int i = 0; i < n; i++)
	{
		if (a == ds[i].ma_sv)
			return true;
	}
	return false;
}
void xoa_sv(sv ds[], int& n, int vt) {
	for (int i = vt; i < n - 1; i++)
	{
		ds[i] = ds[i + 1];
	}
	n--;
}
void tim_masv(sv ds[], int& n, string name) {
	for (int i = 0; i < n; i++)
	{
		if (name == ds[i].ma_sv) {
			xoa_sv(ds, n, i);
			cout << "\nXoa thanh cong";
		}
		else
		{
			cout << "\nKhong tim duoc ma so sinh vien tuong thich.";
		}
	}
}
void xoa_sv_thong_qua_mssv(sv ds[], int& n) {
	string name;
	cout << "\nNhap ma so sinh vien can tim:";
	getline(cin, name);
	tim_masv(ds, n, name);
}
string tach_ten(string name, int th) {
	string ten;
	int i = name.length() - 1;
	while (name[i] != ' ')
	{
		ten.insert(ten.begin() + 0, name[i]);
		name.pop_back();
		i--;
	}
	name.pop_back();
	if (th == 1) {
		return ten;
	}
	else if (th == 2)
	{
		return name;
	}
}
void sx_sv_tang_theo_ho_ten(sv ds[], int n) {
	for (int i = 0; i < n - 1; i++) {
		string t_1 = tach_ten(ds[i].ho_ten, 1);
		string h_1 = tach_ten(ds[i].ho_ten, 2);
		for (int j = i + 1; j < n; j++) {
			string t_2 = tach_ten(ds[j].ho_ten, 1);
			string h_2 = tach_ten(ds[j].ho_ten, 2);
			if (t_1 > t_2)
				swap(ds[i], ds[j]);
			else if (t_1 == t_2) {
				if (h_1 > h_2)
					swap(ds[i], ds[j]);
			}
		}
	}
}
void nhap_bang_diem_cho_sinh_vien(sv ds[], int& n) {
	string name;
	cout << "\nNhap ma so sinh vien can tim:";
	cin.ignore();
	getline(cin, name);
	for (int i = 0; i < n; i++)
	{
		if (name == ds[i].ma_sv) {
			cout << "Nhap bang diem sinh vien:" << endl;
			cout << "Nhap diem Mac Lenin: "; cin >> ds[i].bang_diem.diem_Mac_Lenin;
			cout << "Nhap diem dai so: "; cin >> ds[i].bang_diem.diem_dai_so;
			cout << "Nhap diem c++: "; cin >> ds[i].bang_diem.diem_c_plusplus;
			return;
		}
	}
	cout << "\nKhong tim duoc ma so sinh vien tuong thich.";


}
int tach_ngay_thang_nam_sinh(string date, int st) {
	string day, month, year;
	int i = 0; int d = 0; int m = 0; int y = 0;

	while (date[i] != '/')
	{
		day.insert(day.end(), date[i++]);
	}
	i++;
	while (date[i] != '/')
	{
		month.insert(month.end(), date[i++]);
	}
	i++;
	while (i < date.length())
	{
		year.insert(year.end(), date[i++]);

	}


	int day_int = stoi(day);
	int month_int = stoi(month);
	int year_int = stoi(year);
	if (st == 1)
		return year_int;
	else if (st == 2)
		return month_int;
	else if (st == 3)
		return day_int;
}
void sx_sv_tang_dan_theo_ngay_thang_nam_sinh(sv ds[], int n) {
	int year1, month1, day1;
	int year2, month2, day2;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++) {
			year1 = tach_ngay_thang_nam_sinh(ds[j].ngay_sinh, 1);
			year2 = tach_ngay_thang_nam_sinh(ds[i].ngay_sinh, 1);
			if (year1 > year2) {
				swap(ds[j], ds[i]);
			}
			else if (year1 == year2)
			{
				month1 = tach_ngay_thang_nam_sinh(ds[j].ngay_sinh, 2);
				month2 = tach_ngay_thang_nam_sinh(ds[i].ngay_sinh, 2);
				if (month1 > month2) {
					swap(ds[j], ds[i]);
				}
				else if (month1 == month2)
				{
					day1 = tach_ngay_thang_nam_sinh(ds[j].ngay_sinh, 3);
					day2 = tach_ngay_thang_nam_sinh(ds[i].ngay_sinh, 3);
					if (day1 > day2) {
						swap(ds[j], ds[i]);
					}
				}
			}
		}
	}
}
void xu_ly_ngay_thang_nam(string c, int& day, int& month, int& year) {
	int k = 0;
	int l = 0;
	string d, m, y;
	while (c[k] != '/')
	{
		d.insert(d.end(), c[k++]);
	}
	day = stoi(d);

	k++;
	l = 0;
	while (c[k] != '/')
	{
		m.insert(m.end(), c[k++]);

	}
	month = stoi(m);

	k++;
	l = 0;
	while (k < c.length())
	{
		y.insert(y.end(), c[k++]);

	}
	year = stoi(y);
}

void calendar(int& day, int& month, int& year, bool& check, int& day_max_of_month) {
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
		}
		else if (day >= 1 && day <= 28)
		{
			cout << "Ngay hop le" << endl;
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
void chuan_hoa_ngay_thang_nam(string& c, int& count, bool& check, int& day, int& month, int& year) {
	int day_max = 0;
	int n = c.length();
	if (n < 5) {
		check = false;
		cout << "\nngay thang nam sinh sai dinh dang.\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		if (c[i] == ' ') {
			c.erase(c.begin() + i);
			i--;
			n--;
		}
	}
	for (int i = 0; i < n; i++) {

		if (c[i] == '/') {
			count++;
			if (count > 2) {
				check = false;
				cout << "\nChi co duy nhat 2 ki tu \"/\" trong chuoi \n";
				return;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (c[i] == '/') {
			if (c[i + 1] < 48 || c[i + 1] > 57) {
				check = false;
				cout << "\nngay thang nam sinh sai dinh dang.\n";
				return;
			}
		}
	}

	xu_ly_ngay_thang_nam(c, day, month, year);
	calendar(day, month, year, check, day_max);
}
void nhap_ngay_thang_nam_sinh(string& c) {
	int day = 0; int month = 0; int year = 0;
	int count;
	bool check = true;
	do
	{
		check = true;
		count = 0;
		cout << "Nhap ngay thang nam sinh: ";
		getline(cin, c);
		chuan_hoa_ngay_thang_nam(c, count, check, day, month, year);

	} while ((count != 2) || (check == false));
}
void chuan_hoa_ho_ten(string& s)
{
	while (s[0] == ' ')
	{
		s.erase(s.begin() + 0);
	}
	while (s.back() == ' ')
	{
		s.pop_back();
	}
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
	if (s[0] >= 97 && s[0] <= 122)
	{
		s[0] -= 32;
	}

	for (int i = 1; i < n; i++)
	{
		if (s[i] == ' ')
		{
			i++;
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
