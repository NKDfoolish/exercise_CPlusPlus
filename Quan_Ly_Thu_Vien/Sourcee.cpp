#include "CThuVien.h"
int main()
{
	CThuVien* x = new CThuVien;
	x->Input();
	x->Output();
	cout << "\n\n\t\tTONG TIEN LAM THE: " << (size_t)(x->TinhTongTienlamThe());
	delete x;

	system("pause");
	return 0;
}