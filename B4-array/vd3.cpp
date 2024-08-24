#include <iostream>
#include <string>
using namespace std;

struct SinhVien {
    int id;
    string name;
};

int main() {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    // Khai báo mảng động chứa n phần tử kiểu SinhVien
    SinhVien* sv = new SinhVien[n];

    // Nhập dữ liệu cho mảng sinh viên
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << ":\n";
        cout << "ID: ";
        cin >> sv[i].id;
        cout << "Ten: ";
        cin.ignore(); // Bỏ qua ký tự newline sau khi nhập ID
        getline(cin, sv[i].name);
    }

    // Xuất dữ liệu của mảng sinh viên
    cout << "\nDanh sach sinh vien:\n";
    for (int i = 0; i < n; i++) {
        cout << "ID = " << sv[i].id << ", Ten = " << sv[i].name << endl;
    }

    // Giải phóng bộ nhớ sau khi sử dụng
    delete[] sv;

    return 0;
}
