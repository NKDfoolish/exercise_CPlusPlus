#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "CDocGia.h"

class CDocGiaTreEm : public CDocGia 
{
private:
	string hotennguoidaidien;
public:
	void Input();
	void Output();
	int TinhTienLamThe();

	CDocGiaTreEm();
	~CDocGiaTreEm();
};

