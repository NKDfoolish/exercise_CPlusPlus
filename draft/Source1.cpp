#include <iostream>

using namespace std;

int fun(int n)
{
int S = 1, i;

for (i = 1; i < n; i++);

if (n % i)
	S *= i;

return S;

}

int main() {
	cout << fun(5);

	return 0;
}