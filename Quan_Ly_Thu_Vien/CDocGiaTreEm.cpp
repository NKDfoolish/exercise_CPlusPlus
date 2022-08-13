#include "CDocGiaTreEm.h"

void CDocGiaTreEm::Input()
{
	CDocGia::Input();
	rewind(stdin);
	cout << "\nNhap ten nguoi dai dien: ";
	getline(cin, hotennguoidaidien);
}

void CDocGiaTreEm::Output()
{
	CDocGia::Output();
	cout << "\nHo ten nguoi dai dien: " << hotennguoidaidien;
}

int CDocGiaTreEm::TinhTienLamThe()
{
	return sothangcohieuluc * 5000;
}

CDocGiaTreEm::CDocGiaTreEm()
{

}

CDocGiaTreEm::~CDocGiaTreEm()
{

}