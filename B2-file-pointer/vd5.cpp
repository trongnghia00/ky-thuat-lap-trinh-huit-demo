#include <iostream>
#include <fstream>
#include <string>

// Định nghĩa struct SinhVien với các trường MSSV và HoTen
struct SinhVien {
    std::string MSSV;
    std::string HoTen;
};

// Hàm ghi danh sách sinh viên vào file nhị phân
void writeToFile(const std::string& filename, SinhVien* students, int numStudents) {
    // Mở file ở chế độ nhị phân để ghi
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile) {
        std::cerr << "Khong the mo file de ghi.\n";
        return;
    }

    // Ghi số lượng sinh viên vào file
    outFile.write(reinterpret_cast<const char*>(&numStudents), sizeof(numStudents));

    // Ghi từng sinh viên vào file
    for (int i = 0; i < numStudents; ++i) {
        int mssvLength = students[i].MSSV.size();  // Độ dài của MSSV
        int hoTenLength = students[i].HoTen.size();  // Độ dài của HoTen
        // Ghi độ dài và nội dung của MSSV
        outFile.write(reinterpret_cast<const char*>(&mssvLength), sizeof(mssvLength));
        outFile.write(students[i].MSSV.data(), mssvLength);
        // Ghi độ dài và nội dung của HoTen
        outFile.write(reinterpret_cast<const char*>(&hoTenLength), sizeof(hoTenLength));
        outFile.write(students[i].HoTen.data(), hoTenLength);
    }

    outFile.close();  // Đóng file sau khi ghi xong
}

// Hàm đọc danh sách sinh viên từ file nhị phân
void readFromFile(const std::string& filename) {
    // Mở file ở chế độ nhị phân để đọc
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) {
        std::cerr << "Khong the mo file de doc.\n";
        return;
    }

    int numStudents;
    // Đọc số lượng sinh viên từ file
    inFile.read(reinterpret_cast<char*>(&numStudents), sizeof(numStudents));
    std::cout << "So luong sinh vien: " << numStudents << std::endl;

    // Tạo mảng động để lưu danh sách sinh viên
    SinhVien* students = new SinhVien[numStudents];
    for (int i = 0; i < numStudents; ++i) {
        int mssvLength, hoTenLength;
        // Đọc độ dài và nội dung của MSSV
        inFile.read(reinterpret_cast<char*>(&mssvLength), sizeof(mssvLength));
        students[i].MSSV.resize(mssvLength);
        inFile.read(&students[i].MSSV[0], mssvLength);

        // Đọc độ dài và nội dung của HoTen
        inFile.read(reinterpret_cast<char*>(&hoTenLength), sizeof(hoTenLength));
        students[i].HoTen.resize(hoTenLength);
        inFile.read(&students[i].HoTen[0], hoTenLength);
    }

    // Hiển thị thông tin sinh viên ra màn hình
    for (int i = 0; i < numStudents; ++i) {
        std::cout << "Sinh vien " << i + 1 << ": MSSV = " << students[i].MSSV 
                  << ", HoTen = " << students[i].HoTen << std::endl;
    }

    // Giải phóng bộ nhớ cho mảng động
    delete[] students;
    inFile.close();  // Đóng file sau khi đọc xong
}

// Hàm chính
int main() {
    // Tạo danh sách sinh viên
    SinhVien students[] = {{"123", "Nguyen Van A"}, {"456", "Tran Thi B"}};
    int numStudents = 2;

    // Ghi danh sách sinh viên vào file
    writeToFile("sinhvien.dat", students, numStudents);
    
    // Đọc và hiển thị danh sách sinh viên từ file
    readFromFile("sinhvien.dat");

    return 0;
}
