#include <iostream>
#include <cstring>   // Thư viện chứa các hàm thao tác với chuỗi kiểu C
#include <string>    // Thư viện chứa std::string

using namespace std;

int main() {
    // Chuỗi kiểu C (char[])
    char s1C[] = "This is a simple C string example.";
    char s2C[] = "simple";
    // Chuỗi kiểu C++ (std::string)
    string s1Cpp = "This is a simple C++ string example.";
    string s2Cpp = "simple";

    // char[]
    char* posC = strstr(s1C, s2C);
    if (posC != nullptr) {
        // Tính toán chỉ số dựa trên con trỏ
        int indexC = posC - s1C;
        cout << "Vị trí xuất hiện đầu tiên của '" << s2C << "' trong chuỗi kiểu C là: " << indexC << endl;
    } else {
        cout << "'" << s2C << "' không tìm thấy trong chuỗi kiểu C." << endl;
    }

    // std::string
    size_t indexCpp = s1Cpp.find(s2Cpp);
    if (indexCpp != string::npos) {
        cout << "Vị trí xuất hiện đầu tiên của '" << s2Cpp << "' trong chuỗi kiểu C++ là: " << indexCpp << endl;
    } else {
        cout << "'" << s2Cpp << "' không tìm thấy trong chuỗi kiểu C++." << endl;
    }

    return 0;
}
