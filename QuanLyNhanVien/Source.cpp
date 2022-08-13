#include <iostream>
using namespace std;
#include <string>

class Nhan_Vien_Sua_Ong_nuoc
{
private:
	string Hoten;
	int Tuoi;
	string GioiTinh;
	string DiaChi;
	string SDT;
	float ChieuCao;
	float CanNang;
	float SoGioSua;
public:
	void Nhap();
	void Xuat();
	float TinhTienLuong();

	Nhan_Vien_Sua_Ong_nuoc();
	~Nhan_Vien_Sua_Ong_nuoc();
};

void Nhan_Vien_Sua_Ong_nuoc::Nhap()
{
	rewind(stdin);
	cout << "\nNhap ho ten: ";
	getline(cin, Hoten);
	cout << "\nNhap tuoi: ";
	cin >> Tuoi;
	rewind(stdin);
	cout << "\nNhap gioi tinh: ";
	getline(cin, GioiTinh);
	cout << "\nNhap dia chi: ";
	getline(cin, DiaChi);
	cout << "\nNhap so dien thoai: ";
	getline(cin, SDT);
	cout << "\nNhap chieu cao: ";
	cin >> ChieuCao;
	cout << "\nNhap can nang: ";
	cin >> CanNang;
	cout << "\nNhap so gio sua: ";
	cin >> SoGioSua;
}

void Nhan_Vien_Sua_Ong_nuoc::Xuat()
{
	cout << "\nHo ten: " << Hoten;
	cout << "\nTuoi: " << Tuoi;
	cout << "\nGioi tinh: " << GioiTinh;
	cout << "\nDia chi: " << DiaChi;
	cout << "\nSo dien thoai: " << SDT;
	cout << "\nChieu cao: " << ChieuCao;
	cout << "\nCan nang: " << CanNang;
	cout << "\nSo gio sua: " << SoGioSua;
	cout << "\nTien Luong: " << (size_t)TinhTienLuong();
}

float Nhan_Vien_Sua_Ong_nuoc::TinhTienLuong()
{
	return SoGioSua * 50000;
}

Nhan_Vien_Sua_Ong_nuoc::Nhan_Vien_Sua_Ong_nuoc()
{

}

Nhan_Vien_Sua_Ong_nuoc::~Nhan_Vien_Sua_Ong_nuoc()
{

}

class Nhan_Vien_Giao_Hang
{
private:
	string Hoten;
	int Tuoi;
	string GioiTinh;
	string DiaChi;
	string SDT;
	float ChieuCao;
	float CanNang;
	int SoHangGiao;
public:
	void Nhap();
	void Xuat();
	float TinhTienLuong();

	Nhan_Vien_Giao_Hang();
	~Nhan_Vien_Giao_Hang();
};

void Nhan_Vien_Giao_Hang::Nhap()
{
	rewind(stdin);
	cout << "\nNhap ho ten: ";
	getline(cin, Hoten);
	cout << "\nNhap tuoi: ";
	cin >> Tuoi;
	rewind(stdin);
	cout << "\nNhap gioi tinh: ";
	getline(cin, GioiTinh);
	cout << "\nNhap dia chi: ";
	getline(cin, DiaChi);
	cout << "\nNhap so dien thoai: ";
	getline(cin, SDT);
	cout << "\nNhap chieu cao: ";
	cin >> ChieuCao;
	cout << "\nNhap can nang: ";
	cin >> CanNang;
	cout << "\nNhap so hang giao: ";
	cin >> SoHangGiao;
}

void Nhan_Vien_Giao_Hang::Xuat()
{
	cout << "\nHo ten: " << Hoten;
	cout << "\nTuoi: " << Tuoi;
	cout << "\nGioi tinh: " << GioiTinh;
	cout << "\nDia chi: " << DiaChi;
	cout << "\nSo dien thoai: " << SDT;
	cout << "\nChieu cao: " << ChieuCao;
	cout << "\nCan nang: " << CanNang;
	cout << "\nSo hang giao: " << SoHangGiao;
	cout << "\nTien Luong: " << (size_t)TinhTienLuong();
}

