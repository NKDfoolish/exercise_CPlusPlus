#include <iostream>
using namespace std;
#define MAX 100

void nhap_Mang(int a[], int n);
void xuat_Mang(int a[], int n);
void day_Con_Toan_Duong_Dai_Nhat(int a[], int n);

int main() {
    int a[MAX];
    int na;
    cout << "Nhap so luong phan tu cua mang a tu ban phim: ";
    cin >> na;
    nhap_Mang(a, na);
    xuat_Mang(a, na);
    day_Con_Toan_Duong_Dai_Nhat(a, na);
    return 0;
}

void nhap_Mang(int a[], int n) {
    cout << "\n\t\t========== Nhap mang ==========\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap gia tri cho phan tu [" << i << "]: ";
        cin >> a[i];
    }
}

void xuat_Mang(int a[], int n) {
    cout << "\n\t\t========== Xuat mang ==========\n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

}

void day_Con_Toan_Duong_Dai_Nhat(int a[], int n) {
    int maxIdx = 0, maxLen = 0, currLen = 0, currIdx = 0;

    for (int k = 0; k < n; k++) {
        if (a[k] > 0) {
            currLen++;

            if (currLen == 1)
                currIdx = k;

            if (k == n - 1) {
                if (currLen > maxLen) {
                    maxLen = currLen;
                    maxIdx = currIdx;
                }
            }
        }
        else {
            if (currLen > maxLen) {
                maxLen = currLen;
                maxIdx = currIdx;
            }
            currLen = 0;
        }
    }

    if (maxLen > 0) {
        cout << "\nMang con toan duong dai nhat:\n";
        for (int l = maxIdx; l < maxIdx + maxLen; l++)
        {
            cout << a[l] << " ";
        }
    }
    else
        cout << "\nKhong ton tai mang con toan duong" << endl;
}