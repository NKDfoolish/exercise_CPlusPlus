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