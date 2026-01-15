#include <iostream>
using namespace std;

// Kengaytirilgan Evklid algoritmi
long long gcd_ext(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = gcd_ext(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

int main() {
    long long a, b;
    int maxC;

    cout << "a va b ni kiriting: ";
    cin >> a >> b;

    cout << "c uchun maksimal qiymatni kiriting (c = 4 ... maxC): ";
    cin >> maxC;

    for (int c = 4; c <= maxC; ++c) {
        cout << "==========================================" << endl;

        // Tenglama chiqarish
        cout << a << " * x ";
        if (b >= 0) cout << "+ ";
        cout << b << " * y = " << c << endl;

        long long x0, y0;
        long long d = gcd_ext(a, b, x0, y0);

        // Yechim mavjudligini tekshirish
        if (c % d != 0) {
            cout << "Yechim yo'q (c gcd(a, b) ga bo'linmaydi)" << endl;
            continue;
        }

        // Xususiy yechim
        long long factor = c / d;
        x0 *= factor;
        y0 *= factor;

        cout << "Xususiy yechim: x0 = " << x0 << ", y0 = " << y0 << endl;

        // Umumiy yechim qadamlar
        long long dx = b / d;
        long long dy = a / d;

        cout << "No'no‘liy butun yechimlar (x >= 0, y >= 0):" << endl;

        bool found = false;
        for (int k = -maxC; k <= maxC; ++k) {
            long long x = x0 + k * dx;
            long long y = y0 - k * dy;

            if (x >= 0 && y >= 0) {
                cout << "k = " << k << ": x = " << x << ", y = " << y << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "Berilgan oraliqda no‘no‘liy yechim topilmadi." << endl;
        }
    }

    return 0;
}
