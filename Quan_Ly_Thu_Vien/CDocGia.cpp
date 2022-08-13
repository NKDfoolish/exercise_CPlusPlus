#include "CDocGia.h"

void CDocGia::Input()
{
	rewind(stdin);
	cout << "\nNhap ho ten doc gia: ";
	getline(cin, hoten);
	rewind(stdin);
	cout << "\nNhap ngay lam the (dd/mm/yyyy): ";
	getline(cin, ngaylapthe);
	cout << "\nNhap so thang co hieu luc: ";
	cin >> sothangcohieuluc;
}

void CDocGia::Output()
{
	cout << "\nHo ten doc gia: " << hoten;
	cout << "\nNgay lam the: " << ngaylapthe;
	cout << "\nSo thang co hieu luc: " << sothangcohieuluc;
}

CDocGia::CDocGia()
{

}

CDocGia::~CDocGia()
{

}