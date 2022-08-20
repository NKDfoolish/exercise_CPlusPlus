#include <iostream>
#include <fstream>
#include <string>
using namespace std;

typedef struct bang_diem {
	float mac = 0;
	float dai_so = 0;
	float cpp = 0;
}bang_diem;

typedef struct sv {
	string ma_sv;
	string ho_ten;
	string phai;
	string nam_sinh;
	bang_diem ds_diem;
}sv;

struct node {
	sv data;
	node* pnext;
};
typedef struct node node;

typedef struct dslk {
	node* phead = NULL;
	node* ptail = NULL;
}dslk;

istream& operator >>(istream& is, sv& a);
ostream& operator <<(ostream& os, sv a);
ostream& operator <<(ostream& os, bang_diem a);
istream& operator >>(istream& is, bang_diem& a);

void xuat_danh_sach_sinh_vien(dslk ds, int lc);
node* khoi_tao_node(sv x);
void them_cuoi(dslk& ds, sv a);
void load_file(dslk& ds);
void xoa_sinh_vien_theo_ma_sinh_vien(dslk& ds, string s);
node* kt_trung_ma_sv(dslk ds, string s);
string cat_ho_ten(string s, int lc);
void sap_xep(dslk& ds);

int main() {
	dslk ds;
	bool running = true;

	load_file(ds);
	while (running) {
		system("cls");
		cout << "1. Nhap sv" << endl;
		cout << "2. Xuat danh sach sv " << endl;
		cout << "3. Xoa sv theo ma sv nhap tu ban phim" << endl;
		cout << "4. Sap xep danh sach sinh vien tang dan theo ten" << endl;
		cout << "5. Nhap diem 3 mon cho sinh vien co ma sinh vien nhap tu ban phim" << endl;
		cout << "0. Thoat" << endl;

		int option;
		cout << "Nhap lua chon cua ban: "; 
		cin >> option;

		switch(option) {
		case 1:
		{
			int sl;
			cout << "Nhap so luong can them: ";
			cin >> sl;
			cin.ignore();
			for (int i = 1; i <= sl; i++)
			{
				sv a;
				cout << "\t\t===== Nhap sv thu " << i << " =====\n";
				cin >> a;
				them_cuoi(ds, a);
			}
			break;
		}
		case 2:
		{
			int view;
			cout << "Ban co muon xem diem cua sinh vien khong (1: khong | 2: co):";
			cin >> view;
			xuat_danh_sach_sinh_vien(ds, view);
			system("pause");
			break;
		}
		case 3:
		{
			cin.ignore();
			cout << "Nhap ma sv can xoa: ";
			string s;
			getline(cin, s);
			xoa_sinh_vien_theo_ma_sinh_vien(ds, s);
			break;
		}
		case 4:
		{
			sap_xep(ds);
			break;
		}
		case 5:
		{
			cin.ignore();
			cout << "Nhap ma so sinh vien can them diem: ";
			string s;
			getline(cin, s);
			node* p = kt_trung_ma_sv(ds, s);
			if (p != NULL) {
				cin >> p->data.ds_diem;
			}
			else {
				cout << "Ma so sinh vien khong co trong danh sach.";
			}
			break;
		}
		case 0:
		{
			running = false;
			break;
		}
		}
	}
	return 0;
}
istream& operator >>(istream& is, sv& a) {
	cout << "Nhap ma sv: "; getline(is, a.ma_sv);
	cout << "Nhap ho ten: "; getline(is, a.ho_ten);
	cout << "Nhap phai: "; getline(is, a.phai);
	cout << "Nhap nam sinh: "; getline(is, a.nam_sinh);
	return is;
}
istream& operator >>(istream& is, bang_diem& a) {
	cout << "Nhap diem mac-le-nin: "; cin >> a.mac;
	cout << "Nhap diem dai so: "; cin >> a.dai_so;
	cout << "Nhap diem c++: "; cin >> a.cpp;
	return is;
}
ostream& operator <<(ostream& os, sv a) {
	os << "Ma sv: " << a.ma_sv << endl;
	os << "Ho ten: " << a.ho_ten << endl;
	os << "Phai: " << a.phai << endl;
	os << "Nam sinh: " << a.nam_sinh << endl;
	return os;
}
ostream& operator <<(ostream& os, bang_diem a) {
	os << "Diem mac-le-nin: " << a.mac << endl;
	os << "Diem dai so: " << a.dai_so << endl;
	os << "Diem c++: " << a.cpp << endl;
	return os;
}
void xuat_danh_sach_sinh_vien(dslk ds, int lc) {
	cout << "\t\t=============== DS SV ===============\n\n";
	int i = 1;
	for (node* k = ds.phead; k != NULL; k = k->pnext) {
		cout << "\t\t----- Sv thu " << i++ << " -----\n";
		cout << k->data;
		if (lc == 2) {
			cout << "\t\t* diem *\n";
			cout << k->data.ds_diem;
		}
	}
}
node* khoi_tao_node(sv x) {
	node* p = new node;
	p->data = x;
	p->pnext = NULL;
	return p;
}
void them_cuoi(dslk& ds, sv a) {
	node* p = khoi_tao_node(a);
	if (ds.phead == NULL) {
		ds.phead = ds.ptail = p;
	}
	else {
		ds.ptail->pnext = p;
		ds.ptail = p;
	}
}
void load_file(dslk& ds) {
	ifstream fi("input.txt");
	while (!fi.eof()) {
		sv a;
		getline(fi, a.ma_sv, ',');
		getline(fi, a.ho_ten, ',');
		getline(fi, a.phai, ',');
		getline(fi, a.nam_sinh, ',');
		fi >> a.ds_diem.mac;
		fi.ignore();
		fi >> a.ds_diem.dai_so;
		fi.ignore();
		fi >> a.ds_diem.cpp;
		fi.ignore();
		them_cuoi(ds, a);
	}
	fi.close();
}
void xoa_sinh_vien_theo_ma_sinh_vien(dslk& ds, string s) {
	if (ds.phead != NULL) {
		while (_stricmp(ds.phead->data.ma_sv.c_str(), s.c_str()) == 0) {
			node* tam = ds.phead;
			ds.phead = ds.phead->pnext;
			delete tam;

			if (ds.phead == NULL) {
				ds.ptail = NULL;
				return;
			}
		}
		node* h = NULL;
		for (node* k = ds.phead; k != NULL; k = k->pnext) {
			if (_stricmp(k->data.ma_sv.c_str(), s.c_str()) == 0) {
				h->pnext = k->pnext;
				delete k;
				k = h;

				if (h->pnext == NULL) {
					ds.ptail = h;
					return;
				}
			}
			h = k;
		}
	}
}
node* kt_trung_ma_sv(dslk ds, string s) {
	for (node* k = ds.phead; k != NULL; k = k->pnext) {
		if (_stricmp(k->data.ma_sv.c_str(), s.c_str()) == 0) {
			return k;
		}
	}
	return NULL;
}
string cat_ho_ten(string s, int lc) {
	string ten = "";
	while (s.back() != ' ') {
		ten.insert(ten.begin() + 0, s.back());
		s.pop_back();
	}
	s.pop_back();
	return (lc == 1) ? ten : s;
}
void sap_xep(dslk& ds) {
	for (node* i = ds.phead; i->pnext != NULL;i = i->pnext) {
		for (node* j = i->pnext; j != NULL; j = j->pnext) {
			string ten_i = cat_ho_ten(i->data.ho_ten, 1);
			string ten_j = cat_ho_ten(j->data.ho_ten, 1);
			if (_stricmp(ten_i.c_str(), ten_j.c_str()) > 0) {
				swap(i->data, j->data);
			}
			else if (_stricmp(ten_i.c_str(), ten_j.c_str()) == 0) {
				string ho_i = cat_ho_ten(i->data.ho_ten, 2);
				string ho_j = cat_ho_ten(j->data.ho_ten, 2);
				if (_stricmp(ho_i.c_str(), ho_j.c_str()) > 0) {
					swap(i->data, j->data);
				}
			}
		}
	}
}