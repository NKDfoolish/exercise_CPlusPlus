#include <iostream>
#include <string>
using namespace std;

struct SinhVien {
    string StudentID;
    string Name;
    float GPA;
};

// Hàm nhập thông tin cho một sinh viên
void NhapSinhVien(SinhVien& sv) {
    cout << "Nhap ma sinh vien: ";
    getline(cin, sv.StudentID);
    cout << "Nhap ten sinh vien: ";
    getline(cin, sv.Name);
    cout << "Nhap diem trung binh: ";
    cin >> sv.GPA;
    cin.ignore();
}

// Hàm nhập thông tin cho một danh sách sinh viên gồm n sinh viên
void NhapDanhSachSinhVien(SinhVien*& dsSV, int& n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin cho sinh vien thu " << i + 1 << endl;
        NhapSinhVien(dsSV[i]);
    }
}

// Hàm xuất thông tin cho toàn bộ danh sách sinh viên
void XuatDanhSachSinhVien(SinhVien* dsSV, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Thong tin sinh vien thu " << i + 1 << endl;
        cout << "Ma sinh vien: " << dsSV[i].StudentID << endl;
        cout << "Ten sinh vien: " << dsSV[i].Name << endl;
        cout << "Diem trung binh: " << dsSV[i].GPA << endl;
    }
}

// Hàm đếm số lượng sinh viên có điểm trung bình lớn hơn 8
int DemSVDiemTBLonHon8(SinhVien* dsSV, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (dsSV[i].GPA > 8) {
            count++;
        }
    }
    return count;
}

// Hàm sắp xếp danh sách sinh viên theo thứ tự giảm dần của mã sinh viên
void SapXepDanhSachSinhVien(SinhVien* dsSV, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dsSV[i].StudentID < dsSV[j].StudentID) {
                swap(dsSV[i], dsSV[j]);
            }
        }
    }
}

int main() {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    cin.ignore();

    SinhVien* dsSV = new SinhVien[n];

    // Nhập danh sách sinh viên
    NhapDanhSachSinhVien(dsSV, n);

    // Xuất danh sách sinh viên
    cout << "\nDanh sach sinh vien:\n";
    XuatDanhSachSinhVien(dsSV, n);

    // Đếm số lượng sinh viên có điểm trung bình lớn hơn 8
    int dem = DemSVDiemTBLonHon8(dsSV, n);
    cout << "\nSo luong sinh vien co diem trung binh lon hon 8: " << dem << endl;

    // Sắp xếp danh sách sinh viên theo thứ tự giảm dần của mã sinh viên
    SapXepDanhSachSinhVien(dsSV, n);
    cout << "\nDanh sach sinh vien sau khi sap xep theo MSSV:\n";
    XuatDanhSachSinhVien(dsSV, n);

    // Giải phóng bộ nhớ đã cấp phát cho mảng động
    delete[] dsSV;

    return 0;
}
