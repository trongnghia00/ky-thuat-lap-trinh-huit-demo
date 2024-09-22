#include <iostream>
#include <cstdio>

int main() {
    char inputString[100]; // Giả sử mảng có thể chứa tối đa 99 ký tự + 1 ký tự null

    // Nhập chuỗi có khoảng trắng
    std::cout << "Nhập chuỗi: ";
    std::cin.getline(inputString, 100);  // Nhập cả chuỗi có khoảng trắng

    // Xuất chuỗi
    std::cout << "Bạn đã nhập: " << inputString << std::endl;

    return 0;
}
