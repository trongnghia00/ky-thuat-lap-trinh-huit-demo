#include <iostream>
#include <cstring>  // Thư viện chứa char[] và các hàm kiểu C
#include <string>   // Thư viện chứa std::string
#include <cctype>   // Thư viện chứa hàm tolower()

using namespace std;

int main() {
    // Chuỗi kiểu C (char[])
    char str1C[] = "HELLO, C STRING!";

    // Chuỗi kiểu C++ (std::string)
    string str1Cpp = "HELLO, C++ STRING!";
    
    // Chuyển chuỗi kiểu char[] sang chữ thường
    for (int i = 0; str1C[i] != '\0'; i++) {
        str1C[i] = tolower(str1C[i]);
    }
    // Hoặc sử dụng strlwr
    // Chú ý rằng strlwr chỉ chạy trên HĐH Windows
    strlwr(str1C);

    // Chuyển chuỗi kiểu std::string sang chữ thường
    for (int i = 0; i < str1Cpp.length(); i++) {
        str1Cpp[i] = tolower(str1Cpp[i]);
    }
    // Hiển thị kết quả
    cout << "Chuỗi kiểu C sau khi chuyển sang chữ thường: " << str1C << endl;
    // Hiển thị kết quả
    cout << "Chuỗi kiểu C++ sau khi chuyển sang chữ thường: " << str1Cpp << endl;

    return 0;
}
