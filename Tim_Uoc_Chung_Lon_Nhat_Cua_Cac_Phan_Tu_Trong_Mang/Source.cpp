/*
7. Viết chương trình tìm UCLN của tất cả các phần tử trong mảng 1 chiều các số nguyên.
*/
#include<iostream>
using namespace std;
using namespace std;

// hàm nhập mảng
void Nhap_Mang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap phan tu a[" << i << "] = ";
		cin >> a[i]; // nhập giá trị từ bàn phím cho a[i]
	}
}

// hàm xuất mảng
void Xuat_Mang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "  ";
	}
}

// hàm tìm ước số chung lớn nhất của 2 số nguyên bất kì x, y, x , y > 0
int UCLN(int a, int b)
{
	// Nếu a = 0 => ucln(a,b) = b
	// Nếu b = 0 => ucln(a,b) = a
	if (a == 0 || b == 0) {
		return a + b;
	}
	while (a != b) {
		if (a > b) {
			a -= b; // a = a - b
		}
		else {
			b -= a;
		}
	}
	return a; // return a or b, bởi vì lúc này a và b bằng nhau
}

// hàm tìm ước số chung lớn nhất của tất cả các phần tử trong mảng
int UCLN_Cua_Mang(int a[], int n)
{
	int x = a[0]; // biến chính là ước chung lớn nhất của tất cả các phần tử trong mảng
	for (int i = 1; i < n; i++)
	{
		x = UCLN(x, a[i]); // tìm ước chung lớn nhất của x và a[i] - sau đó gán lại cho biến x
	}
	return x; // biến x sau khi thoát khỏi vòng lặp - giá trị chính là kết quả cần tìm
}

int main()
{
	int a[100]; // khai báo mảng tĩnh chứa tối đa 100 phần tử
	int n;
	do
	{
		cout << "\nNhap n: ";
		cin >> n;
		if (n <= 0 || n > 100)

		{
			cout << "\nSo luong phan tu khong hop le.";
		}

	} while (n <= 0 || n > 100);

	cout << "\n\n\t\t NHAP MANG\n";
	Nhap_Mang(a, n);
	cout << "\n\n\t\t XUAT MANG\n";
	Xuat_Mang(a, n);

	cout << "\nUoc chung lon nhat cua tat ca cac phan tu trong mang: " << UCLN_Cua_Mang(a, n) << endl << endl;

	system("pause");
	return 0;
}