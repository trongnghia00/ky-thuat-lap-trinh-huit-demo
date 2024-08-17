#include <iostream>
using namespace std;

// Hàm thực hiện Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Giả sử phần tử đầu tiên là nhỏ nhất
        int minIndex = i;

        // Tìm phần tử nhỏ nhất trong đoạn chưa sắp xếp
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Hoán đổi phần tử nhỏ nhất với phần tử đầu tiên của đoạn chưa sắp xếp
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main(){
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Mang truoc khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Gọi hàm Selection Sort
    selectionSort(arr, n);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
