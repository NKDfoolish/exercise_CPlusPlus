#include <iostream>
using namespace std;
#define MAX 100

void PrimeArrayInput(int* a, int& n);
int NOEContainsY(int* a, int n, int y);


bool isPrime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;

    return true;
}

void PrimeArrayInput(int* a, int& n) {
	cin >> n;
    int count = 0;
    int start = 0;
    while (count < n)
    {
        int i = count;
        if (isPrime(start)) {
            a[i] = start;
            count++;
        }
        start++;

    }
}

bool checkExist(int source, int num) {
    while (source >0)
    {
        if (source % 10 == num) {
            return true;
        }
        else
        {
            source = source / 10;
        }
    }
    return false;
}

int NOEContainsY(int* a, int n, int y) {
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        if (checkExist(a[i], y)) {
            answer++;
        }
    }
    return answer;
}

int main()
{
	int a[MAX], n, y;
	cin >> y;
	PrimeArrayInput(a, n);
	cout << NOEContainsY(a, n, y);
	return 0;
}
