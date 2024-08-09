#include <iostream>
#include <fstream>
#include <string>

const int MAX_SIZE = 100; 

// Hàm đọc ma trận từ tập tin và lưu vào mảng 2 chiều
void readMatrixFromFile(const std::string& filename, int matrix[MAX_SIZE][MAX_SIZE], int& size) {
    std::ifstream inFile(filename);  // Mở tập tin để đọc
    if (!inFile) {
        std::cerr << "Khong the mo tap tin: " << filename << std::endl;
        return;
    }

    inFile >> size;  // Đọc kích thước của ma trận

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            inFile >> matrix[i][j];  // Đọc từng phần tử của ma trận
        }
    }

    inFile.close();  // Đóng tập tin
}

// Hàm in ma trận ra màn hình
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];  // Mảng 2 chiều để lưu ma trận
    int size = 0;  // Kích thước của ma trận

    std::string filename = "matrix.txt";  // Tên tập tin cần đọc
    readMatrixFromFile(filename, matrix, size);  // Đọc ma trận từ tập tin

    std::cout << "Ma tran da doc:" << std::endl;
    printMatrix(matrix, size);  // In ma trận ra màn hình

    return 0;
}
