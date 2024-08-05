#include <iostream>
#include <string>
#include <stdexcept> 

int main() {
    std::string input;
    std::cout << "Nhap mot so nguyen: ";
    std::cin >> input;

    try {
        int number = std::stoi(input); // Chuyển đổi chuỗi thành số nguyên
        std::cout << "Gia tri so nguyen: " << number << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Loi: Gia tri khong hop le." << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Loi: Gia tri nam ngoai pham vi so nguyen." << std::endl;
    }

    return 0;
}