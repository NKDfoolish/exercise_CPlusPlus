#include "load_file.h"

//============ DS mon hoc =============
istream& operator>>(istream& is, mon_hoc& a);
ostream& operator<<(ostream& os, mon_hoc a);
void xuat_ds_mh(danh_sach_mon_hoc ds_mh);

//============== DS lop ===============
istream& operator>>(istream& is, lop& a);
ostream& operator<<(ostream& os, lop a);
void xuat_ds_lop(danh_sach_lop ds_lop);

//============ DS sinh vien ==========
int kt_trung_ma_lop(danh_sach_lop ds_lop, string s);
istream& operator>>(istream& is, sinh_vien& a);
ostream& operator<<(ostream& os, sinh_vien a);
void xuat_1_ds_sv(danh_sach_sinh_vien ds_sv);
void xuat_ds_sv(danh_sach_lop ds_lop);
//node_sv* khoi_tao_node(sinh_vien a);
//void them_cuoi_sinh_vien(danh_sach_sinh_vien& ds_sv, sinh_vien a);

//============ DS diem thanh phan ==========
node_sv* kt_trung_sinh_vien(danh_sach_sinh_vien ds_sv, string s);
istream& operator>>(istream& is, diem_thanh_phan& a);
ostream& operator<<(ostream& os, diem_thanh_phan a);
void xuat_1_ds_diem_tp(danh_sach_diem_thanh_phan ds_diem);
void xuat_ds_diem_tp(danh_sach_lop ds_lop);
//node_diem_thanh_phan* khoi_tao_node(diem_thanh_phan a);
//void them_cuoi_diem_thanh_phan(danh_sach_diem_thanh_phan& ds_diem_tp, diem_thanh_phan a);

//============== Xuat danh sach sinh vien theo nien khoa ===============
void xuat_ds_sv_theo_nk(danh_sach_lop ds_lop, int s);

//============ Xuat danh sach sinh vien cua mot lop theo thu tu alphabet tang dan cua ten + ho ==============
void sap_xep_tang_dan_sv_trong_1_lop(danh_sach_sinh_vien& ds_sv);

//========================= In bang diem mon hoc cua 1 lop theo 1 lan thi ===================================
void xuat_ds_diem_cua_1_lop_theo_lan_thi(danh_sach_sinh_vien ds_sv, int lan_thi);

//=============== Xuat bang diem mon hoc cua sinh vien qua ma sinh vien ======================
void xuat_diem_tp_1_sv(danh_sach_lop ds_lop, node_sv* p, int dia_chi_ds);

