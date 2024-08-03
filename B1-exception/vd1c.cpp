#include <iostream>
#include <string>

void divide(int a, int b) {
    if (b == 0) {
        throw std::string("Loi chia cho 0."); 
    }
    std::cout << "Ket qua cua phep chia la: " << a / b << std::endl;
}

int main() {
    try {
        divide(10, 0);
    } catch (const std::string& e) {
        std::cerr << "Error: " << e << std::endl; 
    }

    std::cin.get();
    return 0;
}
