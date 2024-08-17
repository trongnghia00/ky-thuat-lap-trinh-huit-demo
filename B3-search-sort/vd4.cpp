#include <iostream>
using namespace std;

// Hàm thực hiện Quick Sortvoid 
void quickSort(int a[], int Left, int Right) 
{
   if (Left >= Right) return;
    int i = Left, j = Right, Mid = (Left+Right)/2;
    int x = a[Mid]; 
    do {
        while(a[i] < x) i++; // lặp cho đến khi a[i] >= x
        while(a[j] > x) j--; // lặp cho đến khi a[j] <= x
        if(i <= j) {
            if(i < j)
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while(i < j);
    quickSort(a, Left, j); 
    quickSort(a, i, Right);
}


// Hàm xuất mảng
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Mang truoc khi sap xep: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Mang sau khi sap xep: ";
    printArray(arr, n);

    return 0;
}
