#include <iostream>
#include <cstdlib>

using namespace std;

int gcd(int a, int b) {
    if (a == 0) {
        return (b);
    }
    else{ return (gcd(b % a, a) ); }
}

int pollard_rho(int n){
    int x1, x2, ans;

    // x1 starts at 2.
    x1 = 2;

    // Test with n random generated numbers
    for (int i = 0; i < n; ++i) {
        // Atribute random value to x2.
        x2 = rand() % n;

        // Compute the gcd of x1-x2 and n
        ans = gcd(abs(x1 - x2), n);

        // If the gcd is not 1 then we have found a factor
        if (ans > 1) {
            return (ans);
        }

        // Update the value on x1
        x1 = x2;
    }

    // If the algorithm reaches this point n is probably prime.
    return (n);
}


int main(){
    int n;

    srand(time(NULL) );
    cout << "Find a factor! Type the number: ";
    cin >> n;

    int factor = pollard_rho(n);

    cout << "A factor of " << n << " is " << factor;
    cout << endl;

    return (0);
}
