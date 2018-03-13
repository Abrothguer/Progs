#include <iostream>

using namespace std;

int extended_gcd(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return(b);
    }
    int gcd, temp;
    gcd = extended_gcd(b % a, a, x, y);

    temp = *x;
    *x   = (*y) - (b / a) * (*x);
    *y   = temp;
    return(gcd);
}

int main() {
    int a, b;

    while (true) {
        cout << "Type two numbers: ";
        cin >> a >> b;
        if (a <= 0 or b <= 0) {
            break;
        }

        int x, y;
        cout << "GCD (" << a << ", " << b << ") = " << extended_gcd(a, b, &x, &y) << endl;
        cout << a << " * " << x << " - " << b << " * " << y << " = GCD(" << a << ", " << b << ")" << endl;
    }
    return(0);
}
