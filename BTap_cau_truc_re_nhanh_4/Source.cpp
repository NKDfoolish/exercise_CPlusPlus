#include<iostream>
using namespace std;
int main()
{
    int n;
    cout << "Nhap vao so n: ";
    cin >> n;
    int a = n % 10;
    int b = (n / 10) % 10;
    int c = n / 100;
    if (n < 0 || n > 999) {
        cout << "\nSo khong thoa man. Vui long nhap lai! ";
    }
    else {
        switch (c) {
        case 0:break;
        case 1: cout << "mot tram "; break;
        case 2: cout << "hai tram "; break;
        case 3: cout << "ba tram "; break;
        case 4: cout << "bon tram "; break;
        case 5: cout << "nam tram "; break;
        case 6: cout << "sau tram "; break;
        case 7: cout << "bay tram "; break;
        case 8: cout << "tam tram "; break;
        case 9: cout << "chin tram "; break;
        }
        if (c != 0 && b == 0 && a != 0) {
            cout<<"le ";
        }
        switch (b) {
        case 0:break;
        case 1: cout << "muoi "; break;
        case 2: cout << "hai muoi "; break;
        case 3: cout << "ba muoi "; break;
        case 4: cout << "bon muoi "; break;
        case 5: cout << "nam muoi "; break;
        case 6: cout << "sau muoi "; break;
        case 7: cout << "bay muoi "; break;
        case 8: cout << "tam muoi "; break;
        case 9: cout << "chin muoi "; break;
        }
        switch (a) {
        case 0:
            if (c==0&&b==0)
            {
                cout << "khong "; 
                break;
            }
            else
            {
                break;
            }
        case 1: cout << "mot "; break;
        case 2: cout << "hai "; break;
        case 3: cout << "ba "; break;
        case 4: cout << "bon "; break;
        case 5:
            if (b==0&&c==0)
            {
                cout << "nam ";
                break;
            }
            else
            {
                cout << "lam "; 
                break;
            }
        case 6: cout << "sau "; break;
        case 7: cout << "bay "; break;
        case 8: cout << "tam "; break;
        case 9: cout << "chin "; break;
        }
    }
    return 0;
}