#include <iostream>
#include <algorithm> // Thư viện cho std::sort dùng trong Binary Search
using namespace std;

// Hàm Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Trả về chỉ số của phần tử tìm thấy
        }
    }
    return -1; // Trả về -1 nếu không tìm thấy
}

// Hàm Binary Search (mảng phải được sắp xếp trước)
int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Kiểm tra nếu phần tử giữa là khóa tìm kiếm
        if (arr[mid] == key) {
            return mid;
        }
        // Nếu khóa lớn hơn, bỏ qua nửa trái
        if (arr[mid] < key) {
            left = mid + 1;
        }
        // Nếu khóa nhỏ hơn, bỏ qua nửa phải
        else {
            right = mid - 1;
        }
    }
    return -1; // Trả về -1 nếu không tìm thấy
}

int main(){
    int arr[] = {23, 12, 4, 56, 78, 1, 98, 34};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Nhap phan tu can tim: ";
    cin >> key;

    // Linear Search
    int linearResult = linearSearch(arr, n, key);
    if (linearResult != -1) {
        cout << "Linear Search: Tim thay " << key << " tai vi tri " << linearResult << endl;
    } else {
        cout << "Linear Search: Khong tim thay " << key << endl;
    }

    // Sắp xếp mảng trước khi thực hiện Binary Search
    sort(arr, arr + n);

    // Binary Search
    int binaryResult = binarySearch(arr, 0, n - 1, key);
    if (binaryResult != -1) {
        cout << "Binary Search: Tim thay " << key << " tai vi tri " << binaryResult << endl;
    } else {
        cout << "Binary Search: Khong tim thay " << key << endl;
    }

    return 0;
}
