#include <iostream>
#include <string>

int main() {
    std::string inputString;

    // Nhập chuỗi có khoảng trắng
    std::cout << "Nhập chuỗi: ";
    std::getline(std::cin, inputString);  // Nhập cả chuỗi có khoảng trắng

    // Xuất chuỗi
    std::cout << "Bạn đã nhập: " << inputString << std::endl;

    return 0;
}
