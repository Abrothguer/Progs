#include <iostream>

using namespace std;

int ugly_number(int n) {
    int ugly[n];
    int m2, m3, m5;

    ugly[0] = 1;
    m2      = m3 = m5 = 0;
    for (int i = 1; i < n; ++i) {
        ugly[i] = min(ugly[m2] * 2, min(ugly[m3] * 3, ugly[m5] * 5));
        if (ugly[i] == ugly[m2] * 2) {
            ++m2;
        }
        if (ugly[i] == ugly[m3] * 3) {
            ++m3;
        }
        if (ugly[i] == ugly[m5] * 5) {
            ++m5;
        }
    }
    return(ugly[n - 1]);
}

int main() {
    int n;

    while (true) {
        cout << "Type n to find the nth ugly number: ";
        cin >> n;
        if (n <= 0) {
            break;
        }
        cout << "The " << n << "th ugly number is " << ugly_number(n) << endl;
    }

    return(0);
}
