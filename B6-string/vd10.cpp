#include <iostream>
#include <cstring>   // Thư viện chứa chuỗi kiểu C
#include <string>    // Thư viện chứa std::string
#include <cctype>    // Thư viện chứa toupper()

using namespace std;

int main() {
    // Chuỗi kiểu C (char[])
    char str1C[] = "hello, c string!";
    // Chuỗi kiểu C++ (std::string)
    string str1Cpp = "hello, c++ string!";

    // Sử dụng vòng lặp để chuyển chuỗi kiểu C sang chữ hoa
    for (int i = 0; str1C[i] != '\0'; i++) {
        str1C[i] = toupper(str1C[i]);
    }
    // Hoặc Sử dụng strupr
    strupr(str1C);
    
    // Sử dụng vòng lặp để chuyển chuỗi kiểu C++ sang chữ hoa
    for (int i = 0; i < str1Cpp.length(); i++) {
        str1Cpp[i] = toupper(str1Cpp[i]);
    }

    // Hiển thị kết quả
    cout << "Chuỗi kiểu C sau khi chuyển sang chữ hoa: " << str1C << endl;
    // Hiển thị kết quả
    cout << "Chuỗi kiểu C++ sau khi chuyển sang chữ hoa: " << str1Cpp << endl;

    return 0;
}
