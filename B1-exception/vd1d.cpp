#include <iostream>
#include <stdexcept>

// Định nghĩa một struct chứa mã lỗi và thông báo lỗi
struct ErrorInfo {
    int code;
    std::string message;
};

void divide(int a, int b) {
    if (b == 0) {
        throw ErrorInfo{1, "Loi chia cho 0."}; 
    }
    std::cout << "Ket qua cua phep chia la: " << a / b << std::endl;
}

int main() {
    try {
        divide(10, 0);
    } catch (const ErrorInfo& e) {
        std::cerr << "Error - code: " << e.code << ", Msg: " << e.message << std::endl;
    }

    std::cin.get();
    return 0;
}
