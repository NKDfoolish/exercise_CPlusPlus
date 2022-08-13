#include <iostream>
using namespace std;

struct sinh_vien {
	char mssv[20];
	char hoTen[30];
	float diem_ki_thuat_lap_trinh;
	float diem_toan_roi_rac;
	float diem_ctdl;
};
typedef struct sinh_vien sv;

void nhap_thong_tin_1_sv(sv& a);
void xuat_thong_tin_1_sv(sv a);
void xuat_danh_sach_sv(sv ds[], int n);
void xep_loai_hoc_luc_sinh_vien(float dtb);
float tinh_diem_trung_binh(sv a);
void sap_xep_danh_sach_sinh_vien_theo_diem_trung_binh(sv ds[], int n);
void them_ki_tu(char k[], int &n, int vt, char x);
void lay_ten(char sv[], char k[]);
int so_sanh_ten(char x[], char y[]);

int main() {
	sv ds[100]; int n = 0;
	bool check = true;
	while (check == true)
	{
		system("cls");
		cout << "1.Nhap thong tin sinh vien" << endl;
		cout << "2.Xuat danh sach sinh vien" << endl;
		cout << "3. Xep loai hoc luc sinh vien theo diem trung binh 3 mon" << endl;
		cout << "4. Sap xep sinh vien theo diem trung binh" << endl;
		cout << "5. Sap xep danh sach sinh vien giam dan theo ten sinh vien." << endl;
		cout << "0. Thoat khoi chuong trinh" << endl;

		int lc; cout << "Nhap lua chon: "; cin >> lc;
		switch (lc)
		{
		case 1:
		{
			int sl;
			cout << "Nhap so luong sinh vien: "; cin >> sl;
			for (int i = 0; i < sl; i++)
			{
				cin.ignore();
				sv a;
				nhap_thong_tin_1_sv(a);
				ds[n++] = a;
			}
			break;
		}
		case 2:
		{
			xuat_danh_sach_sv(ds, n);
			system("pause");
			break;
		}
		case 3:
		{
			cout << "Xep loai hoc luc cua sinh vien:" << endl;
			for (int i = 0; i < n; i++)
			{
				cout << "Sinh vien thu " << i + 1 << " : "; 
				xep_loai_hoc_luc_sinh_vien(tinh_diem_trung_binh(ds[i]));
				cout << endl;
			}
			system("pause");
			break;
		}
		case 4:
		{
			sap_xep_danh_sach_sinh_vien_theo_diem_trung_binh(ds, n);
			break;
		}
		case 5:
		{
			
			for (int i = 0; i < n - 1; i++)
			{
				for (int j = i + 1; j < n; j++) {
					char copy_i[50] = "";
					char copy_j[50] = "";
					strcpy_s(copy_i, ds[i].hoTen);
					strcpy_s(copy_j, ds[j].hoTen);

					char k[10] = "";
					char l[10] = "";
					lay_ten(copy_j, k);
					lay_ten(copy_i, l);

					if (so_sanh_ten(k,l)<0)
					{
						swap(ds[i], ds[j]);
					}
					else if (so_sanh_ten(k,l) == 0) {
						int v = 0;
						int y = 0;
						int lenght_name_original = strlen(copy_i);
						int name = strlen(k);
						for (v; v < lenght_name_original-name-1; v++)//-1 la tru them cho khoang trang
						{
							copy_i[v++] = ds[i].hoTen[v++];
						}
						copy_i[v] = '\0';

						for (y; y < lenght_name_original - name - 1; y++)//-1 la tru them cho khoang trang
						{
							copy_i[y++] = ds[j].hoTen[y++];
						}
						copy_i[y] = '\0';

						lay_ten(copy_j, k);
						lay_ten(copy_i, l);
						if (so_sanh_ten(k, l) < 0)
						{
							swap(ds[i], ds[j]);
						}

					}
				}
			}
			system("pause");
			break;
		}
		case 0:
		{
			check = false;
			break;
		}
		}
	}

	return 0;
}
void nhap_thong_tin_1_sv(sv &a) {
	cout << "Nhap ma so sinh vien: "; gets_s(a.mssv);
	cout << "Nhap ho ten sinh vien: "; gets_s(a.hoTen);
	cout << "Nhap diem ki thuat lap trinh: "; cin >> a.diem_ki_thuat_lap_trinh;
	cout << "Nhap diem toan roi rac: "; cin >> a.diem_toan_roi_rac;
	cout << "Nhap diem cau truc du lieu: "; cin >> a.diem_ctdl;
}
void xuat_thong_tin_1_sv(sv a) {
	cout << "Ma sinh vien: " << a.mssv << endl;
	cout << "Ho ten sinh vien: " << a.hoTen << endl;
	cout << "Diem ki thuat lap trinh: " << a.diem_ki_thuat_lap_trinh << endl;
	cout << "Diem toan roi rac: " << a.diem_toan_roi_rac << endl;
	cout << "Diem cau truc du lieu: " << a.diem_ctdl << endl;
}
void xuat_danh_sach_sv(sv ds[], int n) {
	cout << "Thong tin sinh vien: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Sinh vien thu " << i + 1 << " : " << endl;
		xuat_thong_tin_1_sv(ds[i]);
	}
}
float tinh_diem_trung_binh(sv a) {
	float dtb = (float)(a.diem_ctdl + a.diem_ki_thuat_lap_trinh + a.diem_toan_roi_rac) / 3;
	return dtb;
}
void xep_loai_hoc_luc_sinh_vien(float dtb) {
	if (dtb > 9.8) {
		cout << "Hoc luc xuat sac.";
	}
	else if (dtb >= 8) {
		cout << "Hoc luc gioi.";
	}
	else if (dtb >= 6.5) {
		cout << "Hoc luc kha.";
	}
	else if (dtb >= 4) {
		cout << "Hoc luc trung binh.";
	}
	else
	{
		cout << "Hoc luc yeu.";
	}
}
void sap_xep_danh_sach_sinh_vien_theo_diem_trung_binh(sv ds[], int n) {
	
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (tinh_diem_trung_binh(ds[j]) > tinh_diem_trung_binh(ds[i])) {
				swap(ds[j], ds[i]);
			}
		}
	}
}
void them_ki_tu(char k[], int &n, int vt, char x) {
	for (int i = n+1; i > vt; i--)
	{
		k[i] = k[i - 1];
	}
	k[vt] = x;
	n++;
}
void lay_ten(char sv[], char k[]) {
	int m = 0;
	k[0] = '\0';
	int n = strlen(sv);
	for (int i = n; i >= 0; i--) {
		if (sv[i] == ' ')
		{
			break;
		}
		else {
			them_ki_tu(k, m, 0, sv[i]);
		}
	}
}
int so_sanh_ten(char x[], char y[]) {
	return strcmp(x, y);
}
