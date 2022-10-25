#include <iostream>
using namespace std;
int test(int* &b) {
	b = new int;
	*b = 2;
	return *b;
}
int main() {
	int a = 3;
	int* p;
	p = &a;
	test(p);
	cout << *p;

	return 0;
}