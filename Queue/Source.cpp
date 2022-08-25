#include <iostream>
using namespace std;

struct node {
	int data;
	node* pnext;
};
typedef struct node node;

typedef struct queue {
	node* pfront = NULL;
	node* pback = NULL;
}queue;

//================ Nguyen mau ham ====================
bool is_Empty(queue q);
node* khoi_tao_node(int x);
void push(queue& q, int x);
void pop(queue& q);
int front(queue q);
int back(queue q);
//====================================================

int main() {
	queue q;

	while (true)
	{
		system("cls");
		cout << "1. Push" << endl;
		cout << "2. Xuat Queue" << endl;
		cout << "3. Pop" << endl;
		cout << "4. Front" << endl;
		cout << "5. Back" << endl;
		int lc; cout << "Nhap lua chon: "; cin >> lc;
		switch (lc)
		{
		case 1:
		{
			int sl; cout << "Nhap so luong phan tu can them: "; cin >> sl;
			for (int i = 0; i < sl; i++)
			{
				int x;
				cout << "Nhap pt thu " << i + 1 << ": ";
				cin >> x;
				push(q, x);
			}
			break;
		}
		case 2:
		{
			while (is_Empty(q) == false)
			{
				cout << back(q) << endl;
				pop(q);
			}
			system("pause");
			break;
		}
		case 3:
		{
			pop(q);
			break;
		}
		case 4:
		{
			cout << front(q) << endl;
			system("pause");
			break;
		}
		case 5:
		{
			cout << back(q) << endl;
			system("pause");
			break;
		}
		}
	}
	return 0;
}
bool is_Empty(queue q) {
	return q.pfront == NULL;
}
node* khoi_tao_node(int x) {
	node* p = new node;
	p->data = x;
	p->pnext = NULL;
	return p;
}
void push(queue& q, int x) {
	node* p = khoi_tao_node(x);
	if (is_Empty(q) == true) {
		q.pfront = q.pback = p;
	}
	else {
		q.pback->pnext = p;
		q.pback = p;
	}
}
void pop(queue& q) {
	if (q.pfront == q.pback && q.pfront != NULL) {
		delete q.pfront;
		q.pfront = q.pback = NULL;
	}
	for (node* k = q.pfront; k != NULL; k = k->pnext) {
		if (k->pnext->pnext == NULL) {
			delete q.pback;
			k->pnext = NULL;
			q.pback = k;
		}
	}
}
int front(queue q) {
	return q.pfront->data;
}
int back(queue q) {
	return q.pback->data;
}