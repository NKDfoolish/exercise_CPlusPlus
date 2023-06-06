#include <iostream>
#include <string>
using namespace std;

struct SinhVien {
    string sbd;
    string hoTen;
    int khoa;
    string ngaySinh;
    float gpa;
};

int main() {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    SinhVien* dsSinhVien = new SinhVien[n];

    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
        cout << "So bao danh: ";
        cin >> dsSinhVien[i].sbd;
        cout << "Ho va ten: ";
        getline(cin >> ws, dsSinhVien[i].hoTen);
        cout << "Khoa: ";
        cin >> dsSinhVien[i].khoa;
        cout << "Ngay thang nam sinh: ";
        getline(cin >> ws, dsSinhVien[i].ngaySinh);
        cout << "GPA: ";
        cin >> dsSinhVien[i].gpa;
    }

    cout << "Danh sach sinh vien: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Sinh vien " << i + 1 << ":" << endl;
        cout << "So bao danh: " << dsSinhVien[i].sbd << endl;
        cout << "Ho va ten: " << dsSinhVien[i].hoTen << endl;
        cout << "Khoa: " << dsSinhVien[i].khoa << endl;
        cout << "Ngay thang nam sinh: " << dsSinhVien[i].ngaySinh << endl;
        cout << "GPA: " << dsSinhVien[i].gpa << endl;
    }

    delete[] dsSinhVien;

    return 0;
}
