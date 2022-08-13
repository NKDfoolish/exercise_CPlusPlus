#pragma once // tranh tinh trang dung do thu vien
#include <iostream>
using namespace std;
#include <string>

class CDocGia
{
protected:
	string hoten;
	string ngaylapthe;
	int sothangcohieuluc;
	bool KT;
public:
	virtual void Input();
	virtual void Output();
	virtual int TinhTienLamThe() = 0;
	bool Getter_KT()
	{
		return KT;
	}

	void Setter_KT(bool kt)
	{
		KT = kt;
	}

	CDocGia();
	~CDocGia();
};

