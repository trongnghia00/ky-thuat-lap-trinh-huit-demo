#include <iostream>
using namespace std;

int main() {
    // Truong hop 1: C++ tu dong chuyen doi kieu du lieu
    int intVar = 10;
    double doubleVar;

    // C++ tu dong chuyen doi kieu int thanh double
    doubleVar = intVar;

    cout << "Truong hop 1: Chuyen doi tu dong" << endl;
    cout << "Gia tri cua intVar: " << intVar << endl;
    cout << "Gia tri cua doubleVar (sau khi chuyen doi tu dong): " << doubleVar << endl;

    // Truong hop 2: Nguoi lap trinh ep chuyen doi kieu du lieu
    int x = 5;
    int y = 2;
    
    // Ep kieu x thanh float truoc khi thuc hien phep chia
    float ketqua = (float)x / y;

    cout << "\nTruong hop 2: Ep chuyen doi kieu" << endl;
    cout << "Gia tri cua x: " << x << endl;
    cout << "Gia tri cua y: " << y << endl;
    cout << "Ket qua cua phep chia (sau khi ep kieu): " << ketqua << endl;

    return 0;
}
