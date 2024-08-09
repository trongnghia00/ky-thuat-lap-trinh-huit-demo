#include <iostream>
#include <fstream>
#include <string>

// Hàm ghi mảng các chuỗi vào tập tin văn bản
void writeStringsToFile(const std::string& filename, const std::string* strings, int numStrings) {
    std::ofstream outFile(filename);  // Mở tập tin để ghi
    if (!outFile) {
        std::cerr << "Khong the mo tap tin: " << filename << std::endl;
        return;
    }

    for (int i = 0; i < numStrings; ++i) {
        outFile << strings[i] << std::endl;  // Ghi từng chuỗi vào tập tin, mỗi chuỗi trên một dòng
    }

    outFile.close();  // Đóng tập tin
}

int main() {
    // Khởi tạo mảng các chuỗi
    std::string strings[] = {"Hello, World!", "C++ Programming", "File I/O in C++", "Goodbye, World!"};
    int numStrings = sizeof(strings) / sizeof(strings[0]);  // Số lượng chuỗi trong mảng

    std::string filename = "output.txt";  // Tên tập tin cần ghi
    writeStringsToFile(filename, strings, numStrings);  // Gọi hàm để ghi mảng chuỗi vào tập tin

    std::cout << "Da ghi cac chuoi vao tap tin: " << filename << std::endl;

    return 0;
}
