#include <iostream>
using namespace std;

int main() {
	int k[100];
	int len;
	int start = 0;
	int max_length = 1;
	int sub_max_len = 1;
	int pos[100] = {};
	int temp;


	cout << "Nhap so luong phan tu cho mang : "; cin >> len;
	cout << "Nhap mang: " << endl;
	for (int i = 0; i < len; i++)
	{
		cout << "Phan tu thu " << i + 1 << " : ";
		cin >> k[i];
		cout << endl;
	}

	for (int i = 0; i < len; i++) {
		if (k[i] < k[i + 1]) {
			if (i == 0 || k[i] < k[i - 1]) {
				temp = i;
			}
			//pos[start++] = i;
			sub_max_len++;
		}
		else if ((k[i] > k[i + 1]) && i != 0) {
			pos[start++] = -1;
			if (sub_max_len >= max_length) {
				max_length = sub_max_len;
				
			}
			sub_max_len = 1;
		}
	}
	// 1 2 -1 4 5 -1 -1  0 0 ...

	for (int i = 0; i < len; i++) {
		if (((pos[i - 1] == -1 && pos[i] != 0) || i == 0) && (pos[i] != -1)) {
			cout << pos[i] << " La vi tri xuat hien cua mang: ";
		}
		if (pos[i] == 0 && !(i==0)) {
		}
		else if (pos[i] != -1 ) {
			cout << k[pos[i]] << " ";
		}
		else if ((pos[i] == -1) && (pos[i] != pos[i - 1])) {
			cout << k[pos[i - 1] + 1] << endl;
		}
	}


	return 0;
}