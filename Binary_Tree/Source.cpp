#include <iostream>
using namespace std;
#include <fstream>

struct node {
	int data;
	node* pleft;
	node* pright;
};
typedef struct node node;
typedef struct node* tree;

//=======================
node* khoi_tao_node(int x);
void them(tree& t, int x);
void NLR(tree t);
void load_file(tree& t);
void liet_ke(tree t);
void node_the_mang(node*& k, tree& t);
void xoa(tree& t, int x);
//=======================

int main() {
	//===== setting =====
	tree t = NULL;
	bool running = true;
	//==== load file ====
	load_file(t);
	//======= play =======
	while (running)
	{
		system("cls");
		cout << "1. Them phan tu" << endl;
		cout << "2. Xuat phan tu (NLR)" << endl;
		cout << "3. Liet ke loai node" << endl;
		cout << "4. Xoa" << endl;
		cout << "0. Thoat khoi chuong trinh" << endl;

		int lc; cout << "Nhap lua chon: "; cin >> lc;
		switch (lc)
		{
		case 1:
		{
			int sl; cout << "Nhap so luong phan tu can them: "; cin >> sl;
			for (int i = 0; i < sl; i++)
			{
				int x;
				cout << "Nhap gia tri cho phan tu thu " << i + 1 << " : ";
				cin >> x;
				them(t, x);
			}
			break;
		}
		case 2:
		{
			NLR(t);
			cout << endl << endl;
			system("pause");
			break;
		}
		case 3:
		{
			liet_ke(t);
			system("pause");
			break;
		}
		case 4:
		{
			int x;
			cout << "Nhap gia tri can xoa: " ; cin >> x;
			xoa(t, x);
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
node* khoi_tao_node(int x) {
	node* p = new node;
	p->data = x;
	p->pleft = NULL;
	p->pright = NULL;
	return p;
}
void them(tree& t, int x) {
	if (t == NULL) {
		node* p = khoi_tao_node(x);
		t = p;
	}
	else {
		if (x > t->data) {
			them(t->pright, x);
		}
		else if (x < t->data) {
			them(t->pleft, x);
		}
	}
}
void NLR(tree t) {
	if (t != NULL) {
		cout << t->data << " ";
		NLR(t->pleft);
		NLR(t->pright);
	}
}
void load_file(tree& t) {
	ifstream fi("tree.txt");
	while (!fi.eof())
	{
		int x;
		fi >> x;
		them(t, x);
	}
	fi.close();
}
void liet_ke(tree t) {
	if (t != NULL) {
		if (t->pleft == NULL && t->pright == NULL) {
			cout << "Node la: " << t->data << endl;
		}
		else if(t->pleft != NULL && t->pright != NULL) {
			cout << "Node 2 con: " << t->data << endl;
		}
		else {
			cout << "Node 1 con: " << t->data << endl;
		}
		liet_ke(t->pleft);
		liet_ke(t->pright);
	}
}
void node_the_mang(node*& k, tree& t) {
	if (k->pright == NULL) {
		t->data = k->data;
		node* tam = k;
		k = k->pleft;
		delete tam;
	}
	else {
		node_the_mang(k->pright, t);
	}
}
void xoa(tree& t, int x) {
	if (t != NULL) {
		if (t->data == x) {
			if (t->pleft == NULL && t->pright == NULL) {
				delete t;
				t = NULL;
			}
			else if (t->pleft != NULL && t->pright != NULL) {
				node_the_mang(t->pleft, t);
			}
			else {
				node* tam = t;
				t = (t->pleft != NULL) ? t->pleft : t->pright;
				delete tam;
			}
		}
		else if (x > t->data) {
			xoa(t->pright, x);
		}
		else if (x < t->data) {
			xoa(t->pleft, x);
		}
	}
}