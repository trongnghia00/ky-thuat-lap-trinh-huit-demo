#include <iostream>
using namespace std;

// Hàm thực hiện Interchange Sort
void interchangeSort(int arr[], int n) {
    // Duyệt qua từng phần tử của mảng
    for (int i = 0; i < n - 1; i++) {
        // Duyệt qua các phần tử còn lại sau i
        for (int j = i + 1; j < n; j++) {
            // Nếu phần tử arr[i] lớn hơn arr[j], hoán đổi chúng
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Mang truoc khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Gọi hàm Interchange Sort
    interchangeSort(arr, n);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
