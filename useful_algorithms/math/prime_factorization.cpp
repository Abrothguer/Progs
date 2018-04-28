#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Finds all prime factors of a number n and returns them.
vector<int> prime_factors(int n){
    // If n is 0 return an empty vector.
    vector<int> factors;
    if (not n) {
        return (factors);
    }

    // Divide n by 2 until n is even.
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    // Try to divide n starting at 3 and ending at its square root.
    for (int i = 3; i <= sqrt(n); i += 2) {
        // Divide n by i while the remainder is 0.
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    // Here n should be 1, if it is not then n is a prime number.
    if (n != 1) {
        factors.push_back(n);
    }

    return (factors);
}

int main(){
    int n;

    cout << "Prime factors! Type the number: ";
    cin >> n;

    vector<int> facs = prime_factors(n);

    cout << "Prime factors of " << n << " are: " << endl;
    for (unsigned i = 0; i < facs.size(); ++i) {
        cout << facs[i] << " ";
    }
    cout << endl;

    return (0);
}
