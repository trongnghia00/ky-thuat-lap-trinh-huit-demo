#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct MonHoc {
    string maMon;
    string tenMon;
    int soTinChi;
    float diem;
};

struct SinhVien {
    string maSo;
    string hoTen;
    MonHoc* dsMonHoc;  // Mảng động để lưu các môn học
    int soMonHoc;
};

// Hàm nhập danh sách sinh viên từ file
void nhapDanhSachSinhVien(SinhVien*& dsSinhVien, int& n, const string& tenFile) {
    ifstream file(tenFile);
    if (!file) {
        cout << "Không thể mở file " << tenFile << endl;
        return;
    }

    file >> n;
    dsSinhVien = new SinhVien[n];

    for (int i = 0; i < n; ++i) {
        file >> dsSinhVien[i].maSo;
        file.ignore(); // Bỏ qua ký tự newline
        getline(file, dsSinhVien[i].hoTen);

        file >> dsSinhVien[i].soMonHoc;
        dsSinhVien[i].dsMonHoc = new MonHoc[dsSinhVien[i].soMonHoc];

        for (int j = 0; j < dsSinhVien[i].soMonHoc; ++j) {
            file >> dsSinhVien[i].dsMonHoc[j].maMon;
            file.ignore(); // Bỏ qua ký tự newline
            getline(file, dsSinhVien[i].dsMonHoc[j].tenMon);
            file >> dsSinhVien[i].dsMonHoc[j].soTinChi;
            file >> dsSinhVien[i].dsMonHoc[j].diem;
        }
    }
    file.close();
}

// Hàm xuất danh sách sinh viên ra file
void ghiDanhSachSinhVien(SinhVien* dsSinhVien, int n, const string& tenFile) {
    ofstream file(tenFile);
    if (!file) {
        cout << "Không thể mở file " << tenFile << endl;
        return;
    }

    file << n << endl;
    for (int i = 0; i < n; ++i) {
        file << dsSinhVien[i].maSo << endl;
        file << dsSinhVien[i].hoTen << endl;
        file << dsSinhVien[i].soMonHoc << endl;
        for (int j = 0; j < dsSinhVien[i].soMonHoc; ++j) {
            file << dsSinhVien[i].dsMonHoc[j].maMon << endl;
            file << dsSinhVien[i].dsMonHoc[j].tenMon << endl;
            file << dsSinhVien[i].dsMonHoc[j].soTinChi << endl;
            file << dsSinhVien[i].dsMonHoc[j].diem << endl;
        }
    }
    file.close();
}

// Hàm xuất danh sách sinh viên ra màn hình
void xuatDanhSachSinhVien(SinhVien* dsSinhVien, int n) {
    cout << "Danh sach sinh vien: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Ma so sinh vien: " << dsSinhVien[i].maSo << endl;
        cout << "Ho ten sinh vien: " << dsSinhVien[i].hoTen << endl;
        cout << "So mon hoc: " << dsSinhVien[i].soMonHoc << endl;

        for (int j = 0; j < dsSinhVien[i].soMonHoc; ++j) {
            cout << "  Ma mon: " << dsSinhVien[i].dsMonHoc[j].maMon << endl;
            cout << "  Ten mon: " << dsSinhVien[i].dsMonHoc[j].tenMon << endl;
            cout << "  So tin chi: " << dsSinhVien[i].dsMonHoc[j].soTinChi << endl;
            cout << "  Diem: " << dsSinhVien[i].dsMonHoc[j].diem << endl;
        }

        cout << "-----------------------------" << endl;
    }
}

// Hàm tìm sinh viên theo mã số sinh viên
SinhVien* timSinhVien(SinhVien* dsSinhVien, int n, const string& maSo) {
    for (int i = 0; i < n; ++i) {
        if (dsSinhVien[i].maSo == maSo) {
            return &dsSinhVien[i];
        }
    }
    return nullptr;
}

// Hàm thêm một sinh viên vào danh sách
void themSinhVien(SinhVien*& dsSinhVien, int& n, const SinhVien& svMoi) {
    SinhVien* temp = new SinhVien[n + 1];
    for (int i = 0; i < n; ++i) {
        temp[i] = dsSinhVien[i];
    }
    temp[n] = svMoi;
    delete[] dsSinhVien;
    dsSinhVien = temp;
    ++n;
}

// Hàm xóa một sinh viên khỏi danh sách theo mã số sinh viên
bool xoaSinhVien(SinhVien*& dsSinhVien, int& n, const string& maSo) {
    for (int i = 0; i < n; ++i) {
        if (dsSinhVien[i].maSo == maSo) {
            for (int j = i; j < n - 1; ++j) {
                dsSinhVien[j] = dsSinhVien[j + 1];
            }
            --n;
            SinhVien* temp = new SinhVien[n];
            for (int k = 0; k < n; ++k) {
                temp[k] = dsSinhVien[k];
            }
            delete[] dsSinhVien;
            dsSinhVien = temp;
            return true;
        }
    }
    return false;
}

