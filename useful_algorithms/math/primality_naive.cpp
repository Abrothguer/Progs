#include <iostream>
#include <cmath>

using namespace std;

int naive_prime(int n) {
    if (n == 1) {
        return(false);
    }
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return(false);
        }
    }
    return(true);
}

int main() {
    int n;

    while (true) {
        cout << "Type a number: ";
        cin >> n;
        if (n <= 0) {
            break;
        }

        cout << n << (naive_prime(n) ?  " is prime!" : " is not prime!") << endl;
    }
    return(0);
}
