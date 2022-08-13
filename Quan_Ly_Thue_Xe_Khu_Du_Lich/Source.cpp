#include <iostream>
using namespace std;
#include <string>

class XE
{
protected:
	string HoTenNguoiThue;
	float SoGioThue;
public:
	void NhapThongTin()
	{
		rewind(stdin);
		cout << "\nNhap ho ten nguoi thue: ";
		getline(cin, HoTenNguoiThue);
		cout << "\nNhap so gio thue: ";
		cin >> SoGioThue;
	}
	void XuatThongTin()
	{
		cout << "\nHo ten nguoi thue: " << HoTenNguoiThue;
		cout << "\nSo gi thue: " << SoGioThue;
	}
};

class XEDAP :public XE
{
private:
public:
	float TinhTienThueXe()
	{
		return 10000 + ((SoGioThue - 1) * 8000);
	}
};

class XEMAY :public XE
{
private:
	int LoaiXe;
	string BienSo;
public:
	void NhapThongTin()
	{
		XE::NhapThongTin();
		cout << "\nNhap loai xe can thue (100-250) phan khoi: ";
		cin >> LoaiXe;
		rewind(stdin);
		cout << "\nNhap bien so: ";
		getline(cin, BienSo);
	}
	void XuatThongTin()
	{
		XE::XuatThongTin();
		cout << "\nLoai xe: " << LoaiXe;
		cout << "\nBien so: " << BienSo;
	}
	float TinhTienThueXe()
	{
		float s = 0;
		if (LoaiXe == 100)
		{
			s = 150000;
		}
		else
		{
			s = 200000;
		}
		return s + ((SoGioThue - 1) * 100000);
	}
	int getter_loaixe()
	{
		return LoaiXe;
	}
	void setter_loaixe(int LOAIXE)
	{
		LoaiXe = LOAIXE;
	}
};

void XuatTatCaThongTinthueXe(XEDAP ds_xedap[], int n, XEMAY ds_xemay[], int m)
{
	int dem = 1;
	cout << "\n\n\t\tDANH SACH THUE XE DAP\n";
	for (int i = 0; i < n; i++)
	{
		cout << "\n\n\t\tThong tin thue xe dap thu " << dem++ << endl;
		ds_xedap[i].XuatThongTin();
		cout << "\nTien thue: " << (size_t)ds_xedap[i].TinhTienThueXe();
	}
	cout << "\n\n\t\tDANH SACH THUE XE MAY\n";
	for (int i = 0; i < m; i++)
	{
		cout << "\n\n\t\tThong tin thue xe may thu " << i+1 << endl;
		ds_xemay[i].XuatThongTin();
		cout << "\nTien thue: " << (size_t)ds_xemay[i].TinhTienThueXe();
	}
}

float TinhTongTienThueXe(XEDAP ds_xedap[], int n, XEMAY ds_xemay[], int m)
{
	float tong = 0;
	for (int i = 0; i < n; i++)
	{
		tong += ds_xedap[i].TinhTienThueXe();
	}
	for (int i = 0; i < m; i++)
	{
		tong += ds_xemay[i].TinhTienThueXe();
	}
	return tong;
}

void Menu(XEDAP ds_xedap[], int n, XEMAY ds_xemay[], int m)
{
	int luachon;
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t============== Quan ly xe ===============";
		cout << "\n\t1. Nhap danh sach thue xe dap va xe may";
		cout << "\n\t2. Xuat tat ca thong tin thue xe";
		cout << "\n\t3. Tinh tong so tien cho thue xe dap va xe may";
		cout << "\n\t4. Xuat tat ca cac thong tin lien quan den viec cho thue xe dap";
		cout << "\n\t5. Tinh tong so tien cho thue xe may loai 250 phan khoi";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t==============     End    ===============";

		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 1)
		{
			int chon;
			while (true)
			{
				system("cls");
				cout << "\n1.Thue xe dap";
				cout << "\n2.Thue xe may";
				cout << "\n0.Ket thuc";

				cout << "\nNhap loai xe ban muon thue: ";
				cin >> chon;

				if (chon == 1)
				{
					XEDAP x;
					cout << "\n\n\t\tNhap thong tin thue xe dap\n";
					x.NhapThongTin();
					ds_xedap[n] = x;
					n++;
				}
				else if (chon == 2)
				{
					XEMAY x;
					cout << "\n\n\t\tNhap thong tin thue xe may\n";
					x.NhapThongTin();
					ds_xemay[m] = x;
					m++;
				}
				else if (chon == 0)
				{
					break;
				}
			}
		}
		else if (luachon == 2)
		{
			XuatTatCaThongTinthueXe(ds_xedap, n, ds_xemay, m);
			system("pause");
		}
		else if (luachon == 3)
		{
			cout << "\nTONG TIEN THU XE : " << (size_t)TinhTongTienThueXe(ds_xedap, n, ds_xemay, m);
			system("pause");
		}
		else if (luachon == 0)
		{
			break;
		}
		else if (luachon == 4)
		{
			cout << "\n\n\t\tDANH SACH THUE XE DAP\n";
			for (int i = 0; i < n; i++)
			{
				cout << "\n\n\t\tThong tin thue xe dap thu " << i + 1 << endl;
				ds_xedap[i].XuatThongTin();
				cout << "\nTien thue: " << (size_t)ds_xedap[i].TinhTienThueXe();
			}
			system("pause");
		}
		else if (luachon == 5)
		{
			int dem = 0;
			cout << "\n\n\t\tDANH SACH THUE XE MAY LOAI 250 PHAN KHOI\n";
			for (int i = 0; i < m; i++)
			{
				if (ds_xemay[i].getter_loaixe() == 250)
				{
					cout << "\n\n\t\tThong tin thue xe may thu " << ++dem << endl;
					ds_xemay[i].XuatThongTin();
					cout << "\nTien thue: " << (size_t)ds_xemay[i].TinhTienThueXe();
				}
			}
			system("pause");
		}
	}
}

int main()
{
	XEDAP ds_xedep[100];
	int n = 0;
	XEMAY ds_xemay[100];
	int m = 0;
	Menu(ds_xedep, n, ds_xemay, m);

	system("pause");
	return 0;
}