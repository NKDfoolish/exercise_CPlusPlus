#include<iostream>
using namespace std;
void Doc_So(int n)
{
    int m;
    int dem = 0;
    int sdn = 0;
    int dem_2 = 0;   
    m = n;
    while (m != 0)
    {
        dem_2++;
        m = m / 10;
    }
    while (n != 0)
    {
        int temp = n % 1000;
        sdn = sdn * 1000 + temp;
        n = n / 1000;
    }
    n = sdn;
    while (n != 0)
    {
        int a = n % 10;
        n = n / 10;
        int b = n % 10;
        n = n / 10;
        int c = n % 10;
        ++dem;
        switch (c) {
        case 0:
            if (dem > 1)
            {
                cout << "khong tram ";
                break;
            }
            else
            {
                break;
            }
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
        if (c != 0 && b == 0 && a != 0 || c == 0 && b == 0 && a != 0 && dem > 1) {
            cout << "le ";
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
            if (c == 0 && b == 0)
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
            if (b == 0 && c == 0)
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

        if (dem_2 > 6)
        {
            if (dem == 1)
            {
                cout << "trieu ";
            }
            else if (dem == 2)
            {
                cout << "nghin ";
            }
        }
        else if (dem_2 < 7 && dem_2 > 3)
        {
            if (dem == 1)
            {
                cout << "nghin ";
            }
        }
        n = n / 10;
    }
}
int main()
{
    int n;
    do
    {
        cout << "Nhap vao so n: ";
        cin >> n;
    } while (n < 0 || n > 999999999);   
    Doc_So(n);  
    return 0;
}