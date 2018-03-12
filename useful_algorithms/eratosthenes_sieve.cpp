#include <iostream>

using namespace std;

void sieve_it(int n, bool sieve[]) {
    for (int i = 2; i <= n; ++i) {
        sieve[i] = true;
    }

    sieve[0] = false;
    sieve[1] = false;

    for (int i = 2; i *i <= n; ++i) {
        if (not sieve[i]) {
            continue;
        }

        for (int j = i + i; j <= n; j += i) {
            sieve[j] = false;
        }
    }
}

int main() {
    int n, mx;

    cout << "Type the maximum number: ";
    cin >> mx;

    bool sieve[mx + 1];
    sieve_it(mx, sieve);

    while (true) {
        cout << "Type a number: ";
        cin >> n;
        if (n <0 or n> mx) {
            break;
        }
        cout << n << (sieve[n] ? " is prime!" : " is not prime") << endl;
    }

    return(0);
}
