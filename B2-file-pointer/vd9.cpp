#include <iostream>
using namespace std;

int main() {
    // Cấp phát bộ nhớ cho một biến kiểu int
    int* ptr = new int;

    // Gán giá trị cho biến thông qua con trỏ
    *ptr = 30;

    // In giá trị của biến thông qua con trỏ
    cout << "Gia tri cua bien thong qua con tro ptr: " << *ptr << endl;

    // Giải phóng bộ nhớ được cấp phát cho con trỏ
    delete ptr;

    // Đặt con trỏ về giá trị null để tránh lỗi
    ptr = nullptr;

    // In ra thông báo cho biết bộ nhớ đã được giải phóng
    cout << "Bo nho da duoc giai phong." << endl;

    // Cấp phát bộ nhớ cho một mảng các biến kiểu int
    int* arr = new int[5];

    // Gán giá trị cho các phần tử trong mảng thông qua con trỏ
    for (int i = 0; i < 5; ++i) {
        arr[i] = i * 10;
    }

    // In giá trị của các phần tử trong mảng
    cout << "Gia tri cac phan tu trong mang: ";
    for (int i = 0; i < 5; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Giải phóng bộ nhớ được cấp phát cho mảng
    delete[] arr;

    // Đặt con trỏ về giá trị null để tránh lỗi
    arr = nullptr;

    // In ra thông báo cho biết bộ nhớ của mảng đã được giải phóng
    cout << "Bo nho mang da duoc giai phong." << endl;

    return 0;
}
