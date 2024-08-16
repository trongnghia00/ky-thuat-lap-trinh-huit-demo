#include <iostream>
using namespace std;

int main() {
    int size = 5;
    // Cấp phát bộ nhớ cho mảng kiểu int với kích thước size
    int* arr = new int[size];
    // Gán giá trị cho các phần tử trong mảng thông qua con trỏ
    for (int i = 0; i < size; ++i) {
        arr[i] = i * 10; 
    }

    // In giá trị của các phần tử trong mảng thông qua con trỏ
    cout << "Gia tri cac phan tu trong mang: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";  
    }
    cout << endl;

    // Thay đổi giá trị của các phần tử trong mảng thông qua con trỏ
    for (int i = 0; i < size; ++i) {
        *(arr + i) = (i + 1) * 20; 
    }

    // In giá trị mới của các phần tử trong mảng
    cout << "Gia tri moi cua cac phan tu trong mang: ";
    for (int i = 0; i < size; ++i) {
        cout << *(arr + i) << " ";  // In giá trị mới của phần tử thứ i
    }
    cout << endl;

    // Giải phóng bộ nhớ được cấp phát cho mảng
    delete[] arr;

    // Đặt con trỏ về giá trị null để tránh lỗi
    arr = nullptr;

    return 0;
}
