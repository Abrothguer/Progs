#include <iostream>

#define MAX    300

using namespace std;

int coefficient_topdown(int memo[][MAX], int n, int k){
    if (memo[n][k] == -1) {
        memo[n][k] = coefficient_topdown(memo, n - 1, k - 1) + coefficient_topdown(memo, n - 1, k);
    }
    return (memo[n][k]);
}

int main(){
    int n, k;

    int memo[300][300];
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            if (i == j or not j) {
                memo[i][j] = 1;
            }
            else{
                memo[i][j] = -1;
            }
        }
    }

    while (true) {
        cout << "Type n: ";
        cin >> n;
        if (n < 0) {
            break;
        }
        cout << "Type k: ";
        cin >> k;

        cout << "C (" << n << ", " << k << ") = " << coefficient_topdown(memo, n, k) << endl;
    }

    return (0);
}
