#include <iostream>
using namespace std;

struct node {
	int data;
	node* pnext;
};
typedef struct node node;

typedef struct stack {
	node* ptop = NULL;
}stack;

//============ Nguyen mau ham =============
bool is_Empty(stack s);
node* khoi_tao_node(int x);
void push(stack& s, int x);
void pop(stack& s);
int top(stack s);
//=========================================

int main() {
	stack s;
	while (true)
	{
		system("cls");
		cout << "1. Push" << endl;
		cout << "2. Xuat Stack" << endl;
		cout << "3. Pop" << endl;
		cout << "4. Top" << endl;
		cout << "Nhap lc: "; int lc; cin >> lc;
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
				push(s, x);
			}
			break;
		}
		case 2:
		{
			while (is_Empty(s) == false)
			{
				cout << top(s) << endl;
				pop(s);
			}
			system("pause");
			break;
		}
		case 3:
		{
			pop(s);
			break;
		}
		case 4:
		{
			cout << top(s) << endl;
			system("pause");
			break;
		}
		}
	}

	return 0;
}
bool is_Empty(stack s) {
	return (s.ptop == NULL);
}
node* khoi_tao_node(int x) {
	node* p = new node;
	p->data = x;
	p->pnext = NULL;
	return p;
}
void push(stack& s, int x) {
	node* p = khoi_tao_node(x);
	if (is_Empty(s) == true) {
		s.ptop = p;
	}
	else {
		p->pnext = s.ptop;
		s.ptop = p;
	}
}
void pop(stack& s) {
	if (is_Empty(s) == false) {
		node* temp = s.ptop;
		s.ptop = s.ptop->pnext;
		delete temp;
	}
}
int top(stack s) {
	if (is_Empty(s) == false) {
		return s.ptop->data;
	}
}