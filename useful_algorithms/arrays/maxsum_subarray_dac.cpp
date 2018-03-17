// Finds the maximum sum of a subarray using divide and conquer method.

#include <iostream>
#include <climits>

using namespace std;

int g;
int maxsum_dac(int array[], int start, int end){
    if (start == end) return array[end];

    int middle, maxleft, maxright, rsum, lsum, maxsum;

    middle   = (end + start) / 2;
    maxleft  = maxsum_dac(array, start, middle);
    maxright = maxsum_dac(array, middle + 1, end);

    maxsum = 0;
    lsum   = rsum = INT_MIN;
    for (int i = middle - 1; i >= 0; --i) {
        maxsum += array[i];
        lsum    = max(maxsum, lsum);
    }

    maxsum = 0;
    for (int i = middle; i <= end; ++i) {
        maxsum += array[i];
        rsum    = max(maxsum, rsum);
    }
    if (rsum == INT_MIN or lsum == INT_MIN) return max(maxleft, maxright);
    return max(max(maxleft, maxright), rsum + lsum);
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
        cout << "The maximum subarray sum is: " << maxsum_dac(array, 0, n - 1) << endl;
    }

    return 0;
}
