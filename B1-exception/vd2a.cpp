#include <iostream>
#include <stdexcept>

int main() {
    int soNguyen;

    std::cout << "Nhap mot so nguyen: ";

    try {
        std::cin.exceptions(std::ios::failbit); // Kích hoạt ngoại lệ cho luồng cin khi gặp lỗi
        std::cin >> soNguyen;
        std::cout << "So nguyen da nhap: " << soNguyen << std::endl;
    } catch (const std::ios_base::failure& e) {
        std::cerr << "Loi: Ban can nhap so nguyen." << std::endl;
    }

    return 0;
}