#pragma once
#include <iostream>
using namespace std;
#include <string>
#include"CDocGia.h"

class CDocGiaNguoiLon:public CDocGia
{
private:
	string CMND;
public:
	void Input();
	void Output();
	int TinhTienLamThe();

	CDocGiaNguoiLon();
	~CDocGiaNguoiLon();
};

