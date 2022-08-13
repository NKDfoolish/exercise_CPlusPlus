#include <iostream>
#include <fstream>
#define MAX 100
using namespace std;

struct ps
{
	int ts;
	int ms;
};
typedef struct ps ps;

void nhap_1_ps(ps& a);
void xuat_1_pt(ps a);
void xuat_ds(ps ds[], int n);

int ucln(int a, int b);
void rut_gon(ps& a);
void tim_ps_max(ps ds[], int n);

ps tong(ps a, ps b);
void tong_ds(ps ds[], int n);

void them(ps ds[], int& n, int vt, ps x);
void xoa(ps ds[], int& n, int vt);

istream& operator >>(istream& is, ps& a);
ostream& operator <<(ostream& os, ps a);
ps operator + (ps a, ps b);

void main()
{
	ps a;
	cin >> a;


	ps b;
	cin >> b;

	cout << a + b;



	system("pause");
	ps ds[MAX]; int n = 0;
	bool kt_menu = true;
	while (kt_menu == true)
	{
		system("cls");
		cout << "1. Nhap phan so" << endl;
		cout << "2. Xuat danh sach phan so" << endl;
		cout << "3. Tim ps max" << endl;
		cout << "4. Tong danh sach" << endl;
		cout << "5. Them phan so x tai vi tri vt nhap tu ban phim" << endl;
		cout << "6. Xoa phan so tai vi tri vt nhap tu ban phim" << endl;
		int lc;
		cout << "Nhap lc: "; cin >> lc;
		switch (lc)
		{
		case 1:
		{
			int sl;
			cout << "Nhap sl phan so can them: "; cin >> sl;
			for (int i = 1; i <= sl; i++)
			{
				cout << "\t\t--- Nhap ps thu " << i << " ----" << endl;
				ps a;
				nhap_1_ps(a);
				//---- Thêm cuối ---
				ds[n++] = a;
			}
			break;
		}
		case 2:
		{
			xuat_ds(ds, n);
			system("pause");
			break;
		}
		case 3:
		{
			tim_ps_max(ds, n);
			system("pause");
			break;
		}
		case 4:
		{
			tong_ds(ds, n);
			system("pause");
			break;
		}
		case 5:
		{
			ps x;
			int vt;
			cout << "Nhap pt can them: " << endl;
			nhap_1_ps(x);
			cout << "Nhap vi tri can them: "; cin >> vt;
			them(ds, n, vt, x);
			system("pause");
			break;
		}
		case 6:
		{
			int vt;
			cout << "Nhap vi tri can them: "; cin >> vt;
			xoa(ds, n, vt);
			system("pause");
			break;
		}
		}
	}
}
void nhap_1_ps(ps& a)
{
	// 1/4	-1/4	1/-4	-1/-4	1/0		0/4		5/1

	cout << "Nhap tu so: "; cin >> a.ts;
	do
	{
		cout << "Nhap mau so: "; cin >> a.ms;
	} while (a.ms == 0);

	if (a.ms < 0)
	{
		a.ts = -a.ts;
		a.ms = -a.ms;
	}
	rut_gon(a);
}
istream& operator >>(istream& is, ps& a)
{
	cout << "Nhap tu so: "; is >> a.ts;
	do
	{
		cout << "Nhap mau so: "; is >> a.ms;
	} while (a.ms == 0);

	if (a.ms < 0)
	{
		a.ts = -a.ts;
		a.ms = -a.ms;
	}
	rut_gon(a);
	return is;
}

void xuat_1_pt(ps a)
{
	if (a.ts == 0 || a.ms == 1)
	{
		cout << a.ts << endl;
	}
	else
	{
		cout << a.ts << "/" << a.ms << endl;
	}
}
ostream& operator <<(ostream& os, ps a)
{
	if (a.ts == 0 || a.ms == 1)
	{
		os << a.ts << endl;
	}
	else
	{
		os << a.ts << "/" << a.ms << endl;
	}
	return os;
}


void xuat_ds(ps ds[], int n)
{
	cout << "\t\t===== Xuat ====" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "PT thu " << i << ": "; xuat_1_pt(ds[i]);
	}
}
int ucln(int a, int b)
{
	a = abs(a);
	b = abs(b);
	while (a != b)
	{
		(a > b) ? a = a - b : b = b - a;
	}
	return a;//b
}
void rut_gon(ps& a)
{
	int uc = ucln(a.ts, a.ms);
	//4/8
	a.ts = a.ts / uc;// ts = 4/ucln(4,8) = 1
	a.ms = a.ms / uc;// = 8/ucln(1,8) = 8
}
int so_sanh(ps a, ps b)
{
	return (a.ts * b.ms - b.ts * a.ms);
}
void tim_ps_max(ps ds[], int n)
{
	//1/3	3/4
	ps max = ds[0];
	for (int i = 1; i < n; i++)
	{
		if (so_sanh(ds[i], max) > 0)
		{
			max = ds[i];
		}
	}
	cout << " Phan so max la: "; xuat_1_pt(max);
}
ps tong(ps a, ps b)
{
	//1/3 + 3/4
	ps s;
	s.ts = a.ts * b.ms + b.ts * a.ms;
	s.ms = a.ms * b.ms;
	rut_gon(s);
	return s;
}

ps operator + (ps a, ps b)
{
	//1/3 + 3/4
	ps s;
	s.ts = a.ts * b.ms + b.ts * a.ms;
	s.ms = a.ms * b.ms;
	rut_gon(s);
	return s;
}

void tong_ds(ps ds[], int n)
{
	ps s = ds[0];
	for (int i = 1; i < n; i++)
	{
		s = tong(s, ds[i]);
	}
	cout << "Tong la: "; xuat_1_pt(s);
}
void them(ps ds[], int& n, int vt, ps x)
{
	for (int i = n; i > vt; i--)
	{
		ds[i] = ds[i - 1];
	}
	ds[vt] = x;
	n++;
}//template
void xoa(ps ds[], int& n, int vt)
{
	for (int i = vt; i < n - 1; i++)
	{
		ds[i] = ds[i + 1];
	}
	n--;
}