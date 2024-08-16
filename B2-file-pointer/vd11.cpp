#include <iostream>
using namespace std;

// Khai báo cấu trúc
struct Person {
    string name;
    int age;
};

int main() {
    // Cấp phát bộ nhớ cho một đối tượng Person thông qua con trỏ
    Person* ptr = new Person;

    // Gán giá trị cho các thành viên của cấu trúc thông qua cú pháp ptr->name
    ptr->name = "Alice";
    ptr->age = 30;

    // In giá trị của các thành viên của cấu trúc thông qua cú pháp ptr->name
    cout << "Thong tin nguoi (Su dung ptr->name): " << endl;
    cout << "Ten: " << ptr->name << endl;
    cout << "Tuoi: " << ptr->age << endl;

    // Thay đổi giá trị của các thành viên của cấu trúc thông qua cú pháp (*ptr).name
    (*ptr).name = "Bob";
    (*ptr).age = 25;

    // In giá trị mới của các thành viên của cấu trúc
    cout << "Thong tin nguoi sau khi thay doi (Su dung (*ptr).name): " << endl;
    cout << "Ten: " << (*ptr).name << endl;
    cout << "Tuoi: " << (*ptr).age << endl;

    // Giải phóng bộ nhớ đã cấp phát cho đối tượng Person
    delete ptr;

    // Đặt con trỏ về giá trị null để tránh lỗi
    ptr = nullptr;

    return 0;
}
