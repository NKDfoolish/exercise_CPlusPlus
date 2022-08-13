#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "CDocGiaNguoiLon.h"
#include "CDocGiaTreEm.h"
#include <vector>


class CThuVien
{
private:
	vector <CDocGia *> ds_docgia;
public:
	void Input();
	void Output();
	int TinhTongTienlamThe();

	CThuVien();
	~CThuVien();
};

