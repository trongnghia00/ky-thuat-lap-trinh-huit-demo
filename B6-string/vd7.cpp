#include <iostream>
#include <cstring>  // Thư viện chứa hàm strcmp
#include <string>   // Thư viện chứa std::string

using namespace std;

int main() {
    // Chuỗi kiểu C (char[])
    char str1C[] = "Hello, World!";
    char str2C[] = "Hello, World!";
    char str3C[] = "Goodbye, World!";

    // So sánh chuỗi kiểu C
    if (strcmp(str1C, str2C) == 0) {
        cout << "Chuỗi str1C và str2C giống nhau." << endl;
    } else {
        cout << "Chuỗi str1C và str2C khác nhau." << endl;
    }

    if (strcmp(str1C, str3C) == 0) {
        cout << "Chuỗi str1C và str3C giống nhau." << endl;
    } else {
        cout << "Chuỗi str1C và str3C khác nhau." << endl;
    }

    // Chuỗi kiểu C++ (std::string)
    string str1Cpp = "Hello, World!";
    string str2Cpp = "Hello, World!";
    string str3Cpp = "Goodbye, World!";

    // So sánh chuỗi kiểu C++
    if (str1Cpp == str2Cpp) {
        cout << "Chuỗi str1Cpp và str2Cpp giống nhau." << endl;
    } else {
        cout << "Chuỗi str1Cpp và str2Cpp khác nhau." << endl;
    }

    if (str1Cpp == str3Cpp) {
        cout << "Chuỗi str1Cpp và str3Cpp giống nhau." << endl;
    } else {
        cout << "Chuỗi str1Cpp và str3Cpp khác nhau." << endl;
    }

    return 0;
}
