#include <iostream>
#include <string>
#define MAX 100
using namespace std;

class nv {
protected:
	string ten;
	string ma_nv;
	int luong;

public:
	void nhap() {
		cout << "Nhap luong nhan vien: "; cin >> this->luong;
		cout << "Nhap ten: "; getline(cin, this->ten);
		cout << "Nhap ma nhan vien: "; getline(cin, this->ma_nv);
	}

	void xuat() {
		cout << "Ten nhan vien: " << this->ten << endl;
		cout << "Ma nhan vien: " << this->ma_nv << endl;
		cout << "Luong nhan vien" << this->luong << endl;
	}

public:
	nv() {
		this->luong = 0;
	}

	~nv() {

	}
};

class nv_sua_ong_nuoc : public nv {
protected:
	int luong;
	int luong_1h;
	int so_h_lam;

public:
	void nhap() {
		nv::nhap();
		cout << "Nhap luong 1 gio: "; cin >> this->luong_1h;
		cout << "Nhap so gio lam: "; cin >> this->so_h_lam;
	}

	void xuat() {
		nv::xuat();
		cout << "Luong 1 gio: " << this->luong_1h << endl;
		cout << "So gio lam: " << this->so_h_lam << endl;
	}

public:
	nv_sua_ong_nuoc() {

	}
	
	~nv_sua_ong_nuoc() {

	}
};

class nv_sua_xe_om : public nv {
protected:
	int luong_1km;
	int so_km_da_di;

public:
	void nhap() {
		nv::nhap();
		cout << "Nhap luong 1 gio: "; cin >> this->luong_1km;
		cout << "Nhap so gio lam: "; cin >> this->so_km_da_di;
	}

	void xuat() {
		nv::xuat();
		cout << "Luong 1 gio: " << this->luong_1km << endl;
		cout << "So gio lam: " << this->so_km_da_di << endl;
	}

public:
	nv_sua_xe_om() {

	}

	~nv_sua_xe_om() {

	}
};

class nv_giao_hang : public nv {
protected:
	int luong_1sp;
	int so_sp_da_giao;

public:
	void nhap() {
		nv::nhap();
		cout << "Nhap luong 1 gio: "; cin >> this->luong_1sp;
		cout << "Nhap so gio lam: "; cin >> this->so_sp_da_giao;
	}

	void xuat() {
		nv::xuat();
		cout << "Luong 1 gio: " << this->luong_1sp << endl;
		cout << "So gio lam: " << this->so_sp_da_giao << endl;
	}

public:
	nv_giao_hang() {

	}

	~nv_giao_hang() {

	}
};

int main() {
	nv_sua_ong_nuoc nv_1[MAX];
	nv_sua_xe_om nv_2[MAX];
	nv_giao_hang nv_3[MAX];
	bool running = true;
	int n_1 = 0, n_2 = 0, n_3 = 0;

	while (running)
	{
		system("cls");
		cout << "\t\t=============== OPTIONS ================\n";
		cout << "\t\t1. Them nhan vien vao danh sach nhan vien sua ong nuoc.\n";
		cout << "\t\t2. Them nhan vien vao danh sach nhan vien xe om.\n";
		cout << "\t\t3. Them nhan vien vao danh sach nhan vien giao hang.\n";
		cout << "\t\t4. Xuat thong tin danh sach nhan vien sua ong nuoc.\n";
		cout << "\t\t5. Xuat thong tin danh sach nhan vien xe om.\n";
		cout << "\t\t6. Xuat thong tin danh sach nhan vien giao hang.\n";
		cout << "\t\t0. Thoat khoi chuong trinh.\n";
		int lc; cout << "Nhap lua chon cua ban: "; cin >> lc;
		cin.ignore();
		switch (lc)
		{
		case 0:
		{
			cout << "\n\n==> Ket thuc chuong trinh <==\n";
			running = false;
			break;
		}
		case 1:
		{
			int sl1; cout << "Nhap so luong nhan vien can them: "; cin >> sl1;
			for (int i = 0; i < sl1; i++)
			{
				cin.ignore();
				cout << "\n\t\t--- Nhap thong tin nhan vien sua ong nuoc thu " << i + 1 << ": ---\n" << endl;
				nv_1[n_1++].nhap();
			}
			break;
		}
		case 2:
		{
			int sl2; cout << "Nhap so luong nhan vien can them: "; cin >> sl2;
			for (int i = 0; i < sl2; i++)
			{
				cin.ignore();
				cout << "\n\t\t--- Nhap thong tin nhan vien xe om thu " << i + 1 << ": ---\n" << endl;
				nv_2[n_2++].nhap();
			}
			break;
		}
		case 3:
		{
			int sl3; cout << "Nhap so luong nhan vien can them: "; cin >> sl3;
			for (int i = 0; i < sl3; i++)
			{
				cin.ignore();
				cout << "\n\t\t--- Nhap thong tin nhan vien giao hang thu " << i + 1 << ": ---\n" << endl;
				nv_3[n_3++].nhap();
			}
			break;
		}
		case 4:
		{
			cout << "===> Xuat danh sach nhan vien sua ong nuoc <===" << endl;
			for (int i = 0; i < n_1; i++)
			{
				cout << "\t--- Nhan vien thu " << i + 1 << ": ---\n" << endl;
				nv_1[i].xuat();
			}
			system("pause");
			break;
		}
		case 5:
		{
			cout << "===> Xuat danh sach nhan vien xe om <===" << endl;
			for (int i = 0; i < n_2; i++)
			{
				cout << "\t--- Nhan vien thu " << i + 1 << ": ---\n" << endl;
				nv_2[i].xuat();
			}
			system("pause");
			break;
		}
		case 6:
		{
			cout << "===> Xuat danh sach nhan vien giao hang <===" << endl;
			for (int i = 0; i < n_3; i++)
			{
				cout << "\t--- Nhan vien thu " << i + 1 << ": ---\n" << endl;
				nv_3[i].xuat();
			}
			system("pause");
			break;
		}
		}
	}

	return 0;
}