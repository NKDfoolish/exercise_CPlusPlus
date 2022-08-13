#include <iostream>
using namespace std;
#define MAX 100
void nhap(int a[], int& n)
{
    do
    {
        cout << "\nNhap so phan tu:"; cin >> n;
        if (n <= 0 || n > MAX)
        {
            cout << "\nSo phan tu khong hop le. Xin kiem tra lai !";
        }
    } while (n <= 0 || n > MAX);
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap a[" << i << "]:";
        cin >> a[i];
    }
}

void xuat(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int KiemTraTangDan(int b[], int nb)
{
    for (int i = 0; i < nb - 1; i++)
    {
        if (b[i] > b[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

void XuatMangCon(int b[], int nb)
{
    for (int i = 0; i < nb; i++)
    {
        cout << b[i];
    }
    cout << endl;
}

void LietKeDayConTangDan(int a[], int n)
{
    int ChieuDai;//do lon cua mang con
    int b[MAX], nb;
    for (int i = 0; i < n; i++)
    {
        for (ChieuDai = 1; ChieuDai <= n; ChieuDai++)
        {
            nb = 0;
            for (int j = i; j < ChieuDai; j++)
            {
                b[nb] = a[j];
                nb++;
            }
            if (KiemTraTangDan(b, nb) == 1)
            {
                XuatMangCon(b, nb);
            }
        }
    }
}
int main()
{
    int n;
    int a[MAX];

    nhap(a, n);
    xuat(a, n);
    cout << "\nLiet ke cac day con tang: \n";
    LietKeDayConTangDan(a, n);

    return 0;
}