#include <iostream>
#include <fstream>
using namespace std;
//=================================
struct node
{
	//-- data ---
	int data;
	//-- pointer --
	node* pnext;
};
typedef struct node node;

typedef struct dslk
{
	node* phead = NULL;
	node* ptail = NULL;
}dslk;

//============================
node* khoi_tao_node(int x);
void them_cuoi(dslk& ds, int x);
//-----------------------------------
void xuat_ds(dslk ds);
//-----------------------------------
void them_dau(dslk& ds, int x);
//----------------------------------
void xoa_dau(dslk& ds);
//-----------------------------------
void xoa_cuoi(dslk& ds);
//-----------------------------------
void xoa_tai_vt(dslk& ds, int vt);
//-----------
void sap_xep_giam(dslk& ds);

void load_file(dslk& ds);
void main()
{
	dslk ds;
	load_file(ds);

	while (true)
	{
		system("cls");
		cout << "1. Nhap" << endl;
		cout << "2. Xuat ds" << endl;
		cout << "3. Them dau" << endl;
		cout << "4. Xoa dau" << endl;
		cout << "5. Xoa cuoi" << endl;
		cout << "6. Xoa tai vt" << endl;
		cout << "7. Sap xep" << endl;
		cout << "Nhap lc: "; int lc; cin >> lc;
		switch (lc)
		{
		case 1:
		{
			int sl; cout << "Nhap sl pt can them: "; cin >> sl;
			for (int i = 1; i <= sl; i++)
			{
				int x;
				cout << "Nhap pt thu " << i << ": "; cin >> x;
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
			int x;
			cout << "Nhap gia tri can them: "; cin >> x;
			them_dau(ds, x);
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
			int vt;
			cout << "Nhap vt can xoa: "; cin >> vt;
			xoa_tai_vt(ds, vt);
			break;
		}
		case 7:
		{
			sap_xep_giam(ds);
			break;
		}
		}
	}
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
	if (ds.phead == NULL)//Rỗng
	{
		ds.phead = ds.ptail = p;
	}
	else if (ds.phead != NULL)//1 pt, n pt
	{
		//B1: ptail liên kết pt cần thêm
		ds.ptail->pnext = p;
		//B2: cập nhật ptail
		ds.ptail = p;
	}
}
void xuat_ds(dslk ds)
{
	int j = 1;
	for (node* k = ds.phead; k != NULL; k = k->pnext)
	{
		//------ pt dang xét: k
		cout << "Pt thu " << j++ << " la: " << k->data << endl;
	}
}
void them_dau(dslk& ds, int x)
{
	node* p = khoi_tao_node(x);
	if (ds.phead == NULL)//DS rỗng
	{
		ds.phead = ds.ptail = p;
	}
	else if (ds.phead != NULL)//1 pt, n pt
	{
		//B1: p lk phead
		p->pnext = ds.phead;
		//B2: cập nhật phead
		ds.phead = p;
	}
}
void xoa_dau(dslk& ds)
{
	if (ds.phead == ds.ptail && ds.phead != NULL)
	{
		//B1: Giải phóng
		delete ds.phead;
		//B2: Cập nhật về NULL
		ds.phead = ds.ptail = NULL;
	}
	else if (ds.phead != NULL)
	{
		//B1: cho tạm giữ pt đầu
		node* tam = ds.phead;
		//B2: cập nhật phead về pt thứ 2
		ds.phead = ds.phead->pnext;
		//B3: giải phóng tạm
		delete tam;
	}
}
void xoa_cuoi(dslk& ds)
{
	if (ds.phead == ds.ptail && ds.phead != NULL)
	{
		//B1: Giải phóng
		delete ds.phead;
		//B2: Cập nhật về NULL
		ds.phead = ds.ptail = NULL;
	}
	else if (ds.phead != NULL)//n pt
	{

		for (node* k = ds.phead; k != NULL; k = k->pnext)
		{
			if (k->pnext->pnext == NULL)//B1: Tìm vt áp cuối
			{
				//B2.1 giải ptail
				delete ds.ptail;
				//B2.2 k lk NULL
				k->pnext = NULL;
				//B2.3 cập nhật ptail
				ds.ptail = k;

				return;
			}
		}
	}
}
void xoa_tai_vt1(dslk& ds, int vt)
{
	if (ds.phead != NULL)//1 pt, n pt
	{
		//====== Đảm bảo 100% vt ko nằm ở đầu ======
		while (ds.phead->data == vt)
		{
			node* tam = ds.phead;
			ds.phead = ds.phead->pnext;//NULL
			delete tam;

			if (ds.phead == NULL)//DS rỗng
			{
				ds.ptail = NULL;
				return;
			}
		}

		//1

		//============ h theo k xử lý các pt thứ tự: 2,3,4,5... =====
		node* h = NULL;
		for (node* k = ds.phead; k != NULL; k = k->pnext)
		{
			if (k->data == vt)//Xóa tại k => Xóa sau h
			{
				//B1: h lk pt sau k
				h->pnext = k->pnext;
				//B2: Giải phóng k
				delete k;
				//B3: Lùi k:	tránh vô định + tránh sót pt
				k = h;

				if (h->pnext == NULL)//h đang ở đâu
				{
					//h ở cuối => Vừa xóa cuối => Cập nhật ptail
					ds.ptail = h;
					return;
				}
			}

			//--- h theo k --
			h = k;
		}
	}
}
void xoa_tai_vt(dslk& ds, int vt)
{
	if (ds.phead != NULL)//1 pt, n pt
	{
		//============ h theo k xử lý các pt thứ tự: 2,3,4,5... =====
		node* h = NULL;
		for (node* k = ds.phead; k != NULL; )
		{
			if (k->data == vt && k == ds.phead)//vt ở đầu
			{
				ds.phead = ds.phead->pnext;//NULL
				delete k;//k vô định
				k = ds.phead;//Lùi k

				//--- Ko nhảy k (bước lặp ) ----
				if (ds.phead == NULL)//Rỗng
				{
					ds.ptail = NULL;
					return;
				}
			}
			else
			{
				if (k->data == vt)//Xóa tại k => Xóa sau h
				{
					//B1: h lk pt sau k
					h->pnext = k->pnext;
					//B2: Giải phóng k
					delete k;
					//B3: Lùi k:	tránh vô định + tránh sót pt
					k = h;

					if (h->pnext == NULL)//h đang ở đâu
					{
						//h ở cuối => Vừa xóa cuối => Cập nhật ptail
						ds.ptail = h;
						return;
					}
				}
				//--- h theo k --
				h = k;
				//---- bước lặp ----
				k = k->pnext;
			}
		}
	}
}
void sap_xep_giam(dslk& ds)
{
	for (node* k = ds.phead; k->pnext != NULL; k = k->pnext)
	{
		for (node* h = k->pnext; h != NULL; h = h->pnext)
		{
			if (h->data > k->data)
			{
				swap(h->data, k->data);
			}
		}
	}
}
void load_file(dslk& ds)
{
	ifstream fi("input.txt");
	//---- doc file ----
	while (!fi.eof())
	{
		int x;
		fi >> x;
		//----- Thêm ------
		them_cuoi(ds, x);
	}
	fi.close();
}