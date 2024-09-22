#include <iostream>
#include <cstring>  // Thư viện chứa hàm strlen
#include <string>   // Thư viện chứa std::string

using namespace std;

int main() {
    // Chuỗi kiểu C (char[])
    char cString[] = "Hello, C String!";
    size_t cStringLength = strlen(cString);
    cout << "Độ dài của chuỗi kiểu C là: " << cStringLength << endl;

    // Chuỗi kiểu C++ (std::string)
    string cppString = "Hello, C++ String!";
    size_t cppStringLength = cppString.length();
    cout << "Độ dài của chuỗi kiểu C++ là: " << cppStringLength << endl;

    return 0;
}
