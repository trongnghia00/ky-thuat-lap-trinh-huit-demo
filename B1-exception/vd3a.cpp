#include <iostream>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    int index = 10; 
    if (index < 0 || index >= 5) {
        std::cerr << "Loi: Vuot qua pham vi cua mang." << std::endl;
    } else {
        std::cout << "Gia tri mang tai index " << index << " la: " << arr[index] << std::endl;
    }

    return 0;
}