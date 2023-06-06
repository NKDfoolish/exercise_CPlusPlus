#include <iostream>
#include <string>
using namespace std;

struct SinhVien {
    int maSV;
    string hoTen;
    float diemTB;
    SinhVien* next;
};

SinhVien* taoNodeSV(int maSV, string hoTen, float diemTB) {
    SinhVien* sv = new SinhVien;
    sv->maSV = maSV;
    sv->hoTen = hoTen;
    sv->diemTB = diemTB;
    sv->next = NULL;
    return sv;
}

void themSV(SinhVien*& dsSV, SinhVien* sv) {
    if (dsSV == NULL) {
        dsSV = sv;
    }
    else {
        SinhVien* tmp = dsSV;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = sv;
    }
}

void taoDSSV(SinhVien*& dsSV, int n) {
    for (int i = 0; i < n; i++) {
        int maSV;
        string hoTen;
        float diemTB;
        cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
        cout << "Ma sinh vien: ";
        cin >> maSV;
        cout << "Ho ten: ";
        cin.ignore();
        getline(cin, hoTen);
        cout << "Diem trung binh: ";
        cin >> diemTB;
        SinhVien* sv = taoNodeSV(maSV, hoTen, diemTB);
        themSV(dsSV, sv);
    }
}

void xuatSV(SinhVien* sv) {
    cout << "Ma sinh vien: " << sv->maSV << endl;
    cout << "Ho ten: " << sv->hoTen << endl;
    cout << "Diem trung binh: " << sv->diemTB << endl;
}

void xuatDSSV(SinhVien* dsSV) {
    SinhVien* tmp = dsSV;
    while (tmp != NULL) {
        xuatSV(tmp);
        tmp = tmp->next;
    }
}

void xuatDSSV_DTB(SinhVien* dsSV) {
    SinhVien* tmp = dsSV;
    while (tmp != NULL) {
        if (tmp->diemTB >= 5) {
            xuatSV(tmp);
        }
        tmp = tmp->next;
    }
}

void xuatDSSV_DTB_LT5(SinhVien* dsSV) {
    int count = 0;
    SinhVien* tmp = dsSV;
    while (tmp != NULL) {
        if (tmp->diemTB < 5) {
            count++;
        }
        tmp = tmp->next;
    }
    cout << "So sinh vien co diem TB < 5: " << count << endl;
    if (count > 0) {
        cout << "Danh sach sinh vien co diem TB < 5: " << endl;
        tmp = dsSV;
        while (tmp != NULL) {
            if (tmp->diemTB < 5) {
                xuatSV(tmp);
            }
            tmp = tmp->next;
        }
    }
}

void sapXepDSSV(SinhVien*& dsSV) {
    if (dsSV == NULL || dsSV->next == NULL) {
        return;
    }
    SinhVien* tmp = dsSV;
    while (tmp != NULL) {
        SinhVien* min = tmp;
        SinhVien* j = tmp->next;
        while (j != NULL) {
            if (j->diemTB < min->diemTB) {
                min = j;
            }
            j = j->next;
        }
        if (min != tmp) {
            int maSV = tmp->maSV;
            string hoTen = tmp->hoTen;
            float diemTB = tmp->diemTB;
            tmp->maSV = min->maSV;
            tmp->hoTen = min->hoTen;
            tmp->diemTB = min->diemTB;
            min->maSV = maSV;
            min->hoTen = hoTen;
            min->diemTB = diemTB;
        }
        tmp = tmp->next;
    }
}

void xoaDSSV(SinhVien*& dsSV) {
    if (dsSV == NULL) {
        cout << "Danh sach sinh vien rong!" << endl;
        return;
    }
    cout << "Ban co chac chan muon xoa toan bo danh sach sinh vien? (y/n) ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        SinhVien* tmp;
        while (dsSV != NULL) {
            tmp = dsSV;
            dsSV = dsSV->next;
            delete tmp;
        }
        cout << "Da xoa toan bo danh sach sinh vien!" << endl;
    }
}

int main() {
    SinhVien* dsSV = NULL;
    int choice, n;
    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Tao danh sach sinh vien" << endl;
        cout << "2. Xuat danh sach sinh vien" << endl;
        cout << "3. Xuat danh sach sinh vien co diem TB >= 5" << endl;
        cout << "4. Dem so sinh vien co diem TB < 5 va xuat danh sach" << endl;
        cout << "5. Sap xep danh sach sinh vien tang dan theo diem TB" << endl;
        cout << "6. Xoa toan bo danh sach sinh vien" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Nhap so sinh vien: ";
            cin >> n;
            taoDSSV(dsSV, n);
            break;
        case 2:
            xuatDSSV(dsSV);
            break;
        case 3:
            xuatDSSV_DTB(dsSV);
            break;
        case 4:
            xuatDSSV_DTB_LT5(dsSV);
            break;
        case 5:
            sapXepDSSV(dsSV);
            cout << "Danh sach sinh vien sau khi sap xep:" << endl;
            xuatDSSV(dsSV);
            break;
        case 6:
            xoaDSSV(dsSV);
            break;
        case 0:
            cout << "Cam on ban da su dung chuong trinh!" << endl;
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}
