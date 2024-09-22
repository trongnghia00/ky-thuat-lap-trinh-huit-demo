#include <iostream>
#include <string>

using namespace std;

int main() {
    // Gán giá trị cho chuỗi và chuỗi con cần xóa
    string s = "Hello, this is a sample text.";
    string s1 = "is";
    string result = "";
    for (int i = 0; i < s.length(); i++) {
        bool match = true;
        for (int j = 0; j < s1.length(); j++) {
            if (i + j >= s.length() || s[i + j] != s1[j]) {
                match = false;
                break;
            }
        }
        if (match) { i += s1.length() - 1; }
        else {result += s[i]; }
    }
    cout << "\"" << result << "\"" << endl;

    return 0;
}
