#include <iostream>
using namespace std;

// Hàm kiểm tra mảng có tăng dần hay không
bool mangTangDan(int* arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;

    // Nhập số lượng phần tử của mảng
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;

    // Cấp phát động mảng
    int* arr = new int[n];

    // Nhập các giá trị của mảng
    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << endl;
    cout << "Cac phan tu cua mang da nhap: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Kiểm tra và xuất kết quả
    if (mangTangDan(arr, n)) {
        cout << "Mang tang dan." << endl;
    } else {
        cout << "Mang khong tang dan." << endl;
    }

    // Giải phóng bộ nhớ
    delete[] arr;

    return 0;
}
