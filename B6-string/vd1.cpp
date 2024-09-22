#include <iostream>

int main() {
    char str1[] = "Hello";
    char* str2 = "World";

    std::cout << str1 << " " << str2 << std::endl;

    // Thay đổi một ký tự trong str1
    str1[0] = 'h';
    std::cout << str1 << std::endl;

    return 0;
}