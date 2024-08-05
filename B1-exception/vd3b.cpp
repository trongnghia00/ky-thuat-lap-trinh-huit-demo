#include <iostream>
#include <vector>
#include <stdexcept>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    try {
        int index = 10; // Index ngoài phạm vi của vector
        int value = vec.at(index); // Sẽ ném ngoại lệ std::out_of_range
        std::cout << "Gia tri tai index " << index << " la: " << value << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Loi: Vuot qua pham vi cua vector." << e.what() << std::endl;
    }

    return 0;
}