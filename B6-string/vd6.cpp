#include <iostream>
#include <cstring>  // Thư viện chứa hàm strcpy
#include <string>   // Thư viện chứa std::string

using namespace std;

int main() {
    // Sao chép chuỗi kiểu char[]
    char sourceC[] = "Hello, C String!";
    char destinationC[50];
    strcpy(destinationC, sourceC);

    // Hiển thị kết quả
    cout << "Chuỗi nguồn kiểu C: " << sourceC << endl;
    cout << "Chuỗi đích kiểu C sau khi sao chép: " << destinationC << endl;

    // Sao chép chuỗi kiểu std::string
    string sourceCpp = "Hello, C++ String!";
    string destinationCpp;
    destinationCpp = sourceCpp;

    // Hiển thị kết quả
    cout << "Chuỗi nguồn kiểu C++: " << sourceCpp << endl;
    cout << "Chuỗi đích kiểu C++ sau khi sao chép: " << destinationCpp << endl;

    return 0;
}
