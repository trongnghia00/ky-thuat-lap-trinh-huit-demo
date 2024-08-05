#include <iostream>

int main() {
    int soNguyen;

    std::cout << "Nhap mot so nguyen: ";
    std::cin >> soNguyen;

    if (std::cin.fail()) {
        std::cerr << "Error: Ban da nhap khong dung so nguyen." << std::endl;
        // Xóa trạng thái lỗi và bỏ qua phần nhập không hợp lệ
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else {
        std::cout << "Số nguyên bạn đã nhập là: " << soNguyen << std::endl;
    }

    return 0;
}