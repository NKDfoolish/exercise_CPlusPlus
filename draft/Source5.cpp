#include <iostream>
#define array_size 100
using namespace std;

void nhap(int a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
bool check(int n)
{
    int t = n;
    int socuoi;
    int r = 0;
    while (t > 0)
    {
        socuoi = t % 10;
        r = r * 10 + socuoi;
        t = t / 10;
    }

    if (r == n)
    {
        return true;
    }
    else {

        return false;
    }
}
void xuat(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (check(a[i]))
        {
            cout << a[i] << " ";
        }
        
    }
    cout << endl;
}

void STN(int a[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (check(a[i]))
        {
            dem = dem + 1;
        }
    }
    cout << dem <<endl;
}

int main()
{
    int a[array_size];
    int n;
    int dem;
    int daonguoc;
    nhap(a, n);
    STN(a, n);
    xuat(a, n);

}