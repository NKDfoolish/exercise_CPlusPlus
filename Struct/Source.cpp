#include <iostream>
using namespace std;

struct phan_so {
	int tuSo;
	int mauSo;
};
typedef struct phan_so ps;

void nhap_1_ps(ps& a);
void xuat_1_ps(ps a);
void xuat_ds_ps(ps ds[], int n);
void rut_gon_1_ps(ps& a);
void tim_phan_so_lon_nhat(ps ds[], int n);
void tinh_tong_cac_phan_so(ps ds[], int n);
void xoa(ps ds[], int& n, int vt);
void them(ps ds[], int& n, int vt);

int main() {
	ps ds[100]; int n = 0;
	bool check_Menu = true;
	while (check_Menu == true)
	{
		system("cls");
		cout << "1. Nhap phan so" << endl;
		cout << "2. Xuat danh sach phan so" << endl;
		cout << "3. Rut gon phan so" << endl;
		cout << "4. phan so lon nhat" << endl;
		cout << "5. Tong cac phan so" << endl;
		cout << "6. Xoa phan so" << endl;
		cout << "7. Them phan so" << endl;
		cout << "0. Thoat chuong trinh" << endl;
		int choose; cout << "Nhap lua chon: "; cin >> choose;
		switch (choose)
		{
		case 1:
		{
			int sl;
			cout << "Nhap so luong phan so: "; cin >> sl;
			for (int i = 0; i < sl; i++)
			{
				cout << "phan so thu " << i + 1 << " : " << endl;
				ps a;
				nhap_1_ps(a);
				ds[n++] = a;
			}
			break;
		}
		case 2:
		{
			xuat_ds_ps(ds, n);
			system("pause");
			break;
		}
		case 3:
		{
			for (int i = 0; i < n; i++)
			{
				rut_gon_1_ps(ds[i]);
			}
			break;
		}
		case 4:
		{
			tim_phan_so_lon_nhat(ds, n);
			system("pause");
			break;
		}
		case 5:
		{
			tinh_tong_cac_phan_so(ds, n);
			system("pause");
			break;
		}
		case 6:
		{
			int vt;
			cout << "Nhap vi tri can xoa: "; cin >> vt;
			xoa(ds, n, vt);
			break;
		}
		case 7:
		{
			int vt;
			cout << "Nhap vi tri can them: "; cin >> vt;
			them(ds, n, vt);
			break;
		}
		case 0:
		{
			check_Menu = false;
		}

		}
	}

	return 0;
}
void nhap_1_ps(ps &a) {
	cout << "Nhap tu so: "; cin >> a.tuSo;
	cout << "Nhap mau so: "; cin >> a.mauSo;
}
void xuat_1_ps(ps a) {
	cout << a.tuSo << "/" << a.mauSo << endl;
}
void xuat_ds_ps(ps ds[],int n) {
	cout << "Danh sach phan so: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Phan so thu " << i + 1 << " : " << endl;
		xuat_1_ps(ds[i]);
	}
}
void rut_gon_1_ps(ps &a) {
	int min = (a.tuSo < a.mauSo) ? a.tuSo : a.mauSo;
	for (int i = min; i >= 2; i--)
	{
		if (a.mauSo % i == 0 && a.tuSo % i == 0) {
			a.tuSo = a.tuSo / i;
			a.mauSo = a.mauSo / i;
			break;
		}
	}
}
void tim_phan_so_lon_nhat(ps ds[], int n) {
	float max = (float)ds[0].tuSo / ds[0].mauSo;
	for (int i = 1; i < n; i++)
	{
		if (((float)ds[i].tuSo / ds[i].mauSo) > max) {
			max = ((float)ds[i].tuSo / ds[i].mauSo);
		}
	}
	
	cout << "Phan so lon nhat: " << endl;

	for (int i = 0; i < n; i++)
	{
		if (((float)ds[i].tuSo / ds[i].mauSo) == max) {
			xuat_1_ps(ds[i]);
		}
	}
}
ps tinh_tong_2_phan_so(ps a, ps b) {
	ps sum;
	sum.mauSo = a.mauSo * b.mauSo;
	sum.tuSo = (a.tuSo * b.mauSo) + (b.tuSo * a.mauSo);
	rut_gon_1_ps(sum);
	return sum;
}
void tinh_tong_cac_phan_so(ps ds[], int n) {
	ps sum = ds[0];
	for (int i = 1; i < n; i++)
	{
		sum = tinh_tong_2_phan_so(sum, ds[i]);
		//cout << "Xu ly : " << sum.tuSo << "/" << sum.mauSo << endl;
	}
	cout << "Tong cac phan so: " << sum.tuSo << "/" << sum.mauSo << endl;
}
void xoa(ps ds[], int &n, int vt) {
	for (int i = vt; i < n-1; i++)
	{
		ds[i] = ds[i + 1];
	}
	n--;
}
void them(ps ds[], int &n, int vt) {
	for (int i = n; i > vt; i--)
	{
		ds[i] = ds[i - 1];
	}
	ps a;
	nhap_1_ps(a);
	ds[vt] = a;
	n++;
}