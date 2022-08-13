#include "CThuVien.h"

void CThuVien::Input()
{
	int luachon;
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t\=============== THU VIEN X ==============";
		cout << "\n\t1. Doc gia tre em";
		cout << "\n\t2. Doc gia nguoi lon";
		cout << "\n\t0. Thoat";
		cout << "\n\n\t\t\===============     END    ==============";

		cout << "\nNhap lua chon: ";
		cin >> luachon;

		CDocGia* x;
		if (luachon == 1)
		{
			x = new CDocGiaTreEm;
			cout << "\n\n\t\tNHAP THONG TIN DOC GIA\n";
			x->Input();
			x->Setter_KT(true);
			ds_docgia.push_back(x);
		}
		else if (luachon == 2)
		{
			x = new CDocGiaNguoiLon;
			cout << "\n\n\t\tNHAP THONG TIN DOC GIA\n";
			x->Input();
			x->Setter_KT(false);
			ds_docgia.push_back(x);
		}
		else if (luachon == 0)
		{
			break;
		}
		else
		{
			cout << "\nLua chon khong hop le! Xin vui long nhap lai...";
		}
	}
}

void CThuVien::Output()
{
	cout << "\n\n\t\tDANH SACH DOC GIA\n";
	for (int i = 0; i < ds_docgia.size(); i++)
	{
		if (ds_docgia[i]->Getter_KT() == true)
		{
			cout << "\n\n\t\tDANH SACH DOC GIA TRE EM THU " << i + 1;
			ds_docgia[i]->Output();
		}
		else
		{
			cout << "\n\n\t\tDANH SACH DOC GIA NGUOI LON THU " << i + 1;
			ds_docgia[i]->Output();
		}
		
	}
}

int CThuVien::TinhTongTienlamThe()
{
	int sum = 0;
	for (int  i = 0; i < ds_docgia.size(); i++)
	{
		sum = sum + ds_docgia[i]->TinhTienLamThe();
	}
	return sum;
}

CThuVien::CThuVien()
{

}
CThuVien::~CThuVien()
{

}