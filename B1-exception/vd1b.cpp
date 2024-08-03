#include <iostream>
#include <stdexcept> // Thư viện chứa std::runtime_error

void divide(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("Loi chia cho 0."); 
    }
    std::cout << "Ket qua cua phep chia la: " << a / b << std::endl;
}

int main() {
    try {
        divide(10, 0);
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cin.get();
    return 0;
}