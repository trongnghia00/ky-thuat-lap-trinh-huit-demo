#include <iostream>
#include <fstream>
#include <string>

// Hàm đọc văn bản theo từng dòng và in ra màn hình các dòng đọc được
void readFileAndPrint(const std::string& filename) {
    std::ifstream inFile(filename);  
    if (!inFile) {
        std::cerr << "Khong the mo tap tin: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {  // Đọc từng dòng từ tập tin
        std::cout << line << std::endl;   // In ra màn hình
    }

    inFile.close();  // Đóng tập tin
}

int main() {
    std::string filename = "text.txt"; // Tên tập tin cần đọc
    readFileAndPrint(filename);           // Gọi hàm để đọc và in nội dung tập tin

    return 0;
}