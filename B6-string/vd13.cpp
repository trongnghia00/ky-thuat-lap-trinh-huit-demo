#include <iostream>
#include <string>

using namespace std;

int main() {
    string str = "   Hello    World   from   C++  ";
    string w[4]; int count = 0; int len = str.length(); int i = 0;
    while (i < len && str[i] == ' ') i++;
    while (i < len) {
        string s1 = "";
        while (i < len && str[i] != ' ') {
            s1 += str[i];
            i++;
        }
        if (!s1.empty()) w[count++] = s1;
        while (i < len && str[i] == ' ') i++;
    }
    for (int j = 0; j < count; j++) cout << w[j];

    return 0;
}
