#include "ctdl.h"
//======== cac ham can cho load file =========
node_sv* khoi_tao_node(sinh_vien a);
void them_cuoi_sinh_vien(danh_sach_sinh_vien& ds_sv, sinh_vien a);
node_diem_thanh_phan* khoi_tao_node(diem_thanh_phan a);
void them_cuoi_diem_thanh_phan(danh_sach_diem_thanh_phan& ds_diem_tp, diem_thanh_phan a);

//============= Nguyen mau ham ===============
void load_file_ds_mh(danh_sach_mon_hoc& ds_mh);
void load_file_ds_lop(danh_sach_lop& ds_lop);
void load_file_ds_sv(danh_sach_lop& ds_lop);
void load_file_ds_diem(danh_sach_lop& ds_lop);

void load_file_ds_mh(danh_sach_mon_hoc& ds_mh) {
	ifstream fi("ds_mh.txt");
	while (!fi.eof())
	{
		mon_hoc a;
		getline(fi, a.ma_mh, ',');
		getline(fi, a.ten_mh, ',');
		fi >> a.stclt;
		fi.ignore();// bo ,
		fi >> a.stcth;
		fi.ignore();// bo \n
		ds_mh.ds[ds_mh.sl++] = a;
	}
	fi.close();
}

void load_file_ds_lop(danh_sach_lop& ds_lop) {
	ifstream fi("ds_lop.txt");
	while (!fi.eof())
	{
		lop a;
		getline(fi, a.ma_lop, ',');
		getline(fi, a.ten_lop, ',');
		fi >> a.nien_khoa;
		fi.ignore();//Bỏ \n
		//--- thêm cuối ----
		ds_lop.ds[ds_lop.sl++] = a;
	}
	fi.close();
}

void load_file_ds_sv(danh_sach_lop& ds_lop) {
	ifstream fi("ds_sv.txt");
	for (int i = 0; i < ds_lop.sl; i++) {
		int n;
		fi >> n;
		fi.ignore();
		for (int j = 1; j <= n; j++) {
			sinh_vien a;
			getline(fi, a.ma_sv, ',');
			getline(fi, a.ho, ',');
			getline(fi, a.ten, ',');
			getline(fi, a.phai, ',');
			getline(fi, a.sdt);
			them_cuoi_sinh_vien(ds_lop.ds[i].ds_sv, a);
		}
	}
	fi.close();
}

void load_file_ds_diem(danh_sach_lop& ds_lop) {
	ifstream fi("ds_diem.txt");
	for (int i = 0; i < ds_lop.sl; i++) {
		for (node_sv* k = ds_lop.ds[i].ds_sv.phead; k != NULL; k = k->pnext) {
			int n;
			fi >> n;
			fi.ignore();
			for (int i = 0; i < n; i++)
			{
				diem_thanh_phan a;
				getline(fi, a.ma_mh, ',');
				fi >> a.lan_thi;
				fi.ignore();//Bỏ ,
				fi >> a.diem;
				fi.ignore();//Bỏ \n
				them_cuoi_diem_thanh_phan(k->data.ds_diem_tp, a);
			}
		}
	}
}