// Hàm giải phóng bộ nhớ
void giaiPhongBoNho(SinhVien* dsSinhVien, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] dsSinhVien[i].dsMonHoc;
    }
    delete[] dsSinhVien;
}

int main() {
    SinhVien* dsSinhVien = nullptr;
    int n = 0;
    string tenFile = "sinhvien.txt";
    int luaChon;

    do {
        cout << "===== MENU =====\n";
        cout << "1. Doc du lieu tu file\n";
        cout << "2. Xuat danh sach sinh vien ra man hinh\n";
        cout << "3. Tim sinh vien\n";
        cout << "4. Them sinh vien\n";
        cout << "5. Xoa sinh vien\n";
        cout << "0. Thoat\n";
        cout << "Lua chon cua ban: ";
        cin >> luaChon;
        cin.ignore();  // Bỏ qua ký tự newline sau khi nhập số

        switch (luaChon) {
            case 1: {
                ifstream file(tenFile);
                if (!file) {
                    cout << "File khong ton tai. Tao file moi.\n";
                    ofstream newFile(tenFile);
                    newFile.close();
                } else {
                    nhapDanhSachSinhVien(dsSinhVien, n, tenFile);
                    cout << "Doc du lieu thanh cong.\n";
                }
                break;
            }
            case 2: {
                if (dsSinhVien != nullptr && n > 0) {
                    xuatDanhSachSinhVien(dsSinhVien, n);
                } else {
                    cout << "Danh sach sinh vien rong hoac chua duoc doc du lieu.\n";
                }
                break;
            }
            case 3: {
                string maSo;
                cout << "Nhap ma so sinh vien can tim: ";
                getline(cin, maSo);
                SinhVien* sv = timSinhVien(dsSinhVien, n, maSo);
                if (sv) {
                    cout << "Thong tin sinh vien tim thay:\n";
                    cout << "Ma so: " << sv->maSo << "\nHo ten: " << sv->hoTen << endl;
                } else {
                    cout << "Khong tim thay sinh vien co ma so " << maSo << endl;
                }
                break;
            }
            case 4: {
                SinhVien svMoi;
                cout << "Nhap ma so sinh vien: ";
                getline(cin, svMoi.maSo);
                cout << "Nhap ho ten sinh vien: ";
                getline(cin, svMoi.hoTen);
                cout << "Nhap so mon hoc: ";
                cin >> svMoi.soMonHoc;
                cin.ignore();  // Bỏ qua ký tự newline

                svMoi.dsMonHoc = new MonHoc[svMoi.soMonHoc];
                for (int i = 0; i < svMoi.soMonHoc; ++i) {
                    cout << "Nhap ma mon hoc " << i + 1 << ": ";
                    getline(cin, svMoi.dsMonHoc[i].maMon);
                    cout << "Nhap ten mon hoc " << i + 1 << ": ";
                    getline(cin, svMoi.dsMonHoc[i].tenMon);
                    cout << "Nhap so tin chi mon hoc " << i + 1 << ": ";
                    cin >> svMoi.dsMonHoc[i].soTinChi;
                    cout << "Nhap diem mon hoc " << i + 1 << ": ";
                    cin >> svMoi.dsMonHoc[i].diem;
                    cin.ignore();  // Bỏ qua ký tự newline
                }

                themSinhVien(dsSinhVien, n, svMoi);
                cout << "Them sinh vien thanh cong.\n";
                ghiDanhSachSinhVien(dsSinhVien, n, tenFile);
                break;
            }
            case 5: {
                if (n > 0) {
                    cout << "Danh sach sinh vien hien tai:\n";
                    for (int i = 0; i < n; ++i) {
                        cout << dsSinhVien[i].maSo << " - " << dsSinhVien[i].hoTen << endl;
                    }

                    string maSo;
                    cout << "\nNhap ma so sinh vien can xoa: ";
                    getline(cin, maSo);

                    if (xoaSinhVien(dsSinhVien, n, maSo)) {
                        cout << "Xoa sinh vien thanh cong.\n";
                    } else {
                        cout << "Khong tim thay sinh vien co ma so " << maSo << endl;
                    }
                } else {
                    cout << "Danh sach sinh vien dang rong.\n";
                }
                break;
            }
            case 0:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }
        // Tạm dừng để người dùng có thể xem thông báo trước khi xóa màn hình
        system("pause"); 
        system("cls");  // Sử dụng "clear" nếu bạn đang sử dụng Linux/MacOS
    } while (luaChon != 0);

    giaiPhongBoNho(dsSinhVien, n);
    return 0;
}
