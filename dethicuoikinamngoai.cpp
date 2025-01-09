#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

// Ham tinh gia tri S(n)
double TinhSn(int n) {
    double S = 0;
    for (int i = 1; i <= n; i++) {
        S += 1.0 / (2 * i + 1);
    }
    return S;
}

// Ham tim chu so nho nhat trong so nguyen
int ChuSoNhoNhat(int n) {
    n = abs(n); // Loai bo dau am neu co
    int minDigit = 9;
    while (n > 0) {
        int digit = n % 10;
        if (digit < minDigit) {
            minDigit = digit;
        }
        n /= 10;
    }
    return minDigit;
}

// Menu chinh
void Menu() {
    int choice;
    do {
        system("cls");
        cout << "========== MENU ==========" << endl;
        cout << "1. Tinh S(n)" << endl;
        cout << "2. Tim chu so nho nhat trong so nguyen" << endl;
        cout << "0. Thoat" << endl;
        cout << "==========================" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int n;
            cout << "Nhap n (so nguyen duong): ";
            cin >> n;
            if (n > 0) {
                cout << "S(" << n << ") = " << TinhSn(n) << endl;
            }
            else {
                cout << "n phai la so nguyen duong!" << endl;
            }
            system("pause");
            break;
        }
        case 2: {
            int n;
            cout << "Nhap so nguyen: ";
            cin >> n;
            cout << "Chu so nho nhat trong " << n << " la: " << ChuSoNhoNhat(n) << endl;
            system("pause");
            break;
        }
        case 0:
            cout << "Thoat chuong trinh." << endl;
            break;
        default:
            cout << "Lua chon khong hop le!" << endl;
            system("pause");
        }
    } while (choice != 0);
}

// Ham sinh so ngau nhien trong khoang [20, 40]
void SinhMangNgauNhien(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = 20 + rand() % 21; // [20, 40]
    }
}

// Ham phan tu cach nhau it nhat 3 don vi
bool KiemTraCachNhau3DonVi(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (abs(arr[i] - arr[i + 1]) < 3) {
            return false;
        }
    }
    return true;
}

// Ham sap xep chan le theo yeu cau
void SapXepChanLe(int* arr, int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        while (left < n && arr[left] % 2 == 0) left++;
        while (right >= 0 && arr[right] % 2 != 0) right--;
        if (left < right) {
            swap(arr[left], arr[right]);
        }
    }
}

// In mang
void InMang(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0)); // Khoi tao sinh so ngau nhien
    int choice;
    do {
        system("cls");
        cout << "========== MENU ==========" << endl;
        cout << "1. Bai 1" << endl;
        cout << "2. Bai 2" << endl;
        cout << "0. Thoat" << endl;
        cout << "==========================" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
        case 1:
            Menu();
            break;
        case 2: {
            int n;
            cout << "Nhap so phan tu mang (n): ";
            cin >> n;
            int* arr = new int[n];

            SinhMangNgauNhien(arr, n);
            cout << "Mang ngau nhien: ";
            InMang(arr, n);

            if (KiemTraCachNhau3DonVi(arr, n)) {
                cout << "Cac phan tu cach nhau it nhat 3 don vi." << endl;
            }
            else {
                cout << "Cac phan tu khong cach nhau it nhat 3 don vi." << endl;
            }

            SapXepChanLe(arr, n);
            cout << "Mang sau khi sap xep chan le: ";
            InMang(arr, n);

            delete[] arr;
            system("pause");
            break;
        }
        case 0:
            cout << "Thoat chuong trinh." << endl;
            break;
        default:
            cout << "Lua chon khong hop le!" << endl;
            system("pause");
        }
    } while (choice != 0);

    return 0;
}
