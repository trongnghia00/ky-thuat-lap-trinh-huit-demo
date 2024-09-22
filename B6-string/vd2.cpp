#include <iostream>
#include <string>

int main() {
    std::string str1 = "Hello";       // Khai báo và khởi tạo trực tiếp
    std::string str2("World");        // Khởi tạo với constructor
    std::string str3;                 // Khai báo trước, khởi tạo sau
    str3 = "C++ String";              // Gán giá trị

    std::cout << str1 << " " << str2 << " " << str3 << std::endl;

    // Thay đổi một ký tự trong chuỗi
    str1[0] = 'h';
    std::cout << str1 << std::endl;

    return 0;
}
