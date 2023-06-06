#include <iostream>
using namespace std;
#define MAX 100
// viet ham tach mang 2 chieu co m dong n cot thanh 2 mang 1 chieu b va c trong do b chua cac phan tu la so am va c chua cac phan tu la ko am
void nhap_mang(int a[][MAX], int m, int n) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++) {
			cout << "Nhap phan tu thu a[" << i << "][" << j << "] = "; cin >> a[i][j];
		}
	}
}

void tach_mang(int a[][MAX], int m, int n) {
	int nb = 0;
	int nc = 0;
	int b[MAX];
	int c[MAX];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++) {
			if (a[i][j] < 0) {
				b[nb++] = a[i][j];
			}
			else
			{
				c[nc++] = a[i][j];
			}
		}
	}

	cout << "Xuat mang b: ";
	for (int k = 0; k < nb; k++)
	{
		cout << b[k] << " ";
	}

	cout << endl;

	cout << "Xuat mang c: ";
	for (int l = 0; l < nc; l++)
	{
		cout << c[l] << " ";
	}
}

void xuat_mang(int a[][MAX], int m, int n) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int My_length(char c[]) {
	int i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return i;
}

int My_strcmp(char c1[], char c2[]) {
	int nc1 = My_length(c1);
	int nc2 = My_length(c2);

	int min = (nc1 < nc2) ? nc1 : nc2;

	for (int i = 0; i < min; i++)
	{
		if (c1[i] != c2[i]) {
			return c1[i] - c2[i];
		}
	}
	return nc1 - nc2;
}

void MyStrCpy(char c1[], char c2[]) {
	int nc2 = My_length(c2);
	for (int i = 0; i <= nc2; i++)
	{
		c1[i] = c2[i];
	}
}

int main() {
	int a[MAX][MAX];
	int m, n;
	nhap_mang(a, 3, 4);
	tach_mang(a, 3, 4);
	cout << endl;
	cout << "Mang goc: " << endl;
	xuat_mang(a, 3, 4);
	

	return 0;
}