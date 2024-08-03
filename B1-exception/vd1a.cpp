#include <iostream>

void divide(int a, int b) {
    if (b == 0) {
        throw -1; 
    }
    std::cout << "Ket qua cua phep chia la: " << a / b << std::endl;
}

int main() {
    try {
        divide(10, 2);
    } catch (int e) {
        if (e == -1) {
            std::cerr << "Error: Loi chia cho 0." << std::endl;
        } else {
            std::cerr << "Error: Loi khong xac dinh." << std::endl;
        }
    }

    std::cin.get();
    return 0;
}