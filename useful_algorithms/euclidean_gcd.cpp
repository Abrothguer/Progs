#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (a == 0) {
        return(b);
    }
    else{ return(gcd(b % a, a)); }
}

int main() {
    int a, b;

    while (true) {
        cout << "Type a: ";
        cin >> a;
        cout << "Type b: ";
        cin >> b;
        if (not a or not b) {
            break;
        }

        cout << "GCD (" << a << ", " << b << ") = " << gcd(a, b) << endl;
    }
}
