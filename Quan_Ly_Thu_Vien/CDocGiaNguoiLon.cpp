#include "CDocGiaNguoiLon.h"

void CDocGiaNguoiLon::Input()
{
	CDocGia::Input();
	rewind(stdin);
	cout << "\nNhap CMND: ";
	getline(cin, CMND);
}

void CDocGiaNguoiLon::Output()
{
	CDocGia::Output();
	cout << "\nChung minh nhan dan: " << CMND;
}

int CDocGiaNguoiLon::TinhTienLamThe()
{
	return sothangcohieuluc * 10000;
}

CDocGiaNguoiLon::CDocGiaNguoiLon()
{

}

CDocGiaNguoiLon::~CDocGiaNguoiLon()
{

}