float Nhan_Vien_Giao_Hang::TinhTienLuong()
{
	return SoHangGiao * 33500;
}


Nhan_Vien_Giao_Hang::Nhan_Vien_Giao_Hang()
{

}
Nhan_Vien_Giao_Hang::~Nhan_Vien_Giao_Hang()
{

}

class Nhan_Vien_Xe_Om
{
private:
	string Hoten;
	int Tuoi;
	string GioiTinh;
	string DiaChi;
	string SDT;
	float ChieuCao;
	float CanNang;
	float SoKm;
public:
	void Nhap();
	void Xuat();
	float TinhTienLuong();

	Nhan_Vien_Xe_Om();
	~Nhan_Vien_Xe_Om();
};

void Nhan_Vien_Xe_Om::Nhap()
{
	rewind(stdin);
	cout << "\nNhap ho ten: ";
	getline(cin, Hoten);
	cout << "\nNhap tuoi: ";
	cin >> Tuoi;
	rewind(stdin);
	cout << "\nNhap gioi tinh: ";
	getline(cin, GioiTinh);
	cout << "\nNhap dia chi: ";
	getline(cin, DiaChi);
	cout << "\nNhap so dien thoai: ";
	getline(cin, SDT);
	cout << "\nNhap chieu cao: ";
	cin >> ChieuCao;
	cout << "\nNhap can nang: ";
	cin >> CanNang;
	cout << "\nNhap so kilomet: ";
	cin >> SoKm;
}

void Nhan_Vien_Xe_Om::Xuat()
{
	cout << "\nHo ten: " << Hoten;
	cout << "\nTuoi: " << Tuoi;
	cout << "\nGioi tinh: " << GioiTinh;
	cout << "\nDia chi: " << DiaChi;
	cout << "\nSo dien thoai: " << SDT;
	cout << "\nChieu cao: " << ChieuCao;
	cout << "\nCan nang: " << CanNang;
	cout << "\nSo kilomet: " << SoKm;
	cout << "\nTien Luong: " << (size_t)TinhTienLuong();
}

float Nhan_Vien_Xe_Om::TinhTienLuong()
{
	return SoKm * 10000;
}


Nhan_Vien_Xe_Om::Nhan_Vien_Xe_Om()
{

}
Nhan_Vien_Xe_Om::~Nhan_Vien_Xe_Om()
{

}

double Tong_Tien_Luong_Nhan_Vien_Sua_Ong_Nuoc(Nhan_Vien_Sua_Ong_nuoc ds[], int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += ds[i].TinhTienLuong();
	}
	return sum;
}

double Tong_Tien_Luong_Nhan_Vien_Giao_Hang(Nhan_Vien_Giao_Hang ds[], int m)
{
	double sum = 0;
	for (int i = 0; i < m; i++)
	{
		sum += ds[i].TinhTienLuong();
	}
	return sum;
}

double Tong_Tien_Luong_Nhan_Vien_Xe_Om(Nhan_Vien_Xe_Om ds[], int l)
{
	double sum = 0;
	for (int i = 0; i < l; i++)
	{
		sum += ds[i].TinhTienLuong();
	}
	return sum;
}

void Hoan_Vi_Sua_Ong_Nuoc(Nhan_Vien_Sua_Ong_nuoc& x, Nhan_Vien_Sua_Ong_nuoc& y)
{
	Nhan_Vien_Sua_Ong_nuoc tam = x;
	x = y;
	y = tam;
}

void Hoan_Vi_Giao_Hang(Nhan_Vien_Giao_Hang& x, Nhan_Vien_Giao_Hang& y)
{
	Nhan_Vien_Giao_Hang tam = x;
	x = y;
	y = tam;
}

