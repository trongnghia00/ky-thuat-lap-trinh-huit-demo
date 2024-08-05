#include <iostream>

int main() {
    int number;
    while (true) {
        std::cout << "Nhap so nguyen: ";
        std::cin >> number;

        if (std::cin.fail()) { // Kiểm tra nếu nhập sai kiểu dữ liệu
            std::cin.clear(); // Xóa cờ lỗi
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Bỏ qua dữ liệu không hợp lệ trong bộ đệm
            std::cerr << "Du lieu khong hop le. Hay nhap mot so nguyen.\n";
        } else {
            break; // Thoát khỏi vòng lặp khi nhập đúng số nguyên
        }
    }

    std::cout << "So da nhap: " << number << std::endl;
    return 0;
}