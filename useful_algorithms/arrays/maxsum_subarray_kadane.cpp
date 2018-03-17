#include <iostream>
#include <climits>

using namespace std;


int maxsum_kadane(int array[], int n){
    int max_here, max_total, largest;
    max_here = max_total = 0;
    largest  = INT_MIN;

    for (int i = 0; i < n; ++i) {
        max_here += array[i];
        if (max_here < 0) {
            max_here = 0;
        }else if (max_total < max_here) {
            max_total = max_here;
        }
        largest = max(largest, array[i]);
    }

    if (largest < 0) return largest;
    return max_total;
}


int main() {
    int n, a;

    while (true) {
        cout << "How many elements: ";
        cin >> n;
        if (not n) {
            break;
        }
        cout << "Type the elements: " << endl;

        int array[n];
        for (int i = 0; i < n; ++i) {
            cin >> a;
            array[i] = a;
        }
        cout << "The maximum subarray sum is: " << maxsum_kadane(array, n) << endl;
    }

    return 0;
}
