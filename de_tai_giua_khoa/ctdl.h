#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#define MAX 100

//========== DS mon hoc ===========
typedef struct mon_hoc {
	string ma_mh;
	string ten_mh;
	int stclt;
	int stcth;
}mon_hoc;

typedef struct danh_sach_mon_hoc {
	mon_hoc ds[MAX];
	int sl = 0;
};
//====== DS diem thanh phan ======
typedef struct diem_thanh_phan {
	string ma_mh;
	int lan_thi;
	float diem;
}diem_thanh_phan;

struct node_diem_thanh_phan {
	diem_thanh_phan data;
	node_diem_thanh_phan* pnext;
};
typedef struct node_diem_thanh_phan node_diem_thanh_phan;

typedef struct danh_sach_diem_thanh_phan {
	node_diem_thanh_phan* phead = NULL;
	node_diem_thanh_phan* ptail = NULL;
}danh_sach_diem_thanh_phan;

//========== DS sinh vien ========
typedef struct sinh_vien {
	string ma_sv;
	string ho;
	string ten;
	string phai;
	string sdt;
	danh_sach_diem_thanh_phan ds_diem_tp;
};

struct node_sv {
	sinh_vien data;
	node_sv* pnext;
};
typedef struct node_sv node_sv;

typedef struct danh_sach_sinh_vien {
	node_sv* phead = NULL;
	node_sv* ptail = NULL;
}danh_sach_sinh_vien;

//========== DS lop ==============
typedef struct lop {
	string ma_lop;
	string ten_lop;
	int nien_khoa;
	danh_sach_sinh_vien ds_sv;
}lop;

typedef struct danh_sach_lop {
	lop ds[MAX];
	int sl = 0;
};