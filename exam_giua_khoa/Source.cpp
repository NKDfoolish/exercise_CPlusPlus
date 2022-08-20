#include <iostream>
#include <fstream>
using namespace std;

void xuat(int* p, int n);
void cap_phat_lai(int*& p, int ncu, int nmoi);
void load_file(int*& p, int& n);
void them(int*& p, int& n, int vt, int x);
void xoa(int*& p, int& n, int vt);
void liet_ke_mang_con(int* p, int n);

int main() {
	int* p = NULL;
	int n = 0;
	bool running = true;

	load_file(p, n);
	while (running)
	{
		system("cls");
		cout << "1. Nhap" << endl;
		cout << "2. Xuat danh sach" << endl;
		cout << "3. Them" << endl;
		cout << "4. Xoa" << endl;
		cout << "5. Liet ke mang con" << endl;
		cout << "0. Thoat" << endl;

		int option;
		cout << "Nhap lua chon cua ban: ";
		cin >> option;

		switch (option)
		{
		case 1:
		{
			int quantity;
			cout << "Nhap so luong phan tu can them: ";
			cin >> quantity;
			for (int i = 1; i <= quantity; i++) {
				int x;
				cout << "Nhap gia tri thu " << i << ": ";
				cin >> x;
				cap_phat_lai(p, n, n + 1);
				p[n] = x;
				n++;
			}
			break;
		}
		case 2:
		{
			xuat(p, n);
			system("pause");
			break;
		}
		case 3:
		{
			int vt, x;
			cout << "Nhap vi tri can them: ";
			cin >> vt;
			cout << "Nhap gia tri can them: ";
			cin >> x;
			them(p, n, vt, x);
			break;
		}
		case 4:
		{
			int vt;
			cout << "Nhap vi tri can xoa: ";
			cin >> vt;
			xoa(p, n, vt);
			break;
		}
		case 5:
		{
			liet_ke_mang_con(p, n);
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
void xuat(int* p, int n) {
	cout << "\t\t===== Xuat =====\n";
	for (int i = 0; i < n; i++)
	{
		cout << "Phan tu thu " << i << " la: " << p[i] << endl;
	}
}
void cap_phat_lai(int*& p, int ncu, int nmoi) {
	int* tam = p;
	p = new int[nmoi];
	for (int i = 0; i < ncu; i++) {
		p[i] = tam[i];
	}
	if (tam != NULL) delete[] tam;
}
void load_file(int*& p, int& n) {
	ifstream fi("input.txt");
	while (!fi.eof()) {
		cap_phat_lai(p, n, n + 1);
		fi >> p[n++];
		fi.ignore();
	}
	fi.close();
}
void them(int*& p, int& n, int vt, int x) {
	cap_phat_lai(p, n, n + 1);
	for (int i = n; i > vt; i--) {
		p[i] = p[i - 1];
	}
	p[vt] = x;
	n++;
}
void xoa(int*& p, int& n, int vt) {
	for (int i = vt; i < n - 1; i++) {
		p[i] = p[i + 1];
	}
	cap_phat_lai(p, n - 1, n - 1);
	n--;
}
void liet_ke_mang_con(int* p, int n) {
	for (int vtbd = 0; vtbd < n; vtbd++) {
		for (int slpt = 1; slpt + vtbd <= n; slpt++) {
			for (int i = vtbd; i < slpt + vtbd; i++) {
				cout << p[i] << " ";
			}
			cout << endl;
		}
		cout << "-----------------------------";
		cout << endl;
	}
}