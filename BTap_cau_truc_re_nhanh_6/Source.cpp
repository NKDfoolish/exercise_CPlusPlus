#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cout << "Nhap a: ";
    cin >> a;
    cout << "\nNhap b: ";
    cin >> b;
    if (a > 0 && b > 0)
    {
        a = a + b;
        b = a - b;
        a = a - b;
        cout << "\na= " << a << " ,b= " << b;
    }
    else
    {
        cout << "\nSo ban nhap khong phai so nguyen duong.";
    }
    
    return 0;
}