#include <iostream>

using namespace std;

long fibonacci(long n) {
    if (not n or n == 1) {
        return(n);
    }
    long a, b, tmp;
    a = 0;
    b = 1;

    for (int i = 2; i <= n; ++i) {
        tmp = a;
        a   = b;
        b   = tmp + b;
    }

    return(b);
}

int main() {
    long n;

    while (true) {
        cout << "Type a number: ";
        cin >> n;
        if (n < 0) {
            break;
        }
        cout << "Fib (" << n << ") = " << fibonacci(n) << endl;
    }
    return(0);
}