void menu() {
	//========= setting ===========
	danh_sach_mon_hoc ds_mh;
	danh_sach_lop ds_lop;
	bool running = true;
	//======== load file ==========
	load_file_ds_mh(ds_mh);
	load_file_ds_lop(ds_lop);
	load_file_ds_sv(ds_lop);
	load_file_ds_diem(ds_lop);
	//========== play =============
	while (running)
	{
		system("cls");
		cout << "1. Nhap mon hoc" << endl;
		cout << "2. Xuat danh sach mon hoc" << endl;
		cout << "3. Nhap lop" << endl;
		cout << "4. Xuat danh sach lop" << endl;
		cout << "5. Nhap sinh vien" << endl;
		cout << "6. Xuat danh sach sinh vien" << endl;
		cout << "7. Nhap diem thanh phan cho sinh vien" << endl;
		cout << "8. Xuat danh sach diem thanh phan" << endl;
		cout << "9. Xuat danh sach sinh vien theo nien khoa" << endl;
		cout << "10. Xuat danh sach sinh vien cua 1 lop theo thu tu alphabet (ten + ho)" << endl;
		cout << "11. Xuat bang diem mon hoc cua 1 lop theo lan thi" << endl;
		cout << "12. Xuat bang diem mon hoc cua sinh vien qua ma sinh vien" << endl;
		cout << "0. Thoat khoi chuong trinh" << endl;

		int lc; cout << "Nhap lc: "; cin >> lc;
		switch (lc)
		{
		case 1:
		{
			int sl; cout << "Nhap so luong mon hoc can them: "; cin >> sl;
			for (int i = 1; i <= sl; i++) {
				cin.ignore();
				cout << "\t\t-------- mon hoc thu " << i << " ---------\n";
				cin >> ds_mh.ds[ds_mh.sl++];
			}
			break;
		}
		case 2:
		{
			xuat_ds_mh(ds_mh);
			system("pause");
			break;
		}
		case 3:
		{
			int sl; cout << "Nhap so luong lop can them: "; cin >> sl;
			for (int i = 1; i <= sl; i++) {
				cin.ignore();
				cout << "\t\t-------- lop thu " << i << " ---------\n";
				cin >> ds_lop.ds[ds_lop.sl++];
			}
			break;
		}
		case 4:
		{
			xuat_ds_lop(ds_lop);
			system("pause");
			break;
		}
		case 5:
		{
			string s;
			cin.ignore();
			cout << "Nhap ma lop can them sinh vien: "; getline(cin, s);
			int i = kt_trung_ma_lop(ds_lop, s);
			if (i == -1) {
				cout << "Lop khong ton tai!!!" << endl;
				system("pause");
			}
			else {
				int sl;
				cout << "Nhap so luong sinh vien can them: "; cin >> sl;
				cin.ignore();
				for (int j = 1; j <= sl; j++) {
					cout << "\nSinh vien thu " << j << " : " << endl;
					sinh_vien a;
					cin >> a;
					them_cuoi_sinh_vien(ds_lop.ds[i].ds_sv, a);
				}
			}
			break;
		}
		case 6:
		{
			xuat_ds_sv(ds_lop);
			system("pause");
			break;
		}
		case 7:
		{
			cin.ignore();
			string s;
			cout << "Nhap ma lop can them diem cua sinh vien: "; getline(cin, s);
			int i = kt_trung_ma_lop(ds_lop, s);
			if (i == -1) {
				cout << "Khong ton tai lop!!!" << endl;
				system("pause");
			}
			else {
				cout << "Nhap ma sinh vien can them diem thanh phan: "; getline(cin, s);
				node_sv* p = kt_trung_sinh_vien(ds_lop.ds[i].ds_sv, s);
				if (p == NULL) {
					cout << "Khong tim thay sinh vien!!!" << endl;
					system("pause");
				}
				else {
					int sl;
					cout << "Nhap so luong diem thanh phan can them: "; cin >> sl;
					for (int i = 1; i <= sl; i++) {
						cin.ignore();
						cout << "\t\t--- Diem thanh phan thu " << i << " ---\n";
						diem_thanh_phan a;
						cin >> a;
						them_cuoi_diem_thanh_phan(p->data.ds_diem_tp, a);
					}
				}
			}
			break;
		}
		case 8:
		{
			xuat_ds_diem_tp(ds_lop);
			system("pause");
			break;
		}
		case 9:
		{
			int nk; cout << "Nhap nien khoa can tim: "; cin >> nk;
			xuat_ds_sv_theo_nk(ds_lop, nk);
			system("pause");
			break;
		}
		case 10:
		{
			cin.ignore();
			string s; cout << "Nhap ma lop can tim: "; getline(cin, s);
			int i = kt_trung_ma_lop(ds_lop, s);
			if (i == -1) {
				cout << "Khong ton tai lop!!!" << endl;
				system("pause");
				break;
			}
			else
			{
				sap_xep_tang_dan_sv_trong_1_lop(ds_lop.ds[i].ds_sv);
				xuat_1_ds_sv(ds_lop.ds[i].ds_sv);
				system("pause");
			}
			break;
		}
		case 11:
		{
			cin.ignore();
			string s; cout << "Nhap ma lop can tim: "; getline(cin, s);
			int i = kt_trung_ma_lop(ds_lop, s);
			if (i == -1) {
				cout << "Khong ton tai lop!!!" << endl;
				system("pause");
				break;
			}
			else
			{
				int lan_thi; cout << "Nhap lan thi: "; cin >> lan_thi;
				xuat_ds_diem_cua_1_lop_theo_lan_thi(ds_lop.ds[i].ds_sv, lan_thi);
				system("pause");
			}
			break;
		}
		case 12:
		{
			cin.ignore();
			string s;
			cout << "Nhap ma lop cua sinh vien can xuat diem thanh phan: "; getline(cin, s);
			int i = kt_trung_ma_lop(ds_lop, s);
			if (i == -1) {
				cout << "Khong ton tai lop!!!" << endl;
				system("pause");
			}
			else {
				cout << "Nhap ma sinh vien can xuat diem thanh phan: "; getline(cin, s);
				node_sv* p = kt_trung_sinh_vien(ds_lop.ds[i].ds_sv, s);
				if (p == NULL) {
					cout << "Khong tim thay sinh vien!!!" << endl;
					system("pause");
				}
				else {
					xuat_diem_tp_1_sv(ds_lop, p, i);
				}
				system("pause");
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
	//======== ghi file ===========
}
//============ DS mon hoc =============
istream& operator>>(istream& is, mon_hoc& a) {
	cout << "Nhap ma mon hoc: "; getline(is, a.ma_mh);
	cout << "Nhap ten mon hoc: "; getline(is, a.ten_mh);
	cout << "Nhap so tin chi ly thuyet: "; is >> a.stclt;
	cout << "Nhap so tin chi thuc hanh: "; is >> a.stcth;
	return is;
}
ostream& operator<<(ostream& os, mon_hoc a) {
	os << "Ma mon hoc: " << a.ma_mh << endl;
	os << "Ten mon hoc: " << a.ten_mh << endl;
	os << "So tin chi ly thuyet: " << a.stclt << endl;
	os << "So tin chi thuc hanh: " << a.stcth << endl;
	return os;
}
void xuat_ds_mh(danh_sach_mon_hoc ds_mh) {
	cout << "\t\t======== Danh sach mon hoc =========\n";
	for (int i = 0; i < ds_mh.sl; i++) {
		cout << "\t\t------ mon hoc thu " << i + 1 << " ------\n";
		cout << ds_mh.ds[i];
	}
}
//============ DS lop =============
istream& operator>>(istream& is, lop& a) {
	cout << "Nhap ma lop: "; getline(is, a.ma_lop);
	cout << "Nhap ten lop: "; getline(is, a.ten_lop);
	cout << "Nhap nien khoa: "; is >> a.nien_khoa;
	return is;
}
ostream& operator<<(ostream& os, lop a) {
	os << "Ma lop: " << a.ma_lop << endl;
	os << "Ten lop: " << a.ten_lop << endl;
	os << "Nien khoa: " << a.nien_khoa << endl;
	return os;
}
void xuat_ds_lop(danh_sach_lop ds_lop) {
	cout << "\t\t======== Danh sach lop =========\n";
	for (int i = 0; i < ds_lop.sl; i++) {
		cout << "\t\t------ Lop thu " << i + 1 << " ------\n";
		cout << ds_lop.ds[i];
	}
}
//============ DS sinh vien ==========
int kt_trung_ma_lop(danh_sach_lop ds_lop, string s) {
	for (int i = 0; i < ds_lop.sl; i++) {
		if (_stricmp(ds_lop.ds[i].ma_lop.c_str(), s.c_str()) == 0) {
			return i;
		}
	}
	return -1;
}
istream& operator>>(istream& is, sinh_vien& a) {
	cout << "Nhap ma sinh vien: "; getline(is, a.ma_sv);
	cout << "Nhap ho sinh vien: "; getline(is, a.ho);
	cout << "Nhap ten sinh vien: "; getline(is, a.ten);
	cout << "Nhap phai sinh vien: "; getline(is, a.phai);
	cout << "Nhap so dien thoai sinh vien: "; getline(is, a.sdt);
	return is;
}
ostream& operator<<(ostream& os, sinh_vien a) {
	os << "Ma sinh vien: " << a.ma_sv << endl;
	os << "Ho ten sinh vien: " << a.ho << " " << a.ten << endl;
	os << "Phai sinh vien: " << a.phai << endl;
	os << "Sdt sinh vien: " << a.sdt << endl;
	return os;
}
void xuat_1_ds_sv(danh_sach_sinh_vien ds_sv) {
	int i = 1;
	for (node_sv* k = ds_sv.phead; k != NULL; k = k->pnext) {
		cout << "\t\t------ Sinh vien thu " << i++ << " ------\n";
		cout << k->data;
	}
}
void xuat_ds_sv(danh_sach_lop ds_lop) {
	cout << "\t\t========= Danh sach sinh vien ==========\n";
	for (int i = 0; i < ds_lop.sl; i++) {
		cout << "\t\t------ Danh sach sinh vien lop: " << ds_lop.ds[i].ten_lop << " ------\n";
		xuat_1_ds_sv(ds_lop.ds[i].ds_sv);
	}
}
node_sv* khoi_tao_node(sinh_vien a) {
	node_sv* p = new node_sv;
	p->data = a;
	p->pnext = NULL;
	return p;
}
void them_cuoi_sinh_vien(danh_sach_sinh_vien& ds_sv, sinh_vien a) {
	node_sv* p = khoi_tao_node(a);
	if (ds_sv.phead == NULL) {
		ds_sv.phead = ds_sv.ptail = p;
	}
	else {
		ds_sv.ptail->pnext = p;
		ds_sv.ptail = p;
	}
}
//============ DS diem thanh phan ==========
node_sv* kt_trung_sinh_vien(danh_sach_sinh_vien ds_sv, string s) {
	for (node_sv* k = ds_sv.phead; k != NULL; k = k->pnext) {
		if (_stricmp(k->data.ma_sv.c_str(), s.c_str()) == 0) {
			return k;
		}
	}
	return NULL;
}
istream& operator>>(istream& is, diem_thanh_phan& a) {
	cout << "Nhap ma mon hoc: "; getline(is, a.ma_mh);
	cout << "Nhap so lan thi: "; is >> a.lan_thi;
	cout << "Nhap diem: "; is >> a.diem;
	return is;
}
ostream& operator<<(ostream& os, diem_thanh_phan a) {
	os << "Ma mon hoc: " << a.ma_mh << endl;
	os << "So lan thi: " << a.lan_thi << endl;
	os << "Diem: " << a.diem << endl;
	return os;
}
void xuat_1_ds_diem_tp(danh_sach_diem_thanh_phan ds_diem) {
	int i = 1;
	for (node_diem_thanh_phan* k = ds_diem.phead; k != NULL; k = k->pnext) {
		cout << "\t\t------ Diem thanh phan thu " << i++ << " ------\n";
		cout << k->data;
	}
}
void xuat_ds_diem_tp(danh_sach_lop ds_lop) {
	cout << "\t\t========= Danh sach diem thanh phan ==========\n";
	for (int i = 0; i < ds_lop.sl; i++) {
		cout << "\t\t------ Danh sach diem thanh phan cua lop: " << ds_lop.ds[i].ten_lop << " ------\n";
		for (node_sv* k = ds_lop.ds[i].ds_sv.phead; k != NULL; k = k->pnext) {
			cout << "\t\t--- Danh sach diem thanh phan cua sinh vien: " << k->data.ho << " " << k->data.ten << " ---\n";
			xuat_1_ds_diem_tp(k->data.ds_diem_tp);
		}
	}
}
node_diem_thanh_phan* khoi_tao_node(diem_thanh_phan a) {
	node_diem_thanh_phan* p = new node_diem_thanh_phan;
	p->data = a;
	p->pnext = NULL;
	return p;
}
void them_cuoi_diem_thanh_phan(danh_sach_diem_thanh_phan& ds_diem_tp, diem_thanh_phan a) {
	node_diem_thanh_phan* p = khoi_tao_node(a);
	if (ds_diem_tp.phead == NULL) {
		ds_diem_tp.phead = ds_diem_tp.ptail = p;
	}
	else {
		ds_diem_tp.ptail->pnext = p;
		ds_diem_tp.ptail = p;
	}
}
//========================== Mo rong ===================================

//============== Xuat danh sach sinh vien theo nien khoa ===============
void xuat_ds_sv_theo_nk(danh_sach_lop ds_lop, int s) {
	cout << "\t\t========= Danh sach sinh vien theo nien khoa: " << s << " ==========\n";
	for (int i = 0; i < ds_lop.sl; i++) {
		if (ds_lop.ds[i].nien_khoa == s) {
			cout << "\t\t------ Danh sach sinh vien lop: " << ds_lop.ds[i].ten_lop << " ------\n";
			xuat_1_ds_sv(ds_lop.ds[i].ds_sv);
		}
	}
}

//============ Xuat danh sach sinh vien cua mot lop theo thu tu alphabet tang dan cua ten + ho ==============
void sap_xep_tang_dan_sv_trong_1_lop(danh_sach_sinh_vien& ds_sv) {
	for (node_sv* k = ds_sv.phead; k->pnext != NULL; k = k->pnext) {
		for (node_sv* l = k->pnext; l != NULL; l = l->pnext) {
			if (_stricmp(k->data.ten.c_str(), l->data.ten.c_str()) > 0) {
				swap(k->data, l->data);
			}
			else if (_stricmp(k->data.ten.c_str(), l->data.ten.c_str()) == 0) {
				if (_stricmp(k->data.ho.c_str(), l->data.ho.c_str()) > 0) {
					swap(k->data, l->data);
				}
			}
		}
	}
}
//========================= In bang diem mon hoc cua 1 lop theo 1 lan thi ===================================
void xuat_ds_diem_cua_1_lop_theo_lan_thi(danh_sach_sinh_vien ds_sv, int lan_thi) {
	int i = 1;
	for (node_sv* k = ds_sv.phead; k != NULL; k = k->pnext) {
		for (node_diem_thanh_phan* l = k->data.ds_diem_tp.phead; l != NULL; l = l->pnext) {
			cout << "\t\t--- Danh sach diem thanh phan cua sinh vien: " << k->data.ho << " " << k->data.ten << " ---\n";
			if (l->data.lan_thi == lan_thi) {
				cout << "\t\t------ Diem thanh phan thu " << i++ << " ------\n";
				cout << l->data;
			}
		}
		i = 1;
	}
}
//=============== Xuat bang diem mon hoc cua sinh vien qua ma sinh vien ======================
void xuat_diem_tp_1_sv(danh_sach_lop ds_lop, node_sv* p, int dia_chi_ds) {
	for (node_sv* k = ds_lop.ds[dia_chi_ds].ds_sv.phead; k != NULL; k = k->pnext) {
		if (_stricmp(k->data.ma_sv.c_str(), p->data.ma_sv.c_str()) == 0) {
			for (node_diem_thanh_phan* l = k->data.ds_diem_tp.phead; l != NULL; l = l->pnext) {
				cout << l->data;
			}
		}
	}
}