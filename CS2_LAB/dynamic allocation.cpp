#include <iostream>
using namespace std;

int main() {
    int n = 0; // khởi tạo kích thước ban đầu của mảng là 0
    int* arr = nullptr; // khởi tạo mảng động với kích thước 0

    // Thêm phần tử vào mảng
    int value;
    char choice;
    do {
        cout << "Nhap gia tri can them: ";
        cin >> value;

        // Cấp phát thêm bộ nhớ động cho mảng và thêm phần tử vào cuối mảng
        int* temp = new int[n + 1];
        for (int i = 0; i < n; i++) {
            temp[i] = arr[i];
        }
        temp[n] = value;

        // Giải phóng bộ nhớ cũ của mảng và gán mảng mới vào mảng cũ
        delete[] arr;
        arr = temp;

        n++; // Tăng kích thước mảng
        cout << "Ban co muon nhap them phan tu? (Y/N) ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    // Hiển thị các phần tử trong mảng
    cout << "Cac phan tu trong mang la: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    // Giải phóng bộ nhớ động của mảng khi không cần thiết nữa
    delete[] arr;


	return 0;
}