void Hoan_Vi_Xe_Om(Nhan_Vien_Xe_Om& x, Nhan_Vien_Xe_Om& y)
{
	Nhan_Vien_Xe_Om tam = x;
	x = y;
	y = tam;
}

void Sap_Xep_Nhan_Vien_Sua_Ong_Nuoc_Giam_Dan_Luong(Nhan_Vien_Sua_Ong_nuoc ds[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ds[i].TinhTienLuong() < ds[j].TinhTienLuong())
			{
				Hoan_Vi_Sua_Ong_Nuoc(ds[i], ds[j]);
			}
		}
	}
}

void Sap_Xep_Nhan_Vien_Giao_Hang_Giam_Dan_Luong(Nhan_Vien_Giao_Hang ds[], int m)
{
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (ds[i].TinhTienLuong() < ds[j].TinhTienLuong())
			{
				Hoan_Vi_Giao_Hang(ds[i], ds[j]);
			}
		}
	}
}

void Sap_Xep_Nhan_Vien_Xe_Om_Giam_Dan_Luong(Nhan_Vien_Xe_Om ds[], int l)
{
	for (int i = 0; i < l - 1; i++)
	{
		for (int j = 0; j < l; j++)
		{
			if (ds[i].TinhTienLuong() < ds[j].TinhTienLuong())
			{
				Hoan_Vi_Xe_Om(ds[i], ds[j]);
			}
		}
	}
}

