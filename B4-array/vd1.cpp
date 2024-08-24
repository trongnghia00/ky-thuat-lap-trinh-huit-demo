#include <iostream>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool laSoNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm đếm số phần tử nguyên tố trong mảng
int demSoNguyenTo(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (laSoNguyenTo(arr[i])) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    
    // Nhập số lượng phần tử của mảng
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;

    // Cấp phát động mảng
    int* arr = new int[n];

    // Nhập các giá trị của mảng
    cout << "Nhap cac phan tu cua mang: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << endl;
    cout << "Cac phan tu cua mang da nhap: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Đếm số phần tử là số nguyên tố
    int soNguyenTo = demSoNguyenTo(arr, n);

    // Xuất kết quả
    cout << "So phan tu la so nguyen to trong mang: " << soNguyenTo << endl;

    // Giải phóng bộ nhớ
    delete[] arr;

    return 0;
}
