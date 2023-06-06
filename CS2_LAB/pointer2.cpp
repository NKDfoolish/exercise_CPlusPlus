#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;

    return true;
}

void createArrayPrime(int quantity, int *&pointer) {
    int count = 0;
    int start = 0;
    while (count < quantity)
    {
        int i = count;
        if (isPrime(start)) {
            pointer[i] = start;
            count++;
        }
        start++;
        
    }
}

void printArray(int quantity, int* pointer) {
    for (int i = 0; i < quantity; i++)
    {
        cout << pointer[i] << " ";
    }
}

int main() {
    int quantity;
    cin >> quantity;
    int* p = new int[quantity];
    createArrayPrime(quantity, p);
    printArray(quantity, p);


    return 0;
}