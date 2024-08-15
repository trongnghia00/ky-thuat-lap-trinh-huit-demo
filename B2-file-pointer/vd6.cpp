#include <iostream>
#include <fstream>
#include <string>

// Định nghĩa struct SinhVien
struct SinhVien {
    std::string MSSV;
    std::string HoTen;
};

void writeStudentsToBinaryFile(const std::string& filename, SinhVien* students, int numStudents) {
    std::ofstream outFile(filename, std::ios::binary);

    // Ghi số lượng sinh viên
    outFile.write((char*)&numStudents, sizeof(numStudents));

    // Ghi dữ liệu của từng sinh viên
    for (int i = 0; i < numStudents; ++i) {
        // Ghi MSSV
        int mssvLength = students[i].MSSV.size();
        outFile.write((char*)&mssvLength, sizeof(mssvLength));
        outFile.write(students[i].MSSV.c_str(), mssvLength);

        // Ghi HoTen
        int hotenLength = students[i].HoTen.size();
        outFile.write((char*)&hotenLength, sizeof(hotenLength));
        outFile.write(students[i].HoTen.c_str(), hotenLength);
    }

    outFile.close();
}

void readStudentsFromBinaryFile(const std::string& filename, SinhVien*& students, int& numStudents) {
    std::ifstream inFile(filename, std::ios::binary);

    // Đọc số lượng sinh viên
    inFile.read((char*)&numStudents, sizeof(numStudents));

    // Cấp phát bộ nhớ cho danh sách sinh viên
    students = new SinhVien[numStudents];

    // Đọc dữ liệu của từng sinh viên
    for (int i = 0; i < numStudents; ++i) {
        // Đọc MSSV
        int mssvLength;
        inFile.read((char*)&mssvLength, sizeof(mssvLength));
        students[i].MSSV.resize(mssvLength);
        inFile.read(&students[i].MSSV[0], mssvLength);

        // Đọc HoTen
        int hotenLength;
        inFile.read((char*)&hotenLength, sizeof(hotenLength));
        students[i].HoTen.resize(hotenLength);
        inFile.read(&students[i].HoTen[0], hotenLength);
    }

    inFile.close();
}

int main() {
    // Tạo danh sách sinh viên để ghi vào file
    SinhVien studentsToWrite[] = {
        {"12345", "Nguyen Van A"},
        {"67890", "Le Thi B"}
    };
    int numStudentsToWrite = 2;

    // Ghi danh sách sinh viên vào file
    writeStudentsToBinaryFile("students.dat", studentsToWrite, numStudentsToWrite);

    // Đọc danh sách sinh viên từ file
    SinhVien* studentsRead = nullptr;
    int numStudentsRead;
    readStudentsFromBinaryFile("students.dat", studentsRead, numStudentsRead);

    // Hiển thị danh sách sinh viên đọc được
    std::cout << "So luong sinh vien: " << numStudentsRead << std::endl;
    for (int i = 0; i < numStudentsRead; ++i) {
        std::cout << "MSSV: " << studentsRead[i].MSSV << ", Ho Ten: " << studentsRead[i].HoTen << std::endl;
    }

    // Giải phóng bộ nhớ
    delete[] studentsRead;

    return 0;
}
