#include <iostream>
#include <string>
#include <fstream>
using namespace std;

typedef struct bang_diem
{
	float Mac = 0;
	float dai_so = 0;
	float cpp = 0;
}bang_diem;

typedef struct sv
{
	string ma_sv;
	string ho_ten;
	string phai;
	string ngay_sinh;
	bang_diem ds_diem;
}sv;

istream& operator >>(istream& is, sv& a);
ostream& operator <<(ostream& os, sv a);
ostream& operator <<(ostream& os, bang_diem a);
void xuat_ds_sv(sv ds[], int n, bool lc);
void loadfile(sv ds[], int& n);
//=========== xóa ======
void xoa(sv ds[], int& n, int vt);
void xoa_sv_theo_ma_sv(sv ds[], int& n, string s);
//===== Sắp xếp ====
string cat_ho_ten(string s, bool lc);
void sap_xep(sv ds[], int n);
//======= Nhập điểm =====
int kt_trung_ma_sv(sv ds[], int& n, string s);
void main()
{
	//---- setting ---
	sv ds[100]; int n = 0;
	bool kt_menu = true;
	//--- loadfile --
	//loadfile(ds, n);
	//--- play --
	while (kt_menu == true)
	{
		system("cls");
		cout << "1. Nhap sinh vien" << endl;
		cout << "2. Xuat danh sach sinh vien" << endl;
		cout << "3. Xoa sinh vien nhap tu ban phim" << endl;
		cout << "4. Sap xep ds sinh vien tang dan theo ten" << endl;
		cout << "5. Nhap diem cho 1 sv nhap tu ban phim" << endl;
		cout << "0. Thoat" << endl;
		int lc;
		cout << "Nhap lua chon: "; cin >> lc;
		switch (lc)
		{
		case 1:
		{
			int sl; cout << "Nhap sl sinh vien can them: "; cin >> sl;
			cin.ignore();//Chỉ xóa cho ông sv đầu tiên
			for (int i = 1; i <= sl; i++)
			{
				cout << "\t\t-------- Nhap sv thu " << i << " ----" << endl;
				cin >> ds[n++];
			}
			break;
		}
		case 2:
		{
			xuat_ds_sv(ds, n, 0); // 1 : xuat diem    0: khong xuat diem
			system("pause");
			break;
		}
		case 3:
		{
			string s;
			cin.ignore();
			cout << "Nhap ma sv can xoa: "; getline(cin, s);
			xoa_sv_theo_ma_sv(ds, n, s);
			break;
		}
		case 4:
		{
			sap_xep(ds, n);
			break;
		}
		case 5:
		{
			string s;
			cin.ignore();
			cout << "Nhap ma sv can nhap diem: "; getline(cin, s);
			int i = kt_trung_ma_sv(ds, n, s);
			if (i == -1)
			{
				cout << "Khong tim thay!" << endl;
				system("pause");
			}
			else
			{
				//sv ds[i] cần tìm

				//nhap_diem(ds[i]);
			}
			break;
		}
		case 0:
		{
			kt_menu = false;
			break;
		}
		}
	}
	//---- ghifile ---
}
istream& operator >>(istream& is, sv& a)
{
	cout << "Nhap ma sv: "; getline(is, a.ma_sv);
	cout << "Nhap ho ten: "; getline(is, a.ho_ten);
	cout << "Nhap phai: "; getline(is, a.phai);
	cout << "Nhap ngay sinh: "; getline(is, a.ngay_sinh);
	return is;
}
ostream& operator <<(ostream& os, sv a)
{
	os << "Ma sv: " << a.ma_sv << endl;
	os << "Ho ten: " << a.ho_ten << endl;
	os << "Phai: " << a.phai << endl;
	os << "Ngay sinh: " << a.ngay_sinh << endl;
	return os;
}
ostream& operator <<(ostream& os, bang_diem a)
{
	os << "Diem Mac-Lenin: " << a.Mac << endl;
	os << "Diem dai so: " << a.dai_so << endl;
	os << "Diem C++: " << a.cpp << endl;
	return os;
}
void xuat_ds_sv(sv ds[], int n, bool lc)//true: hiện	false: ẩn
{
	cout << "\t\t===== Xuat ds sinh vien ====" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "\t\t---- SV thu " << i << " ---" << endl;
		cout << ds[i];

		if (lc == true)
		{
			cout << "--- Ds diem ---" << endl;
			cout << ds[i].ds_diem;
		}
	}
}

void loadfile(sv ds[], int& n)
{
	ifstream fi("dslk.txt");
	//--- đọc file ---
	while (fi.eof() == false)
	{
		sv a;
		getline(fi, a.ma_sv, ',');
		getline(fi, a.ho_ten, ',');
		getline(fi, a.phai, ',');
		getline(fi, a.ngay_sinh, ',');
		fi >> a.ds_diem.Mac;
		fi.ignore();//Bỏ ,
		fi >> a.ds_diem.dai_so;
		fi.ignore();//Bỏ ,
		fi >> a.ds_diem.cpp;
		fi.ignore();//Bỏ \n
		//--- thêm cuối ds ---
		ds[n++] = a;
	}
	fi.close();
}
//=========== xóa ======
void xoa(sv ds[], int& n, int vt)
{
	for (int i = vt; i < n - 1; i++)
	{
		ds[i] = ds[i + 1];
	}
	n--;
}
void xoa_sv_theo_ma_sv(sv ds[], int& n, string s)
{
	for (int i = 0; i < n; i++)
	{
		if (_stricmp(ds[i].ma_sv.c_str(), s.c_str()) == 0)
		{
			xoa(ds, n, i);
			i--;//Lùi
		}
	}
}
//===== Sắp xếp ====
//1: tên	0: họ đệm
string cat_ho_ten(string s, bool lc)
{
	//s: Huynh Cong
	//			   i
	//ten: Thanh
	string ten = "";
	while (s.back() != ' ')
	{
		ten.insert(ten.begin() + 0, s.back());
		s.pop_back();
	}
	s.pop_back();//xóa khoảng trắng ở cuối

	return (lc == 1) ? ten : s;
}
void sap_xep(sv ds[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			string teni = cat_ho_ten(ds[i].ho_ten, 1);
			string tenj = cat_ho_ten(ds[j].ho_ten, 1);
			if (_stricmp(tenj.c_str(), teni.c_str()) < 0)
			{
				swap(ds[i], ds[j]);
			}
			else if (_stricmp(tenj.c_str(), teni.c_str()) == 0)
			{
				string hoi = cat_ho_ten(ds[i].ho_ten, 0);
				string hoj = cat_ho_ten(ds[j].ho_ten, 0);
				if (_stricmp(hoj.c_str(), hoi.c_str()) < 0)
				{
					swap(ds[i], ds[j]);
				}
			}
		}
	}
}
//======= Nhập điểm =====
int kt_trung_ma_sv(sv ds[], int& n, string s)
{
	for (int i = 0; i < n; i++)
	{
		if (_stricmp(ds[i].ma_sv.c_str(), s.c_str()) == 0)
		{
			return i;
		}
	}
	return -1;
}