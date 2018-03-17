#include <iostream>

using namespace std;

int coefficient_bottomup(int n, int k){
    int table[n + 1][k + 1];

    // C(n,n) = C(n,0) = 1;
    // C(n,k) = C(n-1, k-1) + C(n-1, k);

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= min(i, k); ++j) {
            if (i == j or not j) {
                table[i][j] = 1;
            }
            else{
                table[i][j] = table[i - 1][j - 1] + table[i - 1][j];
            }
        }
    }

    return (table[n][k]);
}

int main(){
    int n, k;

    while (true) {
        cout << "Type n: ";
        cin >> n;
        if (n < 0) {
            break;
        }
        cout << "Type k: ";
        cin >> k;

        cout << "C (" << n << ", " << k << ") = " << coefficient_bottomup(n, k) << endl;
    }

    return (0);
}
