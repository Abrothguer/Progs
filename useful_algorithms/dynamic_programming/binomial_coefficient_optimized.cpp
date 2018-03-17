#include <iostream>

using namespace std;

int coefficient_optimized(int n, int k){
    int array[k + 1];

    for (int i = 0; i <= n; ++i) {
        for (int j = min(k, i); j >= 0; --j) {
            if (i == j or not j) {
                array[j] = 1;
            }
            else{
                array[j] = array[j] + array[j - 1];
            }
        }
    }

    return (array[k]);
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

        cout << "C (" << n << ", " << k << ") = " << coefficient_optimized(n, k) << endl;
    }

    return (0);
}
