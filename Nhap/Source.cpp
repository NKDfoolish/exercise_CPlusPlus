#include <iostream>
using namespace std;

struct node
{
	int data;
	node* pnext;
};
typedef struct node node;

typedef struct dslk
{
	node* phead = NULL;
	node* ptail = NULL;
}dslk;

node* khoi_tao_node(int x);
void them_cuoi(dslk& ds, int x);
void xuat_ds(dslk ds);
void them_dau(dslk& ds, int x);
void xoa_dau(dslk& ds);
void xoa_cuoi(dslk& ds);
void xoa_tai_vt(dslk& ds, int x);

int main() {
	dslk ds;
	bool running = true;

	while (running)
	{
		system("cls");
		cout << "1. Them cuoi" << endl;
		cout << "2. Xuat danh sach" << endl;
		cout << "3. Them dau" << endl;
		cout << "4. Xoa dau" << endl;
		cout << "5. Xoa cuoi" << endl;
		cout << "6. Xoa tai vi tri bang x" << endl;
		cout << "0. Thoat khoi chuong trinh" << endl;

		int lc;
		cout << "Nhap lua chon: "; cin >> lc;
		switch (lc)
		{
		case 0:
		{
			running = false;
			break;
		}
		case 1:
		{
			int sl; cout << "Nhap so luong phan tu can them: "; cin >> sl;
			for (int i = 0; i < sl; i++)
			{
				int x;
				cout << "Nhap pt thu " << i + 1 << " : "; cin >> x;
				them_cuoi(ds, x);
			}
			break;
		}
		case 2:
		{
			xuat_ds(ds);
			system("pause");
			break;
		}
		case 3:
		{
			int sl; cout << "Nhap so luong phan tu can them: "; cin >> sl;
			for (int i = 0; i < sl; i++)
			{
				int x;
				cout << "PT thu " << i + 1 << " : "; cin >> x;
				them_dau(ds, x);
			}
			break;
		}
		case 4:
		{
			xoa_dau(ds);
			break;
		}
		case 5:
		{
			xoa_cuoi(ds);
			break;
		}
		case 6:
		{
			int x; cout << "Nhap gia tri x muon xoa: "; cin >> x;
			xoa_tai_vt(ds,x);
			break;
		}
		}
	}
	return 0;
}
node* khoi_tao_node(int x)
{
	node* p = new node;
	p->data = x;
	p->pnext = NULL;
	return p;
}
void them_cuoi(dslk& ds, int x)
{
	node* p = khoi_tao_node(x);
	if (ds.phead == NULL) {
		ds.phead = ds.ptail = p;
	}
	else if (ds.phead != NULL)
	{
		ds.ptail->pnext = p;
		ds.ptail = p;
	}
}
void xuat_ds(dslk ds) {
	int j = 1;
	for (node* k = ds.phead; k != NULL; k = k->pnext)
	{
		cout << "PT thu " << j++ << " la: " << k->data << endl;
	}
}
void them_dau(dslk& ds, int x) {
	node* p = khoi_tao_node(x);
	if (ds.phead == NULL) {
		ds.phead = ds.ptail = p;
	}
	else if (ds.phead != NULL) {
		p->pnext = ds.phead;
		ds.phead = p;
	}
}
void xoa_dau(dslk& ds) {
	if (ds.phead == ds.ptail && ds.phead != NULL) {
		delete ds.phead;
		ds.phead = ds.ptail = NULL;
	}
	else if (ds.phead != ds.ptail) {
		node* tam = ds.phead;
		ds.phead = ds.phead->pnext;
		delete tam;
	}
}
void xoa_cuoi(dslk& ds) {
	if (ds.phead == ds.ptail && ds.phead != NULL) {
		delete ds.phead;
		ds.phead = ds.ptail = NULL;
	}
	else if (ds.phead != ds.ptail) {
		node* tam = ds.ptail;
		for (node* k = ds.phead; k != NULL; k = k->pnext) {
			if (k->pnext->pnext == NULL) {
				delete ds.ptail;
				k->pnext = NULL;
				ds.ptail = k;

				return;
			}
		}
	}
}
void xoa_tai_vt(dslk& ds, int x) {
	if (ds.phead != NULL) {
		while (ds.phead->data == x) {
			node* tam = ds.phead;
			ds.phead = ds.phead->pnext;
			delete tam;
			if (ds.phead == NULL) {
				ds.ptail = NULL;
				return;
			}
		}
	}
	node* h = NULL;
	for (node* k = ds.phead; k != NULL; k = k->pnext) {
		if (k->data == x) {
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