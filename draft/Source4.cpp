#include <iostream>
using namespace std;

int main() {
	int k[100];
	int len;
	int start = 0;
	int max_length = 1;
	int sub_max_len = 1;
	int pos[100] = {};
	int dup = 1;


	cout << "Nhap so luong phan tu cho mang : "; cin >> len;
	cout << "Nhap mang: " << endl;
	for (int i = 0; i < len; i++)
	{
		cout << "Phan tu thu " << i + 1 << " : ";
		cin >> k[i];
		cout << endl;
	}
	int box;
	for (int i = 0; i < len; i++)
	{
		if ((k[i] < k[i - 1] && k[i] < k[i + 1]) || (k[i] < k[i + 1] && i == 0)) {
			//pos[start] = i;
			box = i;
		}
		if (k[i] < k[i + 1]) {
			sub_max_len++;
		}
		else if ((k[i] > k[i + 1] && i != 0) || (k[i] > k[i - 1] && i == len - 1)) {
			if (sub_max_len > max_length) {
				max_length = sub_max_len;
				pos[start] = box;

			}
			else if (sub_max_len == max_length) {
				dup++;
				start++;
				pos[start] = box;
			}
			sub_max_len = 1;
		}
	}	
	
	for (int i = 0; i < dup; i++)
	{
		cout << pos[i] << " la vi tri cua mang: ";
		for (int j = pos[i]; j < pos[i] + max_length; j++) {
			cout << k[j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}