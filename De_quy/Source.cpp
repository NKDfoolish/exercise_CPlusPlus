#include <iostream>
using namespace std;

int tong_1(int n) {
	if (n == 1) {
		return 1;
	}
	else {
		return n + tong_1(n - 1);
	}
}

int tich(int n) {
	if (n == 1) {
		return 2;
	}
	else {
		return 2 * n * tich(n - 1);
	}
}

float tong_2(int n) {
	if (n == 0) {
		return 1;
	}
	else {
		return ((1 / float((2 * n + 1))) + (tong_2(n - 1)));
	}
}

int count(int n) {
	if (n == 0) {
		return 0;
	}
	else {
		n /= 10;
		return 1 + count(n);
	}
}

int so_nhi_phan(int n) {
	if (n == 0) {
		return 0;
	}
	else {
		return (n % 2) + so_nhi_phan(n / 2) * 10;
	}
}
int UCLN(int a, int b) {
	if (a > b) {
		a = a - b;
		return UCLN(a, b);
	}
	else if (b > a) {
		b = b - a;
		return UCLN(a, b);
	}
	else {
		return a;
	}
}

void print(int n) {
	if (n == 0) {
		return;
	}
	else if (n > 0) {
		print(n - 1);
		cout << n << endl;
	}
}

int main() {

	return 0;
}