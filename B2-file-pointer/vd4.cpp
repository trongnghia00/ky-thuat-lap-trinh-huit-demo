#include <iostream>
#include <fstream>
#include <string>

// Hàm ghi mảng các số nguyên vào tập tin văn bản
void writeIntegersToFile(const std::string& filename, int numbers[], int numElements) {
    std::ofstream outFile(filename);  // Mở tập tin để ghi
    if (!outFile) {
        std::cerr << "Khong the mo tap tin: " << filename << std::endl;
        return;
    }

    outFile << numElements << std::endl;  // Ghi số phần tử của mảng trên dòng đầu tiên
    for (int i = 0; i < numElements; ++i) {
        outFile << numbers[i];  // Ghi từng phần tử của mảng trên dòng thứ hai
        if (i < numElements - 1) {
            outFile << " ";  // Thêm dấu cách giữa các số
        }
    }
    outFile << std::endl;  // Kết thúc dòng thứ hai

    outFile.close();  // Đóng tập tin
}

int main() {
    // Khởi tạo mảng các số nguyên
    int numbers[] = {5, 10, 15, 20, 25};
    int numElements = 5;  // Số lượng phần tử trong mảng

    std::string filename = "output_numbers.txt";  // Tên tập tin cần ghi
    writeIntegersToFile(filename, numbers, numElements);  // Gọi hàm để ghi mảng số nguyên vào tập tin

    std::cout << "Da ghi mang so nguyen vao tap tin: " << filename << std::endl;

    return 0;
}
