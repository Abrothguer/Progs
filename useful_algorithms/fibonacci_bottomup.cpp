#include <iostream>

using namespace std;

long fibonacci_dp(long n) {
    long fibo[n + 1];

    fibo[0] = 0;
    fibo[1] = 1;

    for (int i = 2; i <= n; ++i) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }

    return(fibo[n]);
}

int main() {
    long n;

    while (true) {
        cout << "Type a number: ";
        cin >> n;
        if (n < 0) {
            break;
        }
        cout << "Fib (" << n << ") = " << fibonacci_dp(n) << endl;
    }
    return(0);
}
