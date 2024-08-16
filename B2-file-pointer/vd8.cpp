#include <iostream>
using namespace std;

int main() {
    // Khai báo một biến kiểu int
    int x = 10;
    
    // Khai báo một con trỏ kiểu int và gán địa chỉ của biến x cho con trỏ
    int* ptr = &x;

    // Sử dụng toán tử & để lấy địa chỉ của biến x
    cout << "Dia chi cua bien x: " << &x << endl;

    // Sử dụng toán tử * để truy cap gia tri tai dia chi ma ptr tro den
    cout << "Gia tri cua bien x thong qua con tro ptr: " << *ptr << endl;

    // Thay doi gia tri cua bien x thong qua con tro ptr
    *ptr = 20;

    // Xuat gia tri cua bien x sau khi thay doi
    cout << "Gia tri moi cua bien x: " << x << endl;

    return 0;
}