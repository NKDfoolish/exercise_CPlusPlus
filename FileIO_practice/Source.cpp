#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct sv {
	string ma_sv;
	string ho_ten;
	string phai;
	string ngay_sinh;
	float diem;
};
typedef struct sv sv;

void nhap_1_sv(sv& a);
void xuat_1_sv(sv a);
void xuat_ds_sv(sv ds[], int n);
void load_file1(sv ds[], int& n);
void load_file2(sv ds[], int& n);
void ghi_file(sv ds[], int n);

int main() {
	sv ds[100]; int n = 0;
	bool kt_menu = true;

	load_file2(ds, n);

	while (kt_menu == true)
	{
		system("cls");
		cout << "1. Nhap sinh vien" << endl;
		cout << "2. Xuat danh sanh sinh vien" << endl;
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
			for (int i = 1; i <= sl; i++)
			{
				cin.ignore();
				sv a;
				cout << "/t/t----- Nhap sv thu " << i << " -----" << endl;
				nhap_1_sv(a);

				ds[n++] = a;
			}
			break;
		}
		case 2:
		{
			xuat_ds_sv(ds, n);
			system("pause");
			break;
		}
		case 0:
		{
			kt_menu = false;
			break;
		}
		}
	}
	ghi_file(ds, n);
	return 0;
}
void nhap_1_sv(sv& a) {
	cout << "Nhap ma sinh vien: "; getline(cin, a.ma_sv);
	cout << "Nhap ho ten sinh vien: "; getline(cin, a.ho_ten);
	cout << "Nhap gioi tinh sinh vien: "; getline(cin, a.phai);
	cout << "Nhap ngay sinh cua sinh vien: "; getline(cin, a.ngay_sinh);
	cout << "Nhap diem sinh vien: "; cin >> a.diem;
}
void xuat_1_sv(sv a) {
	cout << "Ma sinh vien: " << a.ma_sv << endl;
	cout << "Ho ten sinh vien: " << a.ho_ten << endl;
	cout << "Gioi tinh sinh vien: " << a.phai << endl;
	cout << "Ngay sinh cua sinh vien: " << a.ngay_sinh << endl;
	cout << "Diem sinh vien: " << a.diem << endl;
}
void xuat_ds_sv(sv ds[], int n) {
	cout << "\t\t======= Xuat danh sach sinh vien =======" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Sinh vien thu " << i << " : " << endl;
		xuat_1_sv(ds[i]);
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
		fi >> a.diem;
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
		fi >> a.diem;
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
		fo << ds[i].ngay_sinh << "," << ds[i].diem;

		if (i != n - 1) {
			fo << endl;
		}
	}

	fo.close();
}