void Menu(Nhan_Vien_Sua_Ong_nuoc ds_nv_sua_ong_nuoc[], Nhan_Vien_Giao_Hang ds_nv_giao_hang[], Nhan_Vien_Xe_Om ds_nv_xe_om[], int n, int m, int l)
{
	int luachon;
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t============== MENU ==============\n";
		cout << "\n1. Nhap thong tin nhan vien sua chua ong nuoc";
		cout << "\n2. Nhap thong tin nhan vien giao hang";
		cout << "\n3. Nhap thong tin nhan vien xe om";
		cout << "\n4. Xuat thong tin nhan vien sua chua ong nuoc";
		cout << "\n5. Xuat thong tin nhan vien giao hang";
		cout << "\n6. Xuat thong tin nhan vien xe om";
		cout << "\n7. Tong tien luong cua ba loai nhan vien";
		cout << "\n8. Sap xep cac loai nhan vien giam dan theo luong";
		cout << "\n0. Ket thuc";
		cout << "\n\n\t\t============== END  ==============\n";

		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon < 0 || luachon>8)
		{
			cout << "\nLua chon khong hop le. Xin kiem tra lai!";
			system("pause");
		}
		else if (luachon == 1)
		{
			Nhan_Vien_Sua_Ong_nuoc nv_suaongnuoc;
			cout << "\n\n\t\tNhap thong tin nhan vien sua ong nuoc\n";
			nv_suaongnuoc.Nhap();
			ds_nv_sua_ong_nuoc[n] = nv_suaongnuoc;
			n++;
			system("pause");
		}
		else if (luachon == 2)
		{
			Nhan_Vien_Giao_Hang nv_giaohang;
			cout << "\n\n\t\tNhap thong tin nhan vien giao hang\n";
			nv_giaohang.Nhap();
			ds_nv_giao_hang[m] = nv_giaohang;
			m++;
			system("pause");
		}
		else if (luachon == 3)
		{
			Nhan_Vien_Xe_Om nv_xeom;
			cout << "\n\n\t\tNhap thong tin nhan vien xe om\n";
			nv_xeom.Nhap();
			ds_nv_xe_om[l] = nv_xeom;
			l++;
			system("pause");
		}
		else if (luachon == 4)
		{
			cout << "\n\n\t\t Danh sach nhan vien sua ong nuoc\n";
			for (int i = 0; i < n; i++)
			{
				cout << "\n\n\t Thong tin nhan vien sua ong nuoc thu " << i + 1;
				ds_nv_sua_ong_nuoc[i].Xuat();
			}
			cout << "\n\n\t\t Tong tien luong: " << Tong_Tien_Luong_Nhan_Vien_Sua_Ong_Nuoc(ds_nv_sua_ong_nuoc, n);
			system("pause");
		}
		else if (luachon == 5)
		{
			cout << "\n\n\t\t Danh sach nhan vien giao hang\n";
			for (int i = 0; i < m; i++)
			{
				cout << "\n\n\t Thong tin nhan vien giao hang thu " << i + 1;
				ds_nv_giao_hang[i].Xuat();
			}
			cout << "\n\n\t\t Tong tien luong: " << Tong_Tien_Luong_Nhan_Vien_Giao_Hang(ds_nv_giao_hang, m);
			system("pause");
		}
		else if (luachon == 6)
		{
			cout << "\n\n\t\t Danh sach nhan vien xe om\n";
			for (int i = 0; i < l; i++)
			{
				cout << "\n\n\t Thong tin nhan vien xe om thu " << i + 1;
				ds_nv_xe_om[i].Xuat();
			}
			cout << "\n\n\t\t Tong tien luong: " << Tong_Tien_Luong_Nhan_Vien_Xe_Om(ds_nv_xe_om, l);
			system("pause");
		}
		else if (luachon == 7)
		{
			cout << "\n\n\t\t Tong tien Cong Ty Phai Tra Hang thang: " << (size_t)(Tong_Tien_Luong_Nhan_Vien_Sua_Ong_Nuoc(ds_nv_sua_ong_nuoc, n) + Tong_Tien_Luong_Nhan_Vien_Giao_Hang(ds_nv_giao_hang, m) + Tong_Tien_Luong_Nhan_Vien_Xe_Om(ds_nv_xe_om, l));
			system("pause");
		}
		else if (luachon == 8)
		{
			cout << "\n\n\t\tDANH SACH GIAM DAN NHAN VIEN SUA ONG NUOC\n";
			Sap_Xep_Nhan_Vien_Sua_Ong_Nuoc_Giam_Dan_Luong(ds_nv_sua_ong_nuoc, n);
			for (int i = 0; i < n; i++)
			{
				cout << "\n\n\t Thong tin nhan vien sua ong nuoc thu " << i + 1;
				ds_nv_sua_ong_nuoc[i].Xuat();
			}
			cout << "\n\n\t\tDANH SACH GIAM DAN NHAN VIEN GIAO HANG\n";
			Sap_Xep_Nhan_Vien_Giao_Hang_Giam_Dan_Luong(ds_nv_giao_hang, m);
			for (int i = 0; i < m; i++)
			{
				cout << "\n\n\t Thong tin nhan vien giao hang thu " << i + 1;
				ds_nv_giao_hang[i].Xuat();
			}
			cout << "\n\n\t\tDANH SACH GIAM DAN NHAN VIEN SUA ONG NUOC\n";
			Sap_Xep_Nhan_Vien_Xe_Om_Giam_Dan_Luong(ds_nv_xe_om, l);
			for (int i = 0; i < l; i++)
			{
				cout << "\n\n\t Thong tin nhan vien xe om thu " << i + 1;
				ds_nv_xe_om[i].Xuat();
			}
			system("pause");
		}
		else if (luachon == 0)
		{
			break;
		}
	}
}

int main()
{
	Nhan_Vien_Sua_Ong_nuoc ds_nv_sua_ong_nuoc[100];
	Nhan_Vien_Giao_Hang ds_nv_giao_hang[100];
	Nhan_Vien_Xe_Om ds_nv_xe_om[100];
	int n = 0;
	int m = 0;
	int l = 0;
	Menu(ds_nv_sua_ong_nuoc, ds_nv_giao_hang, ds_nv_xe_om, n, m, l);

	system("pause");
	return 0;
}