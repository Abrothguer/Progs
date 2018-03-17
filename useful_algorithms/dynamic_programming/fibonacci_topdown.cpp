#include <iostream>

using namespace std;

int fibonacci_dp(long memo[], long n) {
    if (memo[n] != -1) {
        return(memo[n]);
    }

    return(memo[n] = fibonacci_dp(memo, n - 1) + fibonacci_dp(memo, n - 2));
}

int main() {
    long n;

    while (true) {
        cout << "Type a number: ";
        cin >> n;
        if (n < 0) {
            break;
        }

        long memo[n + 1];
        for (int i = 0; i <= n; ++i) {
            memo[i] = -1;
        }

        memo[0] = 0;
        memo[1] = 1;
        cout << "Fib (" << n << ") = " << fibonacci_dp(memo, n) << endl;
    }
    return(0);
}
