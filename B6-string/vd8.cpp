#include <iostream>
#include <cstring>  // Thư viện chứa hàm strcat
#include <string>   // Thư viện chứa std::string

using namespace std;

int main() {
    // Chuỗi kiểu C (char[])
    char str1C[50] = "Hello, ";  // Cần đảm bảo đủ bộ nhớ để chứa chuỗi nối
    char str2C[] = "World!";

    // Nối chuỗi kiểu C
    strcat(str1C, str2C);  // Nối str2C vào str1C
    cout << "Chuỗi kiểu C sau khi nối: " << str1C << endl;

    // Chuỗi kiểu C++ (std::string)
    string str1Cpp = "Hello, ";
    string str2Cpp = "World!";

    // Nối chuỗi kiểu C++
    string resultCpp = str1Cpp + str2Cpp;  // Sử dụng toán tử + để nối

    // Hiển thị kết quả
    cout << "Chuỗi kiểu C++ sau khi nối: " << resultCpp << endl;

    return 0;
}
