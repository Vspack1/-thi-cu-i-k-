//De thi cuoi ki nam ngoai
#include <iostream>
using namespace std;

// C1a: Ham S(n): tinh gia tri so thuc S(n) = 1/3 + 1/7 + ... + 1/(2n + 1)
double S(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += 1.0 / (2 * i + 1);
    }
    return sum;
}

// C1b: Ham C(n): tra ve so cac so chan trong n
int C(int n) {
    return (n % 2 == 0) ? n / 2 : (n - 1) / 2;
}

// C1c: Ham IsChonNhat(n): kiem tra neu n la so nguyen duong chan
bool IsChonNhat(int n) {
    return (n > 0 && n % 2 == 0);
}

// C2a: Ham in cac so chan trong khoang tu 20 den n
void InSoChan(int n) {
    cout << "Cac so chan: ";
    for (int i = 20; i <= n; i++) {
        if (i % 2 == 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}

// C2b: Ham in cac so le trong khoang tu n den 20
void InSoLe(int n) {
    cout << "Cac so le: ";
    for (int i = n; i >= 20; i--) {
        if (i % 2 != 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    char tieptuc;

    do {
        // Nhap so nguyen duong n tu ban phim
        cout << "Nhap so nguyen duong n: ";
        cin >> n;

        if (n <= 0) {
            cout << "Vui long nhap so nguyen duong!\n";
            continue;
        }

        // C1: Goi ham va hien thi ket qua
        cout << "Gia tri S(" << n << ") = " << S(n) << endl;
        cout << "So luong cac so chan trong " << n << " la: " << C(n) << endl;

        if (IsChonNhat(n)) {
            cout << n << " la so nguyen duong chan.\n";
        }
        else {
            cout << n << " khong phai la so nguyen duong chan.\n";
        }

        // C2: Xu ly in so chan hoac so le trong khoang 20 den 40
        if (n >= 20 && n <= 40) {
            if (n % 2 == 0) {
                InSoChan(n); // C2a
            }
            else {
                InSoLe(n); // C2b
            }
        }
        else {
            cout << "n khong nam trong khoang 20 - 40.\n";
        }

        // Hoi nguoi dung co muon tiep tuc hay khong
        cout << "Ban co muon tiep tuc? (y/n): ";
        cin >> tieptuc;

    } while (tieptuc == 'y' || tieptuc == 'Y');

    cout << "Chuong trinh ket thuc.\n";
    return 0;